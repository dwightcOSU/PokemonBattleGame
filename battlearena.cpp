/**************************************************************************************
* 		 Author:	Chris Dwight
*  Date Created:	06/05/14
* Last Modified:	06/06/14
* 	   Filename:	battlearena.cpp
*
* 		  Class:	Oregon State University: CS 165
* 	 Assignment:	Final Project
* 	   Due Date:	June 8, 2014
**************************************************************************************/
#include <cstdlib>				// exit
#include <iostream>				// cin, cout, endl, etc.
#include <stdlib.h>				// rand, srand
#include <time.h>				// time
#include <vector>				// vector

#include "battlearena.h"

// Default Constructor
BattleArena::BattleArena()
{
	// intentionally left empty
}

// Destructor
BattleArena::~BattleArena()
{
	// intentionally left empty
}

// Creates a new Battle Arena with two Pokemon Trainers
BattleArena::BattleArena(PokemonTrainer newBlue, PokemonTrainer newRed)
{
	blue = newBlue;		// Rival (CPU) Pokemon Trainer
	red = newRed;		// User Pokemon Trainer
}

// Randomly chooses which Pokemon your opponent will battle with
void BattleArena::chooseBluePokemon()
{
	srand (time(NULL));
	currentBluePokemon = blue.getPokemon(rand() % blue.getNumPokemon());	// a Pokemon is randomly selected from the rival's roster
	std::cout << "\n" << blue.getName() << " has sent out " << currentBluePokemon.getName() << "." << std::endl;
}

// Select which Pokemon you would like to battle with
void BattleArena::chooseRedPokemon()
{
	std::string selection;
	std::cout << "Which Pokemon would you like to send out?" << std::endl;
	for (int i = 0; i < red.getNumPokemon(); i++)							// prints out list of available Pokemon
	{
		std::cout << "\t" << red.getPokemon(i).getName() << std::endl;
	}
	
	std::cout << "Enter the name of the Pokemon: " << std::endl;
	std::cin >> selection;
	while (std::cin.fail() || red.isInRoster(selection) == false)
	{
		std::cout << "The Pokemon you selected was not found in your roster." << std::endl;
		std::cout << "Please enter the name of one of your Pokemon: " << std::endl;
		std::cin >> selection;
	}
	currentRedPokemon = red.getPokemon(selection);
}

// Returns the Pokemon that is currently in battle for your rival
Pokemon BattleArena::getBluePokemon()
{
	return currentBluePokemon;
}

// Returns the Pokemon that you are currently using in battle
Pokemon BattleArena::getRedPokemon()
{
	return currentRedPokemon;
}

// Returns the number of Pokemon remaining on your rival's roster
int BattleArena::getBluePokemonRemaining()
{
	return blue.getNumPokemon();
}

// Returns the number of Pokemon remaining on your roster
int BattleArena::getRedPokemonRemaining()
{
	return red.getNumPokemon();
}

// Selects the attack your rival's Pokemon will perform
void BattleArena::blueAttack()
{
	srand (time(NULL));
	int moveChoice = rand() % 4 + 1;	// randomly selects a move by generating a number 1-4
	int damage;							// the damage caused by the move
	
	if (currentBluePokemon.getMove(moveChoice).ppRemaining == 0)	// if the move has no PP left, it cannot be used...
	{
		blueAttack();
	}
	
	std::cout << "Enemy " << currentBluePokemon.getName() << " attacked " << currentRedPokemon.getName() << " using " << currentBluePokemon.getMove(moveChoice).name << "!" << std::endl;
	currentBluePokemon.usePP(moveChoice);		// decreases the PP of the move used

	damage = currentBluePokemon.getMove(moveChoice).power;		// damage caused is equal to the power of the move used
	if (damage >= 100)		// if damage was 100+, then...
	{
		std::cout << "Critical hit!" << std::endl;		// ...the move was a critical hit!
	}
	if (damage == 0)		// if damage is 0, then...
	{
		std::cout << "No effect!" << std::endl;			//...the move had no effect (and your rival is probably using Magikarp)
	}
	std::cout << "Enemy " << currentBluePokemon.getName() << " did " << damage << " points of damage to " << currentRedPokemon.getName() << "!" << std::endl;
	
	/* UPDATE STATS */
	currentRedPokemon.setHP(currentRedPokemon.getHPRemaining() - damage);		// decreases the user Pokemon's HP by the damage caused
	if (currentRedPokemon.getHPRemaining() <= 0)								// if the user Pokemon's HP is now 0 or less...
	{
		std::cout << currentRedPokemon.getName() << " fainted!" << std::endl;	// ...the Pokemon has fainted...
		red.removePokemon(currentRedPokemon.getName());							// ...and is removed from the game
		if (red.getNumPokemon() > 0)		// if the user's team still has Pokemon...
		{
			chooseRedPokemon();				// ...another Pokemon is chosen
		}
	}
}

