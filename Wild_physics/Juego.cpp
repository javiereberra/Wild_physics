#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Juego.h"


using namespace sf;
using namespace std;

Juego::Juego(int ancho, int alto, std::string titulo) {

	//Ventana
	ventana1 = new RenderWindow(VideoMode(ancho, alto), titulo);

	//Textura y Sprite de fondo
	textura1 = new Texture;
	fondo = new Sprite;
	textura1->loadFromFile("assets/fondo.png");
	fondo->setTexture(*textura1);

	//para que siempre inicie el menú
	start = false;

}

void Juego::ejecutar() {

	while (ventana1->isOpen()) {
		Event evento;
		while (ventana1->pollEvent(evento)) {
			if (evento.type == Event::Closed)
				ventana1->close();
			//Presionar "s" para iniciar el gameloop
			if (evento.type == Event::KeyPressed) {
				if (evento.key.code == Keyboard::Key::S && !start) {

					start = true;
					
				}
			}
		}

		ventana1->clear(Color::Black);

		if (start) {
			//iniciar el loop si start es true
			gameLoop();

		}
		else {
			//Menu de fondo si start es false
			ventana1->draw(*fondo);
		}

		ventana1->display();
	}
}

void Juego::gameLoop() {

	bool gameOver = false;

	while (ventana1->isOpen() && !gameOver) {

		procesar_eventos();
		actualizar();
		dibujar();

	}
}

void Juego::procesar_eventos() {
		Event evento1;
		while (ventana1->pollEvent(evento1)) {
			switch (evento1.type) {
			case Event::Closed:
				ventana1->close();
				break;
			case Event::MouseButtonPressed:
				if (evento1.mouseButton.button == Mouse::Button::Left)
					disparar();
				break;
			}
		}
	}

void Juego::actualizar() {
}

void Juego::disparar() {
}

void Juego::dibujar() {

	ventana1->clear();

	ventana1->draw(*fondo);


	ventana1->display();


}

//Destructor de Juego
Juego::~Juego() {

	delete ventana1;
}