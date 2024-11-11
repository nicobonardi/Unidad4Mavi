#pragma once
#include "stdafx.h"
using namespace sf;
using namespace std;
class crosshair
{
	Texture crossText;
	Sprite crosSprite;
public:
	crosshair() {
		crossText.loadFromFile("crosshair.png");
		crosSprite.setTexture(crossText);
		crosSprite.setScale(0.2f, 0.2f);
		Vector2u size = crossText.getSize();
		crosSprite.setOrigin(size.x / 2.0f, size.y / 2.0f);
	}
	void Dibujar(RenderWindow *wnd) {
		wnd->draw(crosSprite);
	}
	void Posicionar(float x, float y) {
		crosSprite.setPosition(x, y);
	}
	Vector2f Posicion() {
		return crosSprite.getPosition();
	}
};

