#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Pajaro.h"



using namespace sf;

Pajaro::Pajaro() {

	pajaroText = new Texture;
	pajaroText->loadFromFile("assets/pajaro.png");
	pajaroSprite = new Sprite(*pajaroText);
	pajaroSprite->setScale(1.5f, 1.5f);
	position = Vector2f(100.0f, 100.0f);


	velocityX = 2.0f;
	

}

void Pajaro::Dibujar(RenderWindow* ventana1) {

	ventana1->draw(*pajaroSprite);


}

bool Pajaro::Colision(float x, float y) {

	FloatRect bounds = pajaroSprite->getGlobalBounds();

	if (bounds.contains(x, y)) {
		return true;
	}

}

void Pajaro::actualizar() {

	float deltaTime = 1.0f / 60.0f;
		
	position.x += velocityX * deltaTime;


	
	if (position.x >= 750.0f)
	{
		position.x = 750.0f;
		velocityX = -velocityX;
		pajaroSprite->setScale(-1.5f, 1.5f);
	}
	if (position.x <= 0.0f)
	{
		position.x = 0.0f;
		velocityX = -velocityX;
		pajaroSprite->setScale(1.5f, 1.5f);
	}

	pajaroSprite->setPosition(position);
}

