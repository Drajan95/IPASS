
#include "hwlib.hpp"
#include "Sensor.h"

int main( void ){
	// kill the watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;
	auto trig	= hwlib::target::pin_out(hwlib::target::pins::d28);
	auto echo	= hwlib::target::pin_in (hwlib::target::pins::d29);
	auto ledGreen	= hwlib::target::pin_out(hwlib::target::pins::d32);
	auto ledYellow	= hwlib::target::pin_out(hwlib::target::pins::d33);
	
	auto buttonSend = hwlib::target::pin_out(hwlib::target::pins::d24);
	auto buttonReceived = hwlib::target::pin_in(hwlib::target::pins::d25);
	bool button = false;
	
	Sensor height(trig, echo);
	
	int startTimer = hwlib::now_us();	
	
	hwlib::wait_ms(500);
	
	while(1){
		//Method to use a 'start/pause' button
		if(button){	//Game is paused
			ledGreen.set(0);
			ledYellow.set(1);
		}
		else{		//Game is running
			ledGreen.set(1);
			ledYellow.set(0);

			/*
			bool echoReceived = 0;
			int timeStart, timeEnd, timeDiff;
	
			//Start trigger
			hwlib::wait_ms(50);
			trig.set(1);
	
			//End Trigger, wait for echo
			hwlib::wait_us(50);
			timeStart = static_cast<int> (hwlib::now_us());
			trig.set(0);
	
			while(!echoReceived){
				echoReceived = echo.get();
			}
			while(echoReceived){
				echoReceived = echo.get();
			}
	
			timeEnd = static_cast<int> (hwlib::now_us());
			timeDiff = static_cast<long> ((timeEnd - timeStart));
			int distance = ((timeDiff * 0.029) / 4) - 5;
			
			hwlib::cout << "De afstand is: " << distance << " cm\nDe tijd is: " << timeDiff << "us\n" << hwlib::endl;
			hwlib::wait_ms(100);*/

		}
		//Have to wait a minimum of 1 second between a start/pause. 
		if((hwlib::now_us() - startTimer) > 1000000 && buttonReceived.get() == false){
			startTimer = hwlib::now_us();
			button = !button;
		}
	}
	return 0;
}

/*
#include "window.hpp"
#include "line.hpp"
#include "ball.hpp"
#include "Helicopter.h"
#include "Collision.h"

using namespace std;
int main(){
	Helicopter* heli	= new Helicopter();
    heli->Initialize();
    Collision* col		= new Collision();
	//Window and bounds
	window w( vector( 128, 64 ), 2 );
    
	//Boundaries of the level
	line top	( w, vector(   0,  0 ), vector( 127,  0 ) );
	line right	( w, vector( 127,  0 ), vector( 127, 63 ) );
	line bottom	( w, vector(   0, 63 ), vector( 127, 63 ) );
	line left	( w, vector(   0,  0 ), vector(   0, 63 ) );
    bool b = true;
    
	while(b){
		w.clear();
        
        //update
        vector tmp1;
        vector tmp2;
        tmp1 = heli->boxmin + heli->position;
        tmp2 = heli->boxmax + heli->position;
       // if(col->AABB(tmp1, tmp2, vector(100, 64), vector(104, 0)))
        //{
         //   b = false;
       // }
        
        heli->Update();

        //draw
        heli->Draw(w);
        
        wait_ms( 100 );
	}
    //Delete heli because of heap memory
    delete heli;
    heli = nullptr;
    w.clear();
}
*/