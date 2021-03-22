/*============================================================================
Programmeur : William Poncelet
Fichier     : Rationnel.cpp
Description : Définition des functions membres et amie de la classe Rationnel
=============================================================================*/


#include <cmath>

#include "Rationnel.h"

// Constructeur par défaut: la fraction initialisée est réduite si possible
Rationnel::Rationnel(const int n, const int d)
{
	numerateur_ = n;
	denominateur_ = d;

	reduire();
}

// ************************************* FONCITONS MEMBRE PRIVÉS *************************************

/* Fonction de réduction de fraction
 * Le plus grand commun diviseur du numérateur et du dénominateur
 * est calculé, puis utilisé pour réduire la fraction.
 * Valeur de retour : true si la fraction fut réduite; false sinon
 */
bool Rationnel::reduire()
{
	// Peut-on réduire?
	if (numerateur_ == 0 || denominateur_ == 0)
		return false;

	// Trouver le plus grand commun diviseur
	int num = abs(numerateur_);
	int den = abs(denominateur_);

	do
	{
		const int reste = num % den;
		int quotient = (num - reste) / den;

		if (reste == 0)
			break;

		num = den;
		den = reste;
	}
	while (true);

	// den est le plus grand commun diviseur, alors on peut réduire
	numerateur_ /= den;
	denominateur_ /= den;

	// S'assurer que c'est le numérateur qui transporte le signe
	if (numerateur_ * denominateur_ < 0)
		numerateur_ = -1 * abs(numerateur_);
	denominateur_ = abs(denominateur_);

	return true;
}

/* Fonction d'addition : additionne la fraction donnée en paramètre à l'instance
 * Paramètres:
 * r : fraction à additionner à l'instance
 */
void Rationnel::additionner(const Rationnel& r)
{
	// Élever les deux fractions au dénominateur commun pour faire l'addition
	numerateur_ = numerateur_ * r.denominateur_ + denominateur_ * r.numerateur_;
	denominateur_ *= r.denominateur_;

	// Réduire la fraction résultante
	reduire();
}

/* Fonction de soustraction : soustrait la fraction donnée en paramètre à l'instance
 * Paramètres:
 * r : fraction à soustraire à l'instance
 */
void Rationnel::soustraire(const Rationnel& r)
{
	// Élever les deux fractions au dénominateur commun pour faire la soustraction
	numerateur_ = numerateur_ * r.denominateur_ - denominateur_ * r.numerateur_;
	denominateur_ *= r.denominateur_;

	// Réduire la fraction résultante
	reduire();
}

/* Fonction de multiplication : multiplier l'instance par la fraction donnée en paramètre 
 * Paramètres:
 * r : fraction dont l'instance doit être divisée
 */
void Rationnel::multiplier(const Rationnel& r)
{
	// Effectuer la multiplication de l'inverse de r
	numerateur_ *= r.numerateur_;
	denominateur_ *= r.denominateur_;

	// Réduire la fraction résultante
	reduire();
}

/* Fonction de division : diviser la fraction donnée en paramètre à l'instance
 * Paramètres:
 * r : fraction à multiplier à l'instance
 */
void Rationnel::diviser(const Rationnel& r)
{
	// Multiplication un à un
	numerateur_ *= r.denominateur_;
	denominateur_ *= r.numerateur_;

	// Réduire la fraction résultante
	reduire();
} // diviser

/* Fonction retournant la valeur flottante correspondant à la fraction
 * Paramètres: aucun
 * Valeur de retour: flottant correspondant à this
 */
double Rationnel::flottant() const
{
	return (1.0 * numerateur_ / denominateur_);
} // flottant

// ************************************* OPÉRATEURS ARITHMÉTIQUES *************************************

// ADDITION *********************************************************************************

// Surcharge : Rationnel + Rationnel
Rationnel Rationnel::operator+(const Rationnel& droite) const
{
	Rationnel resultat(this->numerateur_, this->denominateur_);

	resultat.additionner(droite);

	return resultat;
}

// Surcharge : Rationnel + int
Rationnel Rationnel::operator+(const int droite) const
{
	const Rationnel resultat(droite);

	// Invoquer Rationnel::operator+( Rationnel )
	return *this + resultat;
}

// Surcharge amie : int + Rationnel
Rationnel operator+(const int gauche, const Rationnel& droite)
{
	// Invoquer Rationnel::operator+( Rationnel )
	return Rationnel(gauche) + droite;
}

//  SOUSTRACTION ****************************************************************************

// Surcharge : Rationnel - Rationnel
Rationnel Rationnel::operator-(const Rationnel& droite) const
{
	Rationnel resultat(this->numerateur_, this->denominateur_);

	resultat.soustraire(droite);

	return resultat;
}

// Surcharge : Rationnel - int
Rationnel Rationnel::operator-(const int droite) const
{
	const Rationnel resultat(droite);

	return *this - resultat;
}

