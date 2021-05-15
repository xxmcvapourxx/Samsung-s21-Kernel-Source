/*
 * s2mps20-irq.c - Interrupt controller support for S2MPS20
 *
 * Copyright (C) 2016 Samsung Electronics Co.Ltd
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
*/

#include <linux/module.h>
#include <linux/err.h>
#include <linux/irq.h>
#include <linux/interrupt.h>
#include <linux/gpio.h>
#include <linux/mfd/samsung/s2mps20.h>
#include <linux/mfd/samsung/s2mps20-regulator.h>

static const u8 s2mps20_mask_reg[] = {
	/* TODO: Need to check other INTMASK */
	[S2MPS20_PMIC_INT1] = S2MPS20_PMIC_REG_INT1M,
	[S2MPS20_PMIC_INT2] = S2MPS20_PMIC_REG_INT2M,
};

static struct i2c_client *get_i2c(struct s2mps20_dev *s2mps20,
				enum s2mps20_irq_source src)
{
	switch (src) {
	case S2MPS20_PMIC_INT1 ... S2MPS20_PMIC_INT2:
		return s2mps20->pmic;
	default:
		return ERR_PTR(-EINVAL);
	}
}

struct s2mps20_irq_data {
	int mask;
	enum s2mps20_irq_source group;
};

#define DECLARE_IRQ(idx, _group, _mask)		\
	[(idx)] = { .group = (_group), .mask = (_mask) }

static const struct s2mps20_irq_data s2mps20_irqs[] = {
	DECLARE_IRQ(S2MPS20_PMIC_IRQ_PWRONF_INT1,		S2MPS20_PMIC_INT1, 1 << 0),
	DECLARE_IRQ(S2MPS20_PMIC_IRQ_PWRONR_INT1,		S2MPS20_PMIC_INT1, 1 << 1),
	DECLARE_IRQ(S2MPS20_PMIC_IRQ_OC0_INT1,			S2MPS20_PMIC_INT1, 1 << 2),
	DECLARE_IRQ(S2MPS20_PMIC_IRQ_OC1_INT1,			S2MPS20_PMIC_INT1, 1 << 3),
	DECLARE_IRQ(S2MPS20_PMIC_IRQ_OC2_INT1,			S2MPS20_PMIC_INT1, 1 << 4),
	DECLARE_IRQ(S2MPS20_PMIC_IRQ_WTSR_INT1,			S2MPS20_PMIC_INT1, 1 << 5),
	DECLARE_IRQ(S2MPS20_PMIC_IRQ_ADCDONE_INT1,		S2MPS20_PMIC_INT1, 1 << 6),
	DECLARE_IRQ(S2MPS20_PMIC_IRQ_WRSTB_INT1,		S2MPS20_PMIC_INT1, 1 << 7),

	DECLARE_IRQ(S2MPS20_PMIC_IRQ_INT120C_INT2,		S2MPS20_PMIC_INT2, 1 << 0),
	DECLARE_IRQ(S2MPS20_PMIC_IRQ_INT140C_INT2,		S2MPS20_PMIC_INT2, 1 << 1),
	DECLARE_IRQ(S2MPS20_PMIC_IRQ_TSD_INT2,			S2MPS20_PMIC_INT2, 1 << 2),
	DECLARE_IRQ(S2MPS20_PMIC_IRQ_OVP_INT2,			S2MPS20_PMIC_INT2, 1 << 3),
	DECLARE_IRQ(S2MPS20_PMIC_IRQ_OCP_B1_INT2,		S2MPS20_PMIC_INT2, 1 << 4),
	DECLARE_IRQ(S2MPS20_PMIC_IRQ_OCP_B2_INT2,		S2MPS20_PMIC_INT2, 1 << 5),
	DECLARE_IRQ(S2MPS20_PMIC_IRQ_OCP_B3_INT2,		S2MPS20_PMIC_INT2, 1 << 6),
};

static void s2mps20_irq_lock(struct irq_data *data)
{
	struct s2mps20_dev *s2mps20 = irq_get_chip_data(data->irq);

	mutex_lock(&s2mps20->irqlock);
}

