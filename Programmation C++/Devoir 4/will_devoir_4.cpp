#include <iostream>
#include <windows.h>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

const int TONE = 500;               // fréquence de tonalité sonore
const int VITESSE = 50;             // cadence de référence

// vitesse de transmission (en millisecondes)
const int TI = VITESSE;             // durée d'un ti (point) en ms
const int TA = 3 * TI;              // durée d'un ta (trait) en ms
const int ESPACE_SYMBOLE = TI;      // durée du silence (en ms) entre chaque ti ou ta d'un caractère
const int ESPACE_LETTRE = TA;       // durée du silence (en ms) entre chaque lettre d'un mot
const int ESPACE_MOT = 5 * TI;      // durée du silence (en ms) entre chaque mot du message
const int MAX_TITA = 6;             // maximum de ti et ta dans un caractère traduisible

// A COMPLETER
const int SIGNAL[39][MAX_TITA] = {{TI, TA},                 // A
                                  {TA, TI, TI, TI},         // B
                                  {TA, TI, TA, TI},         // C
                                  {TA, TI, TI},             // D
                                  {TI},                     // E
                                  {TI, TI, TA, TI},         // F
                                  {TA, TA, TI},             // G
                                  {TI, TI, TI, TI},         // H
                                  {TI, TI},                 // I
                                  {TI, TA, TA, TA},         // J
                                  {TA, TI, TA},             // K
                                  {TI, TA, TI, TI},         // L
                                  {TA, TA},                 // M
                                  {TA, TI},                 // N
                                  {TA, TA, TA},             // O
                                  {TI, TA, TA, TI},         // P
                                  {TA, TA, TI, TA},         // Q
                                  {TI, TA, TI},             // R
                                  {TI, TI, TI},             // S
                                  {TA},                     // T
                                  {TI, TI, TA},             // U
                                  {TI, TI, TI, TA},         // V
                                  {TI, TA, TA},             // W
                                  {TA, TI, TI, TA},         // X
                                  {TA, TI, TA, TA},         // Y
                                  {TA, TA, TI, TI},         // Z
                                  {TA, TA, TA, TA},         // 0
                                  {TI, TA, TA, TA, TA},     // 1
                                  {TI, TI, TA, TA, TA},     // 2
                                  {TI, TI, TI, TA, TA},     // 3
                                  {TI, TI, TI, TI, TA},     // 4
                                  {TI, TI, TI, TI, TI},     // 5
                                  {TA, TI, TI, TI, TI},     // 6
                                  {TA, TA, TI, TI, TI},     // 7
                                  {TA, TA, TA, TI, TI},     // 8
                                  {TA, TA, TA, TA, TI},     // 9
                                  {TI, TA, TI, TA, TI, TA}, // .
                                  {TA, TA, TI, TI, TA, TA}, // ,
                                  {TA, TI, TA, TI, TA, TI}  // ;
};

int strMorse(const char msg[], bool afficher);

void majuscules(char chaine[]);

int main() {

    char chaine[50];

    //Prise de l'input
    cout << "Chaine a traduire en morse ?" << endl;
    cin.getline(chaine, 50, '\n');

    //Conversion en majuscules de la chaine
    majuscules(chaine);

    //Traduction en morse
    int compteInconnus = strMorse(chaine, true);
    cout << "\nCaracteres non trasmis: " << compteInconnus;

    return 0;
}


// Fonction de transmission d'un message en Morse
// msg[] : chaîne de caractères à transmettre en Morse sonore
// afficher : true si le code Morse doit aussi être afficher
// dans la console
// La fonction retourne le nombre de caractères n'ayant pu être transmis
int strMorse(const char msg[], bool afficher) {

    // compte le nombre de caractères non transmis
    int compteInconnus = 0;

    // Traiter chaque caractère du message individuellement
    for (unsigned int i = 0; i < strlen(msg); i++) {

        // Est-ce un espace entre deux mots?
        if (msg[i] == ' ') {
            Sleep(ESPACE_MOT);
            if (afficher)
                std::cout << '/';
            continue;
        }

        // Identifier le caractère et le transmettre

        int idx; // index du caractère dans le tableau signal

        if (msg[i] >= 65 && msg[i] <= 90) {
            idx = msg[i] - 65;
        } else {
            switch (msg[i]) {
                case '.':
                    idx = 36;
                    break;
                case ',':
                    idx = 37;
                    break;
                case ';':
                    idx = 38;
                    break;
                default:
                    idx = -1;
                    break;
            }
        }

        // Si le caractère fait partie du tableau,
        if (idx >= 0) {

            // Transmettre chaque symbole du caractère
            for (int j = 0; j < MAX_TITA; j++) {
                if (SIGNAL[idx][j] > 0) {

                    // Transmission visuelle
                    if (afficher)
                        cout << (SIGNAL[idx][j] == TI ? '.' : '-');

                    // Transmission sonore
                    Beep(TONE, SIGNAL[idx][j]);
                }

                //Transmission d'un espace sonore jusqu'au dernier caractère.
                if (SIGNAL[idx][j + 1] <= TA)
                    Sleep(ESPACE_SYMBOLE);
            }
            // Écouler le délai inter-lettres avant de passer au prochain caractère
            Sleep(ESPACE_LETTRE);

        } else {

            // Si le caractère est invalide, l'indiquer visuellement (?) et de
            // façon sonore (pause correspondant à un espace)
            if (afficher)
                std::cout << ' ';

            Sleep(ESPACE_MOT);
            compteInconnus++;
        }
    }

    // Retourner le nombre de caractère n'ayant pu être transmis
    return compteInconnus;
}

//Avec la fonction "toupper" de la libraire standard
void majuscules(char chaine[]) {
    for (int i = 0; chaine[i] != '\0'; i++)
        chaine[i] = static_cast<char> (toupper(chaine[i]));
}
