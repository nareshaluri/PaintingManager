#ifndef PAINTING_H	
#define PAINTING_H

#include "String.h"
  
class Painting{
public:
    // String to hold title of the painting..
	String title;
	// String to hold subject of the painting..
	String subject;
	// Height variable to hold the painting height..
	float height;
	// Width variable to hold the painting width..
	float width;
	// A unique Identifier for the painting..
	int id;
protected:
	 // Default Constructor..
	Painting();
	// Copy Constructor [Deep Copy Implementation]..
	Painting(const Painting& inst);
public:
	// Destructor..
	virtual ~Painting();  
    // Setter method for Painting Title..
	void setTitle(String painting_title);
	// Setter method for Painting Subject..
	void setSubject(String painting_subject);
	// Setter method for Painting height..
	void setHeight(float h);
	// Setter method for Painting width..
	void setWidth(float w);
	// Setter method for Painting Unique Identifier..
	void setId(int painting_id);

	// Getter method for Painting Title..
	String getTitle();
	// Getter method for Painting Subject..
	String getSubject();	
	// Getter method for Painting height..
	float getHeight();
	// Getter method for Painting width..
	float getWidth();
	// Getter method for Painting Unique Identifier..
	int getId();
	// A Pure Virtual Function to have an Abstract Painting class..
	virtual Painting* copy() = 0;
	// A Pure Virtual Function to have an Abstract Painting class..
	virtual void printDetails() = 0;	
};
 
#endif
