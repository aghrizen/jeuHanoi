/* 
   This class contains the declaration of the object: disque 
   Each 'disque' has it's own size, in the function of the number of diques.
*/

#ifndef TOURSHANOI!DISQUE_CLASS
#define TOURSHANOI_DISQUE_CLASS
#include <string>
using namespace std;

// Declaration of the class
class Disque {
public:
  // Declaring the constructor
  Disque();
  // Declaring the constructor with parameters
  // s is the size
  // t is the size of the game
  Disque(int s, int t);   
  int getTaille() const;
  // pour retourner une présentation sous forme de chaîne du disque
  string toString() const;
private:
  // la taille de notre disque
  int m_taille;
  // la taille de notre jeu
  int m_jeusize;
};

#include "Disque.cpp"
