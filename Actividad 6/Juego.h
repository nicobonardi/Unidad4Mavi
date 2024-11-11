#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "crosshair.h"
#include "Enemy.h"
#include <iostream>
using namespace sf;
class Juego
{
	RenderWindow* wnd;	
	crosshair* player;
	Enemigo *enemigos;
public:
	Juego() {
		wnd = new RenderWindow(VideoMode(800, 600), "Que ventana horrible");	
		player = new crosshair();
		enemigos = new Enemigo[5];
		}
	void Loop() {
		while (wnd->isOpen()) {
			procesarEventos();
			Actualizar();
			Dibujar();
		}
	}
	void procesarEventos() {
		Event evt;
		while (wnd->pollEvent(evt))
		{
			switch (evt.type) {
			case Event::Closed:
					wnd->close();
					break;
			case Event::MouseButtonPressed:
				if (evt.mouseButton.button == Mouse::Button::Left)
				{
					Disparar(); 
					break;
				}
			}
		}
	}
	void Actualizar() {
		Vector2i mousePos = Mouse::getPosition(*wnd);
		player->Posicionar(mousePos.x, mousePos.y);
		for (size_t i = 0; i < 5; i++)
		{
			enemigos[i].Actualizar(wnd);
		}
	}
	void Disparar() {
		Vector2f playerPos = player->Posicion();
		for (int i = 0; i < 5; i++)
		{
			if (enemigos[i].estaActivo()) {
				if (enemigos[i].estaEncima(playerPos.x,playerPos.y)) {
					enemigos[i].Derrotar();
				}
			}
		}
	}
	void Dibujar() {
		wnd->clear();
		//Dibujar elementos
		for (int i = 0; i < 5; i++)
		{
			if (enemigos[i].estaActivo()) {
				enemigos[i].Dibujar(wnd);
			}
		}
		player->Dibujar(wnd);
		wnd->display();
	}
	~Juego() {
		delete wnd;
		delete player;
		delete enemigos;
	}
};

