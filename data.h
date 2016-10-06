#ifndef DATA_H
#define DATA_H
#include <iostream>
using namespace std;

class data //User defined classes should start with capital letter
{
public:
	
	data();
	data(const char * name, const char * location);
	data(const data& winery);		//copy constructor: make current object a copy of "student"
	~data();						//destructor: release the dynamically allocated memory	

	void getName(char * name) const;
	void getLocation(char * location) const;
	float getYear(void) const;
	float getRating(void) const;
	float getAcres(void) const;

	void setName(const char * name);
	void setLocation(const char * location);
	void setYear(float year);
	void setRating(float rating);
	void setAcres(float acres);

	friend ostream& operator<< (ostream& out, const data& winery);
	const data& operator=(const data& winery);	//overload assignment operator

private:
	char * name;
	char * location;
	float year;
	float rating;
	float acres;
};

bool operator< (const data& d1, const data& d2);	//overload < on data objects
bool operator== (const data& d1, const data& d2);	//overload == on data objects

#endif