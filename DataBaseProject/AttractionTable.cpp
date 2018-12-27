#include "AttractionTable.h"

//Constructor that initializes number of items stored in the table to zero and increment
//itemCount as items are found in the tree
AttractionTable::AttractionTable(int itemnum, AttractionTree* root) {
	itemNum = itemnum;
	itemCount = 0;
	//table that can store all data in the tree is generated
	tableForNumSearch = new(AttractionTree*[itemnum]);
	//initializing function is called
	initHelp(root);
}

//Function that initializes table. Searches all map data in the tree and store in the table
void AttractionTable::initHelp(AttractionTree* root) {
	//If all data is found, return
	if (itemNum == itemCount) {
		return;
	}
	//If found leaf
	if (root->getIsLeaf()) {
		//Check if the leaf contains data of map
		if (root->getLeafOccupied()) {
			//If it contains data, then store data in the table and increment item count
			//so that searching can stop after all data is found
			tableForNumSearch[root->getNum()-1] = root;
			itemCount += 1;
		}
		return;
	}
	//If the node is not leaf, then it means it is an internal node, so search its children
	else {
		initHelp(root->getSub1());
		initHelp(root->getSub2());
		initHelp(root->getSub3());
		return;
	}
}

//Function to search map data using location number, calls 
void AttractionTable::searchNum(int n) {
	//Calls function to get address of node containing corresponding data
	AttractionTree* temp = addressConverter(n);
	//If result is not found, then tell user that data does not exist
	if (temp == NULL) {
		cout << "Searching Number does not exist!" << endl<<endl;
		return;
	}
	//Else show user corresponding data, but does not let users to modify data
	cout << "Attraction Number: " << temp->getNum() << endl;
	cout << "Attraction Name: " << temp->getName() << endl;
	cout << "Attraction Description: " << temp->getInfo() << endl;
	cout << "Attraction Distance: " << temp->getDistance() << endl;
	cout << "Attraction Navigation: \n" << temp->getNavigator() << endl << endl;
	delete temp;
}

//This function is used to help front-end user search data using location number
AttractionTree* AttractionTable::addressConverter(int AttractionNum) {
	//If number does not match boundary, return null pointer
	if (AttractionNum > itemNum || AttractionNum<0) {
		return NULL;
	}
	//Use hash function to provide front-end user with data, time complexity is O(1) 
	return tableForNumSearch[AttractionNum%(itemNum+1)-1];
}
