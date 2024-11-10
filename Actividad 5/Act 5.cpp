#include <SFML/Graphics.hpp>

int main() {
    // Crear la ventana con un tamaño inicial de 800x600
    sf::RenderWindow App(sf::VideoMode(800, 600), "Ventana Redimensionable");

    // Configurar límites de tamaño de la ventana
    const unsigned int minWidth = 100;
    const unsigned int minHeight = 100;
    const unsigned int maxWidth = 1000;
    const unsigned int maxHeight = 1000;

    // Bucle principal
    while (App.isOpen()) {
        sf::Event event;
        while (App.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                App.close();
            if (event.type == sf::Event::Resized) {
                unsigned int newWidth = event.size.width;
                unsigned int newHeight = event.size.height;

                // Limitar el tamaño de la ventana dentro de los rangos permitidos
                if (newWidth < minWidth) newWidth = minWidth;
                if (newWidth > maxWidth) newWidth = maxWidth;
                if (newHeight < minHeight) newHeight = minHeight;
                if (newHeight > maxHeight) newHeight = maxHeight;
                // Cambiar el tamaño de la ventana ajustado
                App.setSize(sf::Vector2u(newWidth, newHeight));
            }
        }
        App.clear();
        App.display();
    }
    return 0;
}
