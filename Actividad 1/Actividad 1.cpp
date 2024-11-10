//////Bibliotecas////// 
#include <SFML/Window.hpp>  
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
//////Variables//////
Texture texture;
sf::Sprite crosshair;
int main() {
	sf::Event evt;
	//Cargamos la textura del archivo
	texture.loadFromFile("crosshair.png");
	// //Cargamos el material del sprite    
	crosshair.setTexture(texture);
	//Movemos el crosshair
	crosshair.setPosition(342, 230);
	//Creamos la ventana     
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Que ventana horrible");
	/////Loop principal//////
	while (App.isOpen())
	{
		Event evt;
		while (App.pollEvent(evt))
		{
			/////Procesar eventos//////
			switch (evt.type)
			{
				/////Si se cerro la ventana//////
			case sf::Event::Closed:
				App.close();
				break;
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape) == true)
				App.close();
		}
		App.display();
		App.draw(crosshair);
	}
	return 0;
	}
