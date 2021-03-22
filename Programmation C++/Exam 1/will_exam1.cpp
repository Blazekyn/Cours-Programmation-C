// Non          : Poncelet
// Prénom       : William
// Matricule    : 2681407

#include "pch.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

double approximer_pi()
{
	int nFrac = 1000000; // nombre de fractions à appliquer
	double valeurPi = 0.0; // valeur approximative de PI
	double numerateur = 4.0, denominateur = 1.0;

	for (int i = 1; i <= nFrac; ++i)
	{
		if (i % 2 == 0)
		{
			valeurPi -= numerateur / denominateur;
		}
		else
		{
			valeurPi += numerateur / denominateur;
		}
		denominateur += 2.0;
	}

	return valeurPi;
}

int heureEnSeconde(int heure, int minute, int seconde)
{
	int totalSeconde = 0;

	if (heure < 0)
		heure = 0;
	else if (heure > 23)
		heure = 23;

	if (minute < 0)
		minute = 0;
	else if (minute > 59)
		minute = 59;

	if (seconde < 0)
		seconde = 0;
	else if (seconde > 59)
		seconde = 59;
	
	totalSeconde = 3600 * heure + 60 * minute + seconde;

	return totalSeconde;
}

int voyelles(char* s1)
{
	int nombreVoyelle = 0;
	
	// Tant qu'on est pas au caractère null
	while ((*s1) != '\0')
	{
		if (*s1 == 'a' || *s1 == 'e' || *s1 == 'i' || 
			*s1 == 'o' || *s1 == 'u' || *s1 == 'A' || 
			*s1 == 'E' || *s1 == 'I' || *s1 == 'O' || *s1 == 'U')
		{
			nombreVoyelle++;
		}

		// Incrémentation du pointeur
		s1++;
	}

	return nombreVoyelle;
}

float s(const float montant, const float taux, const float nAnnee)
{
	float balance = 0.0;

	cout << "Annee" << '\t' << "Balance" << endl;
	
	for (int annee = 1; annee <= nAnnee; annee ++)
	{
		balance = montant * static_cast<float> (pow((1 + taux), annee));
		cout << annee << '\t' << balance << endl;
	}
	
	return balance;
}

int main()
{
	/* cout << approximer_pi() << endl;*/

	/*cout << heureEnSeconde(22, 0, 0) << endl;*/

	//char chaine[] = "Allo toi";
	//cout << voyelles(chaine) << endl;

	const float montantInvestit = 1000;
	const float taux = 0.05f;

	float rendement = s(montantInvestit, taux, 25);
	cout << "An -> " << 1 << " Rendement -> " << rendement << endl;

	return 0;
}
