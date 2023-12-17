#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

class Jugador {

private:
	//textura y sprite
	Texture* jugadorText;
	Sprite* mira;

public:
	//constructor
	Jugador();

	void Dibujar(RenderWindow* ventana1);

	//gestionar el movimiento del cursor
	void Movimiento(float x, float y);

	//para obtener la posici�n en clase Juego
	Vector2f ObtenerPosicion();

};
