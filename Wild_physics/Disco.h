#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

class Disco {

private:

	Texture* discoText;
	Sprite* discoSprite;

	Vector2f position;

	float velocityX;
	float velocityY;
	
	

public:

	Disco();
	void Dibujar(RenderWindow* ventana1);
	void actualizar();

	bool Colision(float x, float y);


	Sprite* getSprite() { return discoSprite; }



};
