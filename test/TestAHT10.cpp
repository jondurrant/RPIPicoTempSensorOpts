/*
 * TestAHT10.cpp
 *
 * Test a AHT10 Library is working
 *
 *  Created on: 4-Dev-2023
 *      Author: jondurrant
 */

#include "CppUTest/TestHarness.h"

#include "pico/stdlib.h"
#include "ahtxx/ahtxx.hpp"
#include <cstdio>

TEST_GROUP(AHT10){

};

TEST(AHT10, Sanity){
	int i=0;
	float temp;
	float humidity;

	LIB_AHTXX myAHT10(AHT10_ADDRESS_0X38, i2c0, 20, 21, 100);

	myAHT10.AHT10_InitI2C(AHT10_SENSOR);
	busy_wait_ms(500);

	// Start the sensor comms

	while (myAHT10.AHT10_begin() != true) {
		printf("AHT10 not connect r fail load calib coeff \r\n");
		busy_wait_ms(5000);
		i++;
		if (i > 5){
			FAIL("Failed to connect");
		}
	}

	temp = myAHT10.AHT10_readTemperature(true);
	CHECK(temp > 18.0);
	CHECK(temp < 25.0);

	humidity = myAHT10.AHT10_readHumidity(true);

	CHECK(humidity > 30.0);
	CHECK(humidity < 100.0);

	printf("AHT10 %.2fC %.2fH \n", temp, humidity);


}



