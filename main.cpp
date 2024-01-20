/*
 * Authors: salma.aghrizen@etu.univ-cotedazur.fr, bastien.briat@etu.univ-cotedazur.fr
 *
 * Pour l'implémentation du jeu il y'en a deux modes: 
 *   --> mode Default: à l'utilisateur de déplacer les disques
 *   --> mode Démo: à l'ordi de jouer
 * Ce script contient la déclaration des deux modes du jeu. 
 * De plus, la fonction principale main pour faire fonctionner le code.
 */

#include <iostream>
#include "jeuHanoi.hpp"
#include <list>
using namespace std;

// La déclaraton du mode démo du jeu

int main() {
  int nd; // nombre des disques pour le jeu
  int choixMode; // choix du mode de jeu: défailt ou démo
  list<int> myliste;

  std::cout << "Veuillez choisir un numéro des diques pour commencer le jeu: ";
  std::cin >> nd;

  cout << "Choisissez le mode de jeu :\n";
  cout << "1. Mode Default\n";
  cout << "2. Mode Démo\n";
  cout << "Votre choix: ";
  cin >> choixMode;
  ToursHanoi jeu(nd);
  switch (choixMode) {
    case 1:
      jeu.jouer(); // Deafult Mode: à utilisateur de jouer
      break;
    case 2:
      
      jeu.resoudre(); // Démo Mode: à l'ordi de jouer
      break;
    default:
      cout << "Choix invalide.\n";
      return 1;
  }
  return 0;
}
