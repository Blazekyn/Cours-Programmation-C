// Programme principal : teste la classe Rationnel
#include <iostream>
#include <conio.h>

#include "Rationnel.h"

using std::cout;



int main() {
	Rationnel r1(1, 2),
		r2(3, 4),
		r3(5, 6),
		r4;
	
	// Tester l'addition
	cout << "\nAddition : ";r4 = r1 + r2 + r3; cout << (r4 == Rationnel(25, 12) ? "Ok " : "Fail "); // Ok
	r4 = 1 + r1; cout << (r4 == Rationnel(3, 2) ? "Ok " : "Fail "); // Fail
	r4 = r1 + 1; cout << (r4 == Rationnel(3, 2) ? "Ok " : "Fail "); // Ok
	
	//// Tester la soustration
	cout << "\nSoustraction : ";
	r4 = r3 - r2 - r1; cout << (r4 == Rationnel(-5, 12) ? "Ok " : "Fail ");
	r4 = 1 - r1; cout << (r4 == Rationnel(1, 2) ? "Ok " : "Fail ");
	r4 = r1 - 1; cout << (r4 == Rationnel(-1, 2) ? "Ok " : "Fail ");
	
	//// Tester la multiplication
	cout << "\nMultiplication : ";
	r4 = r3 * r2 * r1; cout << (r4 == Rationnel(5, 16) ? "Ok " : "Fail ");
	r4 = 2 * r1; cout << (r4 == Rationnel(1, 1) ? "Ok " : "Fail ");
	r4 = r1 * 2; cout << (r4 == Rationnel(2, 2) ? "Ok " : "Fail ");
	
	//// Tester la division
	cout << "\nDivision : ";
	r4 = r3 / r2 / r1; cout << (r4 == Rationnel(40, 18) ? "Ok " : "Fail ");
	r4 = 2 / r1; cout << (r4 == Rationnel(4, 1) ? "Ok " : "Fail ");
	r4 = r1 / 2; cout << (r4 == Rationnel(1, 4) ? "Ok " : "Fail ");
	
	//// Opérateurs relationnels
	cout << "\n\n== : ";
	cout << (Rationnel(1, 2) == Rationnel(1, 2) ? "Ok " : "Fail ");
	cout << (Rationnel(2, 2) == 1 ? "Ok " : "Fail ");
	cout << (2 == Rationnel(4, 2) ? "Ok " : "Fail ");
	cout << (Rationnel(1, 2) == Rationnel(3, 2) ? "Fail " : "Ok ");
	cout << (Rationnel(2, 2) == 2 ? "Fail " : "Ok ");
	cout << (2 == Rationnel(5, 2) ? "Fail " : "Ok ");
	
	cout << "\n!= : ";
	cout << (Rationnel(1, 3) != Rationnel(1, 2) ? "Ok " : "Fail ");
	cout << (Rationnel(1, 2) != 1 ? "Ok " : "Fail ");
	cout << (2 != Rationnel(5, 2) ? "Ok " : "Fail ");
	cout << (Rationnel(1, 3) != Rationnel(1, 3) ? "Fail " : "Ok ");
	cout << (Rationnel(2, 2) != 1 ? "Fail " : "Ok ");
	cout << (2 != Rationnel(4, 2) ? "Fail " : "Ok ");

	
	cout << "\n< : ";
	cout << (Rationnel(1, 3) < Rationnel(1, 2) ? "Ok " : "Fail ");
	cout << (Rationnel(1, 2) < 1 ? "Ok " : "Fail ");
	cout << (2 < Rationnel(5, 2) ? "Ok " : "Fail ");
	cout << (Rationnel(1, 2) < Rationnel(1, 2) ? "Fail " : "Ok ");
	cout << (Rationnel(3, 2) < 1 ? "Fail " : "Ok ");
	cout << (2 < Rationnel(1, 2) ? "Fail " : "Ok ");
	
	cout << "\n<= : ";
	cout << (Rationnel(1, 3) <= Rationnel(1, 3) ? "Ok " : "Fail ");
	cout << (Rationnel(1, 2) <= 1 ? "Ok " : "Fail ");
	cout << (2 <= Rationnel(4, 2) ? "Ok " : "Fail ");
	cout << (Rationnel(1, 2) <= Rationnel(1, 3) ? "Fail " : "Ok ");
	cout << (Rationnel(3, 2) <= 1 ? "Fail " : "Ok ");
	cout << (2 <= Rationnel(1, 2) ? "Fail " : "Ok ");
	
	cout << "\n> : ";
	cout << (Rationnel(1, 2) > Rationnel(1, 3) ? "Ok " : "Fail ");
	cout << (1 > Rationnel(1, 2) ? "Ok " : "Fail ");
	cout << (Rationnel(5, 2) > 2 ? "Ok " : "Fail ");
	cout << (Rationnel(1, 2) > Rationnel(1, 2) ? "Fail " : "Ok ");
	cout << (1 > Rationnel(3, 2) ? "Fail " : "Ok ");
	cout << (Rationnel(1, 2) > 2 ? "Fail " : "Ok ");
	
	cout << "\n>= : ";
	cout << (Rationnel(1, 3) >= Rationnel(1, 3) ? "Ok " : "Fail ");
	cout << (1 >= Rationnel(1, 2) ? "Ok " : "Fail ");
	cout << (Rationnel(4, 2) >= 2 ? "Ok " : "Fail ");
	cout << (Rationnel(1, 3) >= Rationnel(1, 2) ? "Fail " : "Ok ");
	cout << (1 >= Rationnel(3, 2) ? "Fail " : "Ok ");
	cout << (Rationnel(1, 2) >= 2 ? "Fail " : "Ok ");
	
	//// Opérateurs d'affectation
	cout << "\n\n= : ";
	r4 = Rationnel(1, 2); cout << (r4 == Rationnel(1, 2) ? "Ok " : "Fail ");
	r4 = 2; cout << (r4 == Rationnel(4, 2) ? "Ok " : "Fail ");
	
	cout << "\n+= : ";
	r4 += Rationnel(1, 2); cout << (r4 == Rationnel(5, 2) ? "Ok " : "Fail ");
	r4 += 2; cout << (r4 == Rationnel(9, 2) ? "Ok " : "Fail ");
	
	cout << "\n-= : ";
	r4 -= Rationnel(1, 2); cout << (r4 == Rationnel(8, 2) ? "Ok " : "Fail ");r4 -= 2; cout << (r4 == Rationnel(4, 2) ? "Ok " : "Fail ");
	
	cout << "\n*= : ";
	r4 *= Rationnel(1, 2); cout << (r4 == Rationnel(2, 2) ? "Ok " : "Fail ");
	r4 *= 2; cout << (r4 == Rationnel(4, 2) ? "Ok " : "Fail ");
	
	cout << "\n/= : ";
	r4 /= Rationnel(1, 2); cout << (r4 == Rationnel(8, 2) ? "Ok " : "Fail ");
	r4 /= 2; cout << (r4 == Rationnel(4, 2) ? "Ok " : "Fail ");
	
	//// Opérateurs d'incrémentation et décrémentation
	cout << "\n\n++ : ";
	r4 = Rationnel(1, 2);
	cout << (r4++ == Rationnel(1, 2) && r4 == Rationnel(3, 2) ? "Ok " : "Fail ");
	r4 = Rationnel(1, 2);
	cout << (++r4 == Rationnel(3, 2) && r4 == Rationnel(3, 2) ? "Ok " : "Fail ");
	
	cout << "\n-- : ";
	r4 = Rationnel(3, 2);
	cout << (r4-- == Rationnel(3, 2) && r4 == Rationnel(1, 2) ? "Ok " : "Fail ");
	r4 = Rationnel(3, 2);
	cout << (--r4 == Rationnel(1, 2) && r4 == Rationnel(1, 2) ? "Ok " : "Fail ");
	
	// Attendre confirmation pour fermer la console
	std::cout << "\n\nPressez une touche pour terminer..." << std::endl;
	_getch();
	return 0;
}