static void s2mps20_irq_sync_unlock(struct irq_data *data)
{
	struct s2mps20_dev *s2mps20 = irq_get_chip_data(data->irq);
	int i;

	for (i = 0; i < S2MPS20_IRQ_GROUP_NR; i++) {
		u8 mask_reg = s2mps20_mask_reg[i];
		struct i2c_client *i2c = get_i2c(s2mps20, i);

		if (mask_reg == S2MPS20_REG_INVALID ||
				IS_ERR_OR_NULL(i2c))
			continue;
		s2mps20->irq_masks_cache[i] = s2mps20->irq_masks_cur[i];

		s2mps20_write_reg(i2c, s2mps20_mask_reg[i],
				s2mps20->irq_masks_cur[i]);
	}

	mutex_unlock(&s2mps20->irqlock);
}

static const inline struct s2mps20_irq_data *
irq_to_s2mps20_irq(struct s2mps20_dev *s2mps20, int irq)
{
	return &s2mps20_irqs[irq - s2mps20->irq_base];
}

static void s2mps20_irq_mask(struct irq_data *data)
{
	struct s2mps20_dev *s2mps20 = irq_get_chip_data(data->irq);
	const struct s2mps20_irq_data *irq_data =
	    irq_to_s2mps20_irq(s2mps20, data->irq);

	if (irq_data->group >= S2MPS20_IRQ_GROUP_NR)
		return;

	s2mps20->irq_masks_cur[irq_data->group] |= irq_data->mask;
}

static void s2mps20_irq_unmask(struct irq_data *data)
{
	struct s2mps20_dev *s2mps20 = irq_get_chip_data(data->irq);
	const struct s2mps20_irq_data *irq_data =
	    irq_to_s2mps20_irq(s2mps20, data->irq);

	if (irq_data->group >= S2MPS20_IRQ_GROUP_NR)
		return;

	s2mps20->irq_masks_cur[irq_data->group] &= ~irq_data->mask;
}

static struct irq_chip s2mps20_irq_chip = {
	.name			= MFD_DEV_NAME,
	.irq_bus_lock		= s2mps20_irq_lock,
	.irq_bus_sync_unlock	= s2mps20_irq_sync_unlock,
	.irq_mask		= s2mps20_irq_mask,
	.irq_unmask		= s2mps20_irq_unmask,
};

static irqreturn_t s2mps20_irq_thread(int irq, void *data)
{
	struct s2mps20_dev *s2mps20 = data;
	u8 irq_reg[S2MPS20_IRQ_GROUP_NR] = {0};
	u8 irq_src;
	int i, ret;

	pr_debug("%s: irq gpio pre-state(0x%02x)\n", __func__,
				gpio_get_value(s2mps20->irq_gpio));

	ret = s2mps20_read_reg(s2mps20->i2c,
					S2MPS20_PMIC_REG_INTSRC, &irq_src);
	if (ret) {
		pr_err("%s:%s Failed to read interrupt source: %d\n",
			MFD_DEV_NAME, __func__, ret);
		return IRQ_NONE;
	}

	pr_info("%s: interrupt source(0x%02x)\n", __func__, irq_src);

	if (irq_src & S2MPS20_IRQSRC_PMIC) {

		/* W/A : internal clock on */
		/* enable interrupt registers read & clear */
		if (s2mps20->pmic_rev < 1)
			s2mps20_update_reg(s2mps20->i2c, S2MPS20_PMIC_REG_OTP_TEST,
				1 << MOSCEN_SHIFT, MOSCEN_MASK);

		/* PMIC_INT */
		ret = s2mps20_bulk_read(s2mps20->pmic, S2MPS20_PMIC_REG_INT1,
				S2MPS20_NUM_IRQ_PMIC_REGS, &irq_reg[S2MPS20_PMIC_INT1]);
		if (ret) {
			pr_err("%s:%s Failed to read pmic interrupt: %d\n",
				MFD_DEV_NAME, __func__, ret);
			return IRQ_NONE;
		}

		/* internal clock off */
		if (s2mps20->pmic_rev < 1)
			s2mps20_update_reg(s2mps20->i2c, S2MPS20_PMIC_REG_OTP_TEST,
				0 << MOSCEN_SHIFT, MOSCEN_MASK);


		pr_info("%s: pmic interrupt(0x%02x, 0x%02x)\n",
			 __func__, irq_reg[S2MPS20_PMIC_INT1], irq_reg[S2MPS20_PMIC_INT2]);
	}

	/* Apply masking */
	for (i = 0; i < S2MPS20_IRQ_GROUP_NR; i++)
		irq_reg[i] &= ~s2mps20->irq_masks_cur[i];

	/* Report */
	for (i = 0; i < S2MPS20_IRQ_NR; i++) {
		if (irq_reg[s2mps20_irqs[i].group] & s2mps20_irqs[i].mask)
			handle_nested_irq(s2mps20->irq_base + i);
	}

	return IRQ_HANDLED;
}

