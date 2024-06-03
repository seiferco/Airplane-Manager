#include "manager.h"

using namespace std;

/*********************************************************************
** Function: Default Constructor
** Description: Creates manager objects using the default constructor
** Parameters: None
** Pre-Conditions: No parameters passed
** Post-Conditions: Object is created
*********************************************************************/
Manager::Manager(){
	this->num_airports = 0;
	this->a_arr = nullptr;
}

/*********************************************************************
** Function: non-default constructor
** Description: Creates manager objects using the default constructor
** Parameters:None
** Pre-Conditions: num_airports is passed
** Post-Conditions: Object is created
*********************************************************************/
Manager::Manager(int new_num_airports) {
	this->num_airports = new_num_airports;
}

/*********************************************************************
** Function: Destructor
** Description: Free any dynamic memory
** Parameters: None
** Pre-Conditions: Object exists
** Post-Conditions: Object is deleted
*********************************************************************/
Manager::~Manager() {
	if (this->a_arr != nullptr){
		delete [] a_arr;
		a_arr = nullptr;
	}
}

/*********************************************************************
** Function: set_num_airports
** Description: Set the number of airports to some int
** Parameters: constant integer
** Pre-Conditions: num_airports exists
** Post-Conditions: new_num_airports exists
*********************************************************************/
void Manager::set_num_airports(const int new_num_airports){
	this->num_airports = new_num_airports;
}

/*********************************************************************
** Function: set_a_arr
** Description: Set a_arr to something
** Parameters: Array pointer of Airport class
** Pre-Conditions: a_arr exists
** Post-Conditions: new_a_arr exists
*********************************************************************/
void Manager::set_a_arr(Airport* new_a_arr){
	this->a_arr = new_a_arr;
}

/* Accessors */
/*********************************************************************
** Function: get_num_airports
** Description: returns num_airports member variable from the Manager class
** Parameters: None
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
int Manager::get_num_airports() const{
	return this->num_airports;
}

/*********************************************************************
** Function: get_a_arr
** Description: returns a_arr member array from the Manager class
** Parameters: None
** Pre-Conditions: a_arr exists
** Post-Conditions: None
*********************************************************************/
Airport* Manager::get_a_arr() const{
	return this->a_arr;
}

/*********************************************************************
** Function: populate
** Description: takes info from the txt file "airport.txt" and populates class member variables of every class
** Parameters: ifstream variable reference
** Pre-Conditions: ifstream variable is created and opened a file
** Post-Conditions: None
*********************************************************************/
void Manager::populate(ifstream &inputFile) {
	//Your code goes here:
	inputFile >> this->num_airports;
	this->a_arr = new Airport [this->num_airports];
	for (int i = 0 ; i < this->num_airports ; ++i){
		string new_name;
		int new_num_flights;
		int new_cap;

		inputFile >> new_name >> new_num_flights >> new_cap;
		this->a_arr[i].set_name(new_name);
		this->a_arr[i].set_num_flights(new_num_flights);
		this->a_arr[i].set_cap(new_cap);

		this->a_arr[i].populate_airport(inputFile, new_num_flights);
	}

	return; 
}

/*********************************************************************
** Function: init
** Description: Opens the airport.txt file. Error checks to make sure it exists. Calls populate function.
** 				After program finishes, close the file and call edit_file.
** Parameters: None
** Pre-Conditions: ifstream object is created
** Post-Conditions: File is closed
*********************************************************************/
int Manager::init(){
	ifstream inputFile("airport.txt");
	//Error opening file?:
	//Your code goes here:
	if (!inputFile.is_open()){
		cout << "File cannot be opened" << endl;
		return 1;
	}
	

	Manager::populate(inputFile);

	inputFile.close();
	
	edit_file();

	return 1;
}

/*********************************************************************
** Function: edit_file
** Description: Wipe the airport.txt file, and enter new airport information into it
** Parameters: None
** Pre-Conditions: airport.txt is closed
** Post-Conditions: airport.txt is updated
*********************************************************************/
void Manager::edit_file(){

	ofstream outputFile("airport.txt", ios::trunc);
	
	outputFile << this->num_airports;
	outputFile << endl;
	for (int i = 0 ; i < this->num_airports ; ++i){
		outputFile << this->a_arr[i].get_name() << " " << a_arr[i].get_num_flights() << " " << a_arr[i].get_cap() << endl;
		a_arr[i].edit_file2(outputFile);
	}
}

