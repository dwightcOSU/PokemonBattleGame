/**************************************************************************************
* 		 Author:	Chris Dwight
*  Date Created:	06/04/14
* Last Modified:	06/06/14	
* 	   Filename:	pokemontrainer.h
*
* 		  Class:	Oregon State University: CS 165
* 	 Assignment:	Final Project
* 	   Due Date:	June 8, 2014
**************************************************************************************/
#ifndef POKEMONTRAINER_H
#define POKEMONTRAINER_H

#include "pokemon.h"

using namespace PocketMonsters;

class PokemonTrainer
{
public:
	PokemonTrainer();							// default constructor
	PokemonTrainer(std::string newName, std::vector<Pokemon> newPokemonRoster); // Creates a new Pokemon Trainer with name and roster of Pokemon
	~PokemonTrainer();							// destructor
	void setName(std::string newName);			// sets the name of the Pokemon trainer
	std::string getName();						// returns the name of the Pokemon trainer
	int getNumPokemon();						// returns the number of Pokemon the trainer has
	Pokemon getPokemon(int i);					// finds the Pokemon by provided or randomly generated int							/*** PROJECT REQUIREMENT #14 ***/
	Pokemon getPokemon(std::string name);		// finds the Pokemon by name and returns the corresponding Pokemon object			/*** PROJECT REQUIREMENT #14 ***/
	bool isInRoster(std::string name);			// finds if a Pokemon is in the roster (searches by name)
	void removePokemon(std::string name);		// removes a Pokemon from the roster

private:
	std::string name;							// the name of the Pokemon trainer
	int numPokemon;								// the number of Pokemon the trainer has
	std::vector<Pokemon> pokemonRoster;			// the roster of Pokemon the trainer has
};

#endif
