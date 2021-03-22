using System;

namespace ProgAvecBogueCorrigee
{
    class Program
    {
        static void Main(string[] args)
        {
            // programme corrigé

            
                int n = 0; // nombre saisi

                int factorielle = 1; // factorielle de n (n!)

                int copieN; // une copie de n



                Console.Out.WriteLine("Entrez un entier > 0");

                n = int.Parse(Console.In.ReadLine());

                copieN = n;



                /*

                 * Pour calculer la factorielle n!, on fait la mult.

                 * n * (n - 1) * (n - 2) * (n - 3)...

                 * dans un boucle while

                 */

                while (n > 0)

                {

                    factorielle = factorielle * n;

                    n = n - 1;

                }



                Console.Out.WriteLine("La factorielle de " + copieN +

                                      " est " + factorielle);

                Console.In.ReadLine();

            }
        }
    }
