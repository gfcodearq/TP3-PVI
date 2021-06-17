#include "Juego.h"
#include <string>
#include <iostream>
#include <ctime>

using namespace std;
using namespace sf;

Juego::Juego(Vector2i resolucion, string titulo)
{
	//Window
	wnd = new RenderWindow(VideoMode(800,600),titulo);
	wnd->setFramerateLimit(60);
	//Eventos
	evento = new Event;
	//Relojes
	reloj = new Clock;
	tiempo = new Time;
	reloj->restart(); //Doy inicio al reloj
	//Sonidos
	buffer = new SoundBuffer;
	buffer_game = new SoundBuffer;
	buffer_colision = new SoundBuffer;
	sonido = new Sound;
	sonido_game = new Sound;
	sonido_colision = new Sound;
	//Inicio game over en false
	game_over = false;	
	train = new Tren(120,51);
	wagon = NULL; //inicializo la lista
	//Gameloop
	gameloop();	
}

void Juego::gameloop()
{
	cargar_recursos();
	sonido_game->setVolume(3);
	sonido_game->play();
	sonido_game->setLoop(true);
	while (wnd->isOpen())
	{
		if(!game_over)
		{
			train->Actualizar();
			procesar_eventos();
			procesar_colisiones();				
		}
		dibujar();
	}
}

void Juego::procesar_eventos()
{
	while (wnd->pollEvent(*evento))
	{
		if (evento->type == Event::Closed)
		{
			wnd->close();
		}
	}
}

void Juego::cargar_recursos()
{
	//Sprites y texturas
	tex_background = new Texture;
	tex_background->loadFromFile("Recursos\\Imagenes\\background.png");
	spr_background = new Sprite(*tex_background);
	
	tex_central_inicio = new Texture;
	tex_central_inicio->loadFromFile("Recursos\\Imagenes\\central_nuclear.png");
	spr_central_inicio = new Sprite(*tex_central_inicio);
	spr_central_inicio->setPosition(15,0);
	
	tex_central_final = new Texture;
	tex_central_final->loadFromFile("Recursos\\Imagenes\\central_nuclear.png");
	spr_central_final = new Sprite(*tex_central_final);
	spr_central_final->setPosition(650,400);
	
	
	
	//Cargar sonidos
	if(!buffer->loadFromFile("Recursos\\sonidos\\"))
	{
		cout<<"No se pudo cargar efectos"<<endl;
	}
	sonido->setBuffer(*buffer);
	if(!buffer_game->loadFromFile("Recursos\\sonidos\\"))
	{
		cout<<"No se pudo cargar efectos"<<endl;
	}
	sonido_game->setBuffer(*buffer_game);
	if(!buffer_colision->loadFromFile("Recursos\\sonidos\\"))
	{
		cout<<"No se pudo cargar efectos"<<endl;
	}
	sonido_colision->setBuffer(*buffer_colision);
}

void Juego::procesar_colisiones()
{
	
}

void Juego::dibujar()
{
	wnd->clear(Color(255,255,255,255)); //limpia la pantalla	
	wnd->draw(*spr_background);
	wnd->draw(*spr_central_inicio);
	wnd->draw(*spr_central_final);	
	train->Dibujar(wnd);
	if(wagon !=NULL)
	{		
		train->MostrarLista(*wnd);
	}		
	wnd->display();
}

void Juego::actualizar()
{
	
}
