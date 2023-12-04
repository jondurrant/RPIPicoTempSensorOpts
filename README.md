# RPIPicoTempSensorOpts
Looking at options for Temperature Sensing on Raspberry Pi Pico using C SDK.

This was an experiment for a future project and will be shared on my [YouTube channge](https://youtube.com/@drjonea)

## Temperature Options

### DS18B20
My normal go to option is 1 wire device. Using a library here to read it via PIO

### DS3231 RTC
I have also cheated and used the temperature sensor on a Real Time Clock module, DS3231, to do this. 

### AHT10
Perhaps gold standard of these options to read temperature and humidity.


## Clone and build
I am using submodules for the libraries so clone with the command:
```git clone --recurse-submodules ...```

Build through cmake and make.
```
mkdir build
cd build
cmake ..
make
```



