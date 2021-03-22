#pragma once


class Donnees {
public:
	Donnees(int = 100); // constructeur par défaut

	// Constructeur paramétré
	Donnees(const double* arr, const int nbValeurs, const int szValeurs = 100)
	{
		valeurs_ = new double[szValeurs];

		for (int i = 0; i < nbValeurs; i++)
		{
			valeurs_[i] = arr[i];
		}

		nbValeurs_ = nbValeurs;
		szValeurs_ = szValeurs;
	} 

	// Ajoute une donnée à valeurs[]
	Donnees& ajout(const double nombre)
	{
		valeurs_[nbValeurs_++] = nombre;
		
		std::cout << valeurs_[0] << "\n";
		std::cout << valeurs_[1] << "\n";
		std::cout << valeurs_[2] << "\n";
		std::cout << valeurs_[3] << "\n";
		std::cout << valeurs_[4] << "\n";
		return *this;
	}

	~Donnees()
	{
		delete[] valeurs_;
	}
	
	// Calcule la moyenne des données
	double moyenne() const
	{
		double somme = 0;
		for (int i = 0; i < nbValeurs_; i++)
		{
			somme += valeurs_[i];
		}
		// Ajouter la division
		return somme / nbValeurs_;
	}
private:
	double* valeurs_; // stockage de données
	int nbValeurs_, // nombre de données dans valeurs[]
		szValeurs_; // taille du tableau valeurs[]
};