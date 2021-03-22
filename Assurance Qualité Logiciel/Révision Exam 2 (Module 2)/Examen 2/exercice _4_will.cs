/* IVa-) Solution attendue  (20)
                
-/- Georgetown Cleaning Services -/-
====================================
Customer:    Steve Longley
Home Phone:  301-208-2333
Order Date:  Thursday, April 8, 2010
Order Time:  9:22 AM
------------------------------------
Item Type  Qty Unit/Price Sub-Total
------------------------------------
Shirts      3     0.950     2.850
Pants       5     2.950    14.750
Others      8     4.550    36.400
------------------------------------
Total Order:   54.000
Tax Rate:      15.750%
Tax Amount:    8.505
Net Price:     62.505
------------------------------------
Amount Tended: 100.000
Difference:    37.495
====================================

Le code ci-dessous contient un bug(erreur logique), utilisez les techniques
 de debugage vues en classes pour le détecter et le résoudre.

 N'ajoutez pas de code extra, modifié juste le code ci-dessous sans ajouté une
 variable ou une fonction, juste modifié les ligne(s) causant l'erreur.(20)

Ci-dessous, donnez aussi une description des étapes utilisées pour arriver à la
solution.

Quelques indices pour vous aider à arriver à la solution:

- La fonction obtenirTotalDeLaFacture fonctionne bien, donc vous pouvez la sauter

- Mettez un point d'arrêt/Break point/F9 à la ligne 155, et utilisez la fenêtre
appropriée pour verifier le contenue des variables.

-Pour imprimer le taux d'intérêt avec le signe de pourcentage (%), vous pouvez passer
en paramètre P a la fonction ToString("") à la ligne 135.
 */


using System;

public class OrderProcessing
{
    public static int Main()
    {
        // Price of items
        const double PriceOneShirt = 0.95;
        const double PriceAPairOfPants = 2.95;
        const double PriceOtherItem = 4.55;
        const double TaxRate = 15.75;

        // Basic information about an order
        string customerName, homePhone;
        DateTime orderDate, orderTime;
        // Unsigned numbers to represent cleaning items
        uint numberOfShirts, numberOfPants, numberOfOtherItems;
        // Each of these sub totals will be used for cleaning items
        double subTotalShirts, subTotalPants, subTotalOtherItems;
        // Values used to process an order
        double totalOrder, taxAmount, totalDeLaFacture;
        double sommeTendue, remboursement;

        Console.Title = "Watts A Loan?";

        Console.Title = "Georgetown Cleaning Services";
        Console.WriteLine("-/- Georgetown Cleaning Services -/-");

        customerName = "Steve Longley";

        homePhone = "301-208-2333";

        orderDate = DateTime.Parse("04/08/2010");

        orderTime = DateTime.Parse("09:22 AM");

        numberOfShirts = 3;

        numberOfPants = 5;

        numberOfOtherItems = 8;

        // Perform the necessary calculations
        subTotalShirts = numberOfShirts * PriceOneShirt;
        subTotalPants = numberOfPants * PriceAPairOfPants;
        subTotalOtherItems = numberOfOtherItems * PriceOtherItem;

        // Calculate the "temporary" total of the order
        totalOrder = subTotalShirts +
                     subTotalPants +
                     subTotalOtherItems;

        taxAmount = totalOrder * (TaxRate / 100);

        totalDeLaFacture = obtenirTotalDeLaFacture(totalOrder, taxAmount); 

        Console.WriteLine("\nThe Total order is: {0:F}",
                  totalDeLaFacture);

        sommeTendue = 100;

        remboursement = obtenirRemboursement(totalDeLaFacture, sommeTendue);

        Console.Clear();

        Console.WriteLine("====================================");
        Console.WriteLine("-/- Georgetown Cleaning Services -/-");
        Console.WriteLine("====================================");
        Console.WriteLine("Customer:    {0}", customerName);
        Console.WriteLine("Home Phone:  {0}", homePhone);
        Console.WriteLine("Order Date:  {0:D}", orderDate);
        Console.WriteLine("Order Time:  {0:t}", orderTime);
        Console.WriteLine("------------------------------------");
        Console.WriteLine("Item Type  Qty Unit/Price Sub-Total");
        Console.WriteLine("------------------------------------");
        Console.WriteLine("Shirts{0,7}{1,10}{2,10}",
                  numberOfShirts.ToString(),
                  PriceOneShirt.ToString("F3"),
                  subTotalShirts.ToString("F3"));
        Console.WriteLine("Pants{0,8}{1,10}{2,10}",
                  numberOfPants.ToString(),
                  PriceAPairOfPants.ToString("F3"),
                  subTotalPants.ToString("F3"));
        Console.WriteLine("Others{0,7}{1,10}{2,10}",
                  numberOfOtherItems.ToString(),
                  PriceOtherItem.ToString("F3"),
                  subTotalOtherItems.ToString("F3"));
        Console.WriteLine("------------------------------------");
        Console.WriteLine("Total Order:   {0}",
                  totalOrder.ToString("F3"));
        Console.WriteLine("Tax Rate:      {0}", (TaxRate / 100).ToString("P3"));
        Console.WriteLine("Tax Amount:    {0}",
                  taxAmount.ToString("F3"));
        Console.WriteLine("Net Price:     {0}",
                  totalDeLaFacture.ToString("F3"));
        Console.WriteLine("------------------------------------");
        Console.WriteLine("Amount Tended: {0}",
                  sommeTendue.ToString("F3"));
        Console.WriteLine("Difference:    {0}",
                  remboursement.ToString("F3"));
        Console.WriteLine("====================================");

        System.Console.ReadKey();

        double obtenirTotalDeLaFacture(double somme1, double somme2)
        {
            double total = somme1 + somme2;
            return total;
        }

        double obtenirRemboursement(double somme1, double somme2)
        {
            double remboursement = somme1 - somme2;
            return Math.Abs(remboursement);
        }

        return 0;
    }
}


/*
     IV-b) donnez une description des étapes utilisées pour arriver à la solution. (10)
         Utilisez des mots techniques vus en cours.
 */

// Lors de la mise en place d'un point d'arrêt à la ligne 155 on peux voir que le total de la facture n'est pas bon.
// Le montant des taxes dans l'affichage semble aussi mauvais. J'ai alors vérifier que le taux de taxes additionner au montant
// total de la facture correspondait à 62.505 ce qui n'était pas le cas. Après l'analyse de la variable taxAmount on peux constater
// que le programme multiplie le soustotal à 15.75. C'est une erreure de logique et il faut diviser par 100 pour avoir le bon taux.

// Aussi, après quelques step over jusqu'à la ligne 136,
// on peux constater que le taux de taxes n'est pas bien affiché.
// J'ai alors ajouter la clé de format P et aussi afficher la division de la constante TaxRate par 100.

// Aussi, les unités monétaires doivent afficher 3 chiffre après la virgule. La documentation de microsoft
// spécifie qu'il faut utilsé fixed point (F3) dans le format du ToString pour avoir 3 chiffre.

// Finalement, le remboursement dans l'affichage (Difference: ) présente un signe négatif mais pas dans solution attendue.
// J'ai simplement retourner la valeure absolue de la variable afin d'avoir un affichage positif ce qui est plus intuitif.

