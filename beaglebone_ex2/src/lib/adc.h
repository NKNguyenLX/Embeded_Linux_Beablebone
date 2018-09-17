#ifndef ADC_H_
#define ADC_H_

 /****************************************************************
 * Constants
 ****************************************************************/

//#define SYSFS_PWM_DIR "/sys/class/pwm/pwmchip3"
//#define SYSFS_PWM_PIN "/sys/class/pwm/pwmchip0/pwm-0:0"
#define MAX_BUF 64
//
//#define PWM0 "pwm-0:0"
//#define PWM1 "pwm-0:1"
/****************************************************************
 * adc funtions
 ****************************************************************/

int adc_pin_read(char adc_pin);
int stod(char* string);

#endif /* SIMPLEGPIO_H_ */
