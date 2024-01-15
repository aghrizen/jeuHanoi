#include <iostream>
#include "ToursDeHnoi.hpp"

int main() {
  int nombreDisques; //nombre des disques pour le jeu

  std::cout << "Veuillez choisir un numéro des diques pour commencer le jeu: ";
  std::cin >> nombreDisques;

  ToursDeHanoi game(nombreDisques);
  game.resoudre();

  return 0;

}
