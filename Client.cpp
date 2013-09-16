#include "PaintingManager.h"

//Client Code..

int main(){
	PaintingManager aPM;
	char menu_selection;
	do {
        // Command line options for Painting Manager System..
		cout<<"\nPainting Manager System"<<endl;
		cout<<"List of Commands"<<endl;
		cout<<"a - Add a new Artist"<<endl;
		cout<<"p - Add a new Painting"<<endl;
		cout<<"r - Remove a Painting"<<endl;
		cout<<"d - Delete Paintings by an Artist"<<endl;
		cout<<"l - List all Paintings"<<endl;		
		cout<<"c - Clones an Artist"<<endl;
		cout<<"q - Quits Painting Manager"<<endl;
		cout<<"Enter an Option:";
		cin>>menu_selection;
		switch(menu_selection){
		case 'a':
			aPM.insertArtist();
			break;
		case 'p':
			aPM.addPainting();
			break;
		case 'r':
			aPM.removePainting();
			break;
		case 'd':
			aPM.deleteByArtistName();
			break;
		case 'l':
			aPM.listPaintings();
			break;
		case 'c':
			aPM.cloneArtist();
			break;
		case 'q':
			break;
		default:
			cout<<"Invalid Option"<<endl;
			break;
		}
	} while(menu_selection != 'q');
	system("PAUSE");
	return EXIT_SUCCESS;
}
