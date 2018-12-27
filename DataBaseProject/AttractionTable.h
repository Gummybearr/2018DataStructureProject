#ifndef _ATTRACTIONTABLE_H_
#define _ATTRACTIONTABLE_H_

#include "AttractionTree.h"

class AttractionTable {
private:
	int itemNum;
	int itemCount;
	AttractionTree** tableForNumSearch;
	void initHelp(AttractionTree* root);
	AttractionTree* addressConverter(int attractionNum);
public:
	AttractionTable(int itemnum, AttractionTree* root);
	void searchNum(int n);
};

#endif