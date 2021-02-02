#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	//D�claration et initialisation des variables aux valeurs par d�faut.
	int choixUsager = 0;
	int reponseUsager = 0;
	float pourcentageSalaire = 0.0;
	float salaire = 00.00;

	/*
	 Chaque type d'employé possède son propre code de paie :
	-code de paie 1 repr�sente les cadres;
	-code de paie 2 repr�sente les travailleurs � tarif horaire;
	-code de paie 3 repr�sente les travailleurs � commission; et
	-code de paie 4 repr�sente les travailleurs � la pi�ce.
	*/
	do
	{
		system("CLS");
		cout << "==================L=É=G=E=N=D=E==================\n"
				"|o 1 représente les cadres                      |\n"
				"|o 2 représente les travailleurs à tarif horaire|\n"
				"|o 3 représente les travailleurs à commission   |\n"
				"|o 4 représente les travailleurs à la pièce.    |\n"
				"=================================================\n"
				"Insérer le code (-1 pour quitter): ";
		cin >> choixUsager;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
		}

		switch (choixUsager)
		{
		case 1:
			//Salaire hebdomadaire fixe, sans égard aux heures travaill�es;
			cout << "Insérer le salaire hebdomadaire fixe : ";
			cin >> salaire;
			break;

		case 2:
			/* Travailleurs à tarif horaire : recevant un taux horaire fixe "régulier" pour
			les 40 premières heures et un taux horaire "temps et demi", soit 1.5 fois le taux horaire
			régulier, pour les heures suppl�mentaires. (Exercice 2.1)*/
			cout << "Entrez le nombre d'heure travaillé par l'employé(e) (00) : ";
			cin >> reponseUsager;
			cout << "Entrez le taux horaire de l'employé(e) ($00.00) : ";
			cin >> pourcentageSalaire;

			if (reponseUsager <= 40)
			{
				salaire = reponseUsager * pourcentageSalaire;
			}
			else
			{
				salaire = (40.00 * pourcentageSalaire) + ((reponseUsager - 40.00) * (1.5 * pourcentageSalaire));
			}
			break;

		case 3:
			//travailleurs à commission : recevant 250$ plus 5.7 % de leurs ventes hebdomadaires brutes
			cout << "Entrez le nombre de ventes hebdomadaire(s) : ";
			cin >> reponseUsager;
			salaire = 250 + (0.057 * reponseUsager);
			break;

		case 4:
			/* travailleur à la pièce : recevant un taux fixe d'argent pour chaque article produit;
			chaque travailleur à la pièce de cette compagnie ne travaille que sur un seul type
			d'article. */
			cout << "Entrez le nombre de ventes d'article de produit(s) : ";
			cin >> reponseUsager;
			cout << "Entrez le pourcentage par produit en d�cimal (ex. 66.6) : ";
			cin >> pourcentageSalaire;
			break;

		default:
			if (choixUsager != -1 || cin.fail())
			{
				cout << "Entrer un entier entre 1 et 4, alternativement entrer -1 afin de quitter le logiciel.\n Appuyer espace pour continuer..." << endl;
				_getch();
				continue;
			}
			else
			{
				return 0;
			}
		}
		/*Reinitilisation de la varibale reponseUsager afin de conformer la variable au contexte nécessaire,
		1 étant un employé*/
		reponseUsager = 1;
		cout << "Pour combien de employés calculer-vous le salaire (1 pour individuel): ";
		cin >> reponseUsager;
		cout << "Le salaire de " << reponseUsager << " employé(s) est de " << (salaire * reponseUsager) << "$" << endl;
		_getch();
	} while (choixUsager != -1);

	return 0;
}
/*	==========================================================================================
	||									INSTRUCTIONS										||
	==========================================================================================
	À effectuer 
	Une compagnie r�mun�re ses employ�s selon leur fonction :

	* cadres : recevant un salaire hebdomadaire fixe, sans �gard aux heures travaill�es;

	* travailleurs à tarif horaire : 
	recevant un taux horaire fixe � r�gulier � pour les 40 premi�res heures 
	et un taux horaire �temps et demi�, soit 1.5 fois le taux horaire r�gulier, 
	pour les heures suppl�mentaires; 

	* travailleurs à commission : 
	recevant 250$ plus 5.7 % de leurs ventes hebdomadaires brutes;

	* travailleur à la pièce : 
	recevant un taux fixe d'argent pour chaque article produit; 
	chaque travailleur à la pièce de cette compagnie ne travaille que 
	sur un seul type d'article.

	==========================================================================================
	Écrivez un programme qui calcule la paie pour  chaque  employé. Vous ne connaissez pas
	à l'avance le nombre d'employés. 

	Utilisez une structure switch pour calculer la paie de chaque employé en fonction du code
	de paie de cet employé. À l'intérieur de cette  structure switch, invitez l'utilisateur
	(par exemple, le responsable de la paie) à entrer les faits appropriés requis par votre
	programme pour calculer la paie de chaque employé en fonction du code de paie de l'employé. */