#ifndef MANAGER_H
#define MANAGER_H 

#include "airport.h"
#include <iostream>
#include <fstream>

using namespace std;

class Manager
{
private:
	int num_airports;	//number of airports
	Airport* a_arr;		//airport array

public:

	/* Constructor */ 
	Manager();
	Manager(int new_num_airports);

	/* Deconstructor */
	~Manager();

	/* Mutators */
	void set_num_airports(const int new_num_airports);
	void set_a_arr(Airport* new_a_arr);

	/* Accessors */
	int get_num_airports()const;
	Airport* get_a_arr()const;

	void populate(ifstream &inputFile);
	int init();
	void edit_file();
	void print_menu();
	int get_menu_choice();
	
	void print_all();
	void check_flight_control();
	void add_flight_control();
	void cancel_flight_control();
	void take_off_control();
	void take_off_all_control();
	void validate_destination(int idx, Flight &copyFlight);
	void stats_control();
	
	void run();


	
	
};
#endif