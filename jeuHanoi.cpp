/*
 ************************************************************************************
 * Authors: salma.aghrizen@etu.univ-cotedazur.fr, bastien.briat@etu.univ-cotedazur.fr
 ************************************************************************************
 * Ce script contient la déclaration des fonctions définit dans le jeuHanoi.hpp
 */

 /*
  * Rôle: déplacer le disque de la positio origine vers la position destination
  * paramètres:
  * --> po: position d'origine
  * --> pd:position de destination
  */
#include "jeuHanoi.hpp"
#include "Disque.hpp"
#include "Tours.hpp"
#include <thread>
#include <iostream>
using namespace std;

bool ToursHanoi::deplacer(int po, int pd) {
	bool IsMovePossible;
	Tour* orig = m_tours[po];
	Tour* dest = m_tours[pd];

	IsMovePossible = orig->MoveDisk(dest);

	return IsMovePossible;
}

/*
 * La méthode principale récursive pour le jeu du Hanoi
 * Les variables:
 * --> n: le nombre des disques
 * --> orig: la tour origine
 * --> dest: la tour de la destination
 * --> inter: la tour intérmediaire
 */
void ToursHanoi::hanoi(int n, int orig, int dest, int inter) {
	if (n > 0) {
		hanoi(n - 1, orig, inter, dest);
		deplacer(orig, dest);
		afficherTours();
		afficherToursNew();
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
		
		hanoi(n - 1, inter, dest, orig);
	}
}

/*
 * Cette fonction permet de initialiser certaines variable de la classe définit dans jeuHanoi.hpp
 */
void ToursHanoi::initialiser() {
	// initialiser le premier élément de m_tours avec m_hauteur éléments avec la valeur false
	m_tours[0] = new Tour(1, m_hauteur);
	// initialiser le deuxième élément de m_tours avec m_hauteur éléments avec la valeur true
	m_tours[1] = new Tour(2);
	// initialiser le troisième élément de m_tours avec m_hauteur éléments avec la valeur true
	m_tours[2] = new Tour(3);
	m_deplacement = 0;
	
}


/*
 * Cette fonction est un constructeur de la classe ToursHanoi définit dans jeuHanoi.hpp
 * Input: un entier n
 * Rôle: initialise l'objet ToursHanoi en utilisant une hauteur spécifiée
 */
ToursHanoi::ToursHanoi(int n)
// D_MAX: nombre maximum des disques 
	: m_hauteur(n < MAX_DISQUE ? n : MAX_DISQUE) {
	if (n >= MAX_DISQUE) {
		m_hauteur = MAX_DISQUE;
	}
}

/*
 * Cette fonction a pour but d'afficher l'état actuel du jeu
*/
void ToursHanoi::afficherTours() {

	//Disque vide en cas de tour vide, on affiche un disque vide pour prendre l'espace de caractere
	Disque tempDisque = Disque(0, m_hauteur);
	// variable 's' pour construire la représentation du jeu
	string s;
	for (int i = m_hauteur - 1; i >= 0; --i) {
		if (m_tours[0]->getDisque(i) != NULL)
			s += m_tours[0]->getDisque(i)->toString();
		else
			s += tempDisque.toString();
			
		if (m_tours[1]->getDisque(i) != NULL)
			s += m_tours[1]->getDisque(i)->toString();
		else
			s += tempDisque.toString();

		if (m_tours[2]->getDisque(i) != NULL)
			s += m_tours[2]->getDisque(i)->toString();
		else
			s += tempDisque.toString();
		s += "\n";
	}
	// construction d'une chaîne de caractères '*' qui représente le socle du jeu
	s += string(47, '-'); // 6*8 - 1 = 47 pour garder toujours même taille 
						  // de socle quelque soit le nombre des disques 
	s += "\n";
	// affichage de la chaîne du jeu
	cout << s << endl;
}

void ToursHanoi::afficherToursNew() 
{
	int SpaceBetweenTower = 20;
	int MinimumXSize = SIZE_X_GAME_BOARD / T_MAX * 0.2F;
	int MaximumXSize = SIZE_X_GAME_BOARD / T_MAX - SpaceBetweenTower * T_MAX;
	int SizeY = SIZE_Y_GAME_BOARD / m_hauteur * 0.8F;

	int SizeCurrentDisque;
	int CurentTowerCenterX;

	
	SDL_SetRenderDrawColor(myRenderer, 0, 0, 0, 255);
	SDL_RenderClear(myRenderer);

	for (int indexTower = 0; indexTower < T_MAX; indexTower++)
	{
		if (indexTower == 0)
		{
			CurentTowerCenterX = MaximumXSize / 2;
		}
		else
		{
			CurentTowerCenterX = CurentTowerCenterX + MaximumXSize + SpaceBetweenTower;
		}
		//DrawTower(indexTower, );
		for (int indexDisque = 0; indexDisque < m_hauteur; indexDisque++)
		{
			if (m_tours[indexTower]->getDisque(indexDisque) != NULL)
			{
				SizeCurrentDisque = m_tours[indexTower]->getDisque(indexDisque)->getTaille();
				DrawDisque
				(
					SizeCurrentDisque, indexTower, indexDisque, MinimumXSize, MaximumXSize, SizeY, CurentTowerCenterX
				);
			}
		}
	}
	SDL_RenderPresent(myRenderer);

}


