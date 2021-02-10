/*
    * Exercice 5 :
        1- Ecrire un programme en c qui permet d'afficher les jours de la semaine (lundi, mardi,...)
         sachant que les jours sont codés de 1 à 7:
        1----------------->Lundi
        2----------------->Mardi
        ......
        7---------------->Dimanche
*/

using System;

namespace NomDuProjet
{
    internal class NomDuFichierCSharp
    {
        public static void Main()
        {
            int jour;

            do
            {
                try
                {
                    Console.WriteLine("Entrer un nombre de 1 à 7:");
                    jour = int.Parse(Console.ReadLine() ?? string.Empty);
                    
                    break;
                }
                catch (Exception e)
                {
                    Console.WriteLine(e.GetType());
                    Console.WriteLine("Entrer un nombre => RÉEL seulement!");
                }
            } while (true);

            switch (jour)
            {
                case 1: Console.WriteLine("Lundi");
                    break;
                case 2: Console.WriteLine("Mardi");
                    break;
                case 3: Console.WriteLine("Mercredi");
                    break;
                case 4: Console.WriteLine("Jeudi");
                    break;
                case 5: Console.WriteLine("Vendredi");
                    break;
                case 6: Console.WriteLine("Samedi");
                    break;
                case 7: Console.WriteLine("Dimanche");
                    break;
                default: Console.WriteLine("Aucun jour avec cette valeur !");
                    break;
            }
        }
    }
}