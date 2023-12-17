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
	position = Vector2f(400.0f, 250.0f);
	posicionInicial = position;
	

	velocityX = 0.5f;
	velocityY = 0.0f;
	gravedad = 0.1f;

}

void Pelota::Dibujar(RenderWindow* ventana1) {
	
	ventana1->draw(*pelotaSprite);


}

bool Pelota::Colision(float x, float y) {

	FloatRect bounds = pelotaSprite->getGlobalBounds();

	if (bounds.contains(x, y)) {
		return true;
	}

}

void Pelota::actualizar() {

	float deltaTime = 1.0f / 60.0f;

	velocityY += gravedad * deltaTime;
	position.y += velocityY * deltaTime;
	position.x += velocityX * deltaTime;

	//límites para que la pelota siga rebotando tanto en el suelo como
	//en los bordes de la pantalla
	if (position.y >= 450.0f)
	{
		position.y = 450.0f;
		velocityY = -velocityY;

	}
	if (position.x >= 750.0f)
	{
		position.x = 750.0f;
		velocityX = -velocityX;
	}
	if (position.x <= 0.0f)
	{
		position.x = 0.0f;
		velocityX = -velocityX;
	}

	pelotaSprite->setPosition(position);
}
void Pelota::setPosicionInicial() {

	position = posicionInicial;
}

