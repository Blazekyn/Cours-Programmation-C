#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;


// Retourne la longueur de la chaîne en paramètre.
int maStrlen(const char *);

// Inverse le contenu de la chaîne en paramètre et retourne celle-ci comme valeur de retour.
char *maStrReverse(char *, int);

int main() {
    char chaine[11];
    int longueurChaine;

    cout << "Enter une chaine de max 10 caracteres: " << endl;
    cin >> setw(11) >> chaine;

    longueurChaine = maStrlen(chaine);

//    cin.getline(chaine,11,'\0');

//    cout << "\nLongueur de la chaine: " << longueurChaine << endl;
    cout << "\nChaine inversee: " << maStrReverse(chaine, longueurChaine) << endl;

    return 0;
}

int maStrlen(const char *chaine) {
    int compteurLettre = 0;

    //Tant qu'on est pas au caractère null
    while (*chaine++) {
        compteurLettre ++;
//        compteurLettre++;
    }

    return compteurLettre;
}

char *maStrReverse(char *chaine, int nombreLettres) {

    //Avec pointeur
    char *premier;
    char *dernier;
    char tempo;

    for (int lo = 0, hi = nombreLettres - 1; lo < hi; lo++, hi--) {

        //Avec pointeur
        //Pointe vers l'adresse de :
//        premier = &chaine[lo];
//        dernier = &chaine[hi];

        //Swap des pointeurs
//        tempo = *premier;
//        *premier = *dernier;
//        *dernier = tempo;

       // Sans pointeur
       tempo = chaine[lo];
       cout<< "tempo: " << tempo<< endl;
       chaine[lo] = chaine[hi];
        cout<< "lo: " << chaine[lo]<< endl;
       chaine[hi] = tempo;
        cout<< "hi: " << chaine[hi]<< endl;

    }

    return chaine;
}
