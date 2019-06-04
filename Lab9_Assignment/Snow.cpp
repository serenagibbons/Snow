#include "Snow.h"

Snow::Snow() {		// Default constructor
	dt = 0;
	bs = 0;
}

void Snow::setDate(int date) {
	dt = date;
}

void Snow::setBase(double base) {
	bs = base;
}

int Snow::getDate() {
	return dt;
}

double Snow::getBase() {
	return bs;
}

void Snow::selectionSort(Snow a[], int size) {		// Sort data by base snow depth
	int outer, inner, min;
	for (outer = 0; outer < size - 1; outer++) {
		min = outer;
		for (inner = outer + 1; inner < size; inner++) {
			if (a[inner].getBase() < a[min].getBase()) {
				min = inner;
			}
		}
		double tempB = a[outer].getBase();
		double tempD = a[outer].getDate();
		a[outer].setBase(a[min].getBase());		
		a[outer].setDate(a[min].getDate());		
		a[min].setBase(tempB);
		a[min].setDate(tempD);
	}
}

void Snow::displayResults(Snow a[], int size) {
	for (int i = 0; i < size; i++) {
		cout << a[i].getDate() << "\t";
		cout << fixed << showpoint << setprecision(1) << a[i].getBase() << endl;
	}
}
