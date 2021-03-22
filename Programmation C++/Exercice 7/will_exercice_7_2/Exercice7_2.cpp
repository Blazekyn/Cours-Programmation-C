#include <iostream>

#include "Donnees.h"

using std::cout;
using std::endl;

int main() {
	double v[] = { 3.2, 4.6, 3.9 };
	Donnees data(v, 3);
	data.ajout(1.7).ajout(9.4);

	cout << data.moyenne() << endl;
	return 0;
}
