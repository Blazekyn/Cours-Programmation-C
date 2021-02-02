/*==========================================================
Programmeur : Alexandre Tremblay
Fichier     : Ex2.cpp
Description : Programme valeur ASCII et leurs charactères
Date        : 2021/01/11
==========================================================*/
#include "pch.h"
#include <iostream>

int main() {
	/*
		  |=====================================NOTE======================================|
		 |	Salut monsieur, je sais que je ne suis pas supposé d'utiliser des loops		   |
		|	si tot mais, je connais comment le faire et je ne voulais pas copie coller      |
		|	la même chose 14 fois et changer la même chose, c'est minutieux, donc j'ai	    |
		 |	figurer pourquoi pas sauver du temps et impressioné mon prof en même temps? :D |
		  |===============================================================================|
	*/

	//Affichage Intro
	std::cout << "=== Voici des caractères et leurs valeur ASCII ===" << std::endl;

	//Array de tout les charactère a passer dans la loop
	char list[] = { 'A', 'B', 'C', 'a', 'b', 'c', '0', '1', '2', '$', '*', '+', '/', ' ' };

	//Inspiré de www.learncpp.com/cpp-tutorial/for-each-loops/
	for (char symbol : list)
	{
		std::cout << symbol << " : " << static_cast<int>(symbol) << std::endl;
	}

	return 0;
}