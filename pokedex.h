/**************************************************************************************
* 		 Author:	Chris Dwight
*  Date Created:	06/04/14
* Last Modified:	06/06/14
* 	   Filename:	pokedex.h
*
* 		  Class:	Oregon State University: CS 165
* 	 Assignment:	Final Project
* 	   Due Date:	June 8, 2014
**************************************************************************************/
#ifndef POKEDEX_H
#define POKEDEX_H

#include "legendary.h"
#include "pokemon.h"

using namespace PocketMonsters;

class Pokedex
{
public:
	Pokedex();								// default constructor, initializes the Pokedex
	~Pokedex();								// destructor
	void printFullPokedexNames();			// prints the names of every Pokemon in the Pokedex
	void printFullPokedexInfo();			// prints the full info of every Pokemon in the Pokedex
	int getSize();							// returns the number of Pokemon in the Pokedex
	Pokemon findPokemon(int number);		// Returns the Pokemon listed at the specified Pokedex number
	Pokemon getPokemon(int number);			// Returns the Pokemon based on number in Pokedex vector
	bool isInPokedex(int number);			// Finds if there is a Pokemon listed for a specified Pokedex number

private:
	void bootUp();							// initialization function that creates the Pokedex vector
	std::vector<Pokemon> pokedex;			// the Pokedex vector
};

#endif
