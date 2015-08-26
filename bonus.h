/**************************************************************************************
* 		 Author:	Chris Dwight
*  Date Created:	06/05/14
* Last Modified:	06/06/14
* 	   Filename:	bonus.h
*
* 		  Class:	Oregon State University: CS 165
* 	 Assignment:	Final Project
* 	   Due Date:	June 8, 2014
**************************************************************************************/
#ifndef BONUS_H
#define BONUS_H

class Bonus
{
	const static int SIZE = 16;			// number of types in Generation I Pokemon Type Chart
	
public:
	Bonus();							// default constructor
	~Bonus();							// destructor
	void mainMenu();					// prints main menu options to access other functions
	void getTypeChart();				// prints out the Generation I Pokemon Type Chart
	int findPorygonsNumber(int n);		// finds and prints out Porygon's number
	void magikarpExperience();			// experience what it is like to be Magikarp in battle!
	void multiDemo();					// demo on scope and type casting
	void pointersDemo();				// demo on pointers
	
private:
	void createTypeChart();				// creates the Generation I Pokemon Type Chart
	std::string** typeChart;			// Generation I Pokemon Type Chart
};

#endif
