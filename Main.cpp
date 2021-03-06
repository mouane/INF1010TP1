/**************************************************
* Titre: Travail pratique #1 - Main.cpp
* Date: 02 fevrier 2018
* Auteur: Mohammed Esseddik BENYAHIA, Gabriel Paquette
*         Vittorio Passuello-Dussault
**************************************************/

/*
Réponses aux questions

Quel est le lien (agrégation ou composition) entre la classe Client et la Classe Panier?
Il s'agit d'une relation d'agrégation, puisque le Client et le Panier sont deux objets indépendants:
Un Panier peut exister sans un Client et vice versa. C'est une agrégation par pointeur, puisque le Client 
a comme attribut un pointeur vers un objet Panier.

Quel est le lien (agrégation ou composition) entre un Produit et un Rayon?
Il s'agit d'une relation d'agrégation, puisqu'un Rayon peut exister sans objets de la classe Produit 
et vice versa. Il s'agit d'une agrégation par pointeur, puisque le lien reliant le Rayon aux objets de 
la classe Produit est un pointeur vers un tableau de la classe Produit.
 */

#include "Produit.h"
#include "Rayon.h"
#include "client.h"
#include "panier.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	
	
	//C'est à vous de voir si vous devez allouer dynamiquement ou non les élèments

	//1-  Creez 15 objets du classe produit
    
    const int NOMBRE_OBJETS_A_CREER = 15;
	


	Produit** listeDeProduits = new Produit*[15];

	for (int i = 0; i < NOMBRE_OBJETS_A_CREER; i++)
	{
		listeDeProduits[i] = new Produit("produit" + to_string(i+1), i + 1, 10.00);
	}
    
	//2-  Modifiez le nom, la référence, le prix de  troisieme objet Produit créé
    //   afficher les attributs de cet objet Produit
	listeDeProduits[2]->modifierNom("Tide Pods");
	listeDeProduits[2]->modifierReference(911);
	listeDeProduits[2]->modifierPrix(24.78);
	
	//3-  Creez un objet du classe rayon à l'aide du constructeur par défaut
	Rayon rayonDefault = Rayon();
   
	//4-  Modifiez la catégorie  du rayon
	rayonDefault.modifierCategorie("Produits Domestiques");
   
    // 5- Ajouter 6 produits de  voret chaoix dans le rayon créé
	for (int i = 0; i < 6; i++)
	{
		rayonDefault.ajouterProduit(listeDeProduits[i]);
	}
		
    

    // 6- afficher le contenu du rayon
	rayonDefault.afficher();
  
	//7-  Creez un objet de classe client à l'aide du constructeur
	Client clientParams = Client("Georges", "Hamel", 78952, "G1Q 1Q9", 20160419);

	//8-  afficher l'etat des attributs du client
	cout << "Nom: " << clientParams.obtenirNom() << endl
		<< "Prenom: " << clientParams.obtenirPrenom() << endl
		<< "Identifiant: " << clientParams.obtenirIdentifiant() << endl
		<< "Code postal: " << clientParams.obtenirCodePostal() << endl
		<< "Date de naissance: " << clientParams.obtenirDateNaissance() << endl;

	//9-   Le client achete 9 produits
	for (int i = 0; i < 9; i++)
		clientParams.acheter(listeDeProduits[i]);

	//10- Afficher le contenu du panier du client
	clientParams.afficherPanier();
	
     //11- livrer le panier du client
	clientParams.livrerPanier();
   
    
	//12- afficher le contenu du panier du client
	clientParams.afficherPanier();
    
	//13-  terminer le programme correctement
	for (int i = 0; i < NOMBRE_OBJETS_A_CREER; i++)
	{
		delete listeDeProduits[i];
	}
	delete[] listeDeProduits;

    return 0;
}
