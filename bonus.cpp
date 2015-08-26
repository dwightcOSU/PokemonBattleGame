/**************************************************************************************
* 		 Author:	Chris Dwight
*  Date Created:	06/06/14
* Last Modified:	06/06/14
* 	   Filename:	bonus.cpp
*
* 		  Class:	Oregon State University: CS 165
* 	 Assignment:	Final Project
* 	   Due Date:	June 8, 2014
**************************************************************************************/
#include <iostream>		// cout, endl, etc.
#include "bonus.h"

Bonus::Bonus()
{
	typeChart = new std::string*[SIZE];			// intializes the array of Pokemon types									/*** PROJECT REQUIREMENT #18 ***/
	for (int i = 0; i < SIZE; i++)
	{
		typeChart[i] = new std::string[16];																					/*** PROJECT REQUIREMENT #17 ***/
	}
}

// Destructor
Bonus::~Bonus()
{
	for (int i = 0; i < SIZE; i++)
	{
		delete[] typeChart[i];
	}
	delete[] typeChart;
	
/* 	delete p; */
}

void Bonus::mainMenu()
{
	int selection;
	
	std::cout << "\n\n==========================" << std::endl;
	std::cout << "SECRET BONUS FEATURES MENU" << std::endl;
	std::cout << "==========================" << std::endl;
	std::cout << "[1] Access Generation 1 Pokemon Type Chart" << std::endl;
	std::cout << "[2] Play Porygon's favorite number game!" << std::endl;
	std::cout << "[3] Experience what it is like to be Magikarp in battle!" << std::endl;
	std::cout << "[4] The something something Pokemon demo on scope and type casting!" << std::endl;
	std::cout << "[5] The Pokemon demo on pointers!" << std::endl;
	std::cout << "\nPlease enter the number of your selection now: ";
	std::cin >> selection;
	while (std::cin.fail() || selection > 5 || selection < 1)
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "That was not a valid selection. Please try again: ";
		std::cin >> selection;
	}
	if (selection == 1)
	{
		getTypeChart();
	}
	else if (selection == 2)
	{
		std::cout << "\nPokemon Porygon loves calculating Fibonacci numbers!" << std::endl;
		std::cout << "Enter an integer n and Porygon will calculate the nth Fibonacci number" << std::endl;
		std::cout << "What nth Fibonacci number would you like Porygon to calculate?" << std::endl;
		std::cin >> selection;
		while (std::cin.fail() || selection < 0)
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "That was not a valid integer. Please try again." << std::endl;
			std::cin >> selection;
		}
		std::cout << "The " << selection << "th Fibonacci number is " << findPorygonsNumber(selection) << std::endl;
	}
	else if (selection == 3)
	{
		magikarpExperience();
	}
	else if (selection == 4)
	{
		multiDemo();
	}
	else if (selection == 5)
	{
		pointersDemo();
	}
}

// Prints out the Generation I Pokemon Type Chart
void Bonus::getTypeChart()
{
	createTypeChart();
	std::cout << "\n\n\t*** Warning: Chart may not display correctly if screen is not set wide enough ***" << std::endl;
	std::cout << "\n" << std::endl;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			std::cout << typeChart[i][j] << " | ";
		}
		std::cout << "\n          -----------------------------------------------------------------------------------------" << std::endl;
	}
	std::cout << "\n" << std::endl;
	
 	for (int i = 0; i < SIZE; i++)
	{
		delete[] typeChart[i];
	}
	delete[] typeChart;
}

// Pokemon Porygon loves calculating Fibonacci numbers!
// Porygon calculates the nth Fibonacci number based a number n you provide
int Bonus::findPorygonsNumber(int n)
{
	if (n == 1 || n == 2)						// if n is equal to 1 or 2, return 1
	{
		return 1;
	}
	else										// otherwise return sum of fibonacci(n-1) + fibonacci(n-2)
	{
		return findPorygonsNumber(n-1) + findPorygonsNumber(n-2);																/*** PROJECT REQUIREMENT #16 ***/
	}
}

