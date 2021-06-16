#include "Tren.h"

using namespace sf;

Tren::Tren()
{	
	tex_train = new Texture;
	tex_train->loadFromFile("Recursos//Imagenes//locomotora.png");
}

void Tren::Insertar(int v) //Metodo para insertar vagones de forma ordenada
{
	Vagon *wagon = new Vagon(v,wagon->spriteWagon,wagon->siguiente);
	Vagon *firstAuxiliar = primero;
	Vagon *secondAuxiliar = NULL;
	
	while(firstAuxiliar != NULL && wagon->nroEnVagon > v )
	{
		secondAuxiliar = firstAuxiliar;
		firstAuxiliar = firstAuxiliar->siguiente;		
	}
	if(primero == firstAuxiliar)
	{
		primero = wagon;
	}
	else
	{
	 secondAuxiliar->siguiente = wagon;	
	}
	wagon->siguiente = firstAuxiliar;
}

void Tren::Borrar(int v) //Metodo para eliminar vagones
{
	if(primero !=NULL)
	{
		Vagon *auxiliarBorrado = primero;
		Vagon *referenciaAnterior = NULL;
		while(auxiliarBorrado !=NULL) //Y la suma de correctamente
		{
			referenciaAnterior = auxiliarBorrado;
			auxiliarBorrado = auxiliarBorrado->siguiente;
		}
		if(auxiliarBorrado == NULL)
		{
			return;
		}
		else if(referenciaAnterior == NULL)
		{
			primero = primero->siguiente;
			CantVagones --;
			//delete auxiliarBorrado;
		}
		else 
		{
			referenciaAnterior->siguiente = auxiliarBorrado->siguiente;
			//delete auxiliarBorrado;
		}
	}	
}



bool Tren::TrenVacio() //Si el tren no tiene vagones retorna true
{
	if(primero == NULL)
	{
		return true;
	}
}

int Tren::obtenerCantidadVagones()//obtiene la canitadad de vagones 
{
	return CantVagones;
}

void Tren::ControlarColisiones()
{
	Vagon *actual = primero;
	FloatRect ColliderWagon = actual->spriteWagon->getGlobalBounds();
	while(actual != NULL)
	{		
		FloatRect ColliderTrain = sprite_train->getGlobalBounds();
		if(ColliderWagon.intersects(ColliderTrain))
		{
			//Motrar en pantalla la suma 
			Insertar(5);
			CantVagones ++;
			return;
		}
		else
		{
			actual = actual->siguiente;
		}
	}
}

void Tren::MostrarLista(RenderWindow &wnd)
{
	Vagon *actual = primero;
	Vector2f posicion;
	posicion.x = 15;
	posicion.y =30;
	while(actual = NULL)
	{
		actual->txt_vagon->setPosition(actual->spriteWagon->getPosition().x /2,actual->spriteWagon->getPosition().y);	
		actual->dibujar(wnd);	
	}
}
