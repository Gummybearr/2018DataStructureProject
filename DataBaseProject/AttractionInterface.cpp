#include "AttractionInterface.h"

AttractionInterface::AttractionInterface(AttractionTable* table) {
	int number = 0;
	cout << "***Welcome to Chongqing University D Campus!***\n" << endl;
	cout << "Type in the number of places to see information." << endl;
	cout << "Type in 0 to quit." << endl;
	cout << "Number: ";
	cin >> number; //number means the number of location on the map.
	while (number != 0) { //loops until front-end user wants to stop
		table->searchNum(number);
		cout << "Type in the number of places to see information." << endl;
		cout << "Type in 0 to quit." << endl;
		cout << "Number: ";
		cin >> number;
	}
	if (number == 0) {
		cout << "Good bye! Have a nice day!\n" << endl;
	}
}