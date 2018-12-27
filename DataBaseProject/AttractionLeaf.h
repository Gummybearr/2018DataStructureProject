#ifndef _ATTRACTIONLEAF_H_
#define _ATTRACTIONLEAF_H_

#include <iostream>
#include <string>
using namespace std;

class AttractionLeaf {
private:
	int xMin;      int xMax;      int yMin;         int yMax;            int Num;
	string Name;   string Info;   float Distance;   string Navigator;

public:
	AttractionLeaf();
	AttractionLeaf(int xmin, int xmax, int ymin, int ymax, int num, string name, 
		string info, float distance, string navigator);
	void setxBoundary(int xmin, int xmax);
	void setyBoundary(int ymin, int ymax);
	void setNum(int num);
	void setName(string name);
	void setInfo(string info);
	void setDistance(float distance);
	void setNavigator(string navigator);

	int getxMin();         int getxMax();           int getyMin();      
	int getyMax();         int getNum();
	string getName();      string getInfo();   
	float getDistance();   string getNavigator();
};

#endif