// Experience what it is like to be Magikarp in battle!
void Bonus::magikarpExperience()
{
	int choice;
	while (true)
	{
		std::cout << "It's your turn to make a move, Magikarp!" << std::endl;
		std::cout << "\t[1] Splash" << std::endl;
		std::cout << "\t[2] Something Else" << std::endl;
		std::cout << "What would you like to do?" << std::endl;
		std::cin >> choice;
		while (std::cin.fail() || choice > 2 || choice < 1)
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "That was not a valid selection. Select again: ";
			std::cin >> choice;
		}
		try																														/*** PROJECT REQUIREMENT #35 ***/
		{
			if (choice == 1)
			{
				std::cout << "\nMagikarp used splash!" << std::endl;
				std::cout << "No effect!\n" << std::endl;
			}
			else
			{
				std::string e = "\nERROR: Magikarp knows nothing else!\n";
				throw e;
			}
		}
		catch (std::string e)
		{
			std::cout << e << std::endl;
			std::cout << "Now you know what it is like to be Magikarp!" << std::endl;
			break;
		}
	}
}

// Demo on scope and type casting
void Bonus::multiDemo()																											
{
	std::cout << "\nSCOPE DEMO" << std::endl;																				/*** PROJECT REQUIREMENT #12 ***/
	int e = 0;
	for (int i = 0; i < 5; i++)
	{
		int e = 2;
		if (i == 3)
		{
			int e = 5;									// this e is not accessible outside of the if statement
			std::cout << "e-if:" << e << std::endl;		// prints "e-if: 5"
		}
		std::cout << "e-for:" << e << std::endl;		// prints "e-for: 2"
	}
	std::cout << "e-end:" << e << std::endl;			// prints "e-end: 0"
	
	std::cout << "TYPE CASTING DEMO" << std::endl;																			/*** PROJECT REQUIREMENT #03 ***/
	double f = 55.5;
	std::cout << "Value of double f: " << f << std::endl;
	std::cout << "Value of f after casting from double to int: " << (int) f << std::endl;	// casting to type int
}

// Demo on pointers
void Bonus::pointersDemo()																									/*** PROJECT REQUIREMENT #22 ***/
{
	int size = 10;											// size of array
	int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};		// array of numbers 1-10
	int *p = array;											// pointer to array

	for (int i = 0; i < size; i++)		// prints out "1, 2, 3, 4, 5, 6, 7, 8, 9, 10"
	{
		std::cout << *(p+i) << " ";
	}
	std::cout << std::endl;
	
	for (int i = 0; i < size; i++)		// prints out "1, 2, 3, 4, 5, 6, 7, 8, 9, 10"
	{
		std::cout << p[i] << " ";
	}
	std::cout << std::endl;
	
	p[0] = 10;							// change first value to 10
	p[1] = 9;							// change second value to 9
	*(p+2) = 8;							// change third value to 8
	*(p+3) = 7;							// change fourth value to 7
	p[4] = 6;							// change fifth value to 6
	for (int i = 0; i < size; i++)		// prints out "10, 9, 8, 7, 6, 6, 7, 8, 9, 10"
	{
		std::cout << p[i] << " ";
	}
	std::cout << std::endl;
}

