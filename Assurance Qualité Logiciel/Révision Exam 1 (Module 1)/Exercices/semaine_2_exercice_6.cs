/*
    * Exercice 6 :
        Votre tâche consiste à créer un constructeur Cercle qui crée un cercle 
        avec un rayon fourni par un argument. 
        Les cercles construits doivent avoir deux getters GetArea() (PIr ^ 2) et 
        GetPerimeter() (2PI * r) qui donnent à la fois l’aire et le périmètre respectifs.
*/

using System;

namespace NomDuProjet
{
    internal class Cercle
    {
        private double rayon;

        public Cercle(double rayon)
        {
            this.rayon = rayon;
        }

        public double GetArea()
        {
            return Math.Pow(rayon, 2) * Math.PI;
        }

        public double GetPerimeter()
        {
            return 2 * rayon * Math.PI;
        }
    }
    
    internal static class NomDuFichierCSharp
    {
        public static void Main()
        {
            var cercle = new Cercle(6.25);
            Console.WriteLine(cercle.GetArea());
            Console.WriteLine(cercle.GetPerimeter());
        }
    }
}