// Non          :
// Prénom       : 
// Matricule    :

#include "pch.h"
#include <iostream>

double approximer_pi() {
    int    nFrac = 1000000;        // nombre de fractions à appliquer
    double valeurPi = 0;           // valeur approximative de PI
    
//  A completer...

    return valeurPi;
}

int heureEnSeconde(int heure, int minute, int seconde) {
    int totalSeconde = 0;
    //  A completer...
    return totalSeconde;
}

//  A modifier ...
int voyelles(char* s1) {
    int nombreVoyelle = 0;
    char* p = &s1[0];

    for (int i = 0; i < strlen(s1); i++) {
        if (s1[i] == 'a' || s1[i] == 'A')
            nombreVoyelle++;

        if (s1[i] == 'e' || s1[i] == 'E')
            nombreVoyelle++;
        
        if (s1[i] == 'i' || s1[i] == 'I')
            nombreVoyelle++;
        
        if (s1[i] == 'o' || s1[i] == 'O')
            nombreVoyelle++;
        
        if (s1[i] == 'u' || s1[i] == 'U')
            nombreVoyelle++;
        
        if (s1[i] == 'y' || s1[i] == 'Y')
            nombreVoyelle++;
    }
    return nombreVoyelle;
}

//  A completer...
float s(float, float, float) {
}

int main(){
    std::cout << approximer_pi() << std::endl;
    std::cout << heureEnSeconde(1,2,2) << std::endl;

    char chaine[] = "Allo toi";
    std::cout << voyelles(chaine) << std::endl;

    float montantInvestit = 1000;
    float taux = 0.05;
    
    float rendement = s(montantInvestit, taux, 1);
    std::cout << "An -> " << 1 << " Rendement -> " << rendement << std::endl;
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