/*********************************************************************
** Function: print_menu
** Description: Display a GUI to the user
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
void Manager::print_menu(){
	cout << endl;
	cout << "1. View all Airports & Flights info" << endl;
	cout << "2. Check flight info" << endl;
	cout << "3. Add a new flight" << endl;
	cout << "4. Cancel a flight" << endl;
	cout << "5. Take off a flight" << endl;
	cout << "6. Print airport stats" << endl;
	cout << "7. Take off all flights" << endl;
	cout << "8. Quit" << endl;

	cout << "Your choice: ";
}

/*********************************************************************
** Function: get_menu_choice
** Description: Get the user's menu choice
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: return user's choice integer
*********************************************************************/
int Manager::get_menu_choice() {
	int choice = 0;
	Manager::print_menu();
	cin >> choice;
	cout << endl;

	//Don't forget error handling!!!
	return choice;
}

/*********************************************************************
** Function: print_all
** Description: Print's all airpot information (all shallow class member variables)
** Parameters: None
** Pre-Conditions: Class member variables all exist
** Post-Conditions: None
*********************************************************************/
void Manager::print_all(){
	//Your code goes here:
	for (int i = 0 ; i < this->num_airports ; ++i){
		cout << "**********************************" << endl;
		cout << "******Airport Name: " << this->a_arr[i].get_name() << "******" << endl;
		cout << "Capacity: " << this->a_arr[i].get_cap() << endl; 
		this->a_arr[i].print_airport();
	}
	return; 

}

/*********************************************************************
** Function: check_flight_control
** Description: Ask the user to enter a flight number. If flight is not found print an error. If found, print the fflight's information
** Parameters: None
** Pre-Conditions: flight array and airport array is populated
** Post-Conditions: None
*********************************************************************/
void Manager::check_flight_control() {
    string enterFlight;
    bool foundInAnyAirport = false;

    cout << "Enter the flight number: ";
    cin >> enterFlight;
    
    for (int i = 0; i < this->num_airports; ++i) {
        // Check if the flight is found in the current airport
        if (this->a_arr[i].find_flight(enterFlight)) {
            foundInAnyAirport = true; 
        }
    }

    // If the flight is not found in any airport, print error
    if (!foundInAnyAirport) {
        cout << "Flight not found" << endl;
    }
    return; 
}

/*********************************************************************
** Function: add_flight_control
** Description: Add a flight to the flight array by creating a new flight object and using setters to set Flight class member variables based on user input.
** 				If the airport the user wants to adda flight to is full, print an error. 
**				If it is not full, succesfully add a flight by using the AOO and incrementing the flight array by one, then setting the new flight at the last index.
** Parameters: Nnne
** Pre-Conditions: Flight object is created
** Post-Conditions: flight array is incremented
*********************************************************************/
void Manager::add_flight_control() {
    Flight f1;
	string user_loc;
    string user_flight_num;
    string user_dest;
    int user_num_pilots;
    string* user_pilots;

	cout << "=== Choices ===" << endl;
	for (int i = 0 ; i < this->num_airports ; ++i){
		cout << "(" << a_arr[i].get_name() << ") - Airport " << a_arr[i].get_name() << endl;
	}

    cout << "Choose an airport: ";
    cin >> user_loc;
    f1.set_curr_loc(user_loc);

	int airportIndex = -1;
    for (int i = 0; i < this->num_airports; i++) {
        if (user_loc == this->a_arr[i].get_name()) {
            airportIndex = i;
            break;
        }
    }

    if (airportIndex == -1) {
        cout << "Airport not found." << endl;
        return;
    }

    if (this->a_arr[airportIndex].get_num_flights() == this->a_arr[airportIndex].get_cap()) {
        cout << "Cannot add more flights to this airport" << endl;
        return;
    }


    cout << "Enter flight number: ";
    cin >> user_flight_num;
    f1.set_flight_num(user_flight_num);

	cout << "Enter destination: ";
    cin >> user_dest;
    f1.set_dest(user_dest);

    cout << "Enter number of pilots: ";
    cin >> user_num_pilots;
    f1.set_num_pilots(user_num_pilots);

    user_pilots = new string [user_num_pilots];
    for (int i = 0; i < user_num_pilots; i++){
        cout << "Name of Pilot #" << i +1 << ": ";
        cin >> user_pilots[i];
        f1.set_pilots(user_pilots);
    }

    for(int i = 0; i < this->num_airports; i++){
        if(user_loc == this->a_arr[i].get_name()){
            this->a_arr[i].add_a_flight(f1);
        }
    }
	
    user_pilots = nullptr;
    return; 
}

