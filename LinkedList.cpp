#include "LinkedList.h"
#include "PaintingManager.h"
#include<iostream>

// Default Constructor..
LinkedList::LinkedList(){
	head = NULL;
}

// Copy Constructor [Deep Copy Implementation]..
LinkedList::LinkedList(const LinkedList& inst){	
	if(inst.head == NULL)
		head == NULL;
	else{
		node *currentNode = inst.head;
		node *copyCurrentNode = NULL;
		while(currentNode != NULL){
			node *aNode = new node();
			Painting *aPaint = currentNode->aPainting->copy();
			aNode->aPainting = aPaint;
			aNode->next = NULL;
			if(copyCurrentNode == NULL){
				head = aNode;
				copyCurrentNode = aNode;
			}
			else{
				copyCurrentNode->next = aNode;
				copyCurrentNode = copyCurrentNode->next;
			}
			currentNode->aPainting;
			currentNode = currentNode->next;
		}
	}
}

// Destructor..
LinkedList::~LinkedList(){
	if(head != NULL)
		deleteList(head);
}

// Setter method for ll head..
void LinkedList::setHead(node *aNode){
	head = aNode;
}

// Getter method for ll head..
node* LinkedList::getHead(){
	return head;
}

// Helper Method to delete all the paintings in a LinkedList..
void LinkedList::deleteList(node *aNode){
	if(aNode->next != NULL)
		deleteList(aNode->next);
	delete aNode->aPainting;
	delete aNode;
}
