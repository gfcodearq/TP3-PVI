#include "Vagon.h"

typedef Vagon *pnodo; 

class Tren{
	
private:
	//Punteros de la lista
	pnodo primero; //primer vagon 
	pnodo actual;  //vagon actual
	Vagon *laListaEsEsto; //Lista
	//Texturas y sprites
	Texture *tex_train;
	Sprite *sprite_train;	
	int CantVagones = 2;	
	//Reloj	
	Clock *reloj;
	Time *tiempo;	
	//Fuentes y textos
	Font * fuente2;
	Text * txt_tiempo;
	Text * txt_operacion;
	bool colisiono;
	int a,b,c,respuesta;
public:
	//Constructor de la clase tren
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
	
	//Paro el Tren
	void PararTren();
	
	//Devuelve el sprite
	Sprite get_sprite();
	
	//Destructor
	~Tren();
	
};
