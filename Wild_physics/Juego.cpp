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

	//Inicializar el jugador y objetos
	jugador = new Jugador();

	pelota = new Pelota();

	pajaro = new Pajaro();

	disco = new Disco();

	//ajustar variables para manejar los spawn
	tiempoApagado = 5.0f;
	pelotaVisible = false;
	pajaroVisible = false;
	discoVisible = false;


	//fuente y texto para el menu
	font = new Font;
	menuStart = new Text;
	font->loadFromFile("assets/nintendo-nes-font.ttf");
	menuStart->setFont(*font);
	menuStart->setString("PRESIONA 'S' PARA COMENZAR");
	menuStart->setCharacterSize(20);
	menuStart->setPosition(115, 65);

	menuEnd = new Text;
	menuEnd->setFont(*font);
	menuEnd->setString("PRESIONA 'Q' PARA DETENER EL JUEGO");
	menuEnd->setCharacterSize(20);
	menuEnd->setPosition(60, 510);
	//texto puntaje
	puntajeText = new Text;
	puntajeText->setFont(*font);
	puntajeText->setString("PUNTAJE: " + to_string(ptos));
	puntajeText->setCharacterSize(20);
	puntajeText->setPosition(60, 510);

	//iniciar puntos en 0
	ptos = 0;

}

//metodo para iniciar un menu simple antes de iniciar el juego
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
			ventana1->draw(*menuStart);
			ventana1->draw(*menuEnd);
		}

		ventana1->display();
	}
}
//iniciar el loop
void Juego::gameLoop() {
		

		while (ventana1->isOpen() && start) {

			procesar_eventos();
			actualizar();
			
			dibujar();
		
	}
}
//gestionar eventos del disparo y la opción de abandonar el juego y volver al menu
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
			case Event::KeyPressed:
				if (evento1.key.code == Keyboard::Key::Q)
					start = false;
					ptos = 0;
					puntajeText->setString("PUNTAJE: " + to_string(ptos));
					ejecutar();

			}
		}
	}
//actualizar jugador y todos los objetos con sus spawns
void Juego::actualizar() {
	Vector2i mousePos = Mouse::getPosition(*ventana1);
	jugador->Movimiento(mousePos.x, mousePos.y);
	spawn();
	pelota->actualizar();
	pajaro->actualizar();
	disco->actualizar();
}
//metodo para gestionar el disparo del jugador y comprobar colisiones
//eliminar objetos y sumar puntaje
void Juego::disparar() {

	Vector2f playerPos = jugador->ObtenerPosicion();

	if (pelota->Colision(playerPos.x, playerPos.y)) {
		ptos += 5;
		puntajeText->setString("PUNTAJE: " + to_string(ptos));
		pelotaVisible = false;
	}
	if (pajaro->Colision(playerPos.x, playerPos.y)) {
		ptos += 2;
		puntajeText->setString("PUNTAJE: " + to_string(ptos));
		pajaroVisible = false;
	}
	if (disco->Colision(playerPos.x, playerPos.y)) {
		ptos += 10;
		puntajeText->setString("PUNTAJE: " + to_string(ptos));
		discoVisible = false;
	}
}
//mètodo para aparicion de objetos en una posición inicial
void Juego::spawn() {
	if (!pelotaVisible) {
		if (_clockPelota.getElapsedTime().asSeconds() > tiempoApagado) {
			pelotaVisible = true;
			_clockPelota.restart();
			pelota->setPosicionInicial();
		}
		
	}
	if (!pajaroVisible) {
		if (_clockPajaro.getElapsedTime().asSeconds() > tiempoApagado) {
			pajaroVisible = true;
			_clockPajaro.restart();
			pajaro->setPosicionInicial();
		}

	}
	if (!discoVisible) {
		if (_clockDisco.getElapsedTime().asSeconds() > tiempoApagado) {
			discoVisible = true;
			_clockDisco.restart();
			disco->setPosicionInicial();
		}

	}

}


//Metodo para dibujar
void Juego::dibujar() {

	ventana1->clear();

	ventana1->draw(*fondo);
	ventana1->draw(*puntajeText);

	if (pelotaVisible) {

		pelota->Dibujar(ventana1);
	}

	if (pajaroVisible) {

		pajaro->Dibujar(ventana1);
	}

	if (discoVisible) {
		disco->Dibujar(ventana1);
	}

	jugador->Dibujar(ventana1);
	ventana1->display();


}

//Destructor de Juego
Juego::~Juego() {
	
	delete pelota;
	delete pajaro;
	delete disco;
	delete jugador;
	delete ventana1;
}