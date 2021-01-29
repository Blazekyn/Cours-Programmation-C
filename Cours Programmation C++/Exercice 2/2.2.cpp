/*==========================================================
Programmeur : Alexandre Tremblay
Fichier     : Ex2.2.cpp
Description : écrit un motif sur la console
Date        : 2021/01/18
==========================================================*/
#include <iostream>

using namespace std;
int main()
{
	for (int i = 1; i <= 10; i++)
	{
		//1er triangle
		for (int j = 0; j < i; j++)
		{
			cout << "*";
		}
		
		//1ere espace
		for (int j = 0; j <= 13-i; j++)
		{
			cout << " ";

		}
		
		//2e triangle
		for (int j = 0; j < 11-i; j++)
		{
			cout << "*";
		}
		
		//2e espace
		for (int j = 13; j >= 13 - i; j--)
		{
			cout << " ";

		}

		for (int j = 0; j < 2+i; j++)
		{
			cout << " ";
		}

		//3e triangle
		for (int j = 0; j < 11 - i; j++)
		{
			cout << "*";
		}
		
		//4e espace
		for (int j = 0; j <= 13 - i; j++)
		{
			cout << " ";

		}
		
		//4e triangle
		for (int j = 0; j < i; j++)
		{
			cout << "*";
		}

		//passé à la prochaine ligne
		cout << "\n";
	}
}

