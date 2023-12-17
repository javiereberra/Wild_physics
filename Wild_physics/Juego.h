#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Jugador.h"
#include "Pelota.h"
#include "Pajaro.h"
#include "Disco.h"

using namespace std;
using namespace sf;

class Juego {

private:

	//variables ventana
	RenderWindow* ventana1;

	//variables para el fondo
	Texture* textura1;
	Sprite* fondo;

	//variables para el menu e interfaz
	Font* font;
	Text* menuStart;
	Text* puntajeText;
	Text* menuEnd;

	int ptos;
	Clock _clockPelota;
	Clock _clockPajaro;
	Clock _clockDisco;
	
	float tiempoApagado;
	

	
	
	//un booleano para determinar cuándo se está jugando y cuándo está en el menu
	bool start;

	bool pelotaVisible;
	bool pajaroVisible;
	bool discoVisible;


public:
	//constructor de juego
	Juego(int ancho, int alto, std::string titulo);

	//método para iniciar el juego desde un menú
	void ejecutar();
	//métodos de bucle, dibujo, actualizar y procesar eventos
	void gameLoop();
	void dibujar();
	void actualizar();
	void procesar_eventos();
	// método para gestionar el disparo del mouse
	void disparar();
	void spawn();

	//jugador
	Jugador* jugador;
	Pelota* pelota;
	Pajaro* pajaro;
	Disco* disco;


	//destructor de juego
	~Juego();

};