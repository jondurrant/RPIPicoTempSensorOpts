/*
 * TestDS3231.cpp
 *
 * Test a DS3231 Library is working
 *
 *  Created on: 7 Nov 2023
 *      Author: jondurrant
 */

#include "CppUTest/TestHarness.h"

#include "pico/stdlib.h"
#include "DS3231.hpp"
#include <cstdio>

TEST_GROUP(DS3231){

};

TEST(DS3231, Sanity){

	int i = 0;
	i2c_inst_t * i2c =  & i2c0_inst;

	DS3231 rtc( i2c, 20, 21);

	printf("DS3231: %s -- %s -- %d%C %.2fC\n", rtc.get_date_str(), rtc.get_time_str(), rtc.get_temp(), rtc.get_temp_f());

   CHECK(rtc.get_temp_f() > 18.0);
   CHECK(rtc.get_temp_f() < 25.0);
}



