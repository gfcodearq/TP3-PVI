#include "Vagon.h"

typedef Vagon *pnodo; //Nuestra lista??

class Tren{
	
private:
	//Punteros de la lista
	pnodo primero; //primer vagon 
	pnodo actual;  //vagon actual
	
	Vagon *laListaEsEsto;//los anteriores son apuntadores a elementos específicos de la lista
	
	Texture *tex_train;
	Sprite *sprite_train;	
	int CantVagones = 2;	
	
	//Reloj	
	Clock *reloj;
	Time *tiempo;	
	
	Font * fuente3;
	Text * txt_tiempo;
public:
	Tren(int posX,int posY);
	
	//Devuelve el valor del último nodo
	int Ultimo();
	
	//Inserta en la lista
	void Insertar(int v,int posX,int posY);
	
	//Borra de la lista
	void Borrar(int v);
	
	//Verifica si la lista está vacía
	bool TrenVacio();
	
	//Devuelve la cantidad de nodos de la lista
	int obtenerCantidadVagones();
	
	//Controla la colision de los vagones
	void ControlarColisiones();
	
	void MostrarLista(RenderWindow& wnd);
	//Dibuja los elementos de la lista
	void Dibujar(RenderWindow *wnd);
	//Actualiza el sprite 
	void Actualizar();
	
	Sprite get_sprite();	
	~Tren();
	
};
