#include <SFML/Graphics.hpp>
#include <string>

using namespace std;
using namespace sf;

//Declaracion de contantes 
const int POSICION_CAMINO[5] = {10,50,70,200,300};

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
public:
	Vagon (int nro, sf::Sprite *spr, Vagon *sig = NULL)
	{
		fuente = new Font();
		fuente->loadFromFile("");			
		txt_vagon = new Text();
		txt_vagon->setFont(*fuente);
		txt_vagon->setString(to_string(nro));
		Texture *tex_vagon = new Texture();
		tex_vagon->loadFromFile("Recursos//vagon.png");	
		spriteWagon = new Sprite(*tex_vagon);
	}
	~Vagon();
	friend class Tren;	
	int getNroVagon(){return nroEnVagon;};
};

