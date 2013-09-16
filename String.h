#ifndef STRING_H	
#define STRING_H

#include<iostream>
using namespace std;

class String{
private:
	// Size of the string..
    int size;
    // Char array to hold the string..
	char* str;
public:
    // Default Constructor..
	String();
	// Copy Constructor [Deep Copy Implementation]..
	String(char *charSequence);
	// Copy Constructor [Deep Copy Implementation]..
	String(const String&);
	// Destructor..
	~String();
	// Accessor to string length..
	int length();
	// Returns the character at the specified Index..
	char at(int index);
	// Extraction operator overloaded for String class..
	friend istream& operator>>(istream&, String&);
	// Insertion operator overloaded for String class..
	friend ostream& operator<<(ostream&, const String&);
	// == Operator overloaded to check both the strings has the same content..
	friend bool operator==(const String& aString1, const String& aString2);
	// + Operator overloaded for string concatenation..
	String operator+(const String& aString);
	// = Operator overloaded for deep copy..
	String& operator=(const String&);		
};
 
#endif
