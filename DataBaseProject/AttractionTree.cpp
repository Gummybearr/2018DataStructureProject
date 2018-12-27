#include "AttractionTree.h"

//AttractionTree class has two constructors
//However, only the constructor with 3 parameters is used by administrator
//Another constructor is part of tree initializing process using constructor with 3 parameters.

//This paramater is used by administrator. parameters represent items in the map(subAttractions),
//width(xmax) and length(ymax) respectively
AttractionTree::AttractionTree(int subAttractions, int xmax, int ymax) {
	//height is set to 0 on the root
	height = 0;
	//sub-trees are set to null pointer at first
	sub1 = NULL;    sub2 = NULL;    sub3 = NULL;
	//node status is set to leaf at first
	isLeaf = true;
	//since data of the map is not stored yet, it is not occupied
	leafOccupied = false;
	//boundaries of x and y axis are set here, values put in the parameters define the size of map
	setxBoundary(0, xmax);
	setyBoundary(0, ymax);

	//if there are items to be stored in the map, branching takes place
	if (subAttractions > 0) {
		//since this node will have children, it is not leaf 
		isLeaf = false;
		//numOfDivision records number of divisions needed. 
		//for example, if 4 items are to be stored, branching two times would increase
		//leaf nodes counts to 9, so numOfDivision will be 2
		int numOfDivision = 0;
		//accum stores accumulative divisions taken place. Since division will take place now,
		//initial value is set to one.
		int accum = 1;
		//calculates how many divisions are required
		while (accum < subAttractions) {
			accum *= 3;
			numOfDivision += 1;
		}
		//accum will be the total number of leaves in the tree
		cout << "Total leaf generated in total: " << accum<<endl;

		//division(branching) takes place by calling "divideArea" function
		divideArea(height, numOfDivision);
	}
}

//This function is used to branch, and automatically called while initializing the object. 
//This function is recursive. It will keep branching until leaf nodes grow larger than items in the map
void AttractionTree::divideArea(int height, int divisionNum) {
	//modification of code to show boundaries is here
	cout << "x min: " << getxMin() << ", x max: " << getxMax() << endl;
	cout << "y min: " << getyMin() << ", y max: " << getyMax() << endl << endl;;
	//If there are enough leaf nodes in the tree, it stops
	if (divisionNum < 1) {
		isLeaf = true;
		return;
	}
	//Else, it means that division still has to take place, so first set the node status
	//as "Not leaf", and than decrement division count, to state that division has taken place
	isLeaf = false;
	divisionNum -= 1;
	//if the height is even number, branching will take place in x axis.
	if (height % 2 == 0) {
		//height is incremented by one, so that next time branching can take place in y axis.
		height += 1;
		//Another constructor is used here, only using height and x and y boundaries
		sub1 = new AttractionTree(height, getxMin(),
			getxMin() + (getxMax() - getxMin()) / 3, getyMin(), getyMax());
		sub2 = new AttractionTree(height, getxMin() + (getxMax() - getxMin()) / 3 + 1,
			getxMin() + (getxMax() - getxMin()) / 3 * 2, getyMin(), getyMax());
		sub3 = new AttractionTree(height, getxMin() + (getxMax() - getxMin()) / 3 * 2 + 1,
			getxMax(), getyMin(), getyMax());;
		//recursive function call, so that each divided part can branch
		sub1->divideArea(height, divisionNum);
		sub2->divideArea(height, divisionNum);
		sub3->divideArea(height, divisionNum);
	}
	//if the height is odd number, branching will take place in y axis
	else {
		//height is incremented by one, so that next time branching can take place in x axis
		height += 1;
		sub1 = new AttractionTree(height, getxMin(), getxMax(), getyMin(),
			getyMin() + (getyMax() - getyMin()) / 3);
		sub2 = new AttractionTree(height, getxMin(), getxMax(),
			getyMin() + (getyMax() - getyMin()) / 3 + 1, getyMin() + (getyMax() - getyMin()) / 3 * 2);
		sub3 = new AttractionTree(height, getxMin(), getxMax(),
			getyMin() + (getyMax() - getyMin()) / 3 * 2 + 1, getyMax());
		//recursive function call, so that each divided part can branch
		sub1->divideArea(height, divisionNum);
		sub2->divideArea(height, divisionNum);
		sub3->divideArea(height, divisionNum);
	}
}

//Constructor used during branching process. only takes height and x and y boundaries as parameters
AttractionTree::AttractionTree(int h, int xmin, int xmax, int ymin, int ymax) {
	//initializing logic is same
	height = h;
	sub1 = NULL;   sub2 = NULL;   sub3 = NULL;
	isLeaf = true;
	leafOccupied = false;
	setxBoundary(xmin, xmax);
	setyBoundary(ymin, ymax);
}

//Gets address of first child
AttractionTree* AttractionTree::getSub1() {
	return sub1;
}

//Gets address of second child
AttractionTree* AttractionTree::getSub2() {
	return sub2;
}

//Gets address of third child
AttractionTree* AttractionTree::getSub3() {
	return sub3;
}

