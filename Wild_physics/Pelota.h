#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

class Pelota {

private:
	
	Texture* pelotaText;
	Sprite* pelotaSprite;

	Vector2f position;

	float velocityX;
	float velocityY;
	float gravedad;

public: 

	Pelota();
	void Dibujar(RenderWindow* ventana1);
	void actualizar();
	
	

	Sprite* getSprite() { return pelotaSprite; }



};
