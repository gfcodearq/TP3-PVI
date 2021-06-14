#include "Tren.h"

using namespace sf;

Tren::Tren()
{
	
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
			referenciaAnterior = auxiliarBorrado->siguiente;
		}
		if(auxiliarBorrado == NULL)
		{
			return;
		}
		else if(referenciaAnterior == NULL)
		{
			primero = primero->siguiente;
			delete auxiliarBorrado;
		}
		else 
		{
			referenciaAnterior->siguiente = auxiliarBorrado->siguiente;
			delete auxiliarBorrado;
		}
	}	
}



bool Tren::TrenVacio() //Si el tren no tiene vagones retorna true
{
	
}

int Tren::obtenerCantidadVagones()//obtiene la canitadad de vagones 
{
	
}

void Tren::ControlarColisiones()
{
	Vagon *actual = primero;
	FloatRect ColliderWagon = actual->spriteWagon->getGlobalBounds();
	while(actual != NULL)
	{
		FloatRect ColliderTrain = train->spriteTrain->getGlobalBounds();
		if(ColliderWagon.intersects(ColliderTrain))
		{
			//Motrar en pantalla la suma 
		}
		else
		{
			actual = actual->siguiente;
		}
	}
}

