/*
 ************************************************************************************
 * Authors: salma.aghrizen@etu.univ-cotedazur.fr, bastien.briat@etu.univ-cotedazur.fr
 ************************************************************************************
 * Ce script contient la déclaration des fonctions définit dans le jeuHanoi.hpp
 */

/*
 *ToursHanoi: une fonction pour déplacer le disque de la positio origine vers la position destination
 */
void ToursHanoi::deplacer(int origin_pos, int dest_pos)
{
  Tour &orig = m_tours[origin_pos];
  Tour &dest = m_tours[dest_pos];
  int top1 = orig.sommet();
  HDisque dk = orig.getDisque(top1);
  orig.pop();
  dest.push(dk);
  ++m_ndeplts;
}

/*
 * La méthode principale récursive pour le jeu du Hanoi
 * Les variables:
 * --> n: le nombre des disques
 * --> orig: la tour origine
 * --> dest: la tour de la destination
 * --> inter: la tour intérmediaire
 */
void ToursHanoi::hanoi(int n, int orig, int dest, int inter)
{
  if (n > 0)
  {
    hanoi(n-1, orig, inter, dest);
    deplacer(orig, dest);
    afficherTours();
    hanoi(n-1, inter, dest, orig);
  }
}

/*
 * Cette fonction permet de initialiser certaines variable de la classe définit dans jeuHanoi.hpp
 */
void ToursHanoi::initialiser()
{
  // initialiser le premier élément de m_tours avec m_hauteur éléments avec la valeur false
  m_tours[0].assign(m_hauteur, false);
  // initialiser le deuxième élément de m_tours avec m_hauteur éléments avec la valeur true
  m_tours[1].assign(m_hauteur, true);
  // initialiser le troisième élément de m_tours avec m_hauteur éléments avec la valeur true
  m_tours[2].assign(m_hauteur, true);
  m_ndeplts = 0;
}


/*
 * Cette fonction est un constructeur de la classe ToursHanoi définit dans jeuHanoi.hpp
 * Input: un entier n 
 * Rôle: initialise l'objet ToursHanoi en utilisant une hauteur spécifiée
 */
ToursHanoi::ToursHanoi(int n)
: m_hauteur(n < NMAXDISQUES ? n : NMAXDISQUES) {
  if (n >= NMAXDISQUES) {
    m_hauteur = NMAXDISQUES;}
}

/*
 * Cette fonction a pour but d'afficher l'état actuel du jeu
*/
void ToursHanoi::afficherTours() const
{
  // variable 's' pour construire la représentation du jeu
  string s;
  for (int i = m_hauteur-1; i >= 0; --i)
  {
    s += m_tours[0].getDisque(x).toString();
    s += m_tours[1].getDisque(x).toString();
    s += m_tours[2].getDisque(x).toString();
    s += "\n";
  }
  // construction d'une chaîne de caractères '*' qui représente le socle du jeu
  s += string(6*m_hauteur-1, '*');
  s += "\n";
  // affichage de la chaîne du jeu
  cout << s << endl;
}

/*
 * Cette fonction permet d'éxecuter le jeu 
*/
void ToursHanoi::jouer()
{
  initialiser();
  afficherTours();
  hanoi(m_hauteur, 0, 2, 1);
  cout<<"Nombre de deplacements = "<<m_ndeplts<<endl;
}
