// Ia-) Expliquez la différence entre un step into et un step over. (5)

// Step into : C'est principalement pour rentrer dans une méthode qui va être prochainement éxecuté.
// La prochaine étape est donc de rentrer dans cette méthode et continuer le déboguage pas à pas.

// Step over: Une méthode va être invoqué mais nous ne somme pas intéréssé à déboguer cette invocation. Le débogueur
// exécutera alors cette méthode en une seule étape sans que nous avions à rentrer à l'intérieur.


/*******************************************************************************************
 Ib-) (10)
  En cours nous avons vu trois types d'erreurs communes, syntaxe,exécution et
  logique. Identifié laquelle des erreurs ci-dessous correspond peut causer une
  une de ces erreurs. 2 points chacun.

NB: Chaque question représente des extraits d'un programme, et pas des programmes entiers.
Si une erreur peut être produite mettez juste le nom correspondant( syntaxe,exécution et
logique), si aucune erreur ne peut être produite mettez 'Aucune'.  (10)
********/

//1-)
using System;

int numerateur = 0;
int denominateur = 6;
int resultat = denominateur / numerateur;

//2-)

int Base = 6;
int hauteur = 6;
double AireDutriangle = Base * hauteur / 2;

//3-) Ce programme essaye de calculer la somme des chiffres de 1 a 10.

int debut = 11;
int fin = 1;

int somme = 0;

for (int i = debut; i < fin; i++)
{
    somme = somme + 1;
}

//4-)


if (AireDutriangle = 20)
    Console.Write("Le triangle a une superficie de 20 metres carré");


//5-) 

static void Main(string[] args)
{
    Console.WriteLine("Hello World! 2")
}


/**
1-) Exécution
2-) Aucune erreure
3-) Logique
4-) Syntaxe
5-) Syntaxe
*/




