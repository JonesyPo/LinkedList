#include "linkedlist.h"
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

/************************
private:
	node * head;
************************/
list::list() : head(NULL)
{
}

list::list(char * fileName) : head(NULL)
{
	ifstream in;
	data currData;
	char name[100];
	char location[100];
	float year;
	float rating;
	float acres;

	//initialize the list with the records in the file
	in.open(fileName);
	if(!in)
	{
		cerr << "fail to open " << fileName << " for input!" << endl;
		exit(1);
	}

	in.get(name, 100, ';');
	while(!in.eof())
	{
		//read in the attributes of current record
		in.ignore(100, ';');
		in.get(location, 10, ';');
		in.ignore(100, ';');
		in >> year;
		in.ignore(100, ';');
		in >> rating;
		in.ignore(100, ';');
		in >> acres;
		in.ignore(100, '\n');

		//populate current data 
		currData.setName (name);
		currData.setLocation (location);
		currData.setYear (year);
		currData.setRating (rating);
		currData.setAcres (acres);

		//add current data to the list
		insert(currData);

		//start reading in next record 
		in.get(name, 100, ';');
	}
	in.close ();
}

//C Makles copy a list - paramter is thje passed in "aList"
list::list(const list& aList)
{
	if(aList.head == NULL) //or if(!aList.head)
		head = NULL;
	else
	{
		//copy first node
		head = new node;
		assert(head != NULL); //check allocation
		head->item = aList.head->item;

		//copy the rest of the list
		node * destNode = head;				//points to the last node in new list //copies head nose
		node * srcNode = aList.head->next;  //points to node in aList  // sourceNode
		while(srcNode != NULL) //or while (srcNode)
		{
			destNode->next = new node;
			assert(destNode->next != NULL); //check allocation
			destNode = destNode->next;
			destNode->item = srcNode->item;

			srcNode = srcNode->next;
		}
		destNode->next = NULL;
	}		
}

const list& list::operator= (const list& aList)
{
	if(this == &aList)
		return *this;
	else
	{
		//release dynamically allocated memory held by current object
		node * curr = head;
		while(head)
		{
			curr = head->next;
			delete head;
			head = curr;
		}

		//make *this a deep copy of "aList"
		if(!aList.head)
			head = NULL;
		else
		{
			//copy the first node
			head = new node;
			assert(head != NULL);
			head->item = aList.head->item;

			//copy the rest of the list
			node * destNode = head;
			node * srcNode = aList.head->next;

			while(srcNode)
			{
				destNode->next = new node;
				assert(destNode->next);
				destNode = destNode->next;
				destNode->item = srcNode->item;

				srcNode = srcNode->next;
			}
			destNode->next = NULL;
		}

		return *this;
	}
}

list::~list()
{
	node * curr = head;
	while(head)
	{
		curr = head->next;
		delete head;		//the constructor for individual data (item) is invoked
		head = curr;
	} 
}

bool list::insert (const data& aData)
{
	//pointers to traverse the list
	node * prev = NULL;
	//pointer current head of the list
	node * curr = head; 

	
	
	//traverse to find the position to insert
	//ends when your curerent value reaches the position of aData
	// First condition must be satisfied first ":curr!=NULL. DONT SWITCH THESE 
	while (curr!=NULL && curr->item < aData)
	{
		//now previous is current and current is at tjhe next noder
		prev = curr;
		curr = curr->next;
	}

	//the data already exists
	if(curr && curr->item == aData)
		return false;
	//insert the data here
	else
	{
		//create new node to contain the data
		node * newNode = new node;
		newNode->item = aData;
		newNode->next = NULL;

		//link the newNode into the linked list
		newNode->next = curr;
		if(prev == NULL)
			head = newNode;
		else
			prev->next = newNode;
		size++;
		return true;
	}
}

bool list::remove (char * key)
{
	char location[100];

	//search for the data to be removed
	node * prev = NULL;
	node * curr = head;
	while (curr)
	{
		curr->item.getLocation(location);
		if(strcmp(key, location) == 0)
		{
			//remove the data
			if(!prev)
				head = curr->next;
			else
				prev->next = curr->next;
			delete curr;
			size--;
			return true;
		}

		prev = curr;
		curr = curr->next;
	}
	//data is not in the list
	return false;
}

bool list::retrieve (char * key, data & aData)const
{
	//search for the data to be retrieved
	node * curr;
	char location[100];
	for(curr=head; curr; curr=curr->next)
	{
		curr->item.getLocation (location);
		if(strcmp(key, location) == 0)
		{
			aData = curr->item;
			return true;
		}
	}

	//data is not in the list
	return false;
}

void list::display (void)const
{
	node * curr;

	cout << "Data in the list: " << endl << endl;
	for(curr=head; curr; curr=curr->next)
	{
		//we can use << on data object because we overload << in the data class
		cout << '\t' << curr->item << endl;
	}
}

int list::getSize () const
{
	return size;
}
	
void list::writeOut(char * fileName)const
{
	ofstream out;

	out.open(fileName);
	if(!out)
	{
		cerr << "fail to open " << fileName << " for output!" << endl;
		exit(1);
	}

	node * curr;
	char name[100];
	char location[100];
	for(curr=head; curr; curr=curr->next)
	{
		//we can use << on data object because we overload << in the data class
		curr->item .getName (name);
		curr->item .getLocation (location);
		out << name << ';' << location << ';' << curr->item.getYear () << ";" << curr->item.getRating () << ';' << curr->item.getAcres () << '\n';
	}

	out.close ();
}

	








	


