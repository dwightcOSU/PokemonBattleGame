/**************************************************************************************
* 		 Author:	Chris Dwight
*  Date Created:	06/04/14
* Last Modified:	06/06/14
* 	   Filename:	pokedex.cpp
*
* 		  Class:	Oregon State University: CS 165
* 	 Assignment:	Final Project
* 	   Due Date:	June 8, 2014
**************************************************************************************/
#include <iomanip>			// used to print out Pokedex numbers with leading 0's
#include <iostream>			// cin, cout, endl, etc.
#include <vector>			// vector
#include "pokedex.h"

// Default Constructor
Pokedex::Pokedex()
{
	bootUp();
}

// Destructor
Pokedex::~Pokedex()
{
	// intentionally left empty
}

// Prints the names only of each Pokemon in the Pokedex
void Pokedex::printFullPokedexNames()
{
	for (unsigned int i = 0; i < pokedex.size(); i++)
	{
		std::cout << "\t" << std::setw(3) << std::setfill('0') << pokedex[i].getPokedexNumber() << ": " << pokedex[i].getName() << std::endl;
	}
}

// Prints the full information of the Pokedex
// This includes:
//		- Pokedex number
//		- Name and Type
//		- Each of their four moves and move type
void Pokedex::printFullPokedexInfo()
{
	for (unsigned int i = 0; i < pokedex.size(); i++)
	{
		std::cout << pokedex[i].getName() << " (" <<  pokedex[i].getType() << ")" << std::endl;
		std::cout << "\t\tMove1: " << pokedex[i].getMove(1).name << " (" << pokedex[i].getMove(1).type << ") "
			  << "\n\t\tMove2: " << pokedex[i].getMove(2).name << " (" << pokedex[i].getMove(2).type << ") "
			  << "\n\t\tMove3: " << pokedex[i].getMove(3).name << " (" << pokedex[i].getMove(3).type << ") "
			  << "\n\t\tMove4: " << pokedex[i].getMove(4).name << " (" << pokedex[i].getMove(4).type << ") " << std::endl;
	}
}

// Returns the number of Pokemon in the Pokedex
int Pokedex::getSize()
{
	return pokedex.size();
}

// Returns the Pokemon listed at the specified Pokedex number
Pokemon Pokedex::findPokemon(int number)
{
	for (unsigned int i = 0; i < pokedex.size(); i++)
	{
		if (pokedex[i].getPokedexNumber() == number)
		{
			return pokedex[i];
		}
	}
}

// Returns the Pokemon based on number in Pokedex vector
Pokemon Pokedex::getPokemon(int number)
{
	return pokedex[number];
}

// Finds if there is a Pokemon listed for a specified Pokedex number
bool Pokedex::isInPokedex(int number)
{
	for (unsigned int i = 0; i < pokedex.size(); i++)
	{
		if (pokedex[i].getPokedexNumber() == number)
		{
			return true;
		}
	}
	return false;
}

// The Pokedex
void Pokedex::bootUp()
{
	/***** EASILY ADD MORE POKEMON TO THE POKEDEX! *****/
	// Simply add the Pokemon in the proper place, according
	// to Pokedex number, and include all the information
	// noted in the comments to the lower right of here next
	// to the listing for Bulbasaur

	/* #001 */
	Pokemon Bulbasaur(1, "Bulbasaur", "Grass", 1000,			// Pokemon: Pokedex Number, Name, Type, HP
								"Tackle", "Normal", 50, 35,		 		// Move 1: Name, Type, Power, PP
								"Vine Whip", "Grass", 45, 25,			// Move 2: Name, Type, Power, PP
								"Razor Leaf", "Grass", 55, 25,			// Move 3: Name, Type, Power, PP
								"Take Down", "Normal", 90, 20);			// Move 4: Name, Type, Power, PP
	pokedex.push_back(Bulbasaur);								// add the Pokemon into the Pokedex using the push_back command
	
	/* #004 */
	Pokemon Charmander(4, "Charmander", "Fire", 1000,
								"Scratch", "Normal", 40, 35,
								"Ember", "Fire", 40, 25,
								"Flame Burst", "Fire", 70, 15,
								"Inferno", "Fire", 100, 5);
	pokedex.push_back(Charmander);
	
	/* #007 */
	Pokemon Squirtle(7, "Squirtle", "Water", 1000,
								"Tackle", "Normal", 50, 35,
								"Water Gun", "Water", 40, 25,
								"Bubble", "Water", 40, 30,
								"Hydro Pump", "Water", 110, 5);
	pokedex.push_back(Squirtle);
	
	/* #012 */
	Pokemon Butterfree(12, "Butterfree", "Bug", 1000,
								"Confusion", "Pyschic", 50, 22,
								"Gust", "Flying", 40, 35,
								"Silver Wind", "Bug", 60, 5,
								"Bug Buzz", "Bug", 90, 10);
	pokedex.push_back(Butterfree);
	
	/* #025 */
	Pokemon Pikachu(25, "Pikachu", "Electric", 1000,
								"Thunder Shock", "Electric", 40, 30,
								"Quick Attack", "Normal", 40, 30,
								"Thunderbolt", "Electric", 90, 15,
								"Thunder", "Electric", 110, 10);
	pokedex.push_back(Pikachu);
							
	/* #037 */
	Pokemon Vulpix(37, "Vulpix", "Fire", 1000,
								"Ember", "Fire", 40, 25,
								"Quick Attack", "Normal", 40, 30,
								"Flame Thrower", "Fire", 90, 15,
								"Inferno", "Fire", 100, 5);
	pokedex.push_back(Vulpix);
	
	/* #039 */
	Pokemon Jigglypuff(39, "Jigglypuff", "Normal", 1000,
								"Pound", "Normal", 40, 35,
								"Round", "Normal", 60, 15,
								"Double Slap", "Normal", 15, 10,
								"Hyper Voice", "Normal", 90, 10);
	pokedex.push_back(Jigglypuff);
	
	/* #094 */
	Pokemon Gengar(94, "Gengar", "Ghost", 1000,
								"Lick", "Ghost", 30, 30,
								"Shadow Punch", "Ghost", 60, 20,
								"Dream Eater", "Psychic", 100, 15,
								"Hex", "Ghost", 65, 10);
	pokedex.push_back(Gengar);
	
	/* #095 */
	Pokemon Onix(95, "Onix", "Rock", 1000,
								"Rock Throw", "Rock", 50, 15,
								"Rock Tomb", "Rock", 60, 15,
								"Smack Down", "Rock", 50, 15,
								"Rock Slide", "Rock", 75, 10);
	
	/* #129 */
	Pokemon Magikarp(129, "Magikarp", "Water", 1000,
								"Splash", "Normal", 0, 40,
								"Splash", "Normal", 0, 40,
								"Splash", "Normal", 0, 40,
								"Splash", "Normal", 0, 40);
	pokedex.push_back(Magikarp);
	
	/* #143 */
	Pokemon Snorlax(143, "Snorlax", "Normal", 1000,
								"Tackle", "Normal", 50, 35,
								"Chip Away", "Normal", 70, 20,
								"Body Slam", "Normal", 85, 15,
								"Snore", "Normal", 50, 15);
	pokedex.push_back(Snorlax);
	
	/* #150 */
	Legendary Mewtwo(150, "Mewtwo", "Psychic", 1000,
							"Confusion", "Psychic", 50, 25,
							"Future Sight", "Psychic", 120, 10,
							"Psycho Cut", "Psychic", 70, 20,
							"Psystrike", "Psychic", 100, 10);
	pokedex.push_back(Mewtwo);
}
