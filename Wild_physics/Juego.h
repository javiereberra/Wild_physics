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

	//variables para todos los textos
	Font* font;
	Text* menuStart;
	Text* puntajeText;
	Text* menuEnd;
	//variable para el puntaje
	int ptos;

	//un reloj necesario para que cada objeto pueda respawnear
	Clock _clockPelota;
	Clock _clockPajaro;
	Clock _clockDisco;
	
	//tiempo en que los objetos est�n ausentes
	float tiempoApagado;
	

	
	
	//un booleano para determinar cu�ndo se est� jugando y cu�ndo est� en el menu
	bool start;
	//booleanos para determinar si los objetos est�n activos y por lo tanto dibujarlos
	bool pelotaVisible;
	bool pajaroVisible;
	bool discoVisible;


public:
	//constructor de juego
	Juego(int ancho, int alto, std::string titulo);

	//m�todo para iniciar el juego desde un men�
	void ejecutar();
	//m�todos de bucle, dibujo, actualizar y procesar eventos
	void gameLoop();
	void dibujar();
	void actualizar();
	void procesar_eventos();
	// m�todo para gestionar el disparo del mouse y colisiones
	void disparar();
	//m�todo para la aparicion de objetos
	void spawn();

	//jugador y objetos
	Jugador* jugador;
	Pelota* pelota;
	Pajaro* pajaro;
	Disco* disco;


	//destructor de juego
	~Juego();

};