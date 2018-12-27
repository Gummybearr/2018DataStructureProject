#ifndef _ATTRACTIONTREE_H_
#define _ATTRACTIONTREE_H_

#include "AttractionLeaf.h"

class AttractionTree: public AttractionLeaf {
private:
	int height;
	AttractionTree* sub1;
	AttractionTree* sub2;
	AttractionTree* sub3;
	bool isLeaf;
	bool leafOccupied;
	void divideArea(int height, int divisionNum);

public:
	AttractionTree(int totalAttractions, int xmax, int ymax);
	AttractionTree(int h, int xmin, int xmax, int ymin, int ymax);
	AttractionTree* getSub1();
	AttractionTree* getSub2();
	AttractionTree* getSub3();
	bool getIsLeaf();
	bool getLeafOccupied();
	AttractionTree* getAttractionPoint(int x, int y);
	void addAttraction(AttractionLeaf* item);
};

#endif