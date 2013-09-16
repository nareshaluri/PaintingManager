#include "Stilllife.h"
#include "Painting.h"
#include "String.h"
#include<iostream>

// Default Constructor..
Stilllife::Stilllife(){
}

// Parameterized Constructor..
Stilllife::Stilllife(paintingInfo aPainting){
	title = aPainting._title;
	subject = aPainting._subject;
	height = aPainting.h;
	width = aPainting.w;
	id = aPainting._id;
	medium = aPainting._medium;
}

// Copy Constructor [Deep Copy Implementation]..
Stilllife::Stilllife(const Stilllife& inst) : Painting(inst){
	medium = inst.medium;
}

// Virtual copy method..
Painting* Stilllife::copy(){
	Stilllife* stillLife = new Stilllife(*this);
	return stillLife;
}

// Destructor..
Stilllife::~Stilllife(){
	// String destructor will be called for Medium..
}

// Setter method for painting medium..
void Stilllife::setMedium(String _medium){
	medium = _medium;
}

// Getter method for painting medium..
String Stilllife::getMedium(){
	return medium;
}

// Print painting details..
void Stilllife::printDetails(){
	cout<<"\n\nTitle: "<<title;
	cout<<"\nSubject: "<<subject;
	cout<<"\nHeight: "<<height;
	cout<<"\nWidth: "<<width;
	cout<<"\nId: "<<id;
	cout<<"\nMedium: "<<medium;
}
