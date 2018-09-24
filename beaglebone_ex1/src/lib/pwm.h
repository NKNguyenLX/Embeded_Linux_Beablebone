/**
 * @brief   We set PWM by access to pwm0:x with address: /sys/class/pwm/pwmchip0 and init period, duty cycle
 *          Before that tree overlay must be installed first by add BB-PWM1-00A0.dtbo to /boot/uEvn.txt
 * 
 */
#ifndef PWM_H_
#define PWM_H_

 /****************************************************************
 * Constants
 ****************************************************************/

#define SYSFS_PWM_DIR "/sys/class/pwm/pwmchip0"
#define SYSFS_PWM_EXPORT "/sys/class/pwm/pwmchip0/export"
#define SYSFS_PWM_UNEXPORT "/sys/class/pwm/pwmchip0/unexport"
#define SYSFS_PWM_PIN "/sys/class/pwm/pwmchip0/pwm-0:0"
#define MAX_BUF 64

#define PWM0 "pwm-0:0"
#define PWM1 "pwm-0:1"
/****************************************************************
 * pwm funtions
 ****************************************************************/
int pwm_export(unsigned int pwm);
int pwm_unexport(unsigned int pwm);
int pwm_duty_set(unsigned int duty,char* pwm_n);
int pwm_period_set(unsigned int period,char* pwm_n);
int pwm_enable(unsigned int enable,char* pwm_n);

#endif /* SIMPLEGPIO_H_ */
