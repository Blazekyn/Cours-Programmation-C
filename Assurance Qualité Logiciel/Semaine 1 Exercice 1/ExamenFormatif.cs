using System;

namespace ExamenFormatif
{
    class ExamenFormatif
    {
        static void Main(string[] args)
        {
            //Instanciation de l'objet nommé t pour temps
            Temps temps = new Temps();

            do
            {
                Console.Write("Entrer le nombre d'heures : ");

                /* Utilisation de la methode Parse pour convertir le type String
                obtenue par la methode ReadLine*/
                temps.nombreHeures = Int32.Parse(Console.ReadLine());

                //Verification si le nombre entré est entre 0 et 59
                if (!(temps.nombreHeures >= 0 && temps.nombreHeures <= 23))
                    Console.WriteLine("Entrer un chiffre entre 0 et 23!");
                
            }while (!(temps.nombreHeures >= 0 && temps.nombreHeures <= 23));

            do
            {
                Console.Write("Entrer le nombre de minutes : ");
                temps.nombreMinutes = Int32.Parse(Console.ReadLine());

                //Verification si le nombre entré est entre 0 et 59
                if (!(temps.nombreMinutes >= 0 && temps.nombreMinutes <= 59))
                    Console.WriteLine("Entrer un chiffre entre 0 et 59!");

            }while (!(temps.nombreMinutes >= 0 && temps.nombreMinutes <= 59));

            do
            {
                Console.Write("Entrer le nombre de secondes : ");
                temps.secondes = float.Parse(Console.ReadLine());
                
                //Verification si le nombre entré est entre 00.0000 et 59.9999
                if (!(temps.secondes >= 00.0000 && temps.secondes <= 59.9999))
                    Console.WriteLine("Entrer un chiffre entre 00.0000 et 59.9999!");

            } while (!(temps.secondes >= 00.0000 && temps.secondes <= 59.9999));
            
            Console.WriteLine("Format 24h : "+temps.Format24h()+"\nFormat Standard : "+temps.FormatStandard()+"\nFormat Militaire : "+temps.FormatMilitaire());
        }
    }
    public class Temps
    {
        //Variables du programme
        public int nombreHeures { get; set; }
        public int nombreMinutes { get; set; }
        public float secondes { get; set; }

        public Temps()
        {
            nombreHeures = 0;
            nombreMinutes = 0;
            secondes = 00.0000f;
        }
        public Temps(Temps instance)
        {
            nombreHeures = instance.nombreHeures;
            nombreMinutes = instance.nombreMinutes;
            secondes = instance.secondes;
        }

        public Temps(int h, int m, float s)
        {
            nombreHeures = h;
            nombreMinutes = m;
            secondes = s;
        }
        public String Format24h()
        {
            string str = $" {nombreHeures}h  {nombreMinutes}m {secondes}s";
            return str; 
            /*Format par défaut (ex 23h 4m 17.33s)*/
        }
        public String FormatStandard()
        {
            int format12Heures;
            string tempsDeJournée;

            if (nombreHeures > 12)
            {
                format12Heures = nombreHeures - 12;
                tempsDeJournée = "pm";
            }
            else
            {
                format12Heures = nombreHeures;
                tempsDeJournée = "am";
            }
                
            string str = $" {format12Heures}h  {nombreMinutes}m {secondes}s " + tempsDeJournée ;
            return str;
            /*Format par standard (ex 23h 4m 17.33s pm)*/
        }

        public string FormatMilitaire()
        {
            string str;
            if (nombreMinutes > 9)
            {
                str = $" {nombreHeures}:{nombreMinutes}:{secondes}";
            }
            else if (nombreMinutes < 10 && secondes < 10)
            {
                str = $" {nombreHeures}:0{nombreMinutes}:0{secondes}";
            }
            else
            {
                str = $" {nombreHeures}:0{nombreMinutes}:{secondes}";
            }
             
            return str;
        }

    }
}
