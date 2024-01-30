/*
 ************************************************************************************
 * Authors: salma.aghrizen@etu.univ-cotedazur.fr, bastien.briat@etu.univ-cotedazur.fr
 ************************************************************************************
 *
 * Ce script contient la déclaration de la classe disque
 * Chaque disque contient sa propre taille, en fonction de nombre des disques choisis par l'utilisateur.
*/

// Pour garantir qu'il n'ya pas des doubles inclusions de ce fichier:
#ifndef TOURSHANOI_DISQUE_CLASS
#define TOURSHANOI_DISQUE_CLASS
#include <string>
#include <random>


using namespace std;

// La déclaration de la classe:
class Disque {
	// La déclarations des éléments publiques:
public:
	// La déclaration du constructeur:
	Disque();
	/* La déclaration du constructeur avec ces paramètres
	 * s: la taille
	 * t: la taille du jeu
	 */
	 Disque(int s, int t);
	 Disque(int s, int t, unsigned char ColorDisk[3]);
	
	int getTaille();
	void getColor(unsigned char Color[3]);
	// pour retourner une présentation sous forme de chaîne du disque
	string toString();
	unsigned char ColorDisk[3];
	// La déclaration des éléments privés:
private:
	// la taille de notre disque
	int m_taille;
	// la taille de notre jeu
	int m_jeusize;
	
};


#endif
