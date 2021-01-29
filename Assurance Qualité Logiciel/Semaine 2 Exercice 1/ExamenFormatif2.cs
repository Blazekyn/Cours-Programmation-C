using System;
namespace QA_Semaine_2_Exercice_1
{
    class ExamenFormatif2
    {
        static void Main(string[] args)
        {
            //Déclaration de la variable réponse
            int reponse;
            //Loop do while pour faire répéter la question juste a temps qu'il y a un int.
            do
            {
                Console.Write("Entrer un nombre réel : ");
                
                //Utilisation du try catch pour vérifier si la réponse est un int
                try
                {
                    //Conversion du string en int
                    reponse = Int32.Parse(Console.ReadLine());
                    break;
                }
                catch (Exception)
                {
                    Console.WriteLine("Entrer un nombre => RÉEL <= seulement!");
                }
            } while (true);

            //Affection de la variable réponse pour donner la valeur absolue dépendant du cas.
            if (reponse >= 0)
                Console.Write("La valeur absolue est : " + reponse);
            else
                Console.Write("La valeur absolue est : " + (reponse * -1));
        }
    }
}
/*Semaine 2 Exercice 1:
    Objectif: Ecrire un programme C# servant à calculer la valeur absolue d'un nombre réel x à partir de 
    la définition de la valeur absolue. La valeur absolue du nombre réel x est le nombre réel |x| :
    
    * |x| = x , si x ≥ 0
    
    * |x| = -x si x < 0
    
    Et si un utilisateur tape une chaine de caractère au lieu d’un nombre? Modifiez le code pour l’adapter à 
    ce qu’on a appris aujourd’hui.*/