/*=============================================================
Programmeur : William Poncelet
Fichier     : Rationnel.h
Description : Définition de la classe Rationnel.h
Date        : 2020/02/23
=============================================================*/

#ifndef DEVOIR5_RATIONNEL_H
#define DEVOIR5_RATIONNEL_H

class Rationnel
{
public:
	explicit Rationnel(int = 1, int = 1);
    Rationnel additionner(const Rationnel&) const;
    Rationnel soustraire(const Rationnel&) const;
    Rationnel multiplier(const Rationnel&) const;
    Rationnel diviser(Rationnel&) const;
    void affichageFraction();
    void affichageFlottant() const;

private:
    int numerateur_;
    int denominateur_;
    void reduction(int a, int b);
};


#endif //DEVOIR5_RATIONNEL_H
