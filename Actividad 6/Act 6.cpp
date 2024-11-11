#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para inicializar srand()
#include "Juego.h"
#include "Enemy.h"
#include "crosshair.h"

using namespace sf;
using namespace std;

int main() {
	Juego miJuego;
	miJuego.Loop();

	return 0;
}


