#include "Helicopter.h"

//Boundaries helicopter
void Helicopter::Initialize(){
	boxmin 		= vector(-20, -6);
	boxmax 		= vector( 11,  8);
	position 	= vector( 32, 25);
}

void Helicopter::Update(){
	position += vector(3,0);
	
	if(shrink){
		rotorbladeOffset += 2;
		if(rotorbladeOffset > 5){
			shrink = false;
		}
	}
	else{
		rotorbladeOffset -= 2;
		if(rotorbladeOffset < 0){
			shrink = true;
		}
	}
}

//Drawing of the helicopter
bool Helicopter::Draw(window& w){
	
	line rotor			( w, vector( -10 + rotorbladeOffset,	-6 ) + position,	vector( 11 - rotorbladeOffset, -6 ) + position );
	line tailT			( w, vector( -17,	-2 ) + position,	vector( -4, -3 ) + position );
	line tailB			( w, vector( -17,	-2 ) + position,	vector( -5,  1 ) + position );
	ball tailRotor		( w, vector( -19,	-2 ) + position, 2,	vector(  0,  0 ) + position );
	line landingGearL	( w, vector(   2,	 5 ) + position,	vector(  2,  8 ) + position);
	line landingGearR	( w, vector(  -2,	 5 ) + position,	vector( -2,  8 ) + position);
	line landingGearB	( w, vector(  -5,	 7 ) + position,	vector(  6,  7 ) + position );
	line windowV		( w, vector(   2,	-5 ) + position,	vector(  2, -1 ) + position);
	line windowH		( w, vector(   3,	-1 ) + position,	vector(  6, -1 ) + position);
	ball frame			( w, vector(   0,	 0 ) + position, 5,	vector(  0,  0 ) );
	
	drawable * objects[] = {	&rotor, &tailT, &tailB, &tailRotor, 
								&landingGearL, &landingGearR, &landingGearB,
								&windowV, &windowH, &frame };
	for(auto& p : objects){
		p->draw();
	}
	return true;
}