/*********************************************************************
** Function: cancel_flight_control
** Description: Present airport options. Recieve user input and present all flights within the selected airport. Recieve user's selected flight.
**				Error check both statements to check and make sure the airport and flight exist.
**				return a copy of the selected flight, set all indexies back one in the array.
** Parameters: None
** Pre-Conditions: airport and flight array exist
** Post-Conditions: updated flight array
*********************************************************************/
void Manager::cancel_flight_control() {
    string user_loc;

    cout << "=== Choices ===" << endl;
    for (int i = 0; i < this->num_airports; ++i) {
        cout << "(" << a_arr[i].get_name() << ") - Airport " << this->a_arr[i].get_name() << endl;
    }

    cout << "Choose an airport: ";
    cin >> user_loc;

    int airportIndex = -1;
    for (int i = 0; i < this->num_airports; i++) {
        if (user_loc == this->a_arr[i].get_name()) {
            airportIndex = i;
            break;
        }
    }

    if (airportIndex == -1) {
        cout << "Airport not found." << endl;
        return;
    }

    cout << "**********************************" << endl;
    cout << "******Airport Name: " << this->a_arr[airportIndex].get_name() << "******" << endl;
    cout << "Capacity: " << this->a_arr[airportIndex].get_cap() << endl;
    this->a_arr[airportIndex].print_airport();

    int flightIndex;
    cout << "Choose a flight to cancel: ";
    cin >> flightIndex;

    Flight flightRemoved = this->a_arr[airportIndex].remove_a_flight(flightIndex - 1);

    return;
}

/*********************************************************************
** Function: take_off_control
** Description: Simulates sending a flight to its destination. 
**				Ask the user to pick an airport, and flight.
**				Once selected, remove that flight from the array, make a copy of it and return it to the Manager.
**				Once returned, add tthe flight to its destination and finally, set the curr_loc as its dest.
** Parameters: None
** Pre-Conditions: flight exists
** Post-Conditions: updated arrays
*********************************************************************/
void Manager::take_off_control() {
	//Your code goes here:
	string user_loc;

    cout << "=== Choices ===" << endl;
    for (int i = 0; i < this->num_airports; ++i) {
        cout << "(" << a_arr[i].get_name() << ") - Airport " << this->a_arr[i].get_name() << endl;
    }

    cout << "Choose an airport: ";
    cin >> user_loc;

    int airportIndex = -1;
    for (int i = 0; i < this->num_airports; i++) {
        if (user_loc == this->a_arr[i].get_name()) {
            airportIndex = i;
            break;
        }
    }

    if (airportIndex == -1) {
        cout << "Airport not found." << endl;
        return;
    }

    cout << "**********************************" << endl;
    cout << "******Airport Name: " << this->a_arr[airportIndex].get_name() << "******" << endl;
    cout << "Capacity: " << this->a_arr[airportIndex].get_cap() << endl;
    this->a_arr[airportIndex].print_airport();

    int flightChoice;
    cout << "Choose a flight to takeoff: ";
    cin >> flightChoice;

	if (flightChoice < 1 || flightChoice > this->a_arr[airportIndex].get_num_flights()) {
    	cout << "Invalid flight choice." << endl;
        return;
    }

	Flight copyFlight = a_arr[airportIndex].remove_a_flight2(flightChoice - 1);
	copyFlight.set_curr_loc(copyFlight.get_dest());

	/* Checking to make sure the desitnation airport is not already at max capacity */
	/* If it is, add the flight back to the original airport, and print an error */
	for (int i = 0; i < this->num_airports; i++) {
    	if (copyFlight.get_dest() == this->a_arr[i].get_name() && this->a_arr[i].get_num_flights() >= this->a_arr[i].get_cap()) {
            cout << "Destination airport has reached its maximum capacity of flights." << endl;
            copyFlight.set_curr_loc(this->a_arr[airportIndex].get_name());
            this->a_arr[airportIndex].add_a_flight2(copyFlight);
            return;
        }
    }
	
	if (copyFlight.get_dest() == "A"){
		a_arr[0].add_a_flight2(copyFlight);
	}
	else if (copyFlight.get_dest() == "B"){
		a_arr[1].add_a_flight2(copyFlight);
	}
	else if (copyFlight.get_dest() == "C"){
		a_arr[3].add_a_flight2(copyFlight);
	}
	
	cout << "Flight has taken off and landed!" << endl;

	return; 
}

