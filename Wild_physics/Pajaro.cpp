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
	posicionInicial = position;


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


	//l�mites de movimiento para que el p�jaro rebote en los bordes y cambie su direcci�n//
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
void Pajaro::setPosicionInicial() {

	position = posicionInicial;
}

