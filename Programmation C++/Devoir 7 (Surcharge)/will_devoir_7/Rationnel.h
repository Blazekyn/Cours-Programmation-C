/*============================================================================
Programmeur : William Poncelet
Fichier     : Rationnel.h
Description : D�claration de la classe Rationnel
=============================================================================*/

#ifndef RATIONNEL_H
#define RATIONNEL_H

#include <iostream>

using std::istream;
using std::ostream;

// Classe repr�sentant une fraction.
class Rationnel {
	
	// Surcharge des op�rateurs de flux
	friend istream& operator>>(istream&, Rationnel&);				// flux d'entr�es
	friend ostream& operator<<(ostream&, const Rationnel&);			// flux de sorties

public:
	
	// Constructeur par d�faut
	Rationnel(int = 1, int = 1);										

	// Surcharge des op�rateurs arithm�tiques
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

	// Surcharge des op�rateurs relationnels
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
	

	// Surcharge des op�rateurs d'affectation
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

	// Surcharge des op�rateurs d'incr�ment et d�cr�ment
	Rationnel operator++(int);										// Rationnel ++
	const Rationnel& operator++();									// ++ Rationnel

	Rationnel operator--(int);										// Rationnel --
	const Rationnel& operator--();									// -- Rationnel

private:
	bool reduire();													// R�duit la fraction au d�nominateur le plus petit

	// Fonctions arithm�tiques auxiliaires
	void additionner(const Rationnel& r);
	void soustraire(const Rationnel& r);
	void multiplier(const Rationnel& r);
	void diviser(const Rationnel& r);

	double flottant() const;										// Retourne le flottant correspondant

	int numerateur_,												// Num�rateur de la fraction
		denominateur_;												// D�nominateur de la fraction
}; 

#endif
