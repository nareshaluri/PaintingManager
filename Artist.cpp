#include "Artist.h"
#include<iostream>

// Default Constructor..
Artist::Artist(){
	paintingsList = NULL;
}

// Copy Constructor [Deep Copy Implementation]..
Artist::Artist(const Artist& inst){
	first_name = inst.first_name;
	last_name = inst.last_name;
	if(inst.paintingsList->getHead() == NULL)
		paintingsList = new LinkedList();
	else{
		LinkedList *ll = inst.paintingsList;
		paintingsList = new LinkedList(*ll);
	}
}

// Destructor..
Artist::~Artist(){
}

// Setter method for Artist First Name..
void Artist::setFirstName(String firstName){
	first_name = firstName;
}

// Setter method for Artist Last Name..
void Artist::setLastName(String lastName){
	last_name = lastName;
}

// Setter method for pointer to linked list of paintings by the Artist..
void Artist::setPaintingsList(LinkedList *list){
	paintingsList = list;
}

// Getter method for Artist First Name..
String Artist::getFirstName(){
	return first_name;
}

// Getter method for Artist Last Name..
String Artist::getLastName(){
	return last_name;
}

// Getter method for pointer to linked list of paintings by the Artist..
LinkedList* Artist::getPaintingsList(){
	return paintingsList;
}
