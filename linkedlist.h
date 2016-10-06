#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "data.h"

class list
{
public:
	//dewfault construcrto
	list();
		//constructor to load data and populate list
	list(char * fileName);
	//copy constructor
	list(const list& aList);
	//Destructor need it to dealocate Nodes when list is done
	~list();

	//Overload assignment operator to make a deep copy of the list
	const list& operator= (const list& aList);

	//insetrs according to value of aData
	bool insert(const data& aData);
	
	//Removesd object with a key
	bool remove(char * key);
	//giuve key and I will give you back the data with the key
	bool retrieve(char * key, data& aData)const;
	void display(void)const;
	int getSize()const;
	void writeOut(char * fileName)const;

private:
	//linera single linked list.. for doubly threded you need two next pointer
	struct node
	{
		data item;
		//pointer to next node
		node * next;
	};
	//Keep track of head pointer not a node just a pointer to first node
	node * head;
	//Size of the list
	int size;
};
#endif