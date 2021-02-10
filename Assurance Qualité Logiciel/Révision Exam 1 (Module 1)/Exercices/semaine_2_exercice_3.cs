/*
    * Exercice 3
        Écrivez une fonction qui prend la base et la hauteur d’un triangle et retourne sa surface. 
        Notez que la surface d’un triangle est: (base * hauteur) / 2
*/

using System;

namespace NomDuProjet
{
    internal class NomDuFichierCSharp
    {
        private static int GetAireTriangle(int baseTriangle, int hauteurTriangle)
        {
            var aireTriangle = baseTriangle * hauteurTriangle / 2;
            
            return aireTriangle;
        }
        
        public static void Main()
        {
            int baseTriangle, hauteurTriangle;

            do
            {
                try
                {
                    Console.WriteLine("Veuillez entrer la base et la hauteur du triangle pour" +
                                      "calculer son aire (cm^2).");
                    
                    Console.WriteLine("Base du triangle : ");
                    baseTriangle = int.Parse(Console.ReadLine() ?? string.Empty);
                    
                    Console.WriteLine("Hauteur du triangle : ");
                    hauteurTriangle = int.Parse(Console.ReadLine() ?? string.Empty);
                    
                    break;
                }
                catch (Exception e)
                {
                    Console.WriteLine(e.GetType());
                    Console.WriteLine("Entrer un nombre => RÉEL seulement!");
                }
            } while (true);

            var aireTriangle = GetAireTriangle(baseTriangle, hauteurTriangle);
            
            Console.WriteLine($"L'aire du triangle est de : {aireTriangle} cm carré.");
        }
    }
}