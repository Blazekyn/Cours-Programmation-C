/*============================================================================
Programmeur : William Poncelet
Fichier     : Rationnel.h
Description : Déclaration de la classe Rationnel
=============================================================================*/

#ifndef RATIONNEL_H
#define RATIONNEL_H

#include <iostream>

using std::istream;
using std::ostream;

// Classe représentant une fraction.
class Rationnel {
	
	// Surcharge des opérateurs de flux
	friend istream& operator>>(istream&, Rationnel&);				// flux d'entrées
	friend ostream& operator<<(ostream&, const Rationnel&);			// flux de sorties

public:
	
	// Constructeur par défaut
	Rationnel(int = 1, int = 1);										

	// Surcharge des opérateurs arithmétiques
	Rationnel operator+(const Rationnel&) const;					// Rationnel + Rationnel
	Rationnel operator+(const int) const;							// Rationnel + int
	friend Rationnel operator+(const int, const Rationnel&);		// int + Rationnel

	Rationnel operator-(const Rationnel&) const;					// Rationnel - Rationnel
	Rationnel operator-(const int) const;							// Rationnel - int
	friend Rationnel operator-(const int, const Rationnel&);		// int - Rationnel

	Rationnel operator*(const Rationnel&) const;					// Rationnel * Rationnel
	Rationnel operator*(const int) const;							// Rationnel * int
	friend Rationnel operator*(const int, const Rationnel&);		// int * Rationnel

	Rationnel operator/(const Rationnel&) const;					// Rationnel / Rationnel
		Rationnel operator/(const int) const;						// Rationnel / int
	friend Rationnel operator/(const int, const Rationnel&);		// int / Rationnel

	// Surcharge des opérateurs relationnels
	bool operator==(const Rationnel&) const;						// Rationnel == Rationnel
	bool operator==(const int) const;								// Rationnel == int
	friend bool operator==(const int, const Rationnel&);			// int == Rationnel

	bool operator!=(const Rationnel&) const;						// Rationnel != Rationnel
	bool operator!=(const int) const;								// Rationnel != int
	friend bool operator!=(const int, const Rationnel&);			// int != Rationnel

	bool operator<(const Rationnel&) const;							//Rationnel < Rationnel
	bool operator<(const int) const;								//Rationnel < int
	friend bool operator<(const int, const Rationnel&);				//int < Rationnel

	bool operator <=(const Rationnel&) const;						//Rationnel <= Rationnel
	bool operator<=(const int) const;								//Rationnel <= int
	friend bool operator<=(const int, const Rationnel&);			//int <= Rationnel

	bool operator>(const Rationnel&) const;							//Rationnel > Rationnel
	bool operator>(const int) const;								//Rationnel > int
	friend bool operator>(const int, const Rationnel&);				//int > Rationnel

	bool operator>=(const Rationnel&) const;						//Rationnel >= Rationnel
	bool operator>=(const int) const;								//Rationnel >= int
	friend bool operator>=(const int, const Rationnel&);			//int >= Rationnel
	

	// Surcharge des opérateurs d'affectation
	const Rationnel& operator=(const Rationnel&);					// Rationnel = Rationnel
	const Rationnel& operator=(const int);							// Rationnel = int
	
	const Rationnel& operator+=(const Rationnel&);					// Rationnel += Rationnel
	const Rationnel& operator+=(const int);							// Rationnel += int
	
	const Rationnel& operator-=(const Rationnel&);					// Rationnel -= Rationnel
	const Rationnel& operator-=(const int);							// Rationnel -= int

	const Rationnel& operator*=(const Rationnel&);					// Rationnel *= Rationnel
	const Rationnel& operator*=(const int);							// Rationnel *= int

	const Rationnel& operator/=(const Rationnel&);					// Rationnel /= Rationnel
	const Rationnel& operator/=(const int);							// Rationnel /= int

	// Surcharge des opérateurs d'incrément et décrément
	Rationnel operator++(int);										// Rationnel ++
	const Rationnel& operator++();									// ++ Rationnel

	Rationnel operator--(int);										// Rationnel --
	const Rationnel& operator--();									// -- Rationnel

private:
	bool reduire();													// Réduit la fraction au dénominateur le plus petit

	// Fonctions arithmétiques auxiliaires
	void additionner(const Rationnel& r);
	void soustraire(const Rationnel& r);
	void multiplier(const Rationnel& r);
	void diviser(const Rationnel& r);

	double flottant() const;										// Retourne le flottant correspondant

	int numerateur_,												// Numérateur de la fraction
		denominateur_;												// Dénominateur de la fraction
}; 

#endif
