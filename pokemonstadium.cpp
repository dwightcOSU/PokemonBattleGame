/**************************************************************************************
* 		 Author:	Chris Dwight
*  Date Created:	06/04/14
* Last Modified:	06/06/14
* 	   Filename:	pokemonstadium.cpp
*
* 		  Class:	Oregon State University: CS 165
* 	 Assignment:	Final Project
* 	   Due Date:	June 8, 2014
*
* Overview:
*	A text based version of Pokemon Stadium. The user can choose up to six Pokemon from
*	a limited selection of the original 151 Pokemon and take them into battle against
*	a rival CPU opponent.
**************************************************************************************/
#include <cstdlib>				// exit
#include <fstream>				// File IO
#include <iostream>				// cout, cin, endl, etc.
#include <string.h>
#include <stdlib.h>				// rand, srand
#include <time.h>				// time
#include <vector>				// vector
#include "battlearena.h"
#include "bonus.h"
#include "pokedex.h"
#include "pokemon.h"
#include "pokemontrainer.h"

using namespace PocketMonsters;

/*** FUNCTION DELCARATIONS ***/
void importTrainerProfile(Pokedex pokedex, std::string &name, int &numPokemon, int &selection, std::vector<Pokemon> &pokemonRoster);	// imports trainer profile from file
void createNewProfile(Pokedex pokedex, std::string &name, int &numPokemon, int &selection, std::vector<Pokemon> &pokemonRoster);		// creates new trainer profile
void createRivalProfile(Pokedex pokedex, std::string &rivalName, const int &numPokemon, int &numRivalPokemon, std::vector<Pokemon> &rivalRoster);	// creates CPU trainer profile
void randomlyPickPokemon(Pokedex pokedex, const int &numPokemon, std::vector<Pokemon> &pokemonRoster);	// randomly selects a number of Pokemon

