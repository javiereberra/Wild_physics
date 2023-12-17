#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Disco.h"



using namespace sf;

Disco::Disco() {

	discoText = new Texture;
	discoText->loadFromFile("assets/disco.png");
	discoSprite = new Sprite(*discoText);
	discoSprite->setScale(1.5f, 1.5f);
	position = Vector2f(50.0f, 450.0f);
	posicionInicial = position;

	velocityX = 0.1f;
	velocityY = 0.1f;
	aceleracion = 0.05f;

}

void Disco::Dibujar(RenderWindow* ventana1) {

	ventana1->draw(*discoSprite);


}

bool Disco::Colision(float x, float y) {

	FloatRect bounds = discoSprite->getGlobalBounds();

	if (bounds.contains(x, y)) {
		return true;
	}

}

void Disco::actualizar() {

	float deltaTime = 1.0f / 60.0f;

	velocityX += aceleracion * deltaTime;
	velocityY += aceleracion * deltaTime;
	position.x += velocityX * deltaTime;
	position.y += -velocityY * deltaTime;



	if (position.x >= 750.0f)
	{
		velocityX = 0.0f;
		velocityY = 0.0f;
	}
	if (position.y <= 50.0f)
	{
		velocityX = 0.0f;
		velocityY = 0.0f;
	}


	discoSprite->setPosition(position);
}
void Disco::setPosicionInicial() {

	position = posicionInicial;
}