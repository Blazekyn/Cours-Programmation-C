using System;




namespace BoucleIf
{
    class Program
    {

        //1. Créez 2 variables, une nommée Positif et l’autre nommée Negatif, toutes les deux de type Boolean.

        //2. Suivez cette procédure pour définir votre bloc If.
        //Positif et négatif sont à true -> Afficher dans la console : La lumière est allumée.
        //Positif est true mais Negatif est false -> Afficher dans la console : la lumière est éteinte.
        //Positif est faux mais Negatif est vrai -> Afficher dans la console : la lumière est éteinte.
        //Dans les autres cas -> Afficher dans la console : Veuillez brancher les deux cables pour allumer la lumière.

        //3. Soyez certain de faire des tests pour les tout les cas!


        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            //Déclaration
            bool Positiv;
            bool Negatif;


            //Initialisation
            Positif = false;
            Negatif = false;


            //Condition
            if ((Positiv == true) && (Negatif == true))
            {
                Console.WriteLine("La lumière est allumée.");
            }

            else if ((Positif == false) && (Negatif == true))
            {
                Console.WriteLine("La lumière est éteinte.");
            }

            else if ((Positif == true) && (Negatif == false))
                Console.WriteLine("La lumière est éteinte.");
            else
                Console.WriteLine("Veuillez brancher les deux cables pour allumer la lumière.");



            Console.ReadKey();
        }
       
    }
}
