using System;

namespace ProgAvecBogue
{
    class Program
    {
        // ATTENTION : programme bogué...
        static void Main(string[] args)
        {
            int n = 0; // nombre saisi
            int factorielle = 0; // factorielle de n (n!)

            Console.Out.WriteLine("Entrez un entier > 0");
            n = int.Parse(Console.In.ReadLine());

            /*
             * Pour calculer la factorielle n!, on fait la multiplication
             * n * (n - 1) * (n - 2) * (n - 3)...
             * dans un boucle while
             */
            while (n >= 0)
            {
                factorielle = factorielle * n;
                n = n - 1;
            }

            Console.Out.WriteLine("La factorielle de " + n + " est " +
                                  factorielle);
            Console.In.ReadLine();
        }



