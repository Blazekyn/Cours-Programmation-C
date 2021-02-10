
	
//	                        Assurance Qualité Logiciel – Examen Module 1
	                        ---------------------------------------------



//							Partie I: Theorie, Règles, Principes et Nommage (25 points) 
							-----------------------------------------------------------


1a-) // Citez ci-dessous 3 examples d'un bon code et 3 exemples d'un mauvais code (6)
--------------------------------------------------------------------------------------------
  	// 3 Caractéristiques d'un bon code

  		1-) Lisible.
		2-) Efficace ou rapide.
		3-) Documenté.

   // 3 Caractéristiques d'un mauvais code

  		1-) Non lisible ( mal documenté, commentaires, nom de variables non descriptif, etc).
		2-) Code qui n'est pas testable .
		3-) Complexité (fonctions qui font plus qu'une action, spagethi code, etc).

1b-) // Qu’est ce qui rend une fonction facile à lire et comprendre ? (1)
-------------------------------------------------------------------------



1c-) // Citez ci-dessous 3 examples d'un bon commentaire code et 3 exemples d'un mauvais commentaire (6)
--------------------------------------------------------------------------------------------------------
  	// 3 Caractéristiques d'un bon commentaire

  		1-) Donne de l'information.
		2-) Explique l'intention du code.
		3-) Met en garde d'un certain bug ou autre.

   // 3 Caractéristiques d'un mauvais commentaire

  		1-) Commentaire qui se répète et qui rendent la lisibilité du code pire.
		2-) Code laissé en commentaire sans être utilisé.
		3-) Commentaires menteur.
	

1d-) /*
		Vous révisez le code de votre camarade et vous trouvez la déclaration d’identificateurs ci-dessous
  		selon vos connaissances acquises dans le cours d’assurance qualité logicielle(AQL).
  		            Quelle modifications apportez vous? (12)
    */

public void effectuerTransfertArgent(double compteDuDepot, double compteDuRetrait) {
	compteDuRetrait.balance -= This.montantTransfert;
	compteDuDepot.balance += This.montantTransfert;
}

class Horloge {
	private double nombreHeures; // nombre d’heures
	private double tempsEnMinutes; // temps en minutes

	public double lireHeure();
	public double obtenirDate();
}


// 						Partie II : Redaction de fonctions (40 points)
 						----------------------------------------------
2-a) /* 
		En cours nous avons vu qu'il existe 3 cas ou il est conseillé d’utiliser une fonction avec un seul argument
		Parmi les 5 fonctions ci-dessous, quelles sont les 3 fonctions qui suivent ces 3 cas? (6)
     */
		-- int         caculAire(Rectangle rectangle);
		-- bool        EstUnEtudiantEtranger(Etudiant etudiant);
		-- void        timerExpired(int numberOfSeconds);
		-- double      CalculateInterestAmount(int numberOfMonths)
		-- InputStream fileOpen(“MyFile”);

		1-) void        timerExpired(int numberOfSeconds); // Évenement avec modification d'état -> void
		2-) bool        EstUnEtudiantEtranger(Etudiant etudiant); // Pose une question sur l'argument
		3-) InputStream fileOpen(“MyFile”); // Transforme l'argument

2-b) // Modifiez la declaratiion de la fonction ci-dessous afin qu'elle ait le moins d'arguments possible (4 points)

	void inscrireEtudiantDansUncours(Course course, string studentFirstName, string studentLastname, string studentID);
	
	1- void inscrireEtudiantDansUncours(Course course, Student student);
	
	OU
	
	2- void inscrireEtudiantDansUncours(Student student); // Pcq course pourrait appartenir à la classe Student.

2-c) /* 
		Modifiez la fonction ci-dessous afin de faciliter sa lecture et sa compréhension.
		Assurez vous que le niveau d'indentation est de deux max, et que chaque fonction 
		ne fait qu'une seule action, et eviter de dupliquer le code (30)
     */

	public double calculFraisDetudes(Etudiant etudiant){

		double fraisDebase = 1000;
		double fraisExtraIngenieur = 100;
		double fraisExtraScienceSociales = 75;
		double fraisExtraMedecine = 125;
		double fraisEtudiantEtranger = 200;

		if(etudiant.EstUnEtudiantEtranger()){
			if(etudiant.Faculte == "Ingenieurie"){
				return fraisDebase + fraisExtraIngenieur + fraisEtudiantEtranger;
			} else if(etudiant.Faculte == "Medecine"){
				return fraisDebase + fraisExtraMedecine + fraisEtudiantEtranger;
			} else if(etudiant.Faculte == "Sciences Sociales"){
				return fraisDebase + fraisExtraScienceSociales + fraisEtudiantEtranger;
			}
			return fraisDebase + fraisEtudiantEtranger;
		}

		if(etudiant.Faculte == "Ingenieurie"){
			return fraisDebase + fraisExtraIngenieur;
		} else if(etudiant.Faculte == "Medecine"){
			return fraisDebase + fraisExtraMedecine;
		} else if(etudiant.Faculte == "Sciences Sociales"){
			return fraisDebase + fraisExtraScienceSociales;
		}
		return fraisDebase;

	}
	
	
