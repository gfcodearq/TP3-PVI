#ifndef JUEGO_H
#define JUEGO_H

#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include "Tren.h"
#include "Vagon.h"

using namespace sf;
using namespace std;

class Juego
{
public:
	Juego(Vector2i resolucion, string titulo);
	int sumaNrosVagones();
	void gameloop();
	void procesar_eventos();
	void cargar_recursos();
	void dibujar();	
	void procesar_colisiones();
	void actualizar();
	bool game_over;
private:
	RenderWindow* wnd;
	//Eventos
	Event *evento;
	//Reloj	
	Clock *reloj;
	Time *tiempo;	
	//Tren
	Tren *train;	
	//Sonido 
	SoundBuffer* buffer; //Contiene el archivo de sonido
	Sound* sonido; //Sonido va a cargar el buffer
	SoundBuffer* buffer_game;
	Sound *sonido_game;
	SoundBuffer* buffer_colision;
	Sound* sonido_colision;
	SoundBuffer* buffer_game_over;
	Sound* sonido_game_over;
	//Textos
	Font * fuente1;	
	Text* txt_game_over;	
	//Sprites y texturas
	Texture* tex_background;
	Sprite* spr_background;	
	Texture * tex_central_inicio;
	Sprite *spr_central_inicio;
	Texture * tex_central_final;
	Sprite *spr_central_final;	
};
#endif
