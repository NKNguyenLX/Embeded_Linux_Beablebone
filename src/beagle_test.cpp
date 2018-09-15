//============================================================================
// Name        : beagle_test.cpp
// Author      : Nguyen
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "SimpleGPIO.h"
#include <stdio.h>
#include <fcntl.h>
#include "pwm.h"

using namespace std;

int main() {
	cout << "!!! Begin !!!" << endl; // prints !!!Hello World!!!
	//gpio_omap_mux_setup("EHRPWM1A", "06"); 	//pwm1a
	pwm_export(0);
	pwm_period_set(10000);
	pwm_duty_set(5000);
	pwm_enable(1);

	cout << "!!! End !!!" << endl; // prints !!!Hello World!!!
	return 0;
}
