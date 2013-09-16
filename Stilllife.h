#ifndef STILLLIFE_H	
#define STILLLIFE_H

#include "Painting.h"
#include "String.h"
#include "PaintingManager.h"

class Stilllife : public Painting{
private:
	// String to hold the painting medium..
	String medium;
public:
	// Default Constructor..
	Stilllife();
	// Parameterized Constructor..
	Stilllife(paintingInfo aPainting);
	// Copy Constructor [Deep Copy Implementation]..
	Stilllife(const Stilllife& inst);
	// Virtual copy method..
	virtual Painting* copy();
	// Destructor..
	~Stilllife(); 	
	// Setter method for painting medium..
	void setMedium(String _medium);
	// Getter method for painting medium..
	String getMedium();
	// Print painting details..
	void printDetails();
};

#endif