// Exercice5_1.cpp
// Date: 2021-02-08
// Codé par: William Poncelet

//Énoncé :
//Sans faire appel à l'opérateur [] ni à une variable d'itération de type int,
//complétez le programme suivant de sorte qu'il affiche le nombre de valeurs
//paires trouvées dans le tableau :

#include <iostream>
#include <ctime>

using std::cout;
using std::endl;

int main() {
    const int N = 10; // taille du tableau
    int valeurs[N]; // tableau de valeurs à traiter
    int compte = 0; // compteur

    // Remplir de valeurs aléatoires
    srand(time(nullptr));

    //Méthode originale
//    for ( int i = 0; i < N; i++ ) {
//        valeurs[ i ] = rand() % 100;
//        cout << valeurs[ i ] << " ";
//    }

    //Méthode 2
//    for (int & valeur : valeurs) {
//        valeur = rand() % 100;
//        cout << valeur << " ";
//        if(valeur % 2 == 0) compte++;
//    }

    //Méthode 3
    for (int *i = valeurs; i < valeurs + N; i++) {
        *i = rand() % 100;
        cout << *i << " ";
        if (*i % 2 == 0) compte++;
    }

    cout << endl;

    cout << "# de valeurs paires: "
         << compte << endl;

    return 0;
}
