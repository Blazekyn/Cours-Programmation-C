// Ex1.cpp : This file contains the 'main' function. Program execution begins and ends there.

/*========================================================== 
Programmeur : Alexandre Tremblay 
Fichier     : Ex1.cpp 
Description : Programme somme, moyenne, produit, plus petit 
              et plus grand de trois entier
Date        : 2021/01/11 
==========================================================*/
#include "pch.h"
#include <iostream>

int main()
{
    int a, b, c;
    int som, moy, pro, plpt, plgr;
    //Demander à l'usager de entrer trois entier
    std::cout << "Entrez trois entiers différents : ";
    //Capture des entiers dans les varaiables a, b et c
    std::cin >> a >> b >> c;
    
    //Calculations de la somme, moyenne et produit. 
    som = a + b + c;
    moy = som / 3;
    pro = a * b * c;

    //Calculer le plus petit int
    if (a < b && a < c)
    {
        plpt = a;
    }
    else if (b < a && b < c)
    {
        plpt = b;
    }
    else if (c < b && c < a)
    {
        plpt = c;
    }

    //Calculer le plus grand int
    if (a > b && a > c)
    {
        plgr = a;
    }
    else if (b > a && b > c)
    {
        plgr = b;
    }
    else if (c > b && c > a)
    {
        plgr = c;
    }


    //Afficher SOMME
    std::cout << "La somme est " << som << std::endl;

    //Afficher MOYENNE
    std::cout << "La moyenne est " << moy << std::endl;

    //Afficher PRODUIT
    std::cout << "Le produit est " << pro << std::endl;

    //Afficher PLUS PETIT
    std::cout << "Le plus petit entier est " << plpt << std::endl;

    //Afficher PLUS GRAND
    std::cout << "Le plus grand entier est " << plgr << std::endl;

    /*AFFICHAGE FINAL
     Entrez trois entiers différents : 13 27 14
     La somme est 54 
     La moyenne est 18 
     Le produit est 4914 
     Le plus petit entier est 13 
     Le plus grand entier est 27  
    */

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
