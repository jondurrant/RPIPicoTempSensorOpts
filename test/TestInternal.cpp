/*
 * TestInternal.cpp
 *
 * Test Internal Temp Sensor
 *
 *  Created on: 4-Dev-2023
 *      Author: jondurrant
 */

#include "CppUTest/TestHarness.h"

#include "pico/stdlib.h"
#include <cstdio>
#include "hardware/adc.h"

TEST_GROUP(INTERNAL){

};

TEST(INTERNAL, Sanity){
	float temp;

	adc_init();
	adc_set_temp_sensor_enabled(true);

	const float conversion_factor = 3.3f / (1 << 12);
	adc_select_input(4);

	float v = (float)adc_read() * conversion_factor;
	temp = 27.0 - ((v - 0.706)/0.001721);

	printf("Internal %.2fC \n", temp);

	CHECK(temp > 18.0);
	CHECK(temp < 25.0);


}



