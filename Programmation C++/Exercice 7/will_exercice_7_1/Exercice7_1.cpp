// Exercice7_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Donnees.h"

using std::cout;
using std::endl;

int main() {
	const double v[] = { 3.2, 4.6, 2.9 };
	const Donnees data(v, 3);
	cout << data.moyenne() << endl;
	return 0;
}

