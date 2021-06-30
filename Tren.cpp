#include "Tren.h"
#include <iostream>
#include <string>

using namespace sf;

Tren::Tren(int posX,int posY)
{	
	tex_train = new Texture;
	tex_train->loadFromFile("Recursos//Imagenes//locomotora.png");
	//Sprite tren -creo-escalo-seteo posicion
	sprite_train = new Sprite(*tex_train);
	sprite_train->scale(0.7,0.7);
	sprite_train->setPosition(posX,posY);
	//Inicializo la lista
	laListaEsEsto = NULL;	
	
	Insertar(1,30,51); //Nodo inicial 	
	Insertar(15,120,51); //Nodo inicial
	//Inicializo boleano en false	
	bool TrenVacio = false;
	colisiono = false;	
	
}

void Tren::Insertar(int v,int posX,int posY) //Metodo para insertar vagones de forma ordenada
{
	Vagon *wagon = new Vagon(v,wagon->spriteWagon,wagon->siguiente);
	wagon->spriteWagon->setPosition(posX,posY);
	wagon->setValor(v);
	wagon->txt_vagon->setPosition(posX+40,posY);
	wagon->txt_vagon->setString(to_string(v));
	
	Vagon *firstAuxiliar = laListaEsEsto; //Creo el primer nodo que apunta a la lista
	Vagon *secondAuxiliar = NULL; //Segundo apunta a null
	
	
	while(firstAuxiliar != NULL && wagon->nroEnVagon > v ) //Mientras que exista algo en la lista y el valor del vagon sea mayor al valor del vagon actual
	{
		secondAuxiliar = firstAuxiliar;	
		firstAuxiliar = firstAuxiliar->siguiente;		
	}
	if(laListaEsEsto == firstAuxiliar)
	{
		laListaEsEsto = wagon;
	}
	else
	{
		secondAuxiliar->siguiente = wagon;	
	}
	wagon->siguiente = firstAuxiliar;
}

void Tren::Borrar(int v) //Metodo para eliminar vagones
{
	if(laListaEsEsto !=NULL)
	{
		Vagon *auxiliarBorrado = laListaEsEsto;
		Vagon *referenciaAnterior = NULL;
		while(auxiliarBorrado !=NULL) //Y la suma de correctamente
		{
			referenciaAnterior = auxiliarBorrado; 
			auxiliarBorrado = auxiliarBorrado->siguiente;
		}
		if(auxiliarBorrado == NULL) //Si no hay nada en la lista no realiza ninguna accion
		{
			return;
		}
		else if(referenciaAnterior == NULL)
		{
			laListaEsEsto = laListaEsEsto->siguiente;
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
	if(laListaEsEsto == NULL || CantVagones == 0) //si la lista esta devuelve true 
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
//	Vagon *actual = laListaEsEsto;	// me posiciono en el primer nodo de la lista
//	FloatRect ColliderVagon = actual->spriteWagon->getGlobalBounds();
//	while(actual != NULL)
//	{		
//		if(ColliderVagon.intersects()) //Si intersecta el vagon con el tren
//		{				
//			colisiono = true;
//			cout<<"colisiono"<<endl; //Mensaje de comprobacion	
//			reloj->restart(); //inicio el reloj
//			CantVagones ++;	//Aumento la cantidad de vagones			
//			return; 
//		}
//		else
//		{
//			actual = actual->siguiente;
//		}
//	}	
}

void Tren::MostrarLista(RenderWindow &wnd)
{

}

void Tren::Dibujar(RenderWindow *wnd)
{	
	Vagon *aux = laListaEsEsto;
	
	while(aux != NULL) { //Mientras no este dibujado
		wnd->draw(*aux->spriteWagon); //dibuja el sprite del vagon
		wnd->draw(*aux->txt_vagon);	 //dibuja el texto del vagon	
		aux = aux->siguiente; //Señala al nodo siguiente
	}
	wnd->draw(*sprite_train);//Dibujo el sprite del tren
	if(colisiono)
	{
		wnd->draw(*txt_tiempo);
		wnd->draw(*txt_operacion);
	}
	
	
}

void Tren::Actualizar() //Actualiza la posicion del tren
{
	Vagon *actual = laListaEsEsto; //primer nodo en la lista
	sprite_train->setPosition(sprite_train->getPosition().x+3,sprite_train->getPosition().y);	
	actual->spriteWagon->setPosition(actual->spriteWagon->getPosition().x+3,actual->spriteWagon->getPosition().y); //muevo el primer nodo de la lista
	actual->siguiente->spriteWagon->setPosition(actual->siguiente->spriteWagon->getPosition().x+3,actual->siguiente->spriteWagon->getPosition().y); //muevo el nodo siguiente
	actual->txt_vagon->setPosition(actual->txt_vagon->getPosition().x+3,actual->txt_vagon->getPosition().y); //actualizo la posicion del texto del primer nodo
	actual->siguiente->txt_vagon->setPosition(actual->siguiente->txt_vagon->getPosition().x+3,actual->siguiente->txt_vagon->getPosition().y); //actualizo la posicion del texto del nodo siguiente
	
	if(sprite_train->getPosition().x > 800) // si el tren pasa los limites de la pantalla bajo un nivel
	{
		cout<<"Paso los limites"<<endl;
		sprite_train->setPosition(0,sprite_train->getPosition().y + 100);		
	}	
	
	if(actual->spriteWagon->getPosition().x > 800 ) 
	{
		actual->spriteWagon->setPosition(0,actual->spriteWagon->getPosition().y + 100);
		actual->txt_vagon->setPosition(40,actual->txt_vagon->getPosition().y + 100);
	}
	
	if(actual->siguiente->spriteWagon->getPosition().x > 800 )
	{
		actual->siguiente->spriteWagon->setPosition(0,actual->siguiente->spriteWagon->getPosition().y + 100);
		actual->siguiente->txt_vagon->setPosition(40,actual->siguiente->txt_vagon->getPosition().y + 100);
	}
	   
	if(colisiono)
	{
		PararTren();
	}
}

void Tren::PararTren()
{
	sprite_train->setPosition(sprite_train->getPosition().x-2.5,sprite_train->getPosition().y);	
	actual->txt_vagon->setPosition(actual->txt_vagon->getPosition().x-2.5,actual->txt_vagon->getPosition().y); //actualizo la posicion del texto del primer nodo
//	actual->siguiente->txt_vagon->setPosition(actual->siguiente->txt_vagon->getPosition().x-2.5,actual->siguiente->txt_vagon->getPosition().y); //actualizo la posicion del texto del nodo siguiente
}

Sprite Tren::get_sprite()
{
	return *sprite_train;
}


