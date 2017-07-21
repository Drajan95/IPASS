#ifndef HELICOPTER_H
#define HELICOPTER_H

#include "GameObject.h"

/**
 * @class Helicopter
 * @date 20/07/17
 * @file Helicopter.h
 * @brief Helicopter game object
 */
class Helicopter : public GameObject{
public:
	/**
	 * @brief Constructs the helicopter
	 */
	void Initialize();
	
	/**
	 * @brief Is called every game-update cycle
	 */
    void Update();
	
	/**
	 * @brief Is called when the game requires the helicopter to be drawn
	 * @param w Window to draw on
	 * @return  Returns true when draw was successful
	 */
	bool Draw(window& w);
	
	int rotorbladeOffset;
	bool shrink = true;
};

#endif