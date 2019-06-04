#include <iostream>
#include <iomanip>
#include <string>
#include "Snow.h"
using namespace std;

const int SIZE = 7;

int main() {
	int date, start, end;
	string month;
	double base;

	// Prompt user to input name of month and starting & ending date of the 7-day period
	cout << "Snow Report Program\n" << endl;
	cout << "Enter the 7-day period being measured.\n";
	cout << "Name of the month: ";
	cin >> month;
	do {
		cout << "Starting date: ";
		cin >> start;
		cout << "Ending date: ";
		cin >> end;

		if ((start < 1) || (end > 31))					// Validate date entries
			cout << "Invalid date entry. Please enter a valid 7-day period.\n";
		else {
			if ((end - start) < 6)
				cout << "Period is too short. Please enter a 7-day period.\n";
			else if ((end - start) > 6)
				cout << "Period is too long. Please enter a 7-day period.\n";
		}
	} while (((end - start) != 6) || ((start < 1) || (end > 31)));	// Period must be 7 days long

	cout << "\nYou entered: " << month << " " << start << "-" << end << endl;

	Snow snow[SIZE];					// Define array of snow objects
	date = start;

	// Prompt user to input 7 base snow depths and store in array
	cout << "Enter the base snow depths.\n";
	//cout << "Date" << "\t" << "Base\n";
	for (int i = 0; i < SIZE; i++) {	
		snow[i].setDate(date);			// Store dates in array
		cout << month << " " << date << ": ";
		cin >> base;
		snow[i].setBase(base);			// Store base snow depths in array
		date++;
	}

	Snow report;
	report.selectionSort(snow, SIZE);	// Sort data by base snow depth

	// Print report
	cout << "\nSnow Report " << month << " " << start << "-" << end << endl;;
	cout << "Date" << "\t" << "Base\n";
	report.displayResults(snow, SIZE);

	system("pause");
	return 0;
}