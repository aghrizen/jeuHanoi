#include <iostream>
#include "ToursHanoi.hpp"
#include <list>
using namespace std;

int main() {
  int nombreDisques; //nombre des disques pour le jeu
  list<int> myliste;

  std::cout << "Veuillez choisir un numéro des diques pour commencer le jeu: ";
  std::cin >> nombreDisques;

  ToursHanoi.start(nombreDisques);
  game.resoudre();

  return 0;

}
