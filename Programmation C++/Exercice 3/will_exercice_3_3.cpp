#include <iostream>
#include <cmath>
using namespace std;

//Prototype de la fonction
bool facteurs(double &, double &, double &);

    int main() 
    {
    double valeur, racine2, racine3;    
    cout << "Valeur? ";   
    cin >> valeur; 

    // Calculer les facteurs de valeur  
    if ( facteurs( valeur, racine2, racine3 ) )     
        cout << "Racine carrée de " << valeur << " = " << racine2 << endl  << "Racine cubique de " << valeur << " = " << racine3 << endl;   
    else      
        cout << "Impossible de calculer les racines d'une valeur négative" << endl;  
    return 0; 
    }
//Fonction vérifie si il est possible de trouver la 2e et 3e racine de la valeur
bool facteurs( double &valeur, double &racine2, double &racine3)
{
    if (valeur >= 0)
    {
        racine2 = sqrt(valeur);
        racine3 = cbrt(valeur); 
        return true;
    }
    else
        return false;
}
/* Problème
   Complétez le programme ci - dessous afin qu’il affiche la racine carrée et la racine cubique de la
   valeur fournie par l’utilisateur : */
