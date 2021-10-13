#ifndef VAGON_H
#define VAGON_H
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;
using namespace sf;

//Declaracion de contantes 
//const int POSICION_CAMINO[5] = {10,50,70,200,300};

class Vagon{
private:
	//Numero para imprimir en vagon
	int nroEnVagon;
	//Vagon siguiente
	Vagon *siguiente;
	//Spritedel vagon
	Sprite *spriteWagon;
	//Fuentes y textos
	Font *fuente;
	Text *txt_vagon;
	friend class Tren;	
public:
	Vagon (int nro, sf::Sprite *spr, Vagon *sig = NULL){ //Constructor de la clase vagon
		nroEnVagon = nro;
		fuente = new Font();
		fuente->loadFromFile("Recursos//Textos//GeoSlab703 Md BT Bold.ttf");			
		txt_vagon = new Text();
		txt_vagon->setFont(*fuente);				
		Texture *tex_vagon = new Texture();
		tex_vagon->loadFromFile("Recursos//Imagenes//vagon.png");	
		spriteWagon = new Sprite(*tex_vagon);
		spriteWagon->scale(0.7,0.7);		
	}
	~Vagon();
	
	int getNroVagon(){return nroEnVagon;}; //Retorna el numero del vagon 
	void dibujar(RenderWindow &wnd){wnd.draw(*spriteWagon);}; //Dibuja el sprite del vagon
	void setValor(int newValor){txt_vagon->setString(to_string(newValor));}; //Setea el valor del n° del vagon 
	FloatRect ColliderVagon(){spriteWagon->getGlobalBounds();}; //Devuelve el bounds del sprite del vagon
	Sprite get_sprite() {return *spriteWagon;}; //devuelve el sprite del vagon	
};
#endif
