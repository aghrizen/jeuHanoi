/*
 * Authors: salma.aghrizen@etu.univ-cotedazur.fr, bastien.briat@etu.univ-cotedazur.fr
 * Pour l'implémentation du jeu il y'en a deux modes: 
 *   --> mode Default: à l'utilisateur de déplacer les disques
 *   --> mode Démo: à l'ordi de jouer
 * Ce script contient la déclaration des deux modes du jeu. 
 * De plus, la fonction principale main pour faire fonctionner le code.
 */

#include <iostream>
#include "ToursHanoi.hpp"
#include <list>
using namespace std;

// La déclaraton du mode démo 

int main() {
  int nombreDisques; //nombre des disques pour le jeu
  list<int> myliste;

  std::cout << "Veuillez choisir un numéro des diques pour commencer le jeu: ";
  std::cin >> nombreDisques;

  ToursHanoi.start(nombreDisques);
  game.resoudre();

  return 0;

}
