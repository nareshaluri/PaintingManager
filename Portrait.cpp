#include "Portrait.h"
#include "Painting.h"
#include "String.h"
#include<iostream>

// Default Constructor..
Portrait::Portrait(){
	no_of_people = 0;
}

// Parameterized Constructor..
Portrait::Portrait(paintingInfo aPainting){
	title = aPainting._title;
	subject = aPainting._subject;
	height = aPainting.h;
	width = aPainting.w;
	id = aPainting._id;
	no_of_people = aPainting._no_of_people;
	name_list = aPainting.name_list;
}

// Copy Constructor [Deep Copy Implementation]..
Portrait::Portrait(const Portrait& inst) : Painting(inst){
	no_of_people = inst.no_of_people;
	name_list = inst.name_list;
}

// Virtual copy method..
Painting* Portrait::copy(){
	Portrait* portrait = new Portrait(*this);
	return portrait;
}

// Destructor..
Portrait::~Portrait(){
	// String destructor will be called for name list..
}

// Setter method for No. of people in the painting..
void Portrait::setNoOfPeople(int _no_of_people){
	no_of_people = _no_of_people;
}

// Getter method for No. of people in the painting..
int Portrait::getNoOfPeople(){
	return no_of_people;
}

// Setter method for list of names in the painting..
void Portrait::setNameList(String _name_list){
	name_list = _name_list;
}

// Getter method for list of names in the painting..
String Portrait::getNameList(){
	return name_list;
}

// Print painting details..
void Portrait::printDetails(){
	cout<<"\n\nTitle: "<<title;
	cout<<"\nSubject: "<<subject;
	cout<<"\nHeight: "<<height;
	cout<<"\nWidth: "<<width;
	cout<<"\nId: "<<id;
	cout<<"\nNo. Of People: "<<no_of_people;
	cout<<"\nName List: "<<name_list;
}