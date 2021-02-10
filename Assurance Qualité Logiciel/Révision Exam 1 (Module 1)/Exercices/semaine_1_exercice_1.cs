/*
 * Implantez une classe représentant une horloge gérant une heure exacte
 
    * La classe stocke le temps sous forme d’heure (0 à 23), minute (0 à 59) et seconde (0 à 59.9999)
        Stocke les secondes en flottant de façon à pouvoir représenter le 
        temps avec  fraction de seconde.
        
    * Dispose de trois constructeurs
        Constructeur par défaut (initialise à 00h 00m 00.0s)
        Constructeur paramétré (initialise les attributs selon les paramètres)
        Constructeur de copie (initialise les attributs aux valeurs de l’instance fournie)
        
    * Dispose d’accesseurs (getters) et mutateurs (setters) publiques pour donner
      un accès contrôlé et validé à chaque attribut
      
    * Fournit trois fonctions publiques de transformation en chaînes de caractères
        Format par défaut (ex: 23h 4m 17.33s) 
        Format standard (ex: 11h 4m 17.33s pm)
        Format militaire (ex: 11:04:17.33)
*/

using System;

namespace NomDuProjet
{
    internal class NomDuFichierCSharp
    { 
        private static void Main(string[] args)
        {
            var temps = new Temps();

            do
            {
                Console.Write("Entrer le nombre d'heures : ");
                temps.NombreHeures = int.Parse(Console.ReadLine() ?? string.Empty);

                if (!(temps.NombreHeures >= 0 && temps.NombreHeures <= 23))
                    Console.WriteLine("Entrer un chiffre entre 0 et 23!");
                
            } while (!(temps.NombreHeures >= 0 && temps.NombreHeures <= 23));

            do
            {
                Console.Write("Entrer le nombre de minutes : ");
                temps.NombreMinutes = int.Parse(Console.ReadLine() ?? string.Empty);

                if (!(temps.NombreMinutes >= 0 && temps.NombreMinutes <= 59))
                    Console.WriteLine("Entrer un chiffre entre 0 et 59!");
                
            } while (!(temps.NombreMinutes >= 0 && temps.NombreMinutes <= 59));

            do
            {
                Console.Write("Entrer le nombre de secondes : ");
                temps.Secondes = float.Parse(Console.ReadLine() ?? string.Empty);
                
                if (!(temps.Secondes >= 00.0000 && temps.Secondes <= 59.9999))
                    Console.WriteLine("Entrer un chiffre entre 00.0000 et 59.9999!");
                
            } while (!(temps.Secondes >= 00.0000 && temps.Secondes <= 59.9999));

            Console.WriteLine("Format 24h : " + temps.Format24H() 
                                              + "\nFormat Standard : " + temps.FormatStandard() 
                                              + "\nFormat Militaire : " + temps.FormatMilitaire());
        }
    }

    internal class Temps
    {
        //Variables du programme
        public int NombreHeures { get; set; }
        public int NombreMinutes { get; set; }
        public float Secondes { get; set; }

        public Temps()
        {
            NombreHeures = 0;
            NombreMinutes = 0;
            Secondes = 00.0000f;
        }

        public Temps(Temps instance)
        {
            NombreHeures = instance.NombreHeures;
            NombreMinutes = instance.NombreMinutes;
            Secondes = instance.Secondes;
        }

        public Temps(int h, int m, float s)
        {
            NombreHeures = h;
            NombreMinutes = m;
            Secondes = s;
        }

        public string Format24H()
        {
            var compositeur = $" {NombreHeures}h  {NombreMinutes}m {Secondes}s";
            
            return compositeur;
        }

        public string FormatStandard()
        {
            int format12Heures;
            string tempsDeJournée;

            if (NombreHeures > 12)
            {
                format12Heures = NombreHeures - 12;
                tempsDeJournée = "pm";
            }
            else
            {
                format12Heures = NombreHeures;
                tempsDeJournée = "am";
            }

            var compositeur = $" {format12Heures}h  {NombreMinutes}m {Secondes}s " + tempsDeJournée;
            
            return compositeur;
        }

        public string FormatMilitaire()
        {
            string compositeur;
            
            if (NombreMinutes > 9)
            {
                compositeur = $" {NombreHeures}:{NombreMinutes}:{Secondes}";
            }
            else if (NombreMinutes < 10 && Secondes < 10)
            {
                compositeur = $" {NombreHeures}:0{NombreMinutes}:0{Secondes}";
            }
            else
            {
                compositeur = $" {NombreHeures}:0{NombreMinutes}:{Secondes}";
            }

            return compositeur;
        }
    }
}