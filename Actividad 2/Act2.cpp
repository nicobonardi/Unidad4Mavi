#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;
int main()
{
	Texture redc;
	Sprite sprite1, sprite2, sprite3, sprite4;
	vector<Sprite> sprites;
	redc.loadFromFile("rcircle.png");
	sprite1.setTexture(redc); sprites.push_back(sprite1);
	sprite2.setTexture(redc); sprite2.setPosition(672, 0); sprites.push_back(sprite2);
	sprite3.setTexture(redc); sprite3.setPosition(672, 472); sprites.push_back(sprite3);
	sprite4.setTexture(redc); sprite4.setPosition(0, 472); sprites.push_back(sprite4);

	bool arrastrando = false;
	Sprite* SpriteSeleccionado = nullptr;

	sf::RenderWindow App(VideoMode(800, 600, 32), "Que ventana horrible");
	while (App.isOpen())
	{
		Event event;
		while (App.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				App.close();
		}

		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left) {
				for (auto& sprite : sprites) {
					if (sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
						arrastrando = true;
						SpriteSeleccionado = &sprite;
						break;
					}
				}
			}
		}

		if (event.type == sf::Event::MouseButtonReleased) {
			if (event.mouseButton.button == sf::Mouse::Left) {
				arrastrando = false;
				SpriteSeleccionado = nullptr;
			}
		}

		if (arrastrando && SpriteSeleccionado != nullptr) {
			sf::Vector2i mousePosition = sf::Mouse::getPosition(App);
			SpriteSeleccionado->setPosition(mousePosition.x - SpriteSeleccionado->getGlobalBounds().width / 2, mousePosition.y - SpriteSeleccionado->getGlobalBounds().height / 2);
		}
		App.clear();
		for (const auto& sprite : sprites) {
			App.draw(sprite);
		}
		App.display();
	}
	return 0;
}
