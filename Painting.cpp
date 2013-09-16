#include "Painting.h"
#include<iostream>

// Default Constructor..
Painting::Painting(){
	height = 0.0;
	width = 0.0;
	id = 0;
}

// Copy Constructor [Deep Copy Implementation]..
Painting::Painting(const Painting& inst){
	title = inst.title;
	subject = inst.subject;
	height = inst.height;
	width = inst.width;
	id = inst.id;
}

// Destructor..
Painting::~Painting(){
	// String destructor will be called twice to deallocate title & Subject..
}

// Setter method for Painting Title..
void Painting::setTitle(String painting_title){
	title = painting_title;
}

// Setter method for Painting Subject..
void Painting::setSubject(String painting_subject){
	subject = painting_subject;
}

// Setter method for Painting height..
void Painting::setHeight(float h){
	height = h;
}

// Setter method for Painting width..
void Painting::setWidth(float w){
	width = w;
}

// Setter method for Painting Unique Identifier..
void Painting::setId(int painting_id){
	id = painting_id;
}

// Getter method for Painting Title..
String Painting::getTitle(){
	return title;
}

// Getter method for Painting Subject..
String Painting::getSubject(){
	return subject;
}

// Getter method for Painting height..
float Painting::getHeight(){
	return height;
}

// Getter method for Painting width..
float Painting::getWidth(){
	return width;
}

// Getter method for Painting Unique Identifier..
int Painting::getId(){
	return id;
}
