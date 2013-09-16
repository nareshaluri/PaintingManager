#ifndef LANDSCAPE_H	
#define LANDSCAPE_H

#include "Painting.h"
#include "String.h"
#include "PaintingManager.h"

class Landscape : public Painting{
private:
	// String to hold country in which the landscape was taken..
	String country;
public:
	// Default Constructor..
	Landscape();
	// Parameterized Constructor..
	Landscape(paintingInfo aPainting);
	// Copy Constructor [Deep Copy Implementation]..
	Landscape(const Landscape& inst);
	// Virtual copy method..
	virtual Painting* copy();
	// Destructor..
	~Landscape(); 	 
	// Setter method for Painting landscape country..
	void setCountry(String landscape_country);
	// Getter method for Painting landscape country..
	String getCountry();
	// Print painting details..
	void printDetails();
};

#endif