/*** MAIN FUNCTION ***/
int main(int argc, char *argv[])
{
	/*** VARIABLES ***/
	Pokedex pokedex;							// Pokedex object																/*** PROJECT REQUIREMENT #24 ***/	
	PokemonTrainer Red;							// Trainer object representing the user
	PokemonTrainer Blue;						// Trainer object representing the CPU
	BattleArena battlearena;					// battle arena object where battle functions are handled
	Bonus bonus;								// bonus object where bonus functions can be found
	
	char decision;								// decision input by user
	char secretWord[] = "MISSINGNO.";			// secret keyword to access bonus menu
	
	std::string name;							// name of Pokemon Trainer														/*** PROJECT REQUIREMENT #15 ***/	
	int numPokemon;								// number of Pokemon to be brought into battle
	int selection;								// the current Pokemon selected
	std::vector<Pokemon> pokemonRoster;			// the vector of all Pokemon selected											/*** PROJECT REQUIREMENT #28 ***/
	
	std::string rivalName;						// name of rival Pokemon Trainer
	int numRivalPokemon;						// number of Pokemon rival will bring into battle
	std::vector<Pokemon> rivalRoster;			// the vector of your opponent's Pokemon

	/*** SECRET BONUS FEATURES! ***/
	// Additional bonus features can only be accessed by running program
	// with special keyword at command prompt!
	if (argc > 1 && strcmp(argv[1], secretWord) == 0)																			/*** PROJECT REQUIREMENT #19 ***/
	{
		bonus.mainMenu();
	}

	/*** INTRODUCTION ***/
	std::cout << "\n===========================" << std::endl;																	/*** PROJECT REQUIREMENT #01 ***/
	std::cout << "WELCOME TO POKEMON STADIUM!" << std::endl;
	std::cout << "===========================" << std::endl;
	
	/*** IMPORT OR CREATE NEW TRAINER PROFILE ***/
	std::cout << "\nBefore the battle starts, we need some registration info from you." << std::endl;
  	std::cout << "Would you like to import [I] a trainer profile or create a new [N] one? [I / N]" << std::endl;
	std::cin >> decision;																										/*** PROJECT REQUIREMENT #02 ***/
	decision = toupper(decision);
	while (std::cin.fail() || (decision != 'I' && decision != 'N'))																/*** PROJECT REQUIREMENTS #06, #09 ***/
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Your input was invalid.\nPlease enter either 'I' to import a profile or 'N' to create a new one" << std::endl;
		std::cin >> decision;
		decision = toupper(decision);
	}
	if (decision == 'I')																										/*** PROJECT REQUIREMENT #04 ***/
	{
		importTrainerProfile(pokedex, name, numPokemon, selection, pokemonRoster);		// import a Trainer Profile
	}
	else
	{
		createNewProfile(pokedex, name, numPokemon, selection, pokemonRoster);			// create a new Trainer Profile
	}
	
	
	Red = PokemonTrainer(name, pokemonRoster);		// create the user's trainer profile with name and Pokemon roster
	createRivalProfile(pokedex, rivalName, numPokemon, numRivalPokemon, rivalRoster);
	Blue = PokemonTrainer(rivalName, rivalRoster);	// create the rival's trainer profile with name and Pokemon roster

	
	/*** BATTLE! ***/
	std::cout << "\nNow you're ready to battle!" << std::endl;
	battlearena = BattleArena(Blue, Red);
	battlearena.chooseBluePokemon();			// select rival's starting Pokemon
	battlearena.chooseRedPokemon();				// select your starting Pokemon
	while (battlearena.continueBattle())		// battle continues while both sides still have Pokemon
	{
		std::cout << "\n\n" << std::endl;
		
		std::cout << battlearena.getRedPokemon().getName() << " [HP: " << battlearena.getRedPokemon().getHPRemaining() << "/" << battlearena.getRedPokemon().getHPTotal() << "]"
				  << " vs. " 
				  << battlearena.getBluePokemon().getName() << " [HP: " << battlearena.getBluePokemon().getHPRemaining() << "/" << battlearena.getBluePokemon().getHPTotal() << "]" 
				  << std::endl;	// prints out current status of both Pokemon in the battle arena
		
		/*** PLAYER'S MOVE ***/
		std::cout << "What would you like to do? [A]ttack or [S]witch Pokemon?" << std::endl;
		std::cin >> decision;
		decision = toupper(decision);
		while (std::cin.fail() || (decision != 'A' && decision != 'S'))
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "Your selection was invalid. Please try again." << std::endl;
			std::cin >> decision;
			decision = toupper(decision);
		}
		
		if (decision == 'A')
		{
			battlearena.redAttack();		// user chooses to attack rival's Pokemon
		}
		else
		{
			battlearena.chooseRedPokemon();	// user chooses to switch out their Pokemon
		}
		
		std::cout << "\n\n" << std::endl;
		
		/*** RIVAL'S ATTACK ***/
		if (battlearena.getBluePokemonRemaining() > 0)	// if rival still has Pokemon after user's move...
		{
			std::cout << battlearena.getRedPokemon().getName() << " [HP: " << battlearena.getRedPokemon().getHPRemaining() << "/" << battlearena.getRedPokemon().getHPTotal() << "]"
					  << " vs. " 
					  << battlearena.getBluePokemon().getName() << " [HP: " << battlearena.getBluePokemon().getHPRemaining() << "/" << battlearena.getBluePokemon().getHPTotal() << "]" 
					  << std::endl;		// prints out current status of both Pokemon in the battle arena
			battlearena.blueAttack();		// rival selects attack
		}
	}
	
	/*** END OF BATTLE ***/
	if (battlearena.getBluePokemonRemaining() == 0)		// if all of rival's Pokemon have been defeated...
	{
		std::cout << name << " defeated " << rivalName << "!" << std::endl;		// user wins!
		std::cout << name << " got $" << rand() % 1000 << " for winning!\n\n" << std::endl;		// and wins imaginary money!
	}
	else		// if all of user's Pokemon have been defeated
	{
		std::cout << "\n\n" << rivalName << " defeated " << name << "!" << std::endl;	// CPU wins!
		std::cout << rivalName << " got $" << rand() % 1000 << " for winning!\n\n" << std::endl;	// and wins imaginary money!
	}
}

