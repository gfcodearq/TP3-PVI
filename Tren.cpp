#include "Tren.h"
#include <iostream>
#include <string>

using namespace sf;

Tren::Tren(int posX,int posY)
{	
	tex_train = new Texture;
	tex_train->loadFromFile("Recursos//Imagenes//locomotora.png");
	sprite_train = new Sprite(*tex_train);
	sprite_train->scale(0.7,0.7);
	sprite_train->setPosition(posX,posY);
	laListaEsEsto = NULL;
	Insertar(5,200,155);
	Insertar(5,500,350);	
	reloj = new Clock;
	tiempo =  new Time;	
	fuente3 = new Font;
	txt_tiempo = new Text;
	txt_tiempo->setFont(*fuente3);
	txt_tiempo->setPosition(700,20);	
}

void Tren::Insertar(int v,int posX,int posY) //Metodo para insertar vagones de forma ordenada
{
	Vagon *wagon = new Vagon(v,wagon->spriteWagon,wagon->siguiente);
	wagon->spriteWagon->setPosition(posX,posY);
	wagon->setValor(v);
	Vagon *firstAuxiliar = laListaEsEsto;
	Vagon *secondAuxiliar = NULL;
	
	while(firstAuxiliar != NULL && wagon->nroEnVagon > v )
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
		if(auxiliarBorrado == NULL)
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
	if(laListaEsEsto == NULL)
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
	Vagon *actual = laListaEsEsto;
	FloatRect ColliderTrain = sprite_train->getGlobalBounds();	
	while(actual != NULL)
	{		
		if(ColliderTrain.intersects(actual->get_sprite().getGlobalBounds()))
		{	
			reloj->restart();			
			int tiempo_entero = reloj->getElapsedTime().asSeconds();
			txt_tiempo->setString("Tiempo: "+to_string(tiempo_entero));
			//txt_tiempo-
			cout<<"colisiono"<<endl;			
			CantVagones ++;
			actual->spriteWagon->setPosition(sprite_train->getPosition().x-80,sprite_train->getPosition().y);
			actual->moverVagon();
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

}

void Tren::Dibujar(RenderWindow *wnd)
{	
	Vagon *aux = laListaEsEsto;
	
	while(aux != NULL) {
		wnd->draw(*aux->spriteWagon);
		wnd->draw(*aux->txt_vagon);
		aux = aux->siguiente;		
	}
	wnd->draw(*sprite_train);
	

}

void Tren::Actualizar()
{
	sprite_train->setPosition(sprite_train->getPosition().x+3,sprite_train->getPosition().y);
	if(sprite_train->getPosition().x > 800) // si pasa los limites de la pantalla bajo un nivel
	{
		cout<<"Paso los limites"<<endl;
		sprite_train->setPosition(0,sprite_train->getPosition().y + 100);
	}	
}

Sprite Tren::get_sprite()
{
	return *sprite_train;
}
