#ifndef PAINTING_MANAGER_H	
#define PAINTING_MANAGER_H

#include "Artist.h"
#include "LinkedList.h"
#include <vector>

using namespace std;

// Structure to hold the Artist details entered by the user..
struct artistInfo{
	String fName;
	String lName;
};

// Structure to hold the Painting details entered by the user..
struct paintingInfo{
	String _title;
	String _subject;
	int _id;
	float h;
	float w;
	int _no_of_people;
	String name_list;
	String country;
	String _medium;
};

class PaintingManager{	
private:
    // Vector to hold the list of Artist details and their correspodning Paintings..
	vector<Artist*> artistList;
	// Checks whether the PaintingManager is empty..
	bool isEmpty();
	// Method to get the Artist Information from the user..
	artistInfo getArtistInfo();
	// Helper method to create Artist node..
	Artist* createArtist(artistInfo aArtist);
	// Helper method to check whether the artist is available in Painting Manager..
	bool isArtistAvailable(artistInfo aArtist);
	// Method to get the Painting Information from the user..
	paintingInfo getPaintingInfo();
	// Helper method to insert a painting in a Linked List..
	LinkedList* insertPaintingLinkedList(LinkedList *ll, paintingInfo aPainting);
	// Helper Method to delete all the paintings in a LinkedList..
	void deleteList(node *aNode);
	// Helper Method to duplicate an Artist using Virtual Copy Scheme..
	Artist* replicateArtist(artistInfo aArtist, LinkedList* ll);
public:
    // Default Constructor..       
	PaintingManager();
	// Copy Constructor [Deep Copy Implementation]..
	PaintingManager(const PaintingManager& pm);
	// Destructor..
	~PaintingManager();
	// Method to generate next Unique Painting Id..
	int generateId();
	// Insert a Artist into the Painting Manager..
	void insertArtist();
	// Add a new Painting to the Painting Manager..
	void addPainting();
	// Removes a Painting from the collection..
	void removePainting();
	// Delete all paintings for the given Artist..
	void deleteByArtistName();
	// Display all paintings in the Painting Manager..
	void listPaintings();
	// Clones an Artist..
	void cloneArtist();	
};

#endif
