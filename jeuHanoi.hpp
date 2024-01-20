/*
 ************************************************************************************
 * Authors: salma.aghrizen@etu.univ-cotedazur.fr, bastien.briat@etu.univ-cotedazur.fr
 ************************************************************************************
 *
 * Ce script contient la déclaration de la classe ToursHanoi pour décrir le déroulement du jeu.
 */
#ifndef JEUHANOI_CLASS
#define JEUHANOI_CLASS
#include <iostream>
#include <string>
using namespace std;

#include "Tour.hpp"
const int T_MAX = 3; // le nombre MAX des tours
class ToursHanoi
{
  public:
    explicit ToursHanoi(int n);
    void afficherTours() const;
    void jouer();
  private:
    void deplacer(int o, int d);
    void hanoi(int n, int orig, int dest, int inter);
    void initialiser();
    
    HTour m_tours[T_MAX]; // les tours
    int m_hauteur; // nombre de disques
    
    int m_ndeplts; // nombre de deplacements
};
#endif
