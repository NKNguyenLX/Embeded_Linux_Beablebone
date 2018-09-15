#ifndef PWM_H_
#define PWM_H_

 /****************************************************************
 * Constants
 ****************************************************************/

#define SYSFS_PWM_DIR "/sys/class/pwm/pwmchip3"
#define SYSFS_PWM_PIN "/sys/class/pwm/pwmchip0/pwm-0:0"
#define MAX_BUF 64


/****************************************************************
 * pwm funtions
 ****************************************************************/
int pwm_export(unsigned int pwm);
int pwm_duty_set(unsigned int duty);
int pwm_period_set(unsigned int period);
int pwm_enable(unsigned int enable);

#endif /* SIMPLEGPIO_H_ */
