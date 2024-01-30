#include <SDL2/SDL.h>
#include "Tours.hpp"
const int T_MAX = 3; // le nombre MAX des tours
class ToursHanoi
{
public:
	void jouer();
	void resoudre();
	explicit ToursHanoi(int n);
private:
	bool deplacer(int o, int d);
	bool checkWin();
	void hanoi(int n, int orig, int dest, int inter);
	void afficherTours();
	void afficherToursNew();
	void initialiser();
	void DrawDisque(int SizeCurrentDisque, int indexTower, int indexDisque, int MinimumXSize, int MaximumXSize, int SizeY, int CurentTowerCenterX);
	void CreateRect(int posX, int posY, int sizeX, int sizeY, unsigned char Color[3]);
	unsigned char InitSDL(SDL_Window **window);

	const int SIZE_X_GAME_BOARD = 1536/2;
	const int SIZE_Y_GAME_BOARD = 864/2;

	


	enum direction
	{
		LEFT = 1,
		DOWN = 2,
		UP = 3,
		RIGHT = 4,
		ENTER = 5,

	};

	SDL_Window *window = NULL;
	SDL_Renderer *myRenderer;
	Tour* m_tours[T_MAX]; // les tours
	int m_hauteur; // nombre de disques
	
	int m_deplacement; // nombre de deplacements
};
