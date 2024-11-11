#pragma once
#include "stdafx.h"

using namespace sf;

class Enemigo {
	Texture EnemigoText;
	Sprite EnemigoSprite;
	bool estaVivo;
	bool estaVisible;
	sf::Clock _clock;
	float tiempoVisible;
	float tiempoApagado;
	Vector2f randomPos(Vector2u maxPos) {
		Vector2f random((float)(rand() % maxPos.x), (float)(rand() % maxPos.y));
		return random;
	}
public:
	Enemigo() {
		EnemigoText.loadFromFile("et.png");
		EnemigoSprite.setTexture(EnemigoText);
		EnemigoSprite.setScale(0.4f, 0.4f);
		estaVivo = true;
		estaVisible = false;
		tiempoVisible = 0.5f;
		tiempoApagado = 0.5f;
	}
	bool estaVivo() {
		return estaVivo;
	}
	bool estaActivo() {
		return estaVivo && estaVisible;
	}
	bool estaEncima(float x, float y) {
		FloatRect bounds = EnemigoSprite.getGlobalBounds();
		return bounds.contains(x, y);
	}
	void Derrotar() {
		estaVivo = false;
	}
	void Dibujar(RenderWindow* wnd) {
		wnd->draw(EnemigoSprite);
	}
	void Actualizar(RenderWindow *wnd) {
		if (!estaVivo)
			return;
		if (!estaVisible) {
			if (_clock.getElapsedTime().asSeconds() > tiempoApagado) {
				if (rand() % 100 < 25)
					estaVisible = true;
				EnemigoSprite.setPosition(randomPos(wnd->getSize()));
			}
		}
		else {
			if (_clock.getElapsedTime().asSeconds() > tiempoVisible)
				estaVisible = false;
			_clock.restart();

		}
	}
};