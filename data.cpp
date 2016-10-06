#include "data.h"
#include <iostream>
#include <iomanip>
using namespace std;
/*************************
private:
	char * name;
	char * location;
	float year;
	float rating;
	float acres;
*************************/
data::data() :name(NULL), location(NULL), year(0), rating(0), acres(0)
{
	/*
	name = NULL;
	location = NULL;
	year = 0;
	rating = 0;
	acres = 0;
	*/
}

data::data(const char * name, const char * location):name(NULL), location(NULL), year(0), rating(0), acres(0)
{
	setName(name);
	setLocation(location);
}

data::data(const data& winery):name(NULL), location(NULL)
{
	setName(winery.name);
	setLocation(winery.location);
	setYear(winery.year);
	setRating(winery.rating);
	setAcres(winery.acres);
}

const data& data::operator=(const data& winery)
{
	//if it is a self copy, don't do anything
	if(this == &winery)
		return *this;
	//make current object *this a copy of the passed in winery
	else
	{
		setName(winery.name);
		setLocation(winery.location);
		setYear(winery.year);
		setRating(winery.rating);
		setAcres(winery.acres);
		return *this;
	}
}

data::~data()
{
	if(name)
		delete [] name;
	if(location)
		delete [] location;
}

void data::getName (char * name)const
{
	strcpy(name, this->name);
}

void data::getLocation (char * location)const
{
	strcpy(location, this->location);
}

float data::getYear (void) const
{
	return year;
}

float data::getRating (void) const
{
	return rating;
}

float data::getAcres (void) const
{
	return acres;
}

void data::setName (const char * name)
{
	//release the exisisting memory if there is any
	if(this->name)
		delete [] this->name;

	//set new name
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);
}

void data::setLocation (const char * location)
{
	//release the exisisting memory if there is any
	if(this->location)
		delete [] this->location;

	//set new location
	this->location = new char[strlen(location)+1];
	strcpy(this->location, location);
}

void data::setYear (float year)
{
	this->year = year;
}

void data::setRating (float rating)
{
	this->rating = rating;
}

void data::setAcres (float acres)
{
	this->acres = acres;
}


bool operator< (const data& d1, const data& d2)
{
	char name1[100];
	char name2[100];

	d1.getName (name1);
	d2.getName (name2);

	if(strcmp(name1, name2) < 0)
		return true;
	else
		return false;
}

bool operator== (const data& d1, const data& d2)
{
	char location1[100];
	char location2[100];

	d1.getLocation (location1);
	d2.getLocation (location2);

	if(strcmp(location1, location2) == 0)
		return true;
	else
		return false;
}


ostream& operator<< (ostream& out, const data& winery)
{
	out << setw(20) << winery.name << setw(15) << winery.location << setw(5) << winery.year << setw(5) << winery.rating << setw(5) << winery.acres;
	return out;
}
