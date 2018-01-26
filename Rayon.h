/********************************************
* Titre: Travail pratique #1 -Rayon.h
* Date: 20 janvier 2018
* Auteur: 
*******************************************/

#ifndef RAYON_H
#define RAYON_H

#include <string>
#include "Produit.h"
using namespace std;

class Rayon
{
public:
	// Constructeurs par defaut et par paraametres
    
	Rayon(string cat="inconnu");
	~Rayon();
   
	// Methodes d'acces
	string obtenirCategorie() const;
	Produit ** obtenirTousProduits();
    int obtenirCapaciteProduits() const;
    int obtenirNombreProduits() const;
	

	// Methodes de modification
	void modifierCategorie(string cat);
    
    // autres methodes
    void ajouterProduit (Produit * produit);
    void afficher();
	

private:

	// Attributs prives
	string categorie_;
    Produit ** tousProduits_;
    int capaciteProduits_;
	int nombreProduits_;

};

#endif
