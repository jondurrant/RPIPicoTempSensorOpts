/*
 * TestDS18B20.cpp
 *
 * Test a DS18B20 Library is working
 *
 *  Created on: 4-Dev-2023
 *      Author: jondurrant
 */

#include "CppUTest/TestHarness.h"

#include "pico/stdlib.h"
#include "DS18B20.h"
#include <cstdio>

TEST_GROUP(DS18B20){

};

TEST(DS18B20, Sanity){
	float temp;

	DS18B20 ds = DS18B20(pio0, 18);

	ds.convert();
	busy_wait_ms(1000);

	temp = ds.getTemperature();;
	CHECK(temp > 18.0);
	CHECK(temp < 25.0);



	printf("DS18B20 %.2fC \n", temp);


}



