#include "airport.h"

using namespace std;

/*********************************************************************
** Function: Airprt Default constructor
** Description: Create an airport object 
** Parameters: None
** Pre-Conditions: Object is defined
** Post-Conditions: Object is created
*********************************************************************/
Airport::Airport() {
	this->name = "x";
	this->num_flights = 0;
	this->cap = 0;
	this->f_arr = nullptr;
}


/*********************************************************************
** Function: Airport destructor
** Description: Delets airport object instances
** Parameters: None
** Pre-Conditions: Object is defined
** Post-Conditions: Object is deleted
*********************************************************************/
Airport::~Airport() {
	if (f_arr != nullptr){
		delete [] f_arr;
		f_arr = nullptr;
	}
}

/*********************************************************************
** Function: Assignment operator overload
** Description: Overloads / deep copies Airport object instances
** Parameters: Airport object reference's
** Pre-Conditions: Airport obejects exist
** Post-Conditions: Airport copy is created
*********************************************************************/
Airport& Airport::operator=(const Airport &a_arr){
	if(this == &a_arr){
		return *this;
	}

	if(this->f_arr != NULL){
		delete [] this->f_arr;
		this->f_arr = NULL;
	}

	this->num_flights = a_arr.num_flights;
	this->f_arr = new Flight [this->num_flights];
	for (int i = 0 ; i < this->num_flights ; ++i){
		this->f_arr[i] = a_arr.f_arr[i];
	}

	return *this;
}

/*********************************************************************
** Function: edit_file2
** Description: Print the flight information to a file
** Parameters: ifstream object
** Pre-Conditions:Class members are populated / exist
** Post-Conditions: File is editied 
*********************************************************************/
void Airport::edit_file2(ofstream &outputFile){
	for (int i = 0 ; i < this->num_flights ; ++i){
		outputFile << this->f_arr[i].get_flight_num() << " " << f_arr[i].get_curr_loc() << " " << f_arr[i].get_dest() << " " << f_arr[i].get_num_pilots() << " ";
		f_arr[i].edit_file3(outputFile);
	}
}

/*********************************************************************
** Function: set_name
** Description: Set class membr variable name to something
** Parameters: const string
** Pre-Conditions: name member variable is defined in the Airport class
** Post-Conditions: name holds new value
*********************************************************************/
void Airport::set_name(const string new_name){
	this->name = new_name;
}

/*********************************************************************
** Function: set_num_flights
** Description: set num_flights to a int
** Parameters: integer
** Pre-Conditions:num_flights is declared
** Post-Conditions: num_flights holds a value
*********************************************************************/
void Airport::set_num_flights(int new_num_flights){
	this-> num_flights = new_num_flights;
}

/*********************************************************************
** Function: set_cap
** Description: set cap to a int
** Parameters: integer
** Pre-Conditions: cap is declared
** Post-Conditions: cap holds a value
*********************************************************************/
void Airport::set_cap(const int new_cap){
	this->cap = new_cap;
}

/*********************************************************************
** Function: set_f_arr
** Description: set _f_arr
** Parameters: Flight class array pointer
** Pre-Conditions:f_arr is declared
** Post-Conditions: f_arr holds values
*********************************************************************/
void Airport::set_f_arr(Flight* new_f_arr){
	this->f_arr = new_f_arr;
}

/*********************************************************************
** Function: get_name
** Description: retrieve value of name
** Parameters: none
** Pre-Conditions: name is declared
** Post-Conditions: return name value
*********************************************************************/
string Airport::get_name() const{
	return this->name;
}

/*********************************************************************
** Function: get_num_flights
** Description: retrieve num_flights value
** Parameters: none
** Pre-Conditions: num_flights is delcared
** Post-Conditions: num_flights is returned
*********************************************************************/
int Airport::get_num_flights() const{
	return this->num_flights;
}

/*********************************************************************
** Function: get_cap
** Description: retrieve value of cap
** Parameters: none
** Pre-Conditions: cap is declared
** Post-Conditions: cap is returned
*********************************************************************/
int Airport::get_cap() const{
	return this->cap;
}

/*********************************************************************
** Function: get_f_arr
** Description: retrieve value of f_arr
** Parameters: none
** Pre-Conditions: f_ar is declared
** Post-Conditions: return f_arr
*********************************************************************/
Flight* Airport::get_f_arr() const{
	return this->f_arr;
}

/*********************************************************************
** Function: populate_airport
** Description: Read from a file and populate Airport class members based on that file. 
** Parameters: ifstream object, and an integer
** Pre-Conditions: ifstream object exists
** Post-Conditions: Clas member variavbles are populated with information
*********************************************************************/
void Airport::populate_airport(ifstream& inputFile, int new_num_flights){
	//Your code goes here:
	
	this->f_arr = new Flight [new_num_flights];
	for (int i = 0 ; i < new_num_flights ; ++i){
		string new_flight_num;
		string new_curr_loc;
		string new_dest;
		int new_num_pilots;

		inputFile >> new_flight_num >> new_curr_loc >> new_dest >> new_num_pilots;

		this->f_arr[i].set_flight_num(new_flight_num);
		this->f_arr[i].set_curr_loc(new_curr_loc);
		this->f_arr[i].set_dest(new_dest);
		this->f_arr[i].set_num_pilots(new_num_pilots);

		this->f_arr[i].populate_flight(inputFile, new_num_pilots);
	}

	return; 
}

