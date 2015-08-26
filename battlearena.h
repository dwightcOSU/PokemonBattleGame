/**************************************************************************************
* 		 Author:	Chris Dwight
*  Date Created:	06/05/14
* Last Modified:	06/06/14
* 	   Filename:	battlearena.h
*
* 		  Class:	Oregon State University: CS 165
* 	 Assignment:	Final Project
* 	   Due Date:	June 8, 2014
**************************************************************************************/
#ifndef BATTLEARENA_H
#define BATTLEARENA_H

#include "legendary.h"
#include "pokemon.h"
#include "pokedex.h"
#include "pokemontrainer.h"

using namespace PocketMonsters;

class BattleArena
{
public:
	BattleArena();					// default constructor
	BattleArena(PokemonTrainer Blue, PokemonTrainer Red); // creates a new Battle Arena with two Pokemon Trainers
	~BattleArena();					// destuctor
	void chooseBluePokemon();		// randomly chooses which Pokemon the CPU will battle with
	void chooseRedPokemon();		// selects which Pokemon the user would like to battle with
	Pokemon getBluePokemon();		// returns the Pokemon that the CPU is currently using in battle
	Pokemon getRedPokemon();		// returns the Pokemon that the user is currently using in battle
	int getBluePokemonRemaining();	// returns the number of Pokemon remaining on the rival's roster
	int getRedPokemonRemaining();	// returns the number of Pokemon remaining on the user's roster
	void blueAttack();				// selects the attack the rival's Pokemon will perform
	void redAttack();				// selects the attack the user's Pokemon will perform
	bool continueBattle();			// checks to make sure both sides still have Pokemon to battle with

private:
	PokemonTrainer blue;			// rival (CPU) Pokemon Trainer
	PokemonTrainer red;				// user Pokemon Trainer
	Pokemon currentBluePokemon;		// the Pokemon the CPU is currently using
	Pokemon currentRedPokemon;		// the Pokemon the user is currently using
};

#endif
