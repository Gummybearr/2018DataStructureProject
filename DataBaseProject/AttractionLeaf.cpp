#include "AttractionLeaf.h"

//AttractionLeaf class has two constructors:
//1. Constructor without parameters, used when any member variables are not certain
AttractionLeaf::AttractionLeaf() {
	xMin = 0;    xMax = 0;    yMin = 0;       yMax = 0;          Num = 0;
	Name = "N";  Info = "I";  Distance = .0;  Navigator = "N";
}

//2. Constructor that takes all member variables as parameters.
//Used when all data for the leaf is certain
AttractionLeaf::AttractionLeaf(int xmin, int xmax, int ymin, int ymax, int num, string name,
	string info, float distance, string navigator) {
	xMin = xmin;   xMax = xmax;   yMin = ymin;           yMax = ymax;              Num = num;
	Name = name;   Info = info;   Distance = distance;   Navigator = navigator;

	//This part has been added to constructor
	cout << "Number: " << Num << endl;
	cout << "Name: " << Name << endl;
	cout << "xMin: " << xMin <<", xMax: "<<xMax<<endl;
	cout << "yMin: " << yMin << ", xMax: " << yMax << endl;
	cout << "Info: " << Info << endl;
	cout << "Distance: " << Distance << endl;
	cout << "Navigator: " << Navigator << endl << endl;;
}

//Setting x boundary with minimum and maximum values
void AttractionLeaf::setxBoundary(int min, int max) {
	xMin = min;  xMax = max;
}

//Setting y boundary with minimum and maximum values
void AttractionLeaf::setyBoundary(int min, int max) {
	yMin = min;  yMax = max;
}

//Setting item number, which is the number of specific location in the map
void AttractionLeaf::setNum(int num) {
	Num = num;
}

//Setting item name, which is the name of specific location in the map
void AttractionLeaf::setName(string name) {
	Name = name;
}

//Setting item information, which is the information of specific location in the map
void AttractionLeaf::setInfo(string info) {
	Info = info;
}

//Setting distance, which is the distance of specific location in the map from specific point
void AttractionLeaf::setDistance(float distance) {
	Distance = distance;
}

//Setting step-by-step explanation for the visitor
void AttractionLeaf::setNavigator(string navigator) {
	Navigator = navigator;
}

//Getting the minimum boundary on x axis
int AttractionLeaf::getxMin() {
	return xMin;
}

//Getting the maximum boundary on x axis
int AttractionLeaf::getxMax() {
	return xMax;
}

//Getting the minimum boundary on y axis
int AttractionLeaf::getyMin() {
	return yMin;
}

//Getting the maximum boundary on x axis
int AttractionLeaf::getyMax() {
	return yMax;
}

//Getting the location number 
int AttractionLeaf::getNum() {
	return Num;
}

//Getting the location name
string AttractionLeaf::getName() {
	return Name;
}

//Getting the location information
string AttractionLeaf::getInfo() {
	return Info;
}

//Getting the location distance
float AttractionLeaf::getDistance() {
	return Distance;
}

//Getting the location navigarion
string AttractionLeaf::getNavigator() {
	return Navigator;
}
