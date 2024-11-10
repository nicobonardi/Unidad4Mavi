#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int main() {
    // Crear la ventana
    sf::RenderWindow App(sf::VideoMode(800, 600), "Que ventana horrible");

    // Cargar las texturas
    sf::Texture squareTexture, circleTexture;
    if (!squareTexture.loadFromFile("cuad_yellow.png") || !circleTexture.loadFromFile("rcircle.png")) {
        return -1;
    }

    // Crear el sprite y establecer su textura inicial
    sf::Sprite shapeSprite(squareTexture);
    shapeSprite.setPosition(375, 275); // Posición inicial centrada

    bool isSquare = true; // Control para cambiar entre cuadrado y círculo
    const float speed = 5.0f;

    // Bucle principal
    while (App.isOpen()) {
        sf::Event event;
        while (App.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                App.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                isSquare = !isSquare;
                shapeSprite.setTexture(isSquare ? squareTexture : circleTexture);
            }
        }

        // Movimiento con límites
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && shapeSprite.getPosition().x > 0)
            shapeSprite.move(-speed, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && shapeSprite.getPosition().x + shapeSprite.getGlobalBounds().width < App.getSize().x)
            shapeSprite.move(speed, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && shapeSprite.getPosition().y > 0)
            shapeSprite.move(0, -speed);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && shapeSprite.getPosition().y + shapeSprite.getGlobalBounds().height < App.getSize().y)
            shapeSprite.move(0, speed);

        // Renderizado
        App.clear();
        App.draw(shapeSprite);
        App.display();
    }

    return 0;
}