// Creates the Generation I Pokemon Type Chart
void Bonus::createTypeChart()
{	
	// Set Types
	typeChart[0][0] = "        ";
	typeChart[0][1] = "Nor", typeChart[1][0] = "  Normal";	// Normal
	typeChart[0][2] = "Fig", typeChart[2][0] = "Fighting";	// Fighting
	typeChart[0][3] = "Fly", typeChart[3][0] = "  Flying";	// Flying
	typeChart[0][4] = "Psn", typeChart[4][0] = "  Poison";	// Poison
	typeChart[0][5] = "Gnd", typeChart[5][0] = "  Ground";	// Ground
	typeChart[0][6] = "Rck", typeChart[6][0] = "    Rock";	// Rock
	typeChart[0][7] = "Bug", typeChart[7][0] = "     Bug";	// Bug
	typeChart[0][8] = "Gho", typeChart[8][0] = "   Ghost";	// Ghost
	typeChart[0][9] = "Fir", typeChart[9][0] = "    Fire";	// Fire
	typeChart[0][10] = "Wat", typeChart[10][0] = "   Water";	// Water
	typeChart[0][11] = "Gra", typeChart[11][0] = "   Grass";	// Grass
	typeChart[0][12] = "Ele", typeChart[12][0] = "Electric";	// Electric
	typeChart[0][13] = "Psy", typeChart[13][0] = "  Psycic";	// Psychic
	typeChart[0][14] = "Ice", typeChart[14][0] = "     Ice";	// Ice
	typeChart[0][15] = "Dra", typeChart[15][0] = "  Dragon";	// Dragon
	
	// Set 1x multiplier
	// Sets all to 1x initially as most stay 1x
	for (int i = 1; i < SIZE; i++)
	{
		for (int j = 1; j < SIZE; j++)
		{
			typeChart[i][j] = " 1x";
		}
	}
	
	// Set 0x multiplier
	typeChart[1][8] = " 0x", typeChart[2][8] = " 0x";
	typeChart[5][3] = " 0x";
	typeChart[8][1] = " 0x", typeChart[8][13] = " 0x";
	typeChart[12][5] = " 0x";
	
	// Set 2x multiplier
	typeChart[2][1] = " 2x", typeChart[2][6] = " 2x", typeChart[2][14] = " 2x";
	typeChart[3][2] = " 2x", typeChart[3][7] = " 2x" , typeChart[3][11] = " 2x";
	typeChart[4][7] = " 2x", typeChart[4][11] = " 2x";
	typeChart[5][4] = " 2x", typeChart[5][6] = " 2x", typeChart[5][9] = " 2x", typeChart[5][12] = " 2x";
	typeChart[6][3] = " 2x", typeChart[6][7] = " 2x", typeChart[6][9] = " 2x", typeChart[6][14] = " 2x";
	typeChart[7][4] = " 2x", typeChart[7][11] = " 2x", typeChart[7][13] = " 2x";
	typeChart[8][8] = " 2x";
	typeChart[9][7] = " 2x", typeChart[9][11] = " 2x", typeChart[9][14] = " 2x";
	typeChart[10][5] = " 2x", typeChart[10][6] = " 2x", typeChart[10][9] = " 2x";
	typeChart[11][5] = " 2x", typeChart[11][6] = " 2x", typeChart[11][10] = " 2x";
	typeChart[12][3] = " 2x", typeChart[12][10] = " 2x";
	typeChart[13][2] = " 2x", typeChart[13][4] = " 2x";
	typeChart[14][3] = " 2x", typeChart[14][5] = " 2x", typeChart[14][11] = " 2x", typeChart[14][15] = " 2x";
	typeChart[15][15] = " 2x";

	// Set 1/2x multiplier
	typeChart[1][6] = ".5x";
	typeChart[2][3] = ".5x", typeChart[2][4] = ".5x", typeChart[2][7] = ".5x", typeChart[2][13] = ".5x";
	typeChart[3][6] = ".5x", typeChart[3][12] = ".5x";
	typeChart[4][4] = ".5x", typeChart[4][5] = ".5x", typeChart[4][6] = ".5x", typeChart[4][8] = ".5x";
	typeChart[5][7] = ".5x", typeChart[5][11] = ".5x";
	typeChart[6][2] = ".5x", typeChart[6][5] = ".5x";
	typeChart[7][2] = ".5x", typeChart[7][3] = ".5x", typeChart[7][8] = ".5x", typeChart[7][9] = ".5x";
	typeChart[9][6] = ".5x", typeChart[9][9] = ".5x", typeChart[9][10] = ".5x", typeChart[9][15] = ".5x";
	typeChart[10][10] = ".5x", typeChart[10][11] = ".5x", typeChart[10][15] = ".5x";
	typeChart[11][3] = ".5x", typeChart[11][4] = ".5x", typeChart[11][7] = ".5x", typeChart[11][9] = ".5x";
	typeChart[11][11] = ".5x", typeChart[11][15] = ".5x";
	typeChart[12][11] = ".5x", typeChart[12][12] = ".5x", typeChart[12][15] = ".5x";
	typeChart[13][13] = ".5x";
	typeChart[14][10] = ".5x", typeChart[14][14] = ".5x";
}
