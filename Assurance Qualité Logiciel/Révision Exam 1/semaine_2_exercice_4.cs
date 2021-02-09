/*
    * Exercice 4:
        Écrivez un programme C# pour renvoyer le reste de deux nombres. 
        Il existe un seul opérateur en C#, capable de fournir le reste d’une division. 
        Deux nombres sont transmis comme paramètres. 
        Le premier paramètre divisé par le deuxième paramètre.
        Exemple:
            resteDiv(1, 3) ➞ 1
            resteDiv(2, 4) ➞ 2
            resteDiv(3, 3) ➞ 0
*/

using System;

namespace NomDuProjet
{
    internal class NomDuFichierCSharp
    {
        private static int ResteDeLaDivision(int nombre1, int nombre2)
        {
            var resteDivision = nombre1 % nombre2;
            
            return resteDivision;
        }
        
        public static void Main()
        {
            int nombre1, nombre2;

            do
            {
                try
                {
                    Console.WriteLine("Veuillez entrer deux nombre entier pour obtenir" +
                                      "le reste de la division.");
                    
                    Console.WriteLine("Nombre 1 : ");
                    nombre1 = int.Parse(Console.ReadLine() ?? string.Empty);
                    
                    Console.WriteLine("Nombre 2 : ");
                    nombre2 = int.Parse(Console.ReadLine() ?? string.Empty);
                    
                    break;
                }
                catch (Exception e)
                {
                    Console.WriteLine(e.GetType());
                    Console.WriteLine("Entrer un nombre => RÉEL seulement!");
                }
            } while (true);

            var resteDivision = ResteDeLaDivision(nombre1, nombre2);
            
            Console.WriteLine($"Le reste de la division de {nombre1} par {nombre2}" +
                              $" est : {resteDivision}");
        }
    }
}