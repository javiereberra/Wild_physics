#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Disco.h"



using namespace sf;

Disco::Disco() {
	
	//Textura//
	discoText = new Texture;
	discoText->loadFromFile("assets/disco.png");
	discoSprite = new Sprite(*discoText);
	discoSprite->setScale(1.5f, 1.5f);
	//posicion y posicion inicial//
	position = Vector2f(50.0f, 450.0f);
	posicionInicial = position;

	//velocidad horizontal y vertical y aceleracion//
	velocityX = 0.1f;
	velocityY = 0.1f;
	aceleracion = 0.05f;

}

//dibujar//
void Disco::Dibujar(RenderWindow* ventana1) {

	ventana1->draw(*discoSprite);


}

//booleando para comprobar la colision en juego//
bool Disco::Colision(float x, float y) {

	FloatRect bounds = discoSprite->getGlobalBounds();

	if (bounds.contains(x, y)) {
		return true;
	}

}
//actualizar el movmiento acelerado del objeto//
void Disco::actualizar() {

	float deltaTime = 1.0f / 60.0f;
	//aplicar aceleracion a las velocidades vertical y horizontal//
	velocityX += aceleracion * deltaTime;
	velocityY += aceleracion * deltaTime;
	//aplicar velocidad a la posicion para mover el objeto//
	position.x += velocityX * deltaTime;
	position.y += -velocityY * deltaTime;

	//limite establecido al disco para que no salga de la pantalla
	//y siga acelerando infinitamente

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

	//actualizar la posicion//
	discoSprite->setPosition(position);
}
//método para usar la posicion inicial cada vez que aparece
void Disco::setPosicionInicial() {

	position = posicionInicial;
}