#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

class Disco {

private:

	Texture* discoText;
	Sprite* discoSprite;
	//para que el spawn rescate la posicion de inicio//
	Vector2f posicionInicial;
	Vector2f position;

	float velocityX;
	float velocityY;
	float aceleracion;
	

public:

	Disco();
	void Dibujar(RenderWindow* ventana1);
	void actualizar();
	void setPosicionInicial();

	bool Colision(float x, float y);


	Sprite* getSprite() { return discoSprite; }



};
