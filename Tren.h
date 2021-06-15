
#include "Vagon.h"

typedef Vagon *pnodo;

class Tren{

private:
	//Punteros de la lista
	pnodo primero; //primer vagon 
	pnodo actual;  //vagon actual 
	Texture *tex_train;
	Sprite *sprite_train;	
public:
	Tren();

	//Devuelve el valor del último nodo
	int Ultimo();

	//Inserta en la lista
	void Insertar(int v);

	//Borra de la lista
	void Borrar(int v);

	//Verifica si la lista está vacía
	bool TrenVacio();

	//Devuelve la cantidad de nodos de la lista
	int obtenerCantidadVagones();
	
	//Controla la colision de los vagones
	void ControlarColisiones();
	
	void MostrarLista(RenderWindow& wnd);
	
	~Tren();

};
