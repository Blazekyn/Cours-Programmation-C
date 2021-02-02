/* À effectuer
L’un des jeux de hasard les plus populaires est un jeu de dés appelé
« la barbotte » qui se joue dans les casinos ainsi que dans les lieux
clandestins un peu partout dans le monde.Les règles de ce jeu sont
plutôt simples :

Un joueur lance deux dés. Chaque dé a six faces contenant, respectivement 
un, deux, trois, quatre, cinq et six points.

Après le lancer des dés, on calcule la somme des points des deux faces
pointant vers le haut.

Si la somme est 7 ou 11 au premier coup de dés, le joueur gagne.

Si elle est de 2, 3 ou 12 au premier coup de dés(appelé « barbotte »), 
le joueur perd(autrement dit, la « banque » gagne).

Si la somme est de 4, 5, 6, 8, 9 ou 10 au premier lancer, 
cette somme devient alors le « point » du joueur.

Pour gagner, il doit relancer les dés jusqu’à ce qu’il « obtienne
son point ».

Le joueur perd s’il obtient 7 avant de faire son point. Le programme suivant simule le jeu de la barbotte : */
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int lancerDes(void);	// prototype de fonction.

int main()	// Programme principal.
{
	enum Statut { CONTINUER, GAGNE, PERD };
	int somme, monPoint, pari, soldeBanque;
	Statut statutPartie;
	srand(time(NULL));

	//====================== PARTIE AJOUTÉ ======================
	soldeBanque = 1000;
	pari = 0;
	int chanceMessage = rand() % 10;
	//cout << "CHANCE MESSAGE : "<<chanceMessage << endl;
	
	if (chanceMessage % 3 == 0)
		cout << "Allez - y quoi! Tentez votre chance!" << endl;
	
	do{
		if (pari > 1000)
			cout << "votre pari est trop grand!" << endl;
		cout << "Entrer vôtre pari : ";
		cin >> pari;
	} while(!(pari <= soldeBanque));
	//===========================================================

	somme = lancerDes(); // premier lancer des dés.
	switch (somme) {
	case 7:
	case 11: // victoire au premier lancer.
		statutPartie = GAGNE;
		break;
	case 2:
	case 3:
	case 12: // défaite au premier lancer.
		statutPartie = PERD;
		break;
	default: // point de rappel.
		statutPartie = CONTINUER;
		monPoint = somme;
		cout << "Le point est " << monPoint << endl;
		break; // facultatif.
	}
	while (statutPartie == CONTINUER) { // relancer les dés.
		somme = lancerDes();
		if (somme == monPoint) // victoire en faisant le point.
			statutPartie = GAGNE;
		else
			if (somme == 7) // défaite en lançant 7.
				statutPartie = PERD;
	}
	if (statutPartie == GAGNE) {
		if (chanceMessage % 3 == 0)
			cout << "Vous êtes en pleine montée.Le temps est venu de remporter le magot!" << endl;
		cout << "Le joueur gagne" << endl;
		soldeBanque += pari;
		cout << "soldeBanque = " << soldeBanque;
	}	
	else {
		cout << "Le joueur perd" << endl;
		soldeBanque -= pari;
		if (chanceMessage % 3 == 0)
			cout << "Hmmm! Vous voulez vraiment tout perdre, n'est-ce pas ?" << endl;
		cout << "soldeBanque = " << soldeBanque;
	}
	if (soldeBanque == 0)
	{
		cout << "Désolé. Vous avez fait faillite!";
	}
	return 0;
}

// Routine retournant le résultat d’un lancer de deux dés.
int lancerDes(void)
{
	int de1, de2, sommeDes;
	de1 = 1 + rand() % 6;
	de2 = 1 + rand() % 6;
	sommeDes = de1 + de2;
	cout << "Le joueur a lanc‚ " << de1 << " + " << de2
		<< " = " << sommeDes << endl;
	return sommeDes;
}

/*	Modifiez le programme de jeu de la barbotte ci - dessus pour permettre le pari.

Empaquetez dans une fonction la portion du programme qui exécute
le jeu de la barbotte.

*	Initialisez la variable soldeBanque à 1000$.		

*	Invitez le joueur à entrer le montant de son pari.	

*	Utilisez une boucle while pour vérifier si le montant de son pari (stocké dans la variable pari) 
	est plus petit ou égal à soldeBanque, 
	
*	sinon invitez l'utilisateur à faire une autre entrée de pari jusqu'à ce qu'un 
	pari valide soit entré.

*	Une fois une valeur adéquate entrée dans pari, exécutez une partie du
	jeu de la barbotte.

*	Si le joueur gagne, augmentez soldeBanque par la valeur dans pari et 
	affichez la nouvelle valeur de soldeBanque.

*	Si le joueur perd, diminuez soldeBanque du montant dans pari, 
	affichez la nouvelle valeur de soldeBanque, 

*	vérifiez si soldeBanque est maintenant égal à zéro et 
	affichez le message « Désolé. Vous avez fait faillite!»
	si c'est le cas.

À mesure que la partie progresse, affichez de temps en temps(p.ex.
dans 30 % des parties) différents messages pour créer un certain
bavardage, comme : 

	« Hmmm! Vous voulez vraiment tout perdre, n'est-ce pas ? » ou 
	« Allez - y quoi! Tentez votre chance!» ou 
	« Vous êtes en pleine montée.Le temps est venu de remporter le magot!». */