/**
 * Jon Durrant.
 *
 * Test of three strategies for measuring temperature
 * DS18B20
 * DS3231 RTC
 * AHT10
 */

#include "pico/stdlib.h"
#include "DS3231.hpp"

#include "ahtxx/ahtxx.hpp"
#include "DS18B20.h"

#include <stdio.h>
#define DELAY 1000

#include "hardware/adc.h"



float getTemp(){
	const float conversion_factor = 3.3f / (1 << 12);
	adc_select_input(4);

	float v = (float)adc_read() * conversion_factor;
	float t = 27.0 - ((v - 0.706)/0.001721);

	return t;
}



int main() {
	int i = 0;
	i2c_inst_t * i2c =  & i2c0_inst;

	adc_init();
	adc_set_temp_sensor_enabled(true);

	DS3231 rtc( i2c, 20, 21);
	LIB_AHTXX myAHT10(AHT10_ADDRESS_0X38, i2c0, 20,  21, 100);
	DS18B20 ds = DS18B20(pio0, 18);
	ds.convert();


	stdio_init_all();

	sleep_ms(2000);
	printf("GO\n");

	myAHT10.AHT10_InitI2C(AHT10_SENSOR);
	while (myAHT10.AHT10_begin() != true) {
			printf("AHT10 not connect r fail load calib coeff \r\n");
			busy_wait_ms(5000);
	}

	for(;;) {
		printf("\n");
		printf("Internal: %fC\n", getTemp());
		printf("DS18B20 %fC\n", ds.getTemperature());
		ds.convert();
		printf("DS3231: %s -- %s -- %d%C %.2fC\n", rtc.get_date_str(), rtc.get_time_str(), rtc.get_temp(), rtc.get_temp_f());
		printf("AHT10 Temp %fC Humidity %f\n",
				myAHT10.AHT10_readTemperature(true),
				myAHT10.AHT10_readHumidity(true));


		sleep_ms(DELAY);


	}

}

