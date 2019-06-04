#ifndef SNOW_H
#define SNOW_H

#include <iostream>
#include <iomanip>
using namespace std;

class Snow {

private:
	int dt;
	double bs;

public:
	Snow();										// Default Constructor
	void setDate(int date);
	void setBase(double base);
	int getDate();
	double getBase();
	void selectionSort(Snow a[], int size);		// Sort data by base snow depth
	void displayResults(Snow a[], int size);	// Print snow report information

};

#endif // !SNOW_H
