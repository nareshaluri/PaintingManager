#include<iostream>
#include "PaintingManager.h"
#include "LinkedList.h"
#include "Painting.h"
#include "Portrait.h"
#include "Landscape.h"
#include "Stilllife.h"
#include "String.h"

using namespace std;

// Default Constructor..
PaintingManager::PaintingManager(){	
}

// Destructor..
PaintingManager::~PaintingManager(){
	if(artistList.size() != 0){
		for(int index = 0; index < artistList.size(); index++){
			Artist* artistNode = artistList.at(index);
			if(artistNode->getPaintingsList()->getHead() != NULL){
				deleteList(artistNode->getPaintingsList()->getHead());
				artistNode->getPaintingsList()->setHead(NULL);
			}
			delete artistNode->getPaintingsList();
			delete artistNode;			
		}
		artistList.clear();
	}
}

// Method to generate next Unique Painting Id..
int PaintingManager::generateId(){
	static int unique_id = 0;
	return ++unique_id;
}

// Insert a Artist into the Painting Manager..
void PaintingManager::insertArtist(){
	Artist* artistNode = createArtist(getArtistInfo());
	artistList.push_back(artistNode);
}

// Helper method to create Artist node..
Artist* PaintingManager::createArtist(artistInfo aArtist){
	Artist *artistNode = new Artist();
	artistNode->setFirstName(aArtist.fName);
	artistNode->setLastName(aArtist.lName);
	artistNode->setPaintingsList(new LinkedList());
	return artistNode;
}

// Method to get the Artist Information from the user..
artistInfo PaintingManager::getArtistInfo(){	
	artistInfo aArtist;
	cout<<"Enter Artist First Name: ";
	cin>>aArtist.fName;
	cout<<"Enter Artist Last Name: ";
	cin>>aArtist.lName;
	return aArtist;
}

// Checks whether the PaintingManager is empty..
bool PaintingManager::isEmpty(){
	return (artistList.size() == 0);
}

// Add a new Painting to the Painting Manager..
void PaintingManager::addPainting(){
	artistInfo aArtist = getArtistInfo();
	/*if(!isArtistAvailable(aArtist)){
		Artist* artistNode = createArtist(aArtist);
		paintingInfo aPainting = getPaintingInfo();
		aPainting._id = generateId();
		artistNode->setPaintingsList(insertPaintingLinkedList(artistNode->getPaintingsList(), aPainting));
		artistList.push_back(artistNode);
	}*/
	if(isArtistAvailable(aArtist)){
		for(int index = 0; index < artistList.size(); index++){
			Artist* artistNode = artistList.at(index);
			if(artistNode->getFirstName() == aArtist.fName &&
				artistNode->getLastName() == aArtist.lName){
				paintingInfo aPainting = getPaintingInfo();
				aPainting._id = generateId();
				artistNode->setPaintingsList(insertPaintingLinkedList(artistNode->getPaintingsList(), aPainting));
			}
		}
	}
	else{
		cout<<"[Info]: Painting Manager has no Such Artist..!"<<endl;
	}
}

// Helper method to insert a painting in a Linked List..
LinkedList* PaintingManager::insertPaintingLinkedList(LinkedList *ll, paintingInfo aPainting){
	if(ll->getHead() == NULL){
		node *aNode = new node();
		Painting *aPaint;
		if(aPainting._subject == "Portrait")
			aPaint = new Portrait(aPainting);			
		if(aPainting._subject == "Landscape")			
			aPaint = new Landscape(aPainting);			
		if(aPainting._subject == "StillLife")
			aPaint = new Stilllife(aPainting);		
		aNode->aPainting = aPaint;
		aNode->next = NULL;
		ll->setHead(aNode);
		return ll;
	}
	else{
		node *currentNode = ll->getHead();
		while(currentNode->next != NULL)
			currentNode = currentNode->next;
		node *aNode = new node();
		Painting *aPaint;
		if(aPainting._subject == "Portrait")
			aPaint = new Portrait(aPainting);			
		if(aPainting._subject == "Landscape")			
			aPaint = new Landscape(aPainting);			
		if(aPainting._subject == "StillLife")
			aPaint = new Stilllife(aPainting);
		aNode->aPainting = aPaint;
		aNode->next = NULL;
		currentNode->next = aNode;
		return ll;
	}
}

// Method to get the Painting Information from the user..
paintingInfo PaintingManager::getPaintingInfo(){	
	paintingInfo aPainting;
	int subjectOption, invalid;
	cout<<"Enter Painting Title: ";
	cin>>aPainting._title;
	cout<<"Enter Painting Height: ";
	cin>>aPainting.h;
	cout<<"Enter Painting Width: ";
	cin>>aPainting.w;
	do {
		invalid = 0;
		cout<<"Select Painting Subject from below options: ";
		cout<<"\n1. Portrait";
		cout<<"\n2. Landscape";
		cout<<"\n3. Still Life\n";
		cin>>subjectOption;	
		switch(subjectOption){
			case 1:
				aPainting._subject = "Portrait";
				cout<<"Enter the number of people: ";
				cin>>aPainting._no_of_people;
				cout<<"Enter the list of names of people in painting (seprated by commas - without spaces): ";
				cin>>aPainting.name_list;
				aPainting.country = "";
				aPainting._medium = "";
				break;
			case 2:
				aPainting._subject = "Landscape";
				cout<<"Enter the country in which landscape was taken: ";
				cin>>aPainting.country;
				aPainting.name_list = "";
				aPainting._medium = "";
				break;
			case 3:
				int mediumOption, mediumInvalid;
				aPainting._subject = "StillLife";
				aPainting.name_list = "";
				aPainting.country = "";
				do {
					mediumInvalid = 0;
					cout<<"Select Painting medium from below options: ";
					cout<<"\n1. Oil Based";
					cout<<"\n2. Water Colors\n";
					cin>>mediumOption;
					switch(mediumOption){
						case 1:
							aPainting._medium = "Oil_Based";
							break;
						case 2:
							aPainting._medium = "Water_Colors";
							break;
						default:
							cout<<"Invalid Option"<<endl;
							mediumInvalid = 1;
							break;
					}
				} while(mediumInvalid == 1);
				break;
			default:
				cout<<"Invalid Option"<<endl;
				invalid = 1;
				break;
		}
	} while(invalid == 1);
	return aPainting;
}


