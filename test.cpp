#define CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
#include "data.h"
#include "util.h"
#include "linkedlist.h"
using namespace std;

//comment out the first three directives if you are not using Visual Studio .Net
#define CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

void pause();
const int MAX_CHAR = 101;

int main()
{
	//use memory leak detection tool in Visual Studio .Net. 
	//comment it out if you are not using Visual Studio .Net
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);	

	//test constuctor, add and display
	char fileName[] = "data.dat";
	list roster(fileName);
	cout << "\noriginal data set -- ";
	roster.display ();
	
	//test insert, retrieve, and remove
	data winery("Good wine vinyards", "Oregon");
	data temp;
	winery.setYear (1990);
	winery.setRating (5);
	winery.setAcres (43);
	if(!roster.retrieve ("333333333", temp))
		cout << "\nno such data in the list" << endl << endl ;
	else
		cout << "\nthe newly added winery: " << temp << endl;

	if(!roster.remove ("333333333"))
		cout << "\nno such data in the list" << endl << endl;
	else
	{
		cout << "\nafter deletion -- ";
		roster.display ();
	}
	
	
	//test copy constructor
	list rosterCopy(roster);
	cout << "\ncopy of the data set --";
	rosterCopy.display ();

	cout << "\nThank you for testing me!" << endl << endl;

	roster.writeOut(fileName);

	pause();
	return 0;




	/*
	data winery1;
	data winery2("White Rabbit Wines", "Sanoma");
	data winery3(winery2);

	//test the overloaded operator= and <<
	winery1 = winery2;		//create a deep copy since we overload '=' with deep copy logic
	winery2.setYear (4.0f);
	winery2.setRating (1990);
	winery2.setAcres (25);

	
	cout << "winery 1: " << winery1 << endl
		<< "winery 2: " << winery2 << endl 
		<< "winery 3: " << winery3 << endl << endl;
	

	//you should test every function defined in data class here
	char	location[MAX_CHAR];
	winery1.setLocation ("Vienna");
	winery1.getLocation (location);
	cout << "winery 1 location: " << location << endl;

	pause();
	return 0;
	*/
}











/*
	//test the constructors
	
	data winery3(winery2);	//our copy constructor makes winery3 a deep copy of winery2

	
*/

