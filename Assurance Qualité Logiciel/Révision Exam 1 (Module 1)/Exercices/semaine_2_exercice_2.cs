/*
    * Exercice 2 
        Complétez le code suivant en créant une fonction qui prend deux nombres 
        comme arguments et retourne leur somme.
*/

using System;

namespace NomDuProjet
{
    internal class NomDuFichierCSharp
    {
        private static int Somme(int nombre1, int nombre2)
        {
            var sommeDesDeuxNombres = nombre1 + nombre2;
            
            return sommeDesDeuxNombres;
        }
        
        public static void Main()
        {
            int nombre1, nombre2;

            do
            {
                try
                {
                    Console.WriteLine("Veuillez entrer 2 nombres pour effectuer la somme.");
                    
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

            var resultatSomme = Somme(nombre1, nombre2);
            
            Console.WriteLine($"{nombre1} + {nombre2} = {resultatSomme}");
        }
    }
}