// Surcharge amie : int - Rationnel
Rationnel operator-(const int gauche, const Rationnel& droite)
{
	return Rationnel(gauche) - droite;
}

//  MULTIPLICATION *************************************************************************

// Surcharge : Rationnel * Rationnel
Rationnel Rationnel::operator*(const Rationnel& droite) const
{
	Rationnel resultat(this->numerateur_, this->denominateur_);

	resultat.multiplier(droite);

	return resultat;
}

// Surcharge : Rationnel * int
Rationnel Rationnel::operator*(const int droite) const
{
	const Rationnel resultat(droite);

	// Invoquer Rationnel::operator*( Rationnel )
	return *this * resultat;
}

// Surcharge amie : int * Rationnel
Rationnel operator*(const int gauche, const Rationnel& droite)
{
	// Invoquer Rationnel::operator*( Rationnel )
	return Rationnel(gauche) * Rationnel(droite);
}

//  DIVISION *******************************************************************************

// Surcharge : Rationnel / Rationnel
Rationnel Rationnel::operator/(const Rationnel& droite) const
{
	Rationnel resultat(this->numerateur_, this->denominateur_);

	resultat.diviser(droite);

	return resultat;
}

// Surcharge : Rationnel / int
Rationnel Rationnel::operator/(const int droite) const
{
	const Rationnel resultat(droite);

	// Invoquer Rationnel::operator/( Rationnel )
	return *this / resultat;
}

// Surcharge amie : int / Rationnel
Rationnel operator/(const int droite, const Rationnel& gauche)
{
	// Invoquer Rationnel::operator/( Rationnel )
	return Rationnel(droite) / gauche;
}


// ************************************* OPÉRATEURS RELATIONNELS *************************************

// == ****************************************************************************************
// Surcharge : Rationnel == Rationnel
bool Rationnel::operator==(const Rationnel& droite) const
{
	// Convertir en flottants et comparer les résultats
	const double valGauche = this->numerateur_ * 1.0 / this->denominateur_;
	const double valDroite = droite.numerateur_ * 1.0 / droite.denominateur_;

	return (valGauche == valDroite);
}

// Surcharge : Rationnel == int
bool Rationnel::operator==(const int droite) const
{
	// Invoquer Rationnel::operator==( Rationnel )
	return (*this == Rationnel(droite));
}

// Surcharge amie : int == Rationnel
bool operator==(const int gauche, const Rationnel& droite)
{
	// Invoquer Rationnel::operator==( int )
	return (droite == gauche);
}

// != ****************************************************************************************
// Surcharge : Rationnel != Rationnel
bool Rationnel::operator!=(const Rationnel& droite) const
{
	// Invoquer Rationnel::operator==( Rationnel )
	return !(*this == droite);
}

// Surcharge : Rationnel != int
bool Rationnel::operator!=(const int droite) const
{
	// Invoquer Rationnel::operator==( int )
	return !(*this == droite);
}

// Surcharge : int != Rationnel
bool operator!=(const int gauche, const Rationnel& droite)
{
	// Invoquer Rationnel::operator==( int, Rationnel )
	return !(gauche == droite);
}

// < ****************************************************************************************

// Surcharge : Rationnel < Rationnel
bool Rationnel::operator<(const Rationnel& droite) const
{
	const double valGauche = flottant();
	const double valDroite = droite.flottant();

	return (valGauche < valDroite);
}

// Surcharge : Rationnel < int
bool Rationnel::operator<(const int droite) const
{
	// Invoquer Rationnel::operator<( Rationnel )
	return *this < Rationnel(droite);
}

// Surcharge amie : int < Rationnel
bool operator<(const int droite, const Rationnel& gauche)
{
	// Invoquer Rationnel::operator<( Rationnel )
	return Rationnel(droite) < gauche;
}

// <= ****************************************************************************************

// Surcharge : Rationnel <= Rationnel
bool Rationnel::operator<=(const Rationnel& droite) const
{
	// Invoquer Rationnel::operator<( Rationnel ) OU Rationnel::operator==( Rationnel )
	return (*this < droite || *this == droite);
}

// Surcharge : Rationnel <= int
bool Rationnel::operator<=(const int droite) const
{
	// Invoquer Rationnel::operator<( int ) OU Rationnel::operator==( int )
	return (*this < droite || *this == droite);
}

// Surcharge amie : int <= Rationnel
bool operator<=(const int gauche, const Rationnel& droite)
{
	// Invoquer operator<( int < Rationnel ) OU operator==( int == Rationnel )
	return (gauche < droite || gauche == droite);
}

// > *****************************************************************************************

// Surcharge : Rationnel > Rationnel
bool Rationnel::operator>(const Rationnel& droite) const
{
	const double valGauche = flottant();
	const double valDroite = droite.flottant();

	return valGauche > valDroite;
}

// Surcharge : Rationnel > int
bool Rationnel::operator>(const int droite) const
{
	return *this > Rationnel(droite);
}

