/*============================================================================
Programmeur : William Poncelet
Fichier     : Rationnel.cpp
Description :�D�finition des functions membres et amie de la classe Rationnel
=============================================================================*/


#include <cmath>

#include "Rationnel.h"

// Constructeur par d�faut: la fraction initialis�e est r�duite si possible
Rationnel::Rationnel(const int n, const int d)
{
	numerateur_ = n;
	denominateur_ = d;

	reduire();
}

// ************************************* FONCITONS MEMBRE PRIV�S *************************************

/* Fonction de r�duction de fraction
 * Le plus grand commun diviseur du num�rateur et du d�nominateur
 * est calcul�, puis utilis� pour r�duire la fraction.
 * Valeur de retour : true si la fraction fut r�duite; false sinon
 */
bool Rationnel::reduire()
{
	// Peut-on r�duire?
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

	// den est le plus grand commun diviseur, alors on peut r�duire
	numerateur_ /= den;
	denominateur_ /= den;

	// S'assurer que c'est le num�rateur qui transporte le signe
	if (numerateur_ * denominateur_ < 0)
		numerateur_ = -1 * abs(numerateur_);
	denominateur_ = abs(denominateur_);

	return true;
}

/* Fonction d'addition : additionne la fraction donn�e en param�tre � l'instance
 * Param�tres:
 * r : fraction � additionner � l'instance
 */
void Rationnel::additionner(const Rationnel& r)
{
	// �lever les deux fractions au d�nominateur commun pour faire l'addition
	numerateur_ = numerateur_ * r.denominateur_ + denominateur_ * r.numerateur_;
	denominateur_ *= r.denominateur_;

	// R�duire la fraction r�sultante
	reduire();
}

/* Fonction de soustraction : soustrait la fraction donn�e en param�tre � l'instance
 * Param�tres:
 * r : fraction � soustraire � l'instance
 */
void Rationnel::soustraire(const Rationnel& r)
{
	// �lever les deux fractions au d�nominateur commun pour faire la soustraction
	numerateur_ = numerateur_ * r.denominateur_ - denominateur_ * r.numerateur_;
	denominateur_ *= r.denominateur_;

	// R�duire la fraction r�sultante
	reduire();
}

/* Fonction de multiplication : multiplier l'instance par la fraction donn�e en param�tre 
 * Param�tres:
 * r : fraction dont l'instance doit �tre divis�e
 */
void Rationnel::multiplier(const Rationnel& r)
{
	// Effectuer la multiplication de l'inverse de r
	numerateur_ *= r.numerateur_;
	denominateur_ *= r.denominateur_;

	// R�duire la fraction r�sultante
	reduire();
}

/* Fonction de division : diviser la fraction donn�e en param�tre � l'instance
 * Param�tres:
 * r : fraction � multiplier � l'instance
 */
void Rationnel::diviser(const Rationnel& r)
{
	// Multiplication un � un
	numerateur_ *= r.denominateur_;
	denominateur_ *= r.numerateur_;

	// R�duire la fraction r�sultante
	reduire();
} // diviser

/* Fonction retournant la valeur flottante correspondant � la fraction
 * Param�tres: aucun
 * Valeur de retour: flottant correspondant � this
 */
double Rationnel::flottant() const
{
	return (1.0 * numerateur_ / denominateur_);
} // flottant

// ************************************* OP�RATEURS ARITHM�TIQUES *************************************

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


// ************************************* OP�RATEURS RELATIONNELS *************************************

// == ****************************************************************************************
// Surcharge : Rationnel == Rationnel
bool Rationnel::operator==(const Rationnel& droite) const
{
	// Convertir en flottants et comparer les r�sultats
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


// ************************************* OP�RATEURS D'AFFECTATION *************************************

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


// ************************************* OP�RATEURS D'INCR�MENT et D�CR�MENT *************************************

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

// ************************************* OP�RATEURS DE FLUX D'ENTR�ES ET SORTIE *************************************

// Surcharge de l'op�rateur de flux d'entr�es pour Rationnel
// Param�tres:
//   istr: flux d'entr�es � exploiter
//   r   : instance dans laquelle lire
istream& operator>>(istream& istr, Rationnel& r)
{
	char sep;
	istr >> r.numerateur_ >> sep >> r.denominateur_;
	r.reduire();

	return istr;
} // operator>>

// Surcharge de l'op�rateur de flux de sorties pour Rationnel
// Param�tres:
//   istr: flux de sorties � exploiter
//   r   : instance � afficher
ostream& operator<<(ostream& ostr, const Rationnel& r)
{
	ostr << r.numerateur_ << '/' << r.denominateur_;
	return ostr;
} // operator<<
