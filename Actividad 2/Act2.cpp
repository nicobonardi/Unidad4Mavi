//////Bibliotecas////// 
#include <SFML/Window.hpp>  
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
//////Variables//////
Texture texture1;
Sprite sprite1, sprite2, sprite3, sprite4;
int main() {
	//Cargamos la textura del archivo    
	texture1.loadFromFile("rcircle.png");
	// //Cargamos el material del sprite    
	sprite1.setTexture(texture1);
	sprite2.setTexture(texture1);
	sprite3.setTexture(texture1);
	sprite4.setTexture(texture1);
	//Movemos el sprite1
	sprite1.setPosition(0, 0);
	//Movemos el sprite2
	sprite2.setPosition(0, 472);
	//Movemos el sprite3
	sprite3.setPosition(672, 0);
	//Movemos el sprite4
	sprite4.setPosition(672, 472);
	//Creamos la ventana     
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Que ventana horrible");
	// Loop principal      
	while (App.isOpen()) {
		// Limpiamos la ventana          
		App.clear();
		// Dibujamos la escena          
		App.draw(sprite1);
		App.draw(sprite2);
		App.draw(sprite3);
		App.draw(sprite4);
		// Mostramos la ventana          
		App.display();
	}
	return 0;
}