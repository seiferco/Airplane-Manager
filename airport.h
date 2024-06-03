#ifndef AIRPORT_H
#define AIRPORT_H 

#include <iostream>
#include <string>
#include <fstream>

#include "flight.h"

using namespace std;

class Airport
{
private:

	string name;		//airport name
	int num_flights;	//number of flights
	int cap;			//capacity
	Flight *f_arr;		//flight array

public:

	/* Constructor */
	Airport();
	Airport(string new_name, int new_num_flights, int new_cap);

	/* Deconstructor */
	~Airport();

	/* AOO */
	Airport& operator=(const Airport &a_arr);

	/* Mutators */
	void set_name(const string new_name);
	void set_num_flights(int new_num_flights);
	void set_cap(const int new_cap);
	void set_f_arr(Flight* new_f_arr);

	/* Accessors */
	string get_name() const;
	int get_num_flights() const;
	int get_cap() const;
	Flight* get_f_arr() const;

	void edit_file2(ofstream &outputFile);
	void populate_airport(ifstream& inputFile, int new_num_flights);
	bool find_flight(string enterFlight);
	void find_destinations(int num_airports, int* foundDestinationArr);
	void add_a_flight(Flight &f);
	void add_a_flight2(Flight &f);
	Flight remove_a_flight(int idx);
	Flight remove_a_flight2(int idx);
	Flight remove_all_flights(int idx);
	void take_off_flight();
	void take_off_all_flights();
	void print_airport();
	

};
#endif