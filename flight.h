#ifndef FLIGHT_H
#define FLIGHT_H 

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Flight
{
private: 
	string flight_num;		//flight number
	string curr_loc;		//current airport
	string dest;			//destination 
	int num_pilots;			//number of pilots
	string* pilots;			//pilot array

public:
	//Constructors
	Flight();

	/* Copy Constructor */
	Flight(const Flight &f_arr);

	/* AOO */
	Flight& operator=(const Flight &f_arr);

	//Destructor
	~Flight();

	/* Mutators */
	void set_flight_num(const string new_flight_num);
	void set_curr_loc(string new_curr_loc);
	void set_dest(const string new_dest);
	void set_num_pilots(const int new_num_pilots);
	void set_pilots(string* new_pilots);

	/* Accessors */
	string get_flight_num() const;
	string get_curr_loc() const;
	string get_dest() const;
	int get_num_pilots() const;
	string* get_pilots() const;
	
	void edit_file3(ofstream &outputFile);
	void populate_flight(ifstream &inputFile, int new_num_pilots);
	void print_flight();
	void delete_pilots();



	
	
};

#endif
