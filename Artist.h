#ifndef ARTIST_H	
#define ARTIST_H

#include "LinkedList.h"
#include "String.h"

class Artist{
private:
	// String to hold Artist First Name..
	String first_name;
	// String to hold Artist Last Name..
	String last_name;
	// Pointer to the Linked List of paintings by the artist..
	LinkedList* paintingsList;
public:
	// Default Constructor..
	Artist();
	// Copy Constructor [Deep Copy Implementation]..
	Artist(const Artist& inst);
	// Destructor..
	~Artist();  

	// Setter method for Artist First Name..
	void setFirstName(String firstName);
	// Setter method for Artist Last Name..
	void setLastName(String lastName);
	// Setter method for pointer to linked list of paintings by the Artist..
	void setPaintingsList(LinkedList *list);

	// Getter method for Artist First Name..
	String getFirstName();
	// Getter method for Artist Last Name..
	String getLastName();
	// Getter method for pointer to linked list of paintings by the Artist..
	LinkedList* getPaintingsList();
};

#endif