int s2mps20_irq_init(struct s2mps20_dev *s2mps20)
{
	int i;
	int ret;
	u8 i2c_data;
	int cur_irq;

	if (!s2mps20->irq_gpio) {
		dev_warn(s2mps20->dev, "No interrupt specified.\n");
		s2mps20->irq_base = 0;
		return 0;
	}

	if (!s2mps20->irq_base) {
		dev_err(s2mps20->dev, "No interrupt base specified.\n");
		return 0;
	}

	mutex_init(&s2mps20->irqlock);

	s2mps20->irq = gpio_to_irq(s2mps20->irq_gpio);
	pr_info("%s:%s irq=%d, irq->gpio=%d\n", MFD_DEV_NAME, __func__,
			s2mps20->irq, s2mps20->irq_gpio);

	ret = gpio_request(s2mps20->irq_gpio, "if_pmic_irq");
	if (ret) {
		dev_err(s2mps20->dev, "%s: failed requesting gpio %d\n",
			__func__, s2mps20->irq_gpio);
		return ret;
	}
	gpio_direction_input(s2mps20->irq_gpio);
	gpio_free(s2mps20->irq_gpio);

	/* Mask individual interrupt sources */
	for (i = 0; i < S2MPS20_IRQ_GROUP_NR; i++) {
		struct i2c_client *i2c;

		s2mps20->irq_masks_cur[i] = 0xff;
		s2mps20->irq_masks_cache[i] = 0xff;

		i2c = get_i2c(s2mps20, i);

		if (IS_ERR_OR_NULL(i2c))
			continue;
		if (s2mps20_mask_reg[i] == S2MPS20_REG_INVALID)
			continue;

		s2mps20_write_reg(i2c, s2mps20_mask_reg[i], 0xff);
	}

	/* Register with genirq */
	for (i = 0; i < S2MPS20_IRQ_NR; i++) {
		cur_irq = i + s2mps20->irq_base;
		irq_set_chip_data(cur_irq, s2mps20);
		irq_set_chip_and_handler(cur_irq, &s2mps20_irq_chip,
					 handle_level_irq);
		irq_set_nested_thread(cur_irq, 1);
#ifdef CONFIG_ARM
		set_irq_flags(cur_irq, IRQF_VALID);
#else
		irq_set_noprobe(cur_irq);
#endif
	}

	s2mps20_write_reg(s2mps20->i2c, S2MPS20_PMIC_REG_INTSRC_MASK, 0xff);
	/* Unmask s2mps20 interrupt */
	ret = s2mps20_read_reg(s2mps20->i2c, S2MPS20_PMIC_REG_INTSRC_MASK,
			  &i2c_data);
	if (ret) {
		pr_err("%s:%s fail to read intsrc mask reg\n",
					 MFD_DEV_NAME, __func__);
		return ret;
	}

	/* mask all PMIC interrupts in case of PMIC EVT0 */
	if (s2mps20->pmic_rev >= 1) {
		i2c_data &= ~(S2MPS20_IRQSRC_PMIC);	/* Unmask pmic interrupt */
		s2mps20_write_reg(s2mps20->i2c, S2MPS20_PMIC_REG_INTSRC_MASK, i2c_data);
	}

	pr_info("%s:%s s2mps20_PMIC_REG_INTSRC_MASK=0x%02x\n",
			MFD_DEV_NAME, __func__, i2c_data);

	ret = request_threaded_irq(s2mps20->irq, NULL, s2mps20_irq_thread,
				   IRQF_TRIGGER_LOW | IRQF_ONESHOT,
				   "s2mps20-irq", s2mps20);

	if (ret) {
		dev_err(s2mps20->dev, "Failed to request IRQ %d: %d\n",
			s2mps20->irq, ret);
		return ret;
	}

	return 0;
}
EXPORT_SYMBOL(s2mps20_irq_init);

void s2mps20_irq_exit(struct s2mps20_dev *s2mps20)
{
	if (s2mps20->irq)
		free_irq(s2mps20->irq, s2mps20);
}
EXPORT_SYMBOL(s2mps20_irq_exit);

MODULE_DESCRIPTION("s2mps20 multi-function irq driver");
MODULE_AUTHOR("Samsung Electronics");
MODULE_LICENSE("GPL");
