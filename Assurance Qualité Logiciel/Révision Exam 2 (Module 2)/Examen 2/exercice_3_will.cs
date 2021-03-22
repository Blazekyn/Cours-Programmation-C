/*
 Le code ci-dessous contient un bug(erreur logique), utilisez les techniques
 de debugage vues en classes pour le détecter et le résoudre.

 N'ajoutez pas de code extra, modifié juste le code ci-dessous sans ajouté une
 variable ou une fonction, juste modifié les ligne(s) causant l'erreur.(20)

Ci-dessous, donnez aussi une description des étapes utilisées pour arriver à la
solution.

 NB:Après avoir modifié le code, faites un rebuild, avant d'exécuter le code.
 Le factoriel doit être calculé par le programme, donc une modification de la
 ligne 42 ne sera pas acceptée
                          (30)     

        IIIa-) Solution attendue: La factoriel de 5 est 120  (20)
*/

using System;

namespace ProgAvecBogue
{
    class Program
    {
        // ATTENTION : programme avec bug
        static void Main(string[] args)
        {
            int nombreAtrouverLeFactoriel = 5; 
            int resultat = 1; // 1 ici
            int n = nombreAtrouverLeFactoriel;

           /*
           * Pour calculer le factoriel d un chiffre n, soit n!, on fait la multiplication
             n * (n - 1) * (n - 2) * (n - 3)... * 1
           * dans un boucle while
           */
            while (n > 0) // > ici
            {
                resultat *= n;
                n -= 1;
            }

            Console.Out.WriteLine("Le factoriel de " + nombreAtrouverLeFactoriel + " est " +
                                  resultat);
        }
    }
}

// III-b) donnez une description des étapes utilisées pour arriver à la solution. (10)
// Utilisez des mots techniques vus en cours.

// Après la mise en place d'un point d'arrêt sur la ligne 39,
// nous pouvons comprendre que la variable resultat initialisé à 0 causera un problème,
// il sagit d'une erreure de logique. Dans la boucle while, si résultat est tout le temps
// multiplié par 0, le résultat final sera 0.

// Après la correction de se bogue, nous pouvons voir que la boucle while cause aussi un problème,
// car : n >= 0 fera en sorte que n atteindra 0 un moment donné. n sera donc multiplié à résultat
// et causera aussi une valeur finale de 0. La solution est simplement de faire en sorte que n arrête
// à la valeure 1 (un autre erreure de logique). while(n > 0) ou bien while(n >= 1)