/**************************************************************************************
* 		 Function: importTrainerProfile
* 	  Description: Creates a new Trainer Profile based on an imported text file
**************************************************************************************/
void importTrainerProfile(Pokedex pokedex, std::string &name, int &numPokemon, int &selection, std::vector<Pokemon> &pokemonRoster)	/*** PROJECT REQUIREMENTS #5, #10, #11, #13 ***/
{
	std::ifstream inStream;																											/*** PROJECT REQUIREMENT #31 ***/
	std::string fileName;
	
	std::cout << "\nWhat is the name of the file to be imported?" << std::endl;
	std::cin >> fileName;
	inStream.open(fileName.c_str());
	while (inStream.fail())
	{
		std::cout << "\nERROR: Trainer Profile File Not Found!" << std::endl;
		std::cout << "Please enter the file name again: " << std::endl;
		std::cin >> fileName;
		inStream.open(fileName.c_str());
	}
	inStream >> name >> numPokemon;
	if (numPokemon > 6)
	{
		std::cout << "That is too many Pokemon. You will be limited to 6." << std::endl;
		numPokemon = 6;
	}
	else if (numPokemon < 1)
	{
		std::cout << "You need some Pokemon to battle. You will be given 3." << std::endl;
		numPokemon = 3;
	}
	if (inStream.eof())
	{
		std::cout << "You did not choose any Pokemon. As a result " << numPokemon << " will be chosen for you." << std::endl;
		randomlyPickPokemon(pokedex, numPokemon, pokemonRoster);
	}

	while (! inStream.eof())
	{
		inStream >> selection;
		pokemonRoster.push_back(pokedex.findPokemon(selection));
	}
	
	inStream.close();
}

/**************************************************************************************
* 		 Function: createNewProfile
* 	  Description: Creates a new Trainer Profile based on user input
**************************************************************************************/
void createNewProfile(Pokedex pokedex, std::string &name, int &numPokemon, int &selection, std::vector<Pokemon> &pokemonRoster)
{	
	char choice;
	
	std::cout << "\nWhat is your first name?" << std::endl;
	std::cin >> name;
	
	std::cout << "\nHow many Pokemon will you bring into battle? (max 6)" << std::endl;
	std::cin >> numPokemon;
	while (std::cin.fail() || numPokemon > 6 || numPokemon < 1)
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "That was not a valid choice. Please enter a number between 1 and 6:" << std::endl;
		std::cin >> numPokemon;
	}
	
	std::cout << "\nWould you like to pick [P] your Pokemon or have " << numPokemon << " randomly chosen [R] for you? [P / R]" << std::endl;
	std::cin >> choice;
	choice = toupper(choice);
	
	while (std::cin.fail() || (choice != 'P' && choice != 'R'))
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "That was not a valid choice. Please enter either 'P' to pick your Pokemon or 'R' to have them randomly chosen for you." << std::endl;
		std::cin >> choice;
		choice = toupper(choice);
	}
	
	if (choice == 'P')	// user wants to select their own Pokemon roster
	{
		std::cout << "\nChoose from the following Pokemon:" << std::endl;
		pokedex.printFullPokedexNames();
		
		for (int i = 0; i < numPokemon; i++)
		{
			std::cout << "\nEnter the Pokedex number of your desired Pokemon" << std::endl;
			std::cin >> selection;
			while (std::cin.fail() || pokedex.isInPokedex(selection) == false)
			{
				std::cout << "The Pokedex number you entered was not found in the Pokedex." << std::endl;
				std::cout << "Perhaps you need to wander around in more tall grass to expand your Pokedex." << std::endl;
				std::cout << "Until then, please enter a valid Pokedex number!" << std::endl;
				std::cin >> selection;
			}
			pokemonRoster.push_back(pokedex.findPokemon(selection));
		}
	}
	else	// user wants Pokemon to be randomly selected for their roster
	{
		randomlyPickPokemon(pokedex, numPokemon, pokemonRoster);
	}
}

/**************************************************************************************
* 		 Function: createRivalProfile
* 	  Description: Creates a Trainer Profile for your rival
**************************************************************************************/
void createRivalProfile(Pokedex pokedex, std::string &rivalName, const int &numPokemon, int &numRivalPokemon, std::vector<Pokemon> &rivalRoster)
{
	rivalName = "Gary";							// rival's name will be Gary (Oak), grandson of the great Professor Oak
	numRivalPokemon = numPokemon;				// rival will have same number of Pokemon as player
	randomlyPickPokemon(pokedex, numRivalPokemon, rivalRoster);
}

/**************************************************************************************
* 		 Function: randomlyPickPokemon
* 	  Description: Randomly selects the specified number of Pokemon
**************************************************************************************/
void randomlyPickPokemon(Pokedex pokedex, const int &numPokemon, std::vector<Pokemon> &pokemonRoster)
{
	srand (time(NULL));
	
	for (int i = 0; i < numPokemon; i++)
	{
		int selection = rand() % pokedex.getSize();																					/*** PROJECT REQUIREMENT #07 ***/
		pokemonRoster.push_back(pokedex.getPokemon(selection));
	}
}
