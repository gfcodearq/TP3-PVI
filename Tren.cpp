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
	//Inserto vagones
	Insertar(15,120,51);
	Insertar(1,30,51);
	Insertar(5,200,155);
	Insertar(8,500,350);
	//Textos	
	fuente2 = new Font;
	fuente2->loadFromFile("Recursos\\Textos\\Stenciland.otf");
	txt_tiempo = new Text;
	txt_tiempo->setFont(*fuente2);
	txt_tiempo->setColor(Color::Red);
	txt_tiempo->setString("Tiempo:"+to_string(5));
	txt_tiempo->setPosition(700,20);	
	
	txt_operacion = new Text;
	txt_operacion->setFont(*fuente2);
	txt_operacion->scale(0.5f,0.5f);
	txt_operacion->setString("Resuelva la operacion" + to_string(a) +"+" + to_string(b));
	txt_operacion->setPosition(300,25);	
	
	//Creo reloj
	reloj = new Clock;
	tiempo =  new Time;
	int tiempoEntero = reloj->getElapsedTime().asSeconds();//Variable entera para alojar el tiempo que pasa
	txt_tiempo->setString(to_string(tiempoEntero));
	//Inicializo boleano en false	
	bool TrenVacio = false;
	colisiono = false;
	
	a = rand() % 9 + 1;
	b = rand() % 9 + 1;
	
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
	if(laListaEsEsto == NULL) //si la lista esta devuelve true 
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
		if(ColliderTrain.intersects(actual->get_sprite().getGlobalBounds())) //Si intersecta el vagon con el tren
		{	
			colisiono = true;
			cout<<"colisiono"<<endl; //Mensaje de comprobacion			
			CantVagones ++;	//Aumento la cantidad de vagones			
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
	Vagon *actual = laListaEsEsto;
	sprite_train->setPosition(sprite_train->getPosition().x+3,sprite_train->getPosition().y);
	if(sprite_train->getPosition().x > 800) // si pasa los limites de la pantalla bajo un nivel
	{
		cout<<"Paso los limites"<<endl;
		sprite_train->setPosition(0,sprite_train->getPosition().y + 100);
	}			
	if(colisiono)
	{
		PararTren();
	}
}

void Tren::PararTren()
{
	sprite_train->setPosition(sprite_train->getPosition().x-3,sprite_train->getPosition().y);
}

Sprite Tren::get_sprite()
{
	return *sprite_train;
}

}
