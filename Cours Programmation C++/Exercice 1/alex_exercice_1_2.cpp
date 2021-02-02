/*==========================================================
Programmeur : Alexandre Tremblay
Fichier     : Ex2.cpp
Description : Programme valeur ASCII et leurs charact�res
Date        : 2021/01/11
==========================================================*/
#include "pch.h"
#include <iostream>

int main() {
	/*
		  |=====================================NOTE======================================|
		 |	Salut monsieur, je sais que je ne suis pas suppos� d'utiliser des loops		   |
		|	si tot mais, je connais comment le faire et je ne voulais pas copie coller      |
		|	la m�me chose 14 fois et changer la m�me chose, c'est minutieux, donc j'ai	    |
		 |	figurer pourquoi pas sauver du temps et impression� mon prof en m�me temps? :D |
		  |===============================================================================|
	*/

	//Affichage Intro
	std::cout << "=== Voici des caract�res et leurs valeur ASCII ===" << std::endl;

	//Array de tout les charact�re a passer dans la loop
	char list[] = { 'A', 'B', 'C', 'a', 'b', 'c', '0', '1', '2', '$', '*', '+', '/', ' ' };

	//Inspir� de www.learncpp.com/cpp-tutorial/for-each-loops/
	for (char symbol : list)
	{
		std::cout << symbol << " : " << static_cast<int>(symbol) << std::endl;
	}

	return 0;
}