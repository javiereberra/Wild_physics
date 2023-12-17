#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Pelota.h"



using namespace sf;

Pelota::Pelota() {

	pelotaText = new Texture;
	pelotaText->loadFromFile("assets/ball.png");
	pelotaSprite = new Sprite(*pelotaText);
	pelotaSprite->setScale(0.11f, 0.11f);
	position = Vector2f(400.0f, 100.0f);
	

	velocityX = 1.0f;
	velocityY = 0.0f;
	gravedad = 0.1f;

}

void Pelota::Dibujar(RenderWindow* ventana1) {
	
	ventana1->draw(*pelotaSprite);


}

void Pelota::actualizar() {

	float deltaTime = 1.0f / 60.0f;

	velocityY += gravedad * deltaTime;
	position.y += velocityY * deltaTime;
	position.x += velocityX * deltaTime;


	if (position.y >= 450.0f)
	{
		position.y = 450.0f;
		velocityY = -velocityY;

	}

	pelotaSprite->setPosition(position);
}

