#include "Juego.h"
#include <string>
#include <iostream>
#include <ctime>

using namespace std;
using namespace sf;

Juego::Juego(Vector2i resolucion, string titulo){
	//Window
	wnd = new RenderWindow(VideoMode(800,600),titulo);
	wnd->setFramerateLimit(60);
	//Eventos
	evento = new Event;	
	//Relojes
	reloj = new Clock;
	tiempo = new Time;	
	
	//Sonidos
	buffer = new SoundBuffer;
	buffer_game = new SoundBuffer;
	buffer_colision = new SoundBuffer;
	sonido = new Sound;
	sonido_game = new Sound;
	sonido_colision = new Sound;
	//Inicio game over en false
	game_over = false;
	//Creo el tren
	train = new Tren(210,51);	
	colisiono = false;
	//Inserto vagones
//	train->Insertar(5,200,155);
//	train->Insertar(8,500,350);
	a = rand()% 9+1;
	b = rand()% 9+1;
	//Gameloop
	gameloop();	
}

void Juego::gameloop(){
	cargar_recursos();
	sonido_game->setVolume(3);
	sonido_game->play();
	sonido_game->setLoop(true);
	
	while (wnd->isOpen()){
		if(!game_over){
			train->Actualizar();
			train->ControlarColisiones();
			procesar_eventos();
			procesar_colisiones();			
			actualizar();			
		}		
		operacion();
		dibujar();
	}
	
}

void Juego::procesar_eventos(){
	while (wnd->pollEvent(*evento)){
		if (evento->type == Event::Closed){
			wnd->close();
		}		
	}	
}

void Juego::cargar_recursos(){	
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
	
	tex_vagon = new Texture();
	tex_vagon->loadFromFile("Recursos//Imagenes//vagon.png");	
	spr_vagon = new Sprite(*tex_vagon);
	spr_vagon->scale(0.7,0.7);
	spr_vagon->setPosition(200,155);
	spr_vagon2 = new Sprite(*tex_vagon);
	spr_vagon2->scale(0.7,0.7);
	spr_vagon2->setPosition(500,350);	
	
	fuente1 = new Font;
	fuente1->loadFromFile("Recursos\\Textos\\GeoSlab703 Md BT Bold.ttf");
	
	txt_game_over = new Text();
	txt_game_over->setFont(*fuente1);
	txt_game_over->setPosition(300,260);
	txt_game_over->setString("GAME OVER");
	txt_game_over->setColor(Color::Red);
	
	//Cargar sonidos
	if(!buffer->loadFromFile("Recursos\\sonidos\\tren.wav")){
		cout<<"No se pudo cargar efectos"<<endl;
	}
	sonido->setBuffer(*buffer);
	
	if(!buffer_game->loadFromFile("Recursos\\sonidos\\")){
		cout<<"No se pudo cargar efectos"<<endl;
	}
	sonido_game->setBuffer(*buffer_game);
	
	if(!buffer_colision->loadFromFile("Recursos\\sonidos\\silbato_tren.wav")){
		cout<<"No se pudo cargar efectos"<<endl;
	}
	sonido_colision->setBuffer(*buffer_colision);
}

void Juego::procesar_colisiones(){	
	FloatRect ColliderCentralFinal = spr_central_final->getGlobalBounds();
	if(ColliderCentralFinal.intersects(train->get_sprite().getGlobalBounds())){
		game_over = true;
	}
	if(train->get_sprite().getGlobalBounds().intersects(spr_vagon->getGlobalBounds())){
		sonido_colision->play();
		colisiono = true;
		reloj->restart();
		cout<<"Colisiono";
	}
	train->ControlarColisiones();	
}

void Juego::dibujar(){
	wnd->clear(Color(255,255,255,255)); //limpia la pantalla	
	wnd->draw(*spr_background);
	wnd->draw(*spr_central_inicio);
	wnd->draw(*spr_central_final);	
	wnd->draw(*spr_vagon);
	train->Dibujar(wnd);
	train->MostrarLista(*wnd);	
	
	if(game_over){
		wnd->draw(*txt_game_over);
	}
	
	if(colisiono){
		wnd->draw(*txt_tiempo);		
		wnd->draw(*txt_operacion);
	}
	wnd->display();	
}

void Juego::actualizar(){

}
	

void Juego::operacion(){	
	c = a + b;
	
	if(colisiono){	
	txt_operacion = new Text();
	txt_operacion->setFont(*fuente1);
	txt_operacion->setPosition(330,50);
	txt_operacion->setColor(Color::Red);
	txt_operacion->scale(0.5,0.5);
	txt_operacion->setString("Resuelva la operacion " + to_string(a) +"+" + to_string(b));	
	
	tiempoEntero = reloj->getElapsedTime().asSeconds();//Variable entera para alojar el tiempo que pasa
	txt_tiempo = new Text;
	txt_tiempo->setFont(*fuente1);
	txt_tiempo->setColor(Color::Red);
	txt_tiempo->scale(0.5,0.5);
	txt_tiempo->setString("Tiempo:"+to_string(tiempoEntero));
	txt_tiempo->setPosition(700,20);
	//train->PararTren();
	
//	if(respuesta == c && tiempoEntero < 5)
//	{
//		train->Insertar(c,200,155); //Inserto un vagon con el numero del resultado
//	}
	
	if(tiempoEntero > 5){			
		cout<<"Se borro vagon";
		//Hacer sonido 
	}
	}	
}	
	
	

