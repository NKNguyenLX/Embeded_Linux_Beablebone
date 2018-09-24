/**
 * @brief We read adc by access file in_voltage<x>_raw with address: /sys/bus/iio/devices/iio:device0/in_voltage%c_raw
 *          and read value form that file
 *        Before that tree overlay must be installed first by add BB-ADC-00A0.dtbo to /boot/uEvn.txt
 * 
 */
#ifndef ADC_H_
#define ADC_H_

 /****************************************************************
 * Constants
 ****************************************************************/
#define SYSFS_ADC_DIR "/sys/bus/iio/devices/iio:device0"
#define MAX_BUF 64
/****************************************************************
 * adc funtions
 ****************************************************************/


// Init adc pin, input char form 0 to 9
int adc_pin_read(char adc_pin);
// Convert string to integer, return converted integer
int stod(char* string);

#endif /* SIMPLEGPIO_H_ */
