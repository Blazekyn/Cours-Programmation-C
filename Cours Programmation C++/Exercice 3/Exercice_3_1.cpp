#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

//Prototypes des fonctions
double celcius(double);
double fahrenheit(double);

int main()
{
    cout << "\n__________________________________________________________________________\n" << endl <<
            "||\t\t\t[Fahrénheit => Celcius]\t\t\t\t||\n__________________________________________________________________________\n" << endl;
    _getch();
    for (int i = 32; i <= 212; i++)
    {
        cout << "||\tFahrenheit :\t" << i << "\t ||\tCelcius :\t " << setprecision(2) << fixed << celcius(i) << 
                "\t\t||\n__________________________________________________________________________\n" << endl;
    }
    cout << "\n__________________________________________________________________________\n" << endl <<
        "||\t\t\t[Celcius => Fahrenheit]\t\t\t\t||\n__________________________________________________________________________\n" << endl;
    _getch();

    for (int i = 0; i <= 100; i++)
    {
        cout << "||\tCelcius :\t" << i << "\t ||\tFahrenheit :\t " << setprecision(2) << fixed << fahrenheit(i) <<
            "\t\t||\n__________________________________________________________________________\n" << endl;
    }
    return 0;
}
//Définitio des fonctions celcius et fahrenheit
double celcius(double degreFahrenheit) 
{
    return (5.0/9.0 * (degreFahrenheit - 32.00));
}
double fahrenheit(double degreCelcius) 
{
   return ((9.0/5.0 * degreCelcius) + 32);
}

/*  Problème 

    Implantez les fonctions d’entiers suivantes : 

    a) La  fonction celsius  renvoie  l’équivalent  en  Celsius  d’une  température en degrés Fahrenheit.

    b) La  fonction fahrenheit  renvoie  l’équivalent  en  Fahrenheit  d’une température en degrés Celsius.

    c) Utilisez  ces  fonctions  pour  écrire  un  programme  qui  affiche  des tableaux  illustrant  les 
       équivalents  en  
       
       * Fahrenheit  de  toutes  les températures en Celsius de 0 à 100 degrés, ainsi que les équivalents en 
            T(°C) = (T(°F) - 32) / 1.8

       * Celsius  de  toutes  les  températures  en  Fahrenheit  de  32  à  212  degrés. 
            T(°F) = T(°C) × 1.8 + 32

       Affichez les  sorties  dans  une  forme  claire  utilisant  des  tabulations pour  minimiser  le  nombre  de  
       lignes  de  sortie, tout en  demeurant lisible. */