/*********************************************************************
** Function: take_off_all_control
** Description: Same as take_off_control but instead of asking the user for a specific flight, it sends all flights using a for loop. 
** Parameters: None
** Pre-Conditions: Arrays exist
** Post-Conditions: Arrays are updated 
*********************************************************************/
void Manager::take_off_all_control() {
    for (int i = 0; i < this->num_airports; ++i) {
        Flight copyFlight = a_arr[i].remove_all_flights(i);
        copyFlight.set_curr_loc(copyFlight.get_dest());
        
        for (int j = 0; j < this->num_airports; j++) {
            if (i != j) {
                validate_destination(j, copyFlight);
            }
        }

        if (copyFlight.get_dest() == "A") {
            a_arr[0].add_a_flight2(copyFlight);
        } else if (copyFlight.get_dest() == "B") {
            a_arr[1].add_a_flight2(copyFlight);
        } else if (copyFlight.get_dest() == "C") {
            a_arr[2].add_a_flight2(copyFlight);
        } else if (copyFlight.get_dest() == "D"){
			a_arr[3].add_a_flight2(copyFlight);
		}
		
    }


}

/*********************************************************************
** Function: validate_destination
** Description: Validate that the flight taking off is not being flown into an airport that is already at max capacity.
** Parameters: index of loop, reference of the copied flight object being taken off
** Pre-Conditions: copyFlight exists
** Post-Conditions: None
*********************************************************************/
void Manager::validate_destination(int idx, Flight &copyFlight){
	if (copyFlight.get_dest() == this->a_arr[idx].get_name() && this->a_arr[idx].get_num_flights() >= this->a_arr[idx].get_cap()) {
        cout << "Destination airport has reached its maximum capacity of flights." << endl;
        copyFlight.set_curr_loc(this->a_arr[idx].get_name());
        this->a_arr[idx].add_a_flight2(copyFlight);
        return;
    }
}

/*********************************************************************
** Function: stats_control
** Description: Print out airport's, their capacity and how many flights have that airport as a destination
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
void Manager::stats_control() {
	//Your code goes here:
	int* foundDestinationArr = new int [this->num_airports];
	for (int i = 0 ; i < this->num_airports ; ++i){
		foundDestinationArr[i] = 0;
	}
	for (int i = 0 ; i < this->num_airports ; ++i){
		this->a_arr[i].find_destinations(this->num_airports, foundDestinationArr);
	}
	for (int i = 0 ; i < this->num_airports ; ++i){
		cout << "Airport " << this->a_arr[i].get_name() << endl;
		cout << "Capacity: " << this->a_arr[i].get_cap() << endl;
		cout << "Listed as destination: " << foundDestinationArr[i] << " flights" << endl;
	}

	delete [] foundDestinationArr;
	foundDestinationArr = nullptr;
	return; 
}

/*********************************************************************
** Function: run
** Description: Start of the program. Branching statement to decide what function to call based on user's menu choice
** Parameters: get user's choice
** Pre-Conditions: None
** Post-Conditions: Program is exited
*********************************************************************/
void Manager::run() {
	cout << endl;
	cout << "Welcome to Flight Manager!!" << endl;
	if (Manager::init() != 1)
		return;

	int choice = -1;
	while (choice != 8)
	{
		choice = Manager::get_menu_choice();

		//print all
		if (choice == 1) 
			Manager::print_all();

		//flight info
		else if (choice == 2){
			Manager::check_flight_control();
		}
		//add a new flight
		else if (choice == 3) {
			Manager::add_flight_control();
		}
		//cancel a flight
		else if (choice == 4) {
			Manager::cancel_flight_control();
		}
		//take off a flight
		if (choice == 5){
			Manager::take_off_all_control();
		}
		//airport stats
		else if (choice == 6){
			Manager::stats_control();
		}
		else if (choice == 7) {
			Manager::take_off_all_control();
		}
	}
	
	cout << "Bye!" << endl << endl;

	edit_file();

	return;
}

