#include "hwlib.hpp"
#include "Sensor.h"

Sensor::Sensor(){};
	
double Sensor::getDistance(){
	bool echoReceived = 0;
	int timeStart, timeEnd, timeDiff;
	
	//Start trigger
	hwlib::wait_ms(50);
	trig.set(1);
	
	//End Trigger, wait for echo
	hwlib::wait_us(20);
	timeStart = static_cast<int> (hwlib::now_us());
	trig.set(0);
	
	while(!echoReceived){
		echoReceived = echo.get();
	}
	while(echoReceived){
		echoReceived = echo.get();
	}
	
	timeEnd = static_cast<int> (hwlib::now_us());
	timeDiff = static_cast<int> ((timeEnd - timeStart));
	double distance = timeDiff / 33 / 2;
	
	return distance;
}