// Surcharge amie : int > Rationnel
bool operator>(const int droite, const Rationnel& gauche)
{
	return Rationnel(droite) > gauche;
}

// >= *****************************************************************************************

// Surcharge : Rationnel >= Rationnel
bool Rationnel::operator>=(const Rationnel& droite) const
{
	return (*this > droite || *this == droite);
}

// Surcharge : Rationnel >= int
bool Rationnel::operator>=(const int droite) const
{
	return (*this > Rationnel(droite) || *this == Rationnel(droite));
}

// Surcharge amie : int >= Rationnel
bool operator>=(const int gauche, const Rationnel& droite)
{
	return (Rationnel(gauche) > droite || Rationnel(gauche) == droite);
}


// ************************************* OPÉRATEURS D'AFFECTATION *************************************

// = ******************************************************************************************

// Surcharge  : Rationnel = Rationnel

const Rationnel& Rationnel::operator=(const Rationnel& droite)
{
	// Affectatioin par attribut
	this->numerateur_ = droite.numerateur_;
	this->denominateur_ = droite.denominateur_;

	return *this;
} 

// Surcharge : Rationnel = int
const Rationnel& Rationnel::operator=(const int droite)
{
	// Invoque Rationnel::operator=( Rationnel )
	*this = Rationnel(droite);
	return *this;
} // operator=

// += ******************************************************************************************

// Surcharge : Rationnel += Rationnel
const Rationnel& Rationnel::operator+=(const Rationnel& droite)
{
	// Invoque Rationnel::operator+( Rationnel ) et operator=( Rationnel )
	*this = *this + droite;
	return *this;
} 

// Surcharge : Rationnel += int
const Rationnel& Rationnel::operator+=(const int droite)
{
	// Invoque Rationnel::operator+( Rationnel ) et operator=( Rationnel )
	*this = *this + droite;
	return *this;
}

// -= ******************************************************************************************

// Surcharge : Rationnel -= Rationnel
const Rationnel& Rationnel::operator-=(const Rationnel& droite)
{
	// Invoque Rationnel::operator-( Rationnel ) et operator=( Rationnel )
	return *this = *this - droite;
}

// Surcharge : Rationnel -= int
const Rationnel& Rationnel::operator-=(const int droite)
{
	// Invoque Rationnel::operator-( Rationnel ) et operator=( Rationnel )
	return *this = *this - droite;
}

// *= ******************************************************************************************

// Surcharge : Rationnel *= Rationnel
const Rationnel& Rationnel::operator*=(const Rationnel& droite)
{
	// Invoque Rationnel::operator*( Rationnel ) et operator=( Rationnel )
	return *this = *this * droite;
}

// Surcharge : Rationnel *= int
const Rationnel& Rationnel::operator*=(const int droite)
{
	// Invoque Rationnel::operator*( Rationnel ) et operator=( Rationnel )
	return *this = *this * droite;
}

// /= ******************************************************************************************

// Surcharge : Rationnel /= Rationnel
const Rationnel& Rationnel::operator/=(const Rationnel& droite)
{
	// Invoque Rationnel::operator/( Rationnel ) et operator=( Rationnel )
	return *this = *this / droite;
}

// Surcharge : Rationnel /= int
const Rationnel& Rationnel::operator/=(const int droite)
{
	// Invoque Rationnel::operator-/( Rationnel ) et operator=( Rationnel )
	return *this = *this / droite;
}


// ************************************* OPÉRATEURS D'INCRÉMENT et DÉCRÉMENT *************************************

// Rationnel ++

Rationnel Rationnel::operator++(int)
{
	Rationnel resultat = *this;
	*this += 1;
	return  resultat;
}

// ++ Rationnel
const Rationnel& Rationnel::operator++()
{
	return  *this += 1;
}

// Rationnel --
Rationnel Rationnel::operator--(int)
{
	Rationnel resultat = *this;
	*this -= 1;
	return  resultat;
}

// -- Rationnel
const Rationnel& Rationnel::operator--()
{
	return  *this -= 1;
}

// ************************************* OPÉRATEURS DE FLUX D'ENTRÉES ET SORTIE *************************************

// Surcharge de l'opérateur de flux d'entrées pour Rationnel
// Paramètres:
//   istr: flux d'entrées à exploiter
//   r   : instance dans laquelle lire
istream& operator>>(istream& istr, Rationnel& r)
{
	char sep;
	istr >> r.numerateur_ >> sep >> r.denominateur_;
	r.reduire();

	return istr;
} // operator>>

// Surcharge de l'opérateur de flux de sorties pour Rationnel
// Paramètres:
//   istr: flux de sorties à exploiter
//   r   : instance à afficher
ostream& operator<<(ostream& ostr, const Rationnel& r)
{
	ostr << r.numerateur_ << '/' << r.denominateur_;
	return ostr;
} // operator<<
