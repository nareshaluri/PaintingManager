#include "String.h"
#include<iostream>

using namespace std;

// Default Constructor..
String::String(){
	size = 0;
	str = NULL;
}

// Copy Constructor [Deep Copy Implementation]..
String::String(char* charSeq){
	size = strlen(charSeq);
	str = new char[strlen(charSeq) + 1];
	strcpy(str, charSeq);
}

// Copy Constructor [Deep Copy Implementation]..
String::String(const String& aString){
	size = aString.size;
	str = new char[aString.size + 1];
	strcpy(str, aString.str);
}

// Destructor..
String::~String(){
	if(length() > 0)
		delete[] str;
}

// Accessor to string length..
int String::length(){
	return size;
}

// Returns the character at the specified Index..
char String::at(int index){
	return str[index];
}

// Extraction operator overloaded for String class..
istream& operator>> (istream& in, String& aString){
	char* temp = new char[100];
	in >> temp;
	aString.str = temp;
	aString.size = strlen(temp);	
	return in;
} 

// Insertion operator overloaded for String class..
ostream& operator<< (ostream& out, const String& aString){
	out << aString.str;
	return out;
}

// = Operator overloaded for deep copy..
String& String::operator=(const String& aString){
   if (str != 0)
      delete [] str;
   size = aString.size;
   str = new char[size + 1];
   strcpy(str, aString.str);
   return *this;
}

// == Operator overloaded to check both the strings has the same content..
bool operator==(const String& aString1, const String& aString2){
   if (aString1.size != aString2.size)
      return false;
   else{
      for (int index = 0 ; index < aString1.size; index++){
         if (aString1.str[index] != aString2.str[index])
	        return false;
	  }
   }
  return true;
}

// + Operator overloaded for string concatenation..
String String::operator+(const String& aString){
	String resultString;
	if (size == 0 && aString.size == 0)
		return resultString;
	else{
		int index;
	    resultString.size = size + aString.size;
		resultString.str = new char[resultString.size + 1];
		for (index = 0; index < size ; index++)
			resultString.str[index] = str[index];
		int j = 0;
		while (j < aString.size){
			resultString.str[index] = aString.str[j];
			index++;
			j++;
		}
		resultString.str[index] = '\0';
   }
   return resultString;
}
