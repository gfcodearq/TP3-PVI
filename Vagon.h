#ifndef VAGON_H
#define VAGON_H
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;
using namespace sf;

//Declaracion de contantes 
//const int POSICION_CAMINO[5] = {10,50,70,200,300};

class Vagon
{
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
	//Posicion del vagon
	Vector2f posicion;
	friend class Tren;	
public:
	Vagon (int nro, sf::Sprite *spr, Vagon *sig = NULL)
	{
		fuente = new Font();
		fuente->loadFromFile("");			
		txt_vagon = new Text();
		txt_vagon->setFont(*fuente);
		txt_vagon->setString(to_string(nro));
		Texture *tex_vagon = new Texture();
		tex_vagon->loadFromFile("Recursos//Imagenes//vagon.png");	
		spriteWagon = new Sprite(*tex_vagon);
	}
	~Vagon();
	
	int getNroVagon(){return nroEnVagon;};
	void dibujar(RenderWindow &wnd){wnd.draw(*spriteWagon);};
};
#endif
