/*
    * Exercice  7 :
        – Créez une classe « Person »
        
        – Créez une classe « Student » et une autre classe « Teacher », 
          les deux héritent de la classe « Person ».
          
        – La classe « Student » aura une méthode publique « GoToClasses », 
          qui affichera à l’écran « Je vais aller à ma classe. ».
          
        – La classe « Teacher » aura une méthode publique « Explain », 
          qui affichera à l’écran «Début de l’explication». 
          En plus, il aura un attribut privé « subject » de type string.
          
        – La classe « Person » doit avoir une méthode « SetAge(int n) » 
          qui indiquera la valeur de leur âge (par exemple, 15 ans).
          
        – La classe « Student » aura une méthode publique « DisplayAge » 
          qui écrira sur l’écran « Mon age est : XX ans ».
        – Vous devez créer une autre classe de test appelée « Test » 
           qui contiendra « Main » et:
           
        – Créez un objet Person et faites-lui dire « Allo ! »
        
        – Créer un objet Student, définir son âge à 15 ans, faites-lui dire « Allo ! », 
        « Je vais aller à ma classe. » et afficher son âge
        
        – Créez un objet Teacher, 40 ans, demandez-lui de dire « Allo ! » 
          puis commence l’explication.
*/

using System;

namespace NomDuProjet
{
    internal class Person
    {
        protected int Age;

        public void SayHello()
        {
            Console.WriteLine("Allo!");
        }

        public void SetAge(int age)
        {
            Age = age;
        }
    }

    internal class Student : Person
    {
        public void GoToClasses()
        {
            Console.WriteLine(" Je vais aller à ma classe.");
        }

        public void DisplayAge()
        {
            Console.WriteLine($"Mon age est : {Age} ans");
        }
    }

    internal class Teacher : Person
    {
        private string subject;

        public void Explain()
        {
            Console.WriteLine("Début de l'explication");
        }
    }
    
    internal static class NomDuFichierCSharp
    {
        public static void Main()
        {
            var person = new Person();
            person.SayHello();
            
            var student = new Student();
            student.GoToClasses();
            student.SetAge(15);
            student.SayHello();
            student.DisplayAge();

            var teacher = new Teacher();
            teacher.SetAge(40);
            teacher.SayHello();
            teacher.Explain();
        }
    }
}