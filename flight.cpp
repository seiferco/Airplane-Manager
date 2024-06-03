#include "flight.h"

using namespace std;

/*********************************************************************
** Function: Default constructor
** Description: Create default flight class object
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Flight class object is created
*********************************************************************/
Flight::Flight(){
	this->flight_num = "X";
	this->curr_loc = "X";
	this->dest = "X";
	this->num_pilots = 0;
	this->pilots = nullptr;
}

/*********************************************************************
** Function: Copy constructor
** Description: Copy data from another Flight class, and create a new object with the same data
** Parameters: f_arr
** Pre-Conditions: None
** Post-Conditions:none
*********************************************************************/
Flight::Flight(const Flight &f_arr){
	// Shallow copy
	this->flight_num = f_arr.flight_num;
	this->curr_loc = f_arr.curr_loc;
	this->dest = f_arr.dest;
	this->num_pilots = f_arr.num_pilots;

	this->pilots = new string [this->num_pilots];
	for (int i = 0 ; i < this->num_pilots ; ++i){
		this->pilots[i] = f_arr.pilots[i];
	}
}

/*********************************************************************
** Function: Flight clas object deconstructor
** Description: Delete flightclass  obect
** Parameters: None
** Pre-Conditions: Flight object is created
** Post-Conditions: Flight onject is deleted
*********************************************************************/
Flight::~Flight(){
	if (pilots != nullptr){
		delete [] pilots;
		pilots = nullptr;
	}
}

/*********************************************************************
** Function: Flight class Assignment operator overload
** Description: Assign a flight clas object to another flight class object
** Parameters: f_arr reference
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
Flight& Flight::operator=(const Flight &f_arr){
	/* Shallow copy */
	this->flight_num = f_arr.flight_num;
	this->curr_loc = f_arr.curr_loc;
	this->dest = f_arr.dest;
	this->num_pilots = f_arr.num_pilots;

	if(this == &f_arr){
		return *this;
	}

	if(this->pilots != NULL){
		delete [] this->pilots;
		this->pilots = NULL;
	}

	/* Deep copy */
	this->pilots = new string [this->num_pilots];
	for (int i = 0 ; i < this->num_pilots ; ++i){
		this->pilots[i] = f_arr.pilots[i];
	}

	return *this;
}

/*********************************************************************
** Function: set_flight_num
** Description: set flight_num to a string
** Parameters: const string
** Pre-Conditions: flight_num is declared in class
** Post-Conditions: flight_num hold a new value
*********************************************************************/
void Flight::set_flight_num(const string new_flight_num){
	this->flight_num = new_flight_num;
}

/*********************************************************************
** Function: set_curr_loc
** Description: set curr_loc to a string
** Parameters: string
** Pre-Conditions: curr_loc exists
** Post-Conditions: curr_loc holds a new value
*********************************************************************/
void Flight::set_curr_loc(string new_curr_loc){
	this->curr_loc = new_curr_loc;
}

/*********************************************************************
** Function: set_dest
** Description: dest is set to a const string
** Parameters: const string
** Pre-Conditions: dest is declared in class
** Post-Conditions: dest holds a string
*********************************************************************/
void Flight::set_dest(const string new_dest){
	this->dest = new_dest;
}

/*********************************************************************
** Function: set_num_pilots
** Description: num_ilots is set to a const int
** Parameters: const int
** Pre-Conditions: num_pilots is declared in class
** Post-Conditions:num_pilots holds a int
*********************************************************************/
void Flight::set_num_pilots(const int new_num_pilots){
	this->num_pilots = new_num_pilots;
}

/*********************************************************************
** Function: set_pilots
** Description: set pilots array to strings
** Parameters: strign pointer array
** Pre-Conditions:pilots is delcared in class
** Post-Conditions: pilots holds an array of strings
*********************************************************************/
void Flight::set_pilots(string* new_pilots){
	this->pilots = new_pilots;
}

/* Accessors */
/*********************************************************************
** Function: get_flight_num
** Description: retrieve flight_num
** Parameters: none
** Pre-Conditions: flight_num is delcated in class
** Post-Conditions: return flight_num
*********************************************************************/
string Flight::get_flight_num() const{
	return this->flight_num;
}

/*********************************************************************
** Function: get_curr_loc
** Description: retrieve curr_loc
** Parameters: none
** Pre-Conditions: curr_loc is delcated in class
** Post-Conditions: return curr_loc
*********************************************************************/
string Flight::get_curr_loc() const{
	return this->curr_loc;
}

/*********************************************************************
** Function: get_dest
** Description: retrieve dest
** Parameters: none
** Pre-Conditions: dest is delcated in class
** Post-Conditions: return dest
*********************************************************************/
string Flight::get_dest() const{
	return this->dest;
}

/*********************************************************************
** Function: get_num_pilots
** Description: retrieve num_pilots
** Parameters: none
** Pre-Conditions: num_pilots is delcated in class
** Post-Conditions: return num_pilots
*********************************************************************/
int Flight::get_num_pilots() const{
	return this->num_pilots;
}

/*********************************************************************
** Function: get_pilots
** Description: retrieve pilots
** Parameters: none
** Pre-Conditions: pilots is delcated in class
** Post-Conditions: return pilots
*********************************************************************/
string* Flight::get_pilots() const{
	return this->pilots;
}	

/*********************************************************************
** Function: populate_flight
** Description: read from a text file and populate pilot information
** Parameters: ifstream object, and integer
** Pre-Conditions: ifstream object is opened
** Post-Conditions: pilot aray is filled with data
*********************************************************************/
void Flight::populate_flight(ifstream& inputFile, int new_num_pilots) {
	//Your code goes here:
	this->pilots = new string [new_num_pilots];
	for (int i = 0 ; i < new_num_pilots ; ++i){
		inputFile >> this->pilots[i];
	}
	

	return;
}

/*********************************************************************
** Function: print_flight
** Description: print pilot array information in readable format
** Parameters: None
** Pre-Conditions: pilots array is delcared
** Post-Conditions: None
*********************************************************************/
void Flight::print_flight() {
	//Your code goes here:
	for (int i = 0 ; i < this->num_pilots ; ++i){
		cout << "Pilot " << i + 1 << ": " << this->pilots[i] << endl;

	}
	cout << "----------------------" << endl;
	cout << endl;
}

/*********************************************************************
** Function: delete_pilots
** Description: free pilot's dynamic memory
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: dynamic memory is free'd
*********************************************************************/
void Flight::delete_pilots(){
	if (this->pilots != nullptr){
		delete [] this-> pilots;
		this->pilots = nullptr;
	}
}

/*********************************************************************
** Function: edit_file3
** Description: add pilot information into a text file
** Parameters: txt file
** Pre-Conditions: txt file is open
** Post-Conditions: txt file is edited 
*********************************************************************/
void Flight::edit_file3(ofstream &outputFile){
	for (int i = 0 ; i < this->num_pilots ; ++i){
		outputFile << pilots[i] << " ";
	}
	outputFile << endl;
}




