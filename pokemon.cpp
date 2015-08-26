/**************************************************************************************
* 		 Author:	Chris Dwight
*  Date Created:	06/04/14
* Last Modified:	06/06/14
* 	   Filename:	pokemon.cpp
*
* 		  Class:	Oregon State University: CS 165
* 	 Assignment:	Final Project
* 	   Due Date:	June 8, 2014
**************************************************************************************/
#include <iostream>
//#include <string>
#include "pokemon.h"

namespace PocketMonsters																												/*** PROJECT REQUIREMENT #18 ***/
{
	Pokemon::Pokemon()
	{
		// intentionally left empty
	}

	// Creates a new Pokemon with full info and stats
	Pokemon::Pokemon(int newPokedexNumber, std::string newName, std::string newType, int newHP,
						std::string newMoveName1, std::string newMoveType1, int newPower1, int newPP1, 
						std::string newMoveName2, std::string newMoveType2, int newPower2, int newPP2, 
						std::string newMoveName3, std::string newMoveType3, int newPower3, int newPP3, 
						std::string newMoveName4, std::string newMoveType4, int newPower4, int newPP4)
	{
		pokedexNumber = newPokedexNumber;
		name = newName;
		type = newType;
		hpRemaining = newHP;
		hpTotal = newHP;

		move1.name = newMoveName1;
		move1.type = newMoveType1;
		move1.power = newPower1;
		move1.ppRemaining = newPP1;
		move1.ppTotal = newPP1;
		
		move2.name = newMoveName2;
		move2.type = newMoveType2;
		move2.power = newPower2;
		move2.ppRemaining = newPP2;
		move2.ppTotal = newPP2;

		move3.name = newMoveName3;
		move3.type = newMoveType3;
		move3.power = newPower3;
		move3.ppRemaining = newPP3;
		move3.ppTotal = newPP3;

		move4.name = newMoveName4;
		move4.type = newMoveType4;
		move4.power = newPower4;
		move4.ppRemaining = newPP4;
		move4.ppTotal = newPP4;
	}
	
	// Copy Constructor
/* 	Pokemon::Pokemon(const Pokemon &creature)
	{
		// intentionally left empty
	}
 */
	// Destructor
	Pokemon::~Pokemon()
	{
		// intentionally left empty
	}
	
	// Returns the Pokedex Number of the Pokemon
	int Pokemon::getPokedexNumber()
	{
		return pokedexNumber;
	}

	// Returns the name of the Pokemon
	std::string Pokemon::getName()
	{
		return name;
	}

	// Returns the type of the Pokemon
	std::string Pokemon::getType()
	{
		return type;
	}

	// Sets the current number of HP (Hit Points) a Pokemon has
	void Pokemon::setHP(int newHP)
	{
		hpRemaining = newHP;
	}

	// Returns the current number of HP (Hit Points) a Pokemon has
	int Pokemon::getHPRemaining()
	{
		return hpRemaining;
	}

	// Returns the total HP (Hit Points) a Pokemon can have
	int Pokemon::getHPTotal()
	{
		return hpTotal;
	}

	// Returns the specified move
	MoveSet Pokemon::getMove(int move)
	{
		if (move == 1)
		{
			return move1;
		}
		else if (move == 2)
		{
			return move2;
		}
		else if (move == 3)
		{
			return move3;
		}
		else
		{
			return move4;
		}
	}

	// Decreases the PP (Power Points) a move has
	// A move's PP is decreased by one every time the move is used
	void Pokemon::usePP(int move)
	{
		if (move == 1)
		{
			move1.ppRemaining--;
		}
		else if (move == 2)
		{
			move2.ppRemaining--;
		}
		else if (move == 3)
		{
			move3.ppRemaining--;
		}
		else
		{
			move4.ppRemaining--;
		}
	}
}