/*********************************************************************
** Function: find_flight
** Description: Print out flight information based on user inuutted flight number
** Parameters: string entered by user
** Pre-Conditions: User entered a string
** Post-Conditions: Return the flight object 
*********************************************************************/
bool Airport::find_flight(string enterFlight) {
    bool foundFlight = false; // Flag to indicate if the flight is found

    // Iterate through each flight in the array
    for (int i = 0; i < this->num_flights; ++i) {
        // if the flight number matches the entered flight number
        if (enterFlight == f_arr[i].get_flight_num()) {
            // Flight found
			foundFlight = true;
            cout << "Flight Found!" << endl;
            cout << "----------------------" << endl;
            cout << "Flight #: " << this->f_arr[i].get_flight_num() << endl;
            cout << "Currently at: " << this->f_arr[i].get_curr_loc() << endl;
            cout << "Destination: " << this->f_arr[i].get_dest() << endl;
            this->f_arr[i].print_flight();
			break;
            
        }
    }

    return foundFlight;
}

/*********************************************************************
** Function: find_destinations
** Description: Find if the current flight in loop is equal to a destination, if so update that in the array
** Parameters: number of airports and a dynamic array
** Pre-Conditions: dynamic array exists
** Post-Conditions: dynamic array is incremented
*********************************************************************/
void Airport::find_destinations(int num_airports, int* foundDestinationArr){
	for (int j = 0 ; j < this->num_flights ; ++j){
		if (this->f_arr[j].get_dest() == "A"){
			(++foundDestinationArr[0]);
		}
		else if (this->f_arr[j].get_dest() == "B"){
			(++foundDestinationArr[1]);
		}
		else if (this->f_arr[j].get_dest() == "C"){
			(++foundDestinationArr[2]);
		}
	}
}

/*********************************************************************
** Function: add_a_flight
** Description: Add a flight object to the flight array. Increment the num_flights 
** Parameters: Flight object
** Pre-Conditions: Flight object is created in previosus funtion
** Post-Conditions: Flight object is added to the f_arr array
*********************************************************************/
void Airport::add_a_flight(Flight &f){
  
    Flight* new_f_arr = new Flight[this->num_flights + 1];

    for (int i = 0; i < this->num_flights; i++){
        new_f_arr[i] = this->f_arr[i];
    }
    
    new_f_arr[this->num_flights] = f;

    this->num_flights++;
   
    for (int i = 0; i < this->num_flights - 1; i++){
        this->f_arr[i].delete_pilots();
    }
    
    if (this->f_arr != nullptr){
        delete [] this->f_arr;
    }
    this->f_arr = new_f_arr;

	cout << "Flight added" << endl;
    
    return;
}

/*********************************************************************
** Function: add_a_flight2
** Description: Same as add_flight but without cout statement
** Parameters: Flight object
** Pre-Conditions: Flight object exists
** Post-Conditions: Flight is added to the f_arr array
*********************************************************************/
void Airport::add_a_flight2(Flight &f){
  
    Flight* new_f_arr = new Flight[this->num_flights + 1];
    
    for (int i = 0; i < this->num_flights; i++){
        new_f_arr[i] = this->f_arr[i];
    }

    new_f_arr[this->num_flights] = f;


    this->num_flights++;
    
    for (int i = 0; i < this->num_flights - 1; i++){
        this->f_arr[i].delete_pilots();
    }
    
    if (this->f_arr != nullptr){
        delete [] this->f_arr;
    }

    this->f_arr = new_f_arr;
    
    return;
}

/*********************************************************************
** Function: remove_a_flight
** Description: Check if user entered a valid flight. If they did, make a copy of it using the copy constructor. 
**				Remove an index from the flight array and move all indexes of the array to the left.
** Parameters: loop index
** Pre-Conditions: flight array exists
** Post-Conditions: num_flights decremented
*********************************************************************/
Flight Airport::remove_a_flight(int idx) {
    if (idx < 0 || idx >= num_flights) {
        cout << "Invalid flight." << endl;
        return Flight();
    }

    Flight removedFlight = f_arr[idx]; 

    for (int i = idx; i < num_flights - 1; i++) {
        f_arr[i] = f_arr[i + 1];
    }

    this->num_flights--; 

    cout << "Flight removed successfully." << endl;
    return removedFlight;
}

/*********************************************************************
** Function: remove_all_flights
** Description: Same as remove_flight but without the cout statement for appearance reasons
** Parameters: loop index
** Pre-Conditions:None
** Post-Conditions: None
*********************************************************************/
Flight Airport::remove_all_flights(int idx){

	Flight removedFlight = f_arr[idx];
	for (int i = idx; i < num_flights - 1; i++) {
        f_arr[i] = f_arr[i + 1];
    }

    this->num_flights--;

	return removedFlight;

}

/*********************************************************************
** Function: remove_a_flight2
** Description: Check if user entered a valid flight. If they did, make a copy of it using the copy constructor. 
**				Remove an index from the flight array and move all indexes of the array to the left.
** Parameters: index of a loop
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
Flight Airport::remove_a_flight2(int idx) {
    if (idx < 0 || idx >= num_flights) {
        cout << "Invalid flight." << endl;
        return Flight();
    }

    Flight removedFlight = f_arr[idx]; 

    for (int i = idx; i < num_flights - 1; i++) {
        f_arr[i] = f_arr[i + 1];
    }

    this->num_flights--; 

    return removedFlight;
}

/*********************************************************************
** Function: print_airport
** Description: print all flight class information
** Parameters: None
** Pre-Conditions: flight class member variables exists
** Post-Conditions: None
*********************************************************************/
void Airport::print_airport() {
	//Your code goes here:
	for (int i = 0 ; i < this->num_flights ; ++i){
		cout << "Flight " << i + 1 << ":" << endl;
		cout << "----------------------" << endl;
		cout << "Flight #: " << this->f_arr[i].get_flight_num() << endl;
		cout << "Currently at: " << this->f_arr[i].get_curr_loc() << endl;
		cout << "Destination: " << this->f_arr[i].get_dest() << endl;
		
		this->f_arr[i].print_flight();
	}

	return; 
}

