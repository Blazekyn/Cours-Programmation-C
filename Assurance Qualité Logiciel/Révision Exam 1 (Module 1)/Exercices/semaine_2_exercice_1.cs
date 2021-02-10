/*
 Semaine 2 Exercice 1:
   Objectif: Ecrire un programme C# servant à calculer la valeur absolue d'un nombre réel x à partir de 
   la définition de la valeur absolue. La valeur absolue du nombre réel x est le nombre réel |x| :
    
    * |x| = x , si x ≥ 0
    
    * |x| = -x si x < 0
    
    Et si un utilisateur tape une chaine de caractère au lieu d’un nombre? Modifiez le code pour l’adapter à 
    ce qu’on a appris aujourd’hui.
*/

using System;
namespace NomDuProjet
{
    class NomDuFichierCSharp
    {
        private static void Main(string[] args)
        {
            double userInputToAbsoluteValue;
            
            do
            {
                Console.Write("Entrer un nombre réel : ");
                
                try
                {
                    userInputToAbsoluteValue = double.Parse(Console.ReadLine() ?? string.Empty);
                    break;
                }
                catch (Exception)
                {
                    Console.WriteLine("Entrer un nombre => RÉEL <= seulement!");
                }
            } while (true);
            
            if (userInputToAbsoluteValue >= 0)
                Console.Write("La valeur absolue est : " + userInputToAbsoluteValue);
            else
                Console.Write("La valeur absolue est : " + (userInputToAbsoluteValue * -1));
        }
    }
}