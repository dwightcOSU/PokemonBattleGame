/**************************************************************************************
* 		 Author:	Chris Dwight
*  Date Created:	06/04/14
* Last Modified:	06/06/14
* 	   Filename:	pokemontrainer.cpp
*
* 		  Class:	Oregon State University: CS 165
* 	 Assignment:	Final Project
* 	   Due Date:	June 8, 2014
**************************************************************************************/
#include <string>				// std::string
#include <vector>				// vector
#include "pokemontrainer.h"

// Default Constructor
PokemonTrainer::PokemonTrainer() : name("Red"), numPokemon(0)
{
	// intentionally left empty
}

// Creates a new Pokemon Trainer with name and roster of Pokemon
PokemonTrainer::PokemonTrainer(std::string newName, std::vector<Pokemon> newPokemonRoster)
{
	name = newName;
	numPokemon = newPokemonRoster.size();
	pokemonRoster = newPokemonRoster;
}

// Destructor
PokemonTrainer::~PokemonTrainer()
{
	// intentionally left empty
}


// Sets the name of the Pokemon trainer
void PokemonTrainer::setName(std::string newName)
{
	name = newName;
}

// Returns the name of the Pokemon trainer
std::string PokemonTrainer::getName()
{
	return name;
}

// Returns the number of Pokemon the trainer has
int PokemonTrainer::getNumPokemon()
{
	return pokemonRoster.size();
}

// Finds the Pokemon by provided or randomly generated int
Pokemon PokemonTrainer::getPokemon(int i)																							/*** PROJECT REQUIREMENT #14 ***/
{
	return pokemonRoster[i];
}

// Finds the Pokemon by name and returns the corresponding Pokemon object
Pokemon PokemonTrainer::getPokemon(std::string name)																				/*** PROJECT REQUIREMENT #14 ***/
{
	for (int i = 0; i < getNumPokemon(); i++)
	{
		if (pokemonRoster[i].getName() == name)
		{
			return pokemonRoster[i];
		}
	}
}

// Finds if a Pokemon is in the roster (searches by name)
bool PokemonTrainer::isInRoster(std::string name)
{
	for (int i = 0; i < getNumPokemon(); i++)
	{
		if (pokemonRoster[i].getName() == name)
		{
			return true;
		}
	}
	return false;
}

// Removes a Pokemon from the roster
void PokemonTrainer::removePokemon(std::string name)
{
	for (int i = 0; i < getNumPokemon(); i++)
	{
		if (pokemonRoster[i].getName() == name)
		{
			pokemonRoster.erase(pokemonRoster.begin()+i);
		}
	}
}