// Selects the attack your Pokemon will perform
void BattleArena::redAttack()
{
	int moveChoice;		// the user's move selection
	int damage;			// the damage caused by the move
	
	std::cout << currentRedPokemon.getName() << " is going to attack enemy " << currentBluePokemon.getName() << "!" << std::endl;
	
	/* SELECT A MOVE */
	std::cout << "What move should " << currentRedPokemon.getName() << " use?" << std::endl;
	for (int i = 0; i < 4; i++)		// prints out the four moves and remaining PP points of each move
	{
		std::cout << "\t" << i+1 << ": " << currentRedPokemon.getMove(i+1).name << " [" << currentRedPokemon.getMove(i+1).ppRemaining << "/" << currentRedPokemon.getMove(i+1).ppTotal << "]" << std::endl; 
	}
	std::cout << "Please enter the number of the move you would like to use: ";
	std::cin >> moveChoice;
	while (std::cin.fail() || moveChoice > 4 || moveChoice < 1 || currentRedPokemon.getMove(moveChoice).ppRemaining == 0)	// while not an int or valid move selection or move has 0 PP remaining
	{
		if (currentRedPokemon.getMove(moveChoice).ppRemaining == 0)		// if move has 0 PP remaining it cannot be used anymore
		{
			std::cout << "There are not enough Power Points (PP) remaining to perform that move!" << std::endl;
		}
		else
		{
			std::cout << "That was not a valid move choice." << std::endl;
		}
		std::cout << "Please select a different move: ";
		std::cin >> moveChoice;
	}
	
	/* ATTACK */
	std::cout << currentRedPokemon.getName() << " attacked enemy " << currentBluePokemon.getName() << " using " << currentRedPokemon.getMove(moveChoice).name << "!" << std::endl;
	currentRedPokemon.usePP(moveChoice);		// decreases the PP of the move used

	damage = currentRedPokemon.getMove(moveChoice).power;		// damage caused is equal to the power of the move used
	if (damage >= 100)		// if damage was 100+, then...
	{
		std::cout << "Critical hit!" << std::endl;		// ...the move was a critical hit!
	}
	if (damage == 0)		// if damage is 0, then...
	{
		std::cout << "No effect!" << std::endl;			//...the move had no effect (and you're probably using Magikarp)
	}
	std::cout << currentRedPokemon.getName() << " did " << damage << " points of damage to enemy " << currentBluePokemon.getName() << "!" << std::endl;
	
	/* UPDATE STATS */
	currentBluePokemon.setHP(currentBluePokemon.getHPRemaining() - damage);		// decreases the rival Pokemon's HP by the damage caused
	if (currentBluePokemon.getHPRemaining() <= 0)								// if the rival Pokemon's HP is now 0 or less...
	{
		std::cout << currentBluePokemon.getName() << " fainted!" << std::endl;	// ...the Pokemon has fainted...
		blue.removePokemon(currentBluePokemon.getName());						// ...and is removed from the game
		if (blue.getNumPokemon() > 0)		// if the rival's team still has Pokemon...
		{
			chooseBluePokemon();			// ...another Pokemon is chosen
		}
	}
}

// Checks to make sure both sides still have Pokemon to battle with
// Returns true if battle should continue and returns false if battle is over
bool BattleArena::continueBattle()
{
	if (blue.getNumPokemon() > 0 && red.getNumPokemon() > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
