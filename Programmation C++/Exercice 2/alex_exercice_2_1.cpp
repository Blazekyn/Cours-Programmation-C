/*==========================================================
Programmeur : Alexandre Tremblay
Fichier     : Ex2.1.cpp
Description : programme de paie d'employés
Date        : 2021/01/18
==========================================================*/

#include <iostream>
using namespace std;
int main()
{
    int numHeures = 0;
    double tauxHorraire = 0.0;
    double salaire = 10.00;

    while (true)
    {
        cout << "Entrez le nombre d’heures travaillées(-1 pour terminer) : ";
        cin >> numHeures;
        
        if (numHeures != -1)
        {
            cout << "Entrez le taux horaire de l’employé($00.00) : ";
            cin >> tauxHorraire;

            if (numHeures <= 40)
            {
                salaire = numHeures * tauxHorraire;
            }
            else
            {
                salaire = (40.00 * tauxHorraire) + ((numHeures - 40.00f) * (1.5 * tauxHorraire));
            }

            cout << "Le salaire est de $" << salaire << endl;
        }
        else
        {
            return 0;
        } 
    }
}
/*
Développez un programme en C++ qui déterminera le salaire brut de chacun des employés d’une compagnie.
L’entreprise paie le « temps régulier » pour les 40 premières heures travaillées par chaque employé et 
paie le « temps et demi » pour toutes les heures dépassant les 40 heures régulières.

La compagnie vous confie  la  liste  des  employés, le  [nombre  d’heures]  travaillées  par  chaque employé  la 
semaine  dernière, ainsi  que  le  [taux  horaire]  de  chaque  employé.

Votre  programme  doit  entrer  ces  informations  pour  chaque  employé  et  doit déterminer et afficher 
le salaire brut de chacun d’entre eux.

AFFICHAGE :
Entrez le nombre d’heures travaillées(-1 pour terminer) : 39
Entrez le taux horaire de l’employé($00.00) : 10.00 
Le salaire est de $390.00 

Entrez le nombre d’heures travaillées(-1 pour terminer) : 40
Entrez le taux horaire de l’employé($00.00) : 10.00 
Le salaire est de $400.00 

Entrez le nombre d’heures travaillées(-1 pour terminer) : 41
Entrez le taux horaire de l’employé($00.00) : 10.00 
Le salaire est de $415.00 

Entrez le nombre d’heures travaillées(-1 pour terminer) : -1
*/