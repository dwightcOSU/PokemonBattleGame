/**************************************************************************************
* 		 Author:	Chris Dwight
*  Date Created:	06/06/14
* Last Modified:	06/06/14
* 	   Filename:	legendary.cpp
*
* 		  Class:	Oregon State University: CS 165
* 	 Assignment:	Final Project
* 	   Due Date:	June 8, 2014
**************************************************************************************/
#include <iostream>
//#include <string>
#include "legendary.h"

namespace PocketMonsters																												/*** PROJECT REQUIREMENT #18 ***/
{
	Legendary::Legendary() : Pokemon()
	{
		// intentionally left empty
	}

	// Creates a new Pokemon with full info and stats
	Legendary::Legendary(int newPokedexNumber, std::string newName, std::string newType, int newHP,
							std::string newMoveName1, std::string newMoveType1, int newPower1, int newPP1, 
							std::string newMoveName2, std::string newMoveType2, int newPower2, int newPP2, 
							std::string newMoveName3, std::string newMoveType3, int newPower3, int newPP3, 
							std::string newMoveName4, std::string newMoveType4, int newPower4, int newPP4)
						: Pokemon(newPokedexNumber, newName, newType, newHP,
									newMoveName1, newMoveType1, newPower1, newPP1, 
									newMoveName2, newMoveType2, newPower2, newPP2, 
									newMoveName3, newMoveType3, newPower3, newPP3, 
									newMoveName4, newMoveType4, newPower4, newPP4)
	{
		// intentionally left empty
	}

	// Destructor
/* 	Legendary::~Legendary()
	{
		// intentionally left empty
	} */

	// Sets the current number of HP (Hit Points) a Legendary Pokemon has
	void Legendary::setHP(int newHP)
	{
		double temp = (double)newHP*1.25;
		hpRemaining = (int)temp;							// Legendary regenerates up to 25% HP after enemy turn;
	}
}
