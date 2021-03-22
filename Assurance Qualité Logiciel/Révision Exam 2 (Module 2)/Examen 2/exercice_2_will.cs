//II-a) (5) Quel avertissement correspond au code CS0162? Donnez votre propre
// exemple illustrant cet avertissement. NB: Une note de 0/5 sera donnée si vous
// utilisé un exemple dans les notes de cours ou sur le site de Microsoft.

// C'est du code qui ne sera jamais exécuté :
// Par example faire un return dans une fonction avant d'autre ligne de codes lancerais cette erreure.


/********
                            II-b (20)
  Modifiez le code ci-dessous afin qu'il n y ait pas d'erreur de syntaxe, d'
exécution ou de logique. (5 points chacun)

NB: Chaque question représente des extraits d'un programme, et pas des programmes entiers.
********/

//1-)
using System;

int numerateur = 1; // numérateur à 1 ici
int denominateur = 6;
int resultat = denominateur / numerateur;

//2-) Ce programme essaye de calculer la somme des chiffres de 1 a 10.

int debut = 1;
int fin = 10;

int somme = 0;

for (int i = debut; i <= fin; i++)
{
    somme += i;
}

//3-)

int AireDutriangle = 20;

if (AireDutriangle == 20)
    Console.Write("Le triangle a une superficie de 20 metres carré");


//4-) 

static void Main(string[] args)
{
    Console.WriteLine("Hello World! 2");
}




