#ifndef _ATTRACTIONINTERFACE_H_
#define _ATTRACTIONINTERFACE_H_

#include "AttractionTable.h"

class AttractionInterface{
public:
	AttractionInterface(AttractionTable* table);
	int number;
};

#endif