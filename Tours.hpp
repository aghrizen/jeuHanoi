/*
 ************************************************************************************
 * Authors: salma.aghrizen@etu.univ-cotedazur.fr, bastien.briat@etu.univ-cotedazur.fr
 ************************************************************************************
 */
// pour éviter la double inclusion:
#ifndef TOUR_CLASS
#define TOUR_CLASS
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
  Tour(int TowerTag);
  Tour(int TowerTag, int n);
  int TourTag;
  bool MoveDisk(Tour* TourDestination);
  bool AddDisk(Disque* Disque);
  
  void ShowDiskList();

private:
  //Liste de nos disques sur la Tour (dans l'ordre)
  vector <Disque*> ListeDisqueInOrder();
  // L'indice de notre sommet
  int top_index;
};