//Function to get the block surrounding specific x and y coordinate in the map
//This function is also recursive, to dig deeper in the tree until leaf is found
AttractionTree* AttractionTree::getAttractionPoint(int x, int y) {
	//Boolean is set to false at the beginning, changes to true after finding leaf surrounding
	//specific coordinate
	bool foundIt = false;
	//pointer is set as static, so loop takes place until reaching leaf value
	static AttractionTree* found = NULL;
	//If coordinate are out of search boundary, ends function
	if (getxMax() < x || getyMax() < y) {
		std::cout << "Coordinate out of range." << endl;
		return found;
	}
	//If reached leaf and coordinates are in the boundary, it means that leaf surroundng the 
	//coordinate is found. So change Boolean to true, and return address of leaf
	if ((isLeaf == true) && (x < getxMax()) && (y < getyMax())) {
		foundIt = true;
		found = this;     return found;
	}
	//If the current node is internal, find children surrounding coordinate and search again.
	if ((foundIt == false) && (isLeaf == false)) {
		//depending on the height of the node, branching axis was different
		//, so it is the same for searching
		if (height % 2 == 0) {
			if (x < sub1->getxMax())
				sub1->getAttractionPoint(x, y);
			else if (x < sub2->getxMax())
				sub2->getAttractionPoint(x, y);
			else
				sub3->getAttractionPoint(x, y);
		}
		else {
			if (y < sub1->getyMax())
				sub1->getAttractionPoint(x, y);
			else if (y < sub2->getyMax())
				sub2->getAttractionPoint(x, y);
			else
				sub3->getAttractionPoint(x, y);
		}
	}
	return found;
}

//Function to implement data of map in to the tree, takes individual leaf with data as parameter
//Collision resolving technique(clock-wise probing) is used
void AttractionTree::addAttraction(AttractionLeaf* item) {
	//First searching if top-left(xmin,ymin) block is empty
	if (!getAttractionPoint(item->getxMin(), item->getyMin())->leafOccupied) {
		//Modification of code to show collision status
		cout << "No collision" << endl;
		//put data in the leaf
		getAttractionPoint(item->getxMin(), item->getyMin())->leafOccupied = true;
		getAttractionPoint(item->getxMin(), item->getyMin())->setInfo(item->getInfo());
		getAttractionPoint(item->getxMin(), item->getyMin())->setNum(item->getNum());
		getAttractionPoint(item->getxMin(), item->getyMin())->setName(item->getName());
		getAttractionPoint(item->getxMin(), item->getyMin())->setDistance(item->getDistance());
		getAttractionPoint(item->getxMin(), item->getyMin())->setNavigator(item->getNavigator());
	}	
	//If first block is occuppied, then see if top-right(xmax,ymin) block is empty
	else if (!getAttractionPoint(item->getxMax(), item->getyMin())->leafOccupied) {
		//Modification of code to show collision status
		cout << "coordinate for xMin and yMin is occupied, so collision occured" << endl;
		cout << "collision addressed" << endl;
		getAttractionPoint(item->getxMax(), item->getyMin())->leafOccupied = true;
		getAttractionPoint(item->getxMax(), item->getyMin())->setInfo(item->getInfo());
		getAttractionPoint(item->getxMax(), item->getyMin())->setNum(item->getNum());
		getAttractionPoint(item->getxMax(), item->getyMin())->setName(item->getName());
		getAttractionPoint(item->getxMax(), item->getyMin())->setDistance(item->getDistance());
		getAttractionPoint(item->getxMax(), item->getyMin())->setNavigator(item->getNavigator());
	}
	//If second block is occuppied, then see if bottom-right(xmax,ymax) block is empty
	else if (!getAttractionPoint(item->getxMax(), item->getyMax())->leafOccupied) {
		//Modification of code to show collision status
		cout << "coordinate for xMin and yMin is occupied, so collision occured" << endl;
		cout << "coordinate for xMax and yMin is occupied, so collision occured" << endl;
		cout << "collision addressed" << endl;
		getAttractionPoint(item->getxMax(), item->getyMax())->leafOccupied = true;
		getAttractionPoint(item->getxMin(), item->getyMax())->setInfo(item->getInfo());
		getAttractionPoint(item->getxMin(), item->getyMax())->setNum(item->getNum());
		getAttractionPoint(item->getxMin(), item->getyMax())->setName(item->getName());
		getAttractionPoint(item->getxMin(), item->getyMax())->setDistance(item->getDistance());
		getAttractionPoint(item->getxMin(), item->getyMax())->setNavigator(item->getNavigator());
	}	
	//If third block is occupied, then see if bottom-left(xmin,ymax) block is empty
	else if (!getAttractionPoint(item->getxMin(), item->getyMax())->leafOccupied) {
		//Modification of code to show collision status
		cout << "coordinate for xMin and yMin is occupied, so collision occured" << endl;
		cout << "coordinate for xMax and yMin is occupied, so collision occured" << endl;
		cout << "coordinate for xMax and yMin is occupied, so collision occured" << endl;
		cout << "collision addressed" << endl;
		getAttractionPoint(item->getxMin(), item->getyMax())->leafOccupied = true;
		getAttractionPoint(item->getxMin(), item->getyMax())->setInfo(item->getInfo());
		getAttractionPoint(item->getxMin(), item->getyMax())->setNum(item->getNum());
		getAttractionPoint(item->getxMin(), item->getyMax())->setName(item->getName());
		getAttractionPoint(item->getxMin(), item->getyMax())->setDistance(item->getDistance());
		getAttractionPoint(item->getxMin(), item->getyMax())->setNavigator(item->getNavigator());
	}
	//If fourth block is also occupied, print error message
	else {
		cout << "All four blocks are occupied, failed to put data in the map." << endl;
	}
}

//Boolean to check if specific node is leaf
bool AttractionTree::getIsLeaf() {
	return isLeaf;
}

//Boolean to check if leaf is occupied.
bool AttractionTree::getLeafOccupied() {
	return leafOccupied;
}