#ifndef __GP2AP110S_H__
#define __GP2AP110S_H__

//// Register address ////
#define REG_COM1              0x80
#define REG_COM2              0x81
#define REG_COM3              0x82
#define REG_COM4              0x83

#define REG_D0_LSB              0x90
#define REG_D0_MSB              0x91
#define REG_REV_CODE            0xA0
#define REG_DYNAMIC_CAL_RESULT  0xC0

#define DYNAMIC_CALIBRATION_DELAY   1000
#define AUTO_CALIB_OFFSET_MAX 4500

struct gp2ap_data
{
	struct mutex		mutex;
	struct i2c_client	*client;
	struct delayed_work	dynamic_calib_work;
	struct hrtimer		prox_timer;
	struct workqueue_struct	*prox_wq;
	struct work_struct	work_prox;
	ktime_t			prox_poll_delay;
	atomic_t		prox_enable;
	int			avg[3];
	int			p_out;
	int			vled_ldo;
	int			ps_irq;
	int			irq_flags;
	struct input_dev	*ps_input_dev;
	struct device		*dev;
	struct work_struct	ps_int_work;
	int			ps_enabled;
	int			ps_distance;
	int			ps_count;
	int			auto_calib_offset;
	int			dynamic_calib_delay;
	u8			dynamic_calib_timer_enabled;
	int			calib_target;
	int			ps_high_th;
	int			ps_low_th;
	int			dynamic_calib_enabled;
	int			dynamic_calib_done;
	enum of_gpio_flags	irq_gpio_flags;
};

#endif