// **************************************************************** MA RÉPONSE
	
public double calculFraisDetudes(Etudiant etudiant)
{ 
    const double fraisDebase = 1000;
    const double fraisExtraIngenieur = 100;
    const double fraisExtraScienceSociales = 75;
    const double fraisExtraMedecine = 125;
    const double fraisEtudiantEtranger = 200;
            
    double fraisRegulierIngenieur = fraisDebase + fraisExtraIngenieur;
    double fraisRegulierMedecine = fraisDebase + fraisExtraMedecine;
    double fraisRegulierScienceSociales = fraisDebase + fraisExtraScienceSociales;
            
    double fraisDeBaseEtranger = fraisDebase + fraisEtudiantEtranger;
    double fraisEtrangerIngenieur = fraisDeBaseEtranger + fraisExtraIngenieur;
    double fraisEtrangerMedecine = fraisDeBaseEtranger + fraisExtraMedecine;
    double fraisEtrangerScienceSociales = fraisDeBaseEtranger + fraisExtraScienceSociales;
            
            
    var faculteEtudiant = etudiant.Faculte;

    switch (faculteEtudiant)
    {
        case "Ingenieurie":
        {
            return etudiant.EstUnEtudiantEtranger() ? fraisEtrangerIngenieur : fraisRegulierIngenieur;
        }

        case "Medecine":
        {
            return etudiant.EstUnEtudiantEtranger() ? fraisEtrangerMedecine : fraisRegulierMedecine;
        }
        case "Sciences Sociales":
        {
            return etudiant.EstUnEtudiantEtranger() ? fraisEtrangerScienceSociales : fraisRegulierScienceSociales;
        }
    }
            
    return fraisDebase;
}

// 						Partie III : Doducmentation du code source (35 points)
 						------------------------------------------------------
 	3a-) // Modifiez le code ci-dessous afin qu'il suive les principes etudier durant le module 1
//         (enlevez les mauvais commentaires, propre indentation, noms dindentificateurs descriptifs,
//		   formatage conforme) (25)

using System;

namespace ValeurAbsolueTryCatch
{
    class Program
    {
        static void Main(string[] args)
        {
            //Declaration des variables
            double x;
            // Recuperation de la chaine saisie par l'utilisateur + sa conversion
            System.Console.Write("Entrez un nombre x = ");
            try
            {
                x = Double.Parse(System.Console.ReadLine());
                // if - else pour verifier la valeur absolue d'un entier avec affichage du resultat
                if (x < 0) Console.WriteLine("|x| = " + (-x));
                else System.Console.WriteLine("|x| = " + x);
            }
            catch (FormatException)
            { //...traitement de l'erreur de saisie 
                Console.WriteLine( "Vous n'avez pas saisie un nombre!");
            }
        }
    }
}

// **************************************************************** MA RÉPONSE
using System;

namespace ValeurAbsolueTryCatch
{
    class Program
    {
        static void Main(string[] args)
        {
            double userInputToAbsoluteValue;
            
            Console.Write("Entrez un nombre pour trouver sa valeur absolue : ");
            
            try
            {
                userInputToAbsoluteValue = Double.Parse(Console.ReadLine() ?? string.Empty);
                
                if (userInputToAbsoluteValue < 0)
                {
                    Console.WriteLine($"|{userInputToAbsoluteValue}| = " + (-userInputToAbsoluteValue));
                }
                else
                {
                    Console.WriteLine($"|{userInputToAbsoluteValue}| = " + userInputToAbsoluteValue);
                }
            }
            catch (FormatException)
            {
                Console.WriteLine("Vous n'avez pas saisie un nombre!");
            }
        }
    }
}

3b-) // Modifiez le code ci-dessous afin qu'il suive les principes etudier durant le module 1
//         (enlevez les mauvais commentaires, propre indentation, noms dindentificateurs descriptifs,
//		   formatage conforme) (10)

using System;namespace Triangle{public class Program{public static int getSurface(int Base, int hauteur)
{return ((Base * hauteur) / 2);}public static void Main()
{Console.WriteLine(getSurface(8, 2));
Console.WriteLine(getSurface(7, 3));
}}}


// **************************************************************** MA RÉPONSE

using System;

namespace Triangle
{
    public class Program
    {
        public static int GetSurfaceTriangle(int baseTriangle, int hauteurTriangle)
        {
            return ((baseTriangle * hauteurTriangle) / 2);
        }

        public static void Main()
        {
            Console.WriteLine(GetSurfaceTriangle(8, 2));
            Console.WriteLine(GetSurfaceTriangle(7, 3));
        }
    }
}






































