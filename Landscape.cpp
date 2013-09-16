#include "Landscape.h"
#include "Painting.h"
#include<iostream>

// Default Constructor..
Landscape::Landscape(){
}

// Parameterized Constructor..
Landscape::Landscape(paintingInfo aPainting){
	title = aPainting._title;
	subject = aPainting._subject;
	height = aPainting.h;
	width = aPainting.w;
	id = aPainting._id;
	country = aPainting.country;
}

// Copy Constructor [Deep Copy Implementation]..
Landscape::Landscape(const Landscape& inst) : Painting(inst){
	country = inst.country;
}

// Virtual copy method..
Painting* Landscape::copy(){
	Landscape* lScape = new Landscape(*this);
	return lScape;
}

// Destructor..
Landscape::~Landscape(){
	// String destructor will be called for Country..
}

// Setter method for Painting landscape country..
void Landscape::setCountry(String landscape_country){
	country = landscape_country;
}

// Getter method for Painting landscape country..
String Landscape::getCountry(){
	return country;
}

// Print painting details..
void Landscape::printDetails(){
	cout<<"\n\nTitle: "<<title;
	cout<<"\nSubject: "<<subject;
	cout<<"\nHeight: "<<height;
	cout<<"\nWidth: "<<width;
	cout<<"\nId: "<<id;
	cout<<"\nCountry: "<<country;
}
