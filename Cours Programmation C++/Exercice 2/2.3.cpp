// 2.3.cpp : This file contains the 'main' function. Program execution begins and ends there.

/*==========================================================
Programmeur : Alexandre Tremblay
Fichier     : Ex2.2.cpp
Description : programme de profit de Fresh co.
Date        : 2021/01/18
==========================================================*/
#include <iostream>
using namespace std;

int main()
{
    int choix;
    int unVendu = 0;
    double profit;

    cout << "Entrer numéro de produit : ";
    cin >> choix;
    cout << "Entrer numéro de unités vendus : ";
    cin >> unVendu;

    switch (choix)
    {
    case 1:
        profit = 2.98 * unVendu;
        break;
    case 2:
        profit = 4.50 * unVendu;
        break;
    case 3:
        profit = 9.98 * unVendu;
        break;
    case 4:
        profit = 4.49 * unVendu;
        break;
    case 5:
        profit = 6.87 * unVendu;
        break;
    default:
        break;
    }

    cout << "Voici le profit de la journée : " << profit << "$";
}

/*
Produit #1 : 2.98$ / u
Produit #2 : 4.50$ / u
Produit #3 : 9.98$ / u
Produit #4 : 4.49$ / u
Produit #5 : 6.87$ / u

rivez un programme qui lit une série de paires de nombres de la façon suivante : 
a)Le numéro du produit (1 à 5).
b)Le nombre d’unités vendus en une journée. 

Votre programme doit utiliser une instruction switch pour déterminer le prix de détail de chaque produit. 
Le programme doit calculer et afficher la valeur au détail totale de tous les produits vendus durant la journée.
*/