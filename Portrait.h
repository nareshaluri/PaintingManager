#ifndef PORTRAIT_H	
#define PORTRAIT_H

#include "Painting.h"
#include "String.h"
#include "PaintingManager.h"

class Portrait : public Painting{
private:
	// To account for the number of people in the painting..
	int no_of_people;
	// String to hold the list of names in the painting(if any)..
	String name_list;
public:
	// Default Constructor..
	Portrait();
	// Parameterized Constructor..
	Portrait(paintingInfo aPainting);
	// Copy Constructor [Deep Copy Implementation]..
	Portrait(const Portrait& inst);
	// Virtual copy method..
	virtual Painting* copy();
	// Destructor..
	~Portrait(); 	 
	// Setter method for No. of people in the painting..
	void setNoOfPeople(int _no_of_people);
	// Getter method for No. of people in the painting..
	int getNoOfPeople();
	// Setter method for list of names in the painting..
	void setNameList(String _name_list);
	// Getter method for list of names in the painting..
	String getNameList();
	// Print painting details..
	void printDetails();
};

#endif