void ToursHanoi::DrawDisque(int SizeCurrentDisque, int indexTower, int indexDisque, int MinimumXSize, int MaximumXSize, int SizeY, int CurentTowerCenterX)
{


	int DisqueSizeX = MinimumXSize + (MaximumXSize - MinimumXSize) * SizeCurrentDisque / m_hauteur;
	int DisqueXpos = CurentTowerCenterX - DisqueSizeX / 2;
	int DisqueYpos = SIZE_Y_GAME_BOARD - ( 10 + indexDisque * SizeY) - SizeY;
	
	
	unsigned char bleu[3]={170,219,225};
	unsigned char	roseP[3]={255,182,193};
	unsigned char	vert[3]={218,242,164};
	unsigned char	beige[3]={245,245,220};
	unsigned char	violetC[3] ={200,162,200};
	unsigned char	violetP[3]={219,187,255};
	unsigned char	beigeP[3]={222,184,135};
	unsigned char	rouge[3]={255,211,210};


	switch (SizeCurrentDisque % 8)
	{
		case 0:
			CreateRect(DisqueXpos, DisqueYpos, DisqueSizeX, SizeY, bleu);
			break;

		case 1:
			CreateRect(DisqueXpos, DisqueYpos, DisqueSizeX, SizeY, roseP);
			break;

		case 2:
			CreateRect(DisqueXpos, DisqueYpos, DisqueSizeX, SizeY, vert);
			break;
			
		case 3:
			CreateRect(DisqueXpos, DisqueYpos, DisqueSizeX, SizeY, beige);
			break;
			
		case 4:
			CreateRect(DisqueXpos, DisqueYpos, DisqueSizeX, SizeY, violetC);
			break;

		case 5:
			CreateRect(DisqueXpos, DisqueYpos, DisqueSizeX, SizeY, violetP);
			break;
			
		case 6:
			CreateRect(DisqueXpos, DisqueYpos, DisqueSizeX, SizeY, beigeP);
			break;
		case 7:
			CreateRect(DisqueXpos, DisqueYpos, DisqueSizeX, SizeY, rouge);
			break;

		default:
			CreateRect(DisqueXpos, DisqueYpos, DisqueSizeX, SizeY, rouge);
		
	}


	

}

void ToursHanoi::CreateRect(int posX, int posY, int sizeX, int sizeY, unsigned char Color[3])

{

	SDL_Rect rect;
	rect.x = posX;
	rect.y = posY;
	rect.w = sizeX;
	rect.h = sizeY;

	//SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(myRenderer, Color[0], Color[1], Color[2], 255);
	SDL_RenderDrawRect(myRenderer, &rect);
	SDL_RenderFillRect(myRenderer, &rect);
}


/*
 * Rôle: cette fonction permet de vérifier si le joueur a gagné
 * Output: elle retourne 'vrai' si tous les disques sont placés vers la tour de destination
 * Sinon, elle retourne 'false'
 */
bool ToursHanoi::checkWin() {
	// Si la derniere tour a atteint la hauteur max --> Tout les disques sont sur la derniee tour
	if (m_tours[2]->TourSize >= m_hauteur)
	{
		return true;
	}
	// si aucun disque maquant n'est trouvé, le joueur a gagné
	return false;
}


/*
 * Cette fonction permet d'éxecuter le jeu
*/
void ToursHanoi::resoudre() {
	initialiser();
	InitSDL(&window);
	afficherTours();
	afficherToursNew();
	
	
	hanoi(m_hauteur, 0, 2, 1);
	cout << "Nombre de deplacements = " << m_deplacement << endl;

	if (checkWin()) {
		cout << "Félicitations ^^ vous avez gangé :) !" << endl;
	}
	else {
		cout << "Vous n'avez pas gagné :( ." << endl;
	}
}

void ToursHanoi::jouer() {
	initialiser();
	string reponse = "";
	int origine_index;
	int destination_index;
	bool IsMoveLegal;
	InitSDL(&window);

	while (checkWin() == false)
	{
		afficherToursNew();
		afficherTours();

		cout << "Choisir la colonne origine, puis la colonne destination, de 1 à 3, sans espace" << endl;
		while(reponse.size() < 1)
		cin >> reponse;

		origine_index = reponse[0] - '0';
		destination_index = reponse[1] - '0';
		reponse = "";

		if (origine_index >= 1 && origine_index <= 3 && destination_index >= 1 && destination_index <= 3)
		{

			IsMoveLegal = m_tours[origine_index - 1]->MoveDisk(m_tours[destination_index - 1]);

			if (IsMoveLegal == true)
			{
				continue;
			}
			else
			{
				//Aficher rouge
				cout << "Numéro de tour invalide, veuillez recommencer" << endl;
			}
		}
		else
		{
			//Aficher rouge
			cout << "Numéro de tour invalide, veuillez recommencer" << endl;
		}

	}




	cout << "Nombre de deplacements = " << m_deplacement << endl;

	if (checkWin()) {
		cout << "Félicitations ^^ vous avez gangé :) !" << endl;
	}
	else {
		cout << "Vous n'avez pas gagné :( ." << endl;
	}
}

unsigned char ToursHanoi::InitSDL(SDL_Window **window) {
	if (0 != SDL_Init(SDL_INIT_VIDEO))
	{
		return EXIT_FAILURE;
	}
	*window = SDL_CreateWindow("SDL2", 0, 0,
		SIZE_X_GAME_BOARD, SIZE_Y_GAME_BOARD, SDL_WINDOW_SHOWN);
	if (NULL == *window)
	{
		return EXIT_FAILURE;
	}

	SDL_CreateRenderer(*window, 0, SDL_INIT_VIDEO);
	myRenderer = SDL_GetRenderer(*window);
	return 0;
}
