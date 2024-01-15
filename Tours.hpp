// pour éviter la double inclusion:
#ifndef TOURSHANOI_TOUR_CLASS
#define TOURSHANOI_TOUR_CLASS
#include <string>
#include "Disque.hpp"
using namespace std;

/*
 *Définition du Tour avec ses disques
 */

#include "Disque.hpp"

const int MAX_DISQUE = 8; // Le nombre max des disques pour le jeu 
class Tour {
public: 
  Tour();
  Tour(int n, bool vide);
  Disque getDisque(int k);
  int sommet();
  void push(Disque  &d);
  void pop();
  void assign(int taille, bool vide);
private:
  // Le pilier
  Disque m_pilier[MAX_DISQUE];
  // L'indice de notre sommet
  int m_top; 
  // La dimension du socle
  int m_dim; 
};

#include "Tour.cpp"
