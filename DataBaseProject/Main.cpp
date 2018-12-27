#include "AttractionInterface.h"

int main() {
	//Using text file is also possible, but in this project, manual input method is used.
	AttractionLeaf library(88, 128, 258, 288, 1, "Library", 
		"Library of Chongqing University, has a unique architecture resembling bookshelf.", 0.8f, 
		"1) Go straight until reaching 4 stone arhitectures, \n2) Turn left\n3) Go straight for 500 meters.\n4) On your right hand side.");
	AttractionLeaf secondTeachingBuilding(14, 54, 221, 251, 2, "secondTeachingBuilding", 
		"Building used for students majoring in biology, chemistry and etc.", 1.0f, 
		"1) Go straight until reaching 4 stone arhitectures, \n2) Turn left\n3) Go straight for 700 meters.\n4) On your front side.");
	AttractionLeaf garden(162, 202, 166, 196, 3, "garden", 
		"Beautiful garden where white swans and black swans are often observed.", 0.9f, 
		"1) Go straight. 2) Walkways surrounding lake are available");
	AttractionLeaf laboratory(277, 317, 198, 228, 4, "laboratory", 
		"Laboratory usually used for students majoring in physics, computer science and etc.", 0.5f, 
		"1) Go straight until reaching 4 stone arhitectures, \n2) On your right hand side.");
	AttractionLeaf soccorField(427, 467, 148, 178, 5, "soccorField", 
		"Soccor field of Chongqing University. Military training for freshmen also takes place here.", 0.7f, 
		"1) Go straight until reaching 4 stone arhitectures, \n2) Turn right\n3) Go straight for 300 meters\n4) On your front.");
	AttractionLeaf firstTeachingBuilding(233, 273, 123, 153, 6, "firstTeachingBuilding", 
		"First teaching building of Chongqing university. Bookshops, print managers and conference rooms are also in this building.", 1.1f, 
		"1) Go straight until reaching 4 stone arhitectures, \n2) Turn right\n3) Go straight for 50 meters.\n4) Turn left\n5)Go straight for 300m\n6) On your front side.");
	AttractionLeaf lake(111, 151, 119, 149, 7, "lake", 
		"One of two lakes in this campus. Visitors and students usually takes pictures with statues located near the lake. Known for stunning scenery during sunset and twilight.", 1.2f, 
		"1) Go straight until reaching 4 stone arhitectures, \n2) Turn left\n3) Go straight for 700 meters.\n4) Turn right\n5) Go straight for 200 meters\n6) On your left hand side.");
	AttractionLeaf tennisCourt(324, 364, 105, 135, 8, "tennisCourt", 
		"Tennis court of Chongqing University. Usually crowded with students playing tennis and other outdoor activities.", 1.1f, 
		"1) Go straight until reaching 4 stone arhitectures, \n2) Turn right\n3) Go straight for 300 meters.\n4) Turn left\n5) Go straight for 200m\n6) On your right hand side.");
	AttractionLeaf basketballCourt(351, 391, 90, 120, 9, "basketballCourt", 
		"Basketball court of Chongqing University. Students of Chongqing university loves basketball. Visitors sometimes play basketball with students here.", 1.2f, 
		"1) Go straight until reaching 4 stone arhitectures, \n2) Turn right\n3) Go straight for 300 meters.\n4) Turn left\n5) Go straight for 200m\n6) Turn right\n7)Go straight 100m\n8) On your right hand side.");
	AttractionLeaf undergraduateDormitory(291, 331, 39, 69, 10, "undergraduateDormitory", 
		"Student dormitory of Chongqing University. There are many dormitories in this campus, but this dormitory mainly accommodate undergraduate Chinese students and is the biggest dormitory in the campus.", 1.4f, 
		"1) Go straight until reaching 4 stone arhitectures, \n2) Turn right\n3) Go straight for 300 meters.\n4) Turn left\n5) Go straight for 500m\n6) On your right hand side.");
	AttractionLeaf firstDiningHall(227, 267, 23, 53, 11, "firstDiningHall", 
		"Biggest dining hall in the campus. Meeting tables, cafe, and places for leisure activities are also in this building.", 1.5f, 
		"1) Go straight until reaching 4 stone arhitectures, \n2) Turn right\n3) Go straight for 300 meters.\n4) Turn left\n5) Go straight for 600m\n6) On your front.");
	AttractionLeaf bigDataAndSoftwareEngineeringBuilding(36, 76, 10, 40, 12, 
		"bigDataAndSoftwareEngineeringBuilding", "Building of software students and professors. Presentations for software students are often held in this buildig.", 1.8f, 
		"1) Go straight until reaching 4 stone arhitectures, \n2) Turn right\n3) Go straight for 300 meters.\n4) Turn left\n5) Go straight for 900m\n6) On your left hand side.");
	
	
	AttractionTree ChongqingTree(12, 540, 360);

	ChongqingTree.addAttraction(&library);
	ChongqingTree.addAttraction(&secondTeachingBuilding);
	ChongqingTree.addAttraction(&garden);
	ChongqingTree.addAttraction(&laboratory);
	ChongqingTree.addAttraction(&soccorField);
	ChongqingTree.addAttraction(&firstTeachingBuilding);
	ChongqingTree.addAttraction(&lake);
	ChongqingTree.addAttraction(&tennisCourt);
	ChongqingTree.addAttraction(&basketballCourt);
	ChongqingTree.addAttraction(&undergraduateDormitory);
	ChongqingTree.addAttraction(&firstDiningHall);	
	ChongqingTree.addAttraction(&bigDataAndSoftwareEngineeringBuilding);	

	AttractionTable ChongqingTable(12, &ChongqingTree);

	AttractionInterface ChongqingInterface(&ChongqingTable);
	
}