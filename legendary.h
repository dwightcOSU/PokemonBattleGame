/**************************************************************************************
* 		 Author:	Chris Dwight
*  Date Created:	06/06/14
* Last Modified:	06/06/14
* 	   Filename:	legendary.h
*
* 		  Class:	Oregon State University: CS 165
* 	 Assignment:	Final Project
* 	   Due Date:	June 8, 2014
**************************************************************************************/
#ifndef LEGENDARY_H
#define LEGENDARY_H

#include "pokemon.h"

namespace PocketMonsters																												/*** PROJECT REQUIREMENT #25 ***/
{
	class Legendary : public Pokemon
	{
	public:
		Legendary();					// default constructor
		Legendary(int newPokedexNumber, std::string newName, std::string newType, int newHP,
				std::string newMoveName1, std::string newMoveType1, int newPower1, int newPP1, 
				std::string newMoveName2, std::string newMoveType2, int newPower2, int newPP2, 
				std::string newMoveName3, std::string newMoveType3, int newPower3, int newPP3, 
				std::string newMoveName4, std::string newMoveType4, int newPower4, int newPP4);
//		~Legendary();					// destructor
		void setHP(int newHP);			// sets the current number of HP (Hit Points) a Pokemon has
	};
}

#endif