// Helper method to check whether the artist is available in Painting Manager..
bool PaintingManager::isArtistAvailable(artistInfo aArtist){
	if(isEmpty())
		return false;
	else{
		for(int index = 0; index < artistList.size(); index++){
			Artist* artistNode = artistList.at(index);
			if(artistNode->getFirstName() == aArtist.fName &&
				artistNode->getLastName() == aArtist.lName){
				return true;
			}
		}
		return false;
	}
}

// Display all paintings in the Painting Manager..
void PaintingManager::listPaintings(){
	if(isEmpty())
		cout<<"\n[Info]: The Painting Manager System is empty!";
	else{
		cout<<"\nList of Paintings in Painting Manager System\n";
		for(int index = 0; index < artistList.size(); index++){
			Artist* artistNode = artistList.at(index);
			cout<<"\n[Artist First Name]: "<<artistNode->getFirstName()<<" | [Artist Last Name]: "<<artistNode->getLastName();
			node *currentNode = artistNode->getPaintingsList()->getHead();
			if(currentNode == NULL)
				cout<<"\nNo Paintings are available for this artist..!";
			while(currentNode != NULL){
				currentNode->aPainting->printDetails();
				currentNode = currentNode->next;
			}
			cout<<endl;
		}
	}
}

// Removes a Painting from the collection..
void PaintingManager::removePainting(){
	int paintingId;
	cout<<"\nEnter the Painting Id to be deleted: ";
	cin>>paintingId;
	if(isEmpty())
		cout<<"[Info]: Painting Manager has no Paintings for the given Id..!"<<endl;
	else{
		for(int index = 0; index < artistList.size(); index++){
			Artist* artistNode = artistList.at(index);
			node *currentNode = artistNode->getPaintingsList()->getHead();
			node *previousNode = artistNode->getPaintingsList()->getHead(); 
			while(currentNode != NULL){
				if(currentNode->aPainting->getId() == paintingId){
					if(currentNode == previousNode)
						artistNode->getPaintingsList()->setHead(currentNode->next);
					else
						previousNode->next = currentNode->next;
					delete currentNode->aPainting;
					delete currentNode;
					return;
				}
				previousNode = currentNode;
				currentNode = currentNode->next;
			}
			cout<<endl;
		}
		cout<<"[Info]: Painting Manager has no Painting for the given Id..!"<<endl;
	}
}

// Delete all paintings for the given Artist..
void PaintingManager::deleteByArtistName(){
	artistInfo aArtist = getArtistInfo();
	if(isEmpty())
		cout<<"[Info]: Painting Manager has no Paintings..!"<<endl;
	else{
		for(int index = 0; index < artistList.size(); index++){
			Artist* artistNode = artistList.at(index);
			if(artistNode->getFirstName() == aArtist.fName &&
				artistNode->getLastName() == aArtist.lName){
					if(artistNode->getPaintingsList()->getHead() != NULL){
						deleteList(artistNode->getPaintingsList()->getHead());
						artistNode->getPaintingsList()->setHead(NULL);
						cout<<"[Info]: Paintings for the given Artist Deleted successfully..!"<<endl;
					}
					return;
			}
		}
		cout<<"[Info]: Painting Manager has no Such Artist..!"<<endl;
	}
}

// Helper Method to delete all the paintings in a LinkedList..
void PaintingManager::deleteList(node *aNode){
	if(aNode->next != NULL)
		deleteList(aNode->next);
	delete aNode->aPainting;
	delete aNode;
}

// Clones an Artist..
void PaintingManager::cloneArtist(){
	String new_first_name;
	cout<<"\nEnter the Artist details to be cloned:"<<endl;
	artistInfo aArtist = getArtistInfo();
	cout<<"\nEnter the new Artist First Name: ";
	cin>>new_first_name;
	if(isEmpty())
		cout<<"[Info]: Painting Manager has no Paintings..!"<<endl;
	else{
		for(int index = 0; index < artistList.size(); index++){
			Artist* artistNode = artistList.at(index);
			if(artistNode->getFirstName() == aArtist.fName &&
				artistNode->getLastName() == aArtist.lName){
					aArtist.fName = new_first_name;
					Artist* newArtistNode = replicateArtist(aArtist, artistNode->getPaintingsList());
					artistList.push_back(newArtistNode);
					cout<<"\n[Info]: Artist Cloned Successfully..!"<<endl;
					return;
			}
		}
		cout<<"[Info]: Painting Manager has no Such Artist..!"<<endl;
	}
}

// Helper Method to duplicate an Artist using Virtual Copy Scheme..
Artist* PaintingManager::replicateArtist(artistInfo aArtist, LinkedList* ll){
	Artist* artistNode = createArtist(aArtist);
	if(ll->getHead() != NULL){
		node *currentNode = ll->getHead();
		node *copyCurrentNode = NULL;
		while(currentNode != NULL){
			node *aNode = new node();
			Painting *aPaint = currentNode->aPainting->copy();
			aPaint->setId(generateId());
			aNode->aPainting = aPaint;
			aNode->next = NULL;
			if(copyCurrentNode == NULL){
				artistNode->getPaintingsList()->setHead(aNode);
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
	return artistNode;
}
