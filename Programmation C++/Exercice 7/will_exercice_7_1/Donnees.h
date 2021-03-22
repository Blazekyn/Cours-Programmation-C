#pragma once
const int MAX = 100;
class Donnees
{
public:
	Donnees(): valeurs_(nullptr), nbValeurs_(0)
	{
	}

	Donnees(const double* arr, const int size)
	{
		valeurs_ = new double[MAX];
		
		for (int i = 0; i < size; i++)
		{
			valeurs_[i] = arr[i];
		}

		nbValeurs_ = size;
		
	}

	~Donnees()
	{
		delete[] valeurs_;
	}

	double moyenne() const
	{
		double somme = 0;
		for (int i = 0; i < nbValeurs_; i++)
		{
			somme += valeurs_[i];
		}
		
		return somme;
	}

private:
	double* valeurs_;
	int nbValeurs_;
};



