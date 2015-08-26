/**************************************************************************************
* 		 Author:	Chris Dwight
*  Date Created:	06/04/14
* Last Modified:	06/06/14
* 	   Filename:	pokemon.h
*
* 		  Class:	Oregon State University: CS 165
* 	 Assignment:	Final Project
* 	   Due Date:	June 8, 2014
**************************************************************************************/
#ifndef POKEMON_H
#define POKEMON_H

namespace PocketMonsters																												/*** PROJECT REQUIREMENT #25 ***/
{
	struct MoveSet			// each Pokemon move consists of...																			/*** PROJECT REQUIREMENT #20 ***/
	{
		std::string name;		// a name
		std::string type;		// a type
		int power;				// power	
		int ppRemaining;		// PP (Power Points) remaining
		int ppTotal;			// PP (Power Points) total
	};

	class Pokemon
	{
	public:
		Pokemon();						// default constructor
		Pokemon(int newPokedexNumber, std::string newName, std::string newType, int newHP,
					std::string newMoveName1, std::string newMoveType1, int newPower1, int newPP1, 
					std::string newMoveName2, std::string newMoveType2, int newPower2, int newPP2, 
					std::string newMoveName3, std::string newMoveType3, int newPower3, int newPP3, 
					std::string newMoveName4, std::string newMoveType4, int newPower4, int newPP4);
		//Pokemon(const Pokemon &creature);// copy constructor
		~Pokemon();						// destructor
										// creates a new Pokemon with full info and stats
		int getPokedexNumber();			// returns the Pokedex Number of the Pokemon
		std::string getName();			// returns the name of the Pokemon
		std::string getType();			// returns the type of the Pokemon
		void setHP(int newHP);			// sets the current number of HP (Hit Points) a Pokemon has
		int getHPRemaining();			// returns the current number of HP (Hit Points) a Pokemon has
		int getHPTotal();				// returns the total HP (Hit Points) a Pokemon can have
		MoveSet getMove(int move);		// returns the specified move
		void usePP(int move);			// decreases the PP (Power Points) a move has

	protected:
		int pokedexNumber;				// the Pokedex number of the Pokemon
		std::string name;				// the name of the Pokemon
		std::string type;				// the type of the Pokemon
		int hpRemaining;				// the HP (Hit Points) remaining of the Pokemon
		int hpTotal;					// the total HP (Hit Points) a Pokemon can have
		MoveSet move1;					// the first move of the Pokemon
		MoveSet move2;					// the second move of the Pokemon
		MoveSet move3;					// the third move of the Pokemon
		MoveSet move4;					// the fourth move of the Pokemon
	};
}

#endif
