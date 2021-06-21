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
	int nroEnVagon = 10;
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
		nroEnVagon = nro;
		fuente = new Font();
		fuente->loadFromFile("Recursos//Textos//Stenciland.otf");			
		txt_vagon = new Text();
		txt_vagon->setFont(*fuente);
		txt_vagon->setString(to_string(nroEnVagon));
		txt_vagon->setPosition(200,155);
		Texture *tex_vagon = new Texture();
		tex_vagon->loadFromFile("Recursos//Imagenes//vagon.png");	
		spriteWagon = new Sprite(*tex_vagon);
		spriteWagon->scale(0.7,0.7);		
	}
	~Vagon();
	
	int getNroVagon(){return nroEnVagon;};
	void dibujar(RenderWindow &wnd){wnd.draw(*spriteWagon);};
	void setValor(int newValor){txt_vagon->setString(to_string(newValor));};
	FloatRect ColliderVagon(){spriteWagon->getGlobalBounds();};
	Sprite get_sprite() {return *spriteWagon;};
	void moverVagon()
	{
		spriteWagon->setPosition(spriteWagon->getPosition().x+3,spriteWagon->getPosition().y);
		if(spriteWagon->getPosition().x > 800) // si pasa los limites de la pantalla bajo un nivel
		{			
			spriteWagon->setPosition(1,spriteWagon->getPosition().y + 100);
		}
	}
};
#endif
