#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

class Pajaro {

private:

	Texture* pajaroText;
	Sprite* pajaroSprite;

	Vector2f position;

	float velocityX;
	float velocityY;
	float gravedad;

public:

	Pajaro();
	void Dibujar(RenderWindow* ventana1);
	void actualizar();

	bool Colision(float x, float y);


	Sprite* getSprite() { return pajaroSprite; }



};
