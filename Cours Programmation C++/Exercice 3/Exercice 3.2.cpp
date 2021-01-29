#include <iostream>
#include <cstdlib>
using namespace std;

/*	Prototype de la fonction, inspiré par le code 
	dans la présentation, diapo 15	*/
int lancerDe();

int main()
{
	//Afin d'avoir un résultat réellement aléatoire à chaque éxécution.
	srand(time(0));
	//Déclaration des variables somme et sept ainsi que son initialisation.
	int somme;
	int sept = 0;
	//Simulation x 1000
	for (size_t i = 0; i < 10000; i++)
	{
		//Somme des deux dés
		somme = (lancerDe() + lancerDe());
		//Vérification si la somme des deux dés est égale à 7
		if (somme % 7 == 0)
		{
			cout << somme << " : True" << endl;
			++sept;
		}
		else
			cout << somme << endl;
	}
	//Affichage du résultat
	cout << "Pourcentage sur 10000 simulations : " << (sept * 100 / 10000) << "%";
	return 0;
}

//Simule le lancement d'un dé
int lancerDe() 
{
	return 1 + rand() % 6;
}

/* Écrivez un programme calculant la probabilité d’obtenir 7 le jeu de hasard labarbotte,
   qui  consiste  à  

	* lancer  deux  dés  et  d’en  faire  la  somme.

Pour calculer  cette  probabilité, 

	* simuler  10000  fois  le  lancement  de  deux  dés  et 

	* compter le nombre de fois que la somme des deux dés est 7.

	* Affichez ensuite le % des lancers ayant donnée 7. */