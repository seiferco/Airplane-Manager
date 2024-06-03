/*********************************************************************
** Program Filename: Assignment 3
** Author: Cole Seifert
** Date: 2/27/2023
** Description: This program is a airport manager. There are 3 classes (Manager, airport, flight). The manager class calls different functions depending on the user's choice.
** 				The manager has access to an array of airports, and each airport has an array of flights.
**				The manager can add, remove, take off, list all the airport information, and print airport stats. 7
*********************************************************************/
#include <iostream>
#include "manager.h"

using namespace std;

int main()
{

	
	Manager m;
	m.run();

	
	return 0;
}