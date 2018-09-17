#ifndef PWM_H_
#define PWM_H_

 /****************************************************************
 * Constants
 ****************************************************************/

#define SYSFS_PWM_DIR "/sys/class/pwm/pwmchip3"
#define SYSFS_PWM_PIN "/sys/class/pwm/pwmchip0/pwm-0:0"
#define MAX_BUF 64

#define PWM0 "pwm-0:0"	// P9.14
#define PWM1 "pwm-0:1"	// P9.16
/****************************************************************
 * pwm funtions
 ****************************************************************/
int pwm_export(unsigned int pwm);
int pwm_unexport(unsigned int pwm);
int pwm_duty_set(unsigned int duty,char* pwm_n);
int pwm_period_set(unsigned int period,char* pwm_n);
int pwm_enable(unsigned int enable,char* pwm_n);

#endif /* SIMPLEGPIO_H_ */