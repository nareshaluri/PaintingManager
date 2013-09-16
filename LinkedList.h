#ifndef LINKED_LIST_H	
#define LINKED_LIST_H
#include "String.h"
#include "Painting.h"

// LinkedList nodes to hold the paintings of the Artist..
struct node{
	Painting* aPainting;
	node* next;
};
 
class LinkedList{
private:
	node* head;
	// Helper Method to delete all the paintings in a LinkedList..
	void LinkedList::deleteList(node *aNode);
public:
    // Default Constructor..
	LinkedList();
	// Copy Constructor [Deep Copy Implementation]..
	LinkedList(const LinkedList& inst);
	// Destructor..
	~LinkedList();	
	// Setter method for ll head..
	void setHead(node *aNode);
	// Getter method for ll head..
	node* getHead();
};

#endif
