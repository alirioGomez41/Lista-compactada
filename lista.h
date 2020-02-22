#ifndef L_LISTA
#define L_LISTA

#include <iostream>
#include <assert.h>
#include "nodo.h"

using namespace std;

template <class elemento>
class Lista : public Nodo<elemento>
{
    private:
    Nodo <elemento> *primero;
    int tamano;

    public:
    Lista(); // constructor
    void insertar(elemento elemento_insertar,int posicion); // insertar elemento
    bool esVacia(); // me dice si es vacia
    int longitud(); // Devuelve la longitud
    elemento consultar(int posicion); //Consulta un elemento
    bool esta(elemento element); // verifica que este un elemento en la lista: True o False 
    void eliminar(int posicion);// ingreso una posicion y la elimino
    // void eliminarElemento(elemento elemento);// Busco un elemento y lo elimino
    void ordenar(bool ascendente);
    void modificar(elemento element, int posicion);
    ~Lista();//Destructor

};
//Constructor
template <class elemento>
Lista <elemento>::Lista()
{
    this->primero  = NULL;
    this->tamano = 0;
}

//Verifica si es vacia
template <class elemento>
bool Lista<elemento>::esVacia()
{
    return this->tamano == 0;
}
//Retorna la longitud de la lista
template <class elemento>
int Lista<elemento>::longitud()
{	
	return this->tamano;
}


template <class elemento>
void Lista<elemento>::insertar(elemento nuevo_elemento, int posicion)
{
	assert(posicion <= this->tamano + 1 && posicion >= 1);
    int i;
    Nodo <elemento>*anterior,*siguiente,*nuevo;
	nuevo = new Nodo<elemento>;
	nuevo->modificarElemento(nuevo_elemento);
    
       
        if(posicion == 1)
        {                               //el puntero de la lista
        	nuevo->modificarSiguiente(this->primero);  //el prox de elemento nuevo apuntara a donde primero
            this->primero = nuevo;
		}
        else
        {
            anterior = this->primero;
            siguiente = anterior->siguiente();
            i = 2;
            while( i < posicion && siguiente != NULL )
            {
                anterior = siguiente;
                siguiente = siguiente->siguiente();
                i++;
            }
            anterior->modificarSiguiente(nuevo);
            nuevo->modificarSiguiente(siguiente);
        }
        
        this->tamano++;
        
}

template <class elemento>
elemento Lista <elemento>::consultar (int posicion)
{
    int i;

    Nodo <elemento> *anterior,*actual;   

    if (posicion == 1)
    {
        return this->primero->obtenerElemento();
    }
    else
    {
        anterior = this->primero;
        actual = anterior->siguiente();
        i = 2;
       while(i < posicion && actual != NULL)
       {
           anterior = anterior->siguiente();
           actual = anterior->siguiente();
           i++;
       }
       if(i = posicion && actual != NULL)
       {
           return actual->obtenerElemento();
       }
    }
    
}

template <class elemento>


// Este metodo elimina una poscionElimina una posicion
void Lista<elemento>::eliminar(int posicion)
{   
	assert(posicion >= 1 && posicion <= this->tamano);
    int i;
    Nodo <elemento> *actual,*auxiliar;

    if(posicion == 1)
    {
        auxiliar = this->primero;
        this->primero = auxiliar->siguiente();
     
    }
    else
    {
        actual = this->primero;
		for(i = 2; i < posicion; i++)
		{
			actual = actual->siguiente();
		}
		auxiliar = actual->siguiente();
		actual = auxiliar->siguiente(); // 
    }
    delete auxiliar;
    this->tamano = this->tamano - 1;

}
//Esta vaina me da ciclo InfinitoxD xD
// template <class elemento>
// void Lista<elemento>::eliminarElemento(elemento elemento)
// {
//     	Nodo<elemento> *anterior , *auxiliar, *actual;
//         anterior = this->primero;
//         actual = anterior->siguiente();
// 	while(actual != NULL)
// 	{
// 		if (anterior == this->primero && anterior->siguiente() == elemento)
// 		{
// 			auxiliar = anterior;
// 			this->primero = actual;
// 			anterior = actual;
// 			actual = actual->siguiente();
// 			delete auxiliar;
// 		}
// 		else if(actual->siguiente() == elemento)
// 		{
// 			auxiliar = actual;
// 			anterior->modificarSiguiente(actual->siguiente());
// 			actual = actual->siguiente();
// 			delete auxiliar;
// 		}
// 		else
// 		{
// 			anterior->modificarSiguiente(actual);
// 			actual->modificarSiguiente(actual->siguiente());
// 		}
// 	}
// }

template <class elemento>
void Lista<elemento>::modificar(elemento element, int posicion)
{
	assert(posicion >= 1 && posicion <= this->tamano);
	int i = 1;
	Nodo<elemento> *actual;
    actual =  this->primero;;

	while(i <= posicion)
	{
		actual = actual->siguiente();
		i++;
	}
	actual->modificarElemento(element);
}

template <class elemento>
bool Lista<elemento>::esta(elemento element)
{
	
	Nodo<elemento> *auxiliar;
    auxiliar = this->primero; 
	bool encontrado = false;

	while(auxiliar != NULL && !encontrado)
	{
		if(auxiliar->obtenerElemento() == element)
			encontrado = true;
		else
			auxiliar = auxiliar->siguiente();
	}
    // TRUE = 1 and FALSE = 0
	return encontrado;
}

template<class elemento>
void Lista<elemento>::ordenar(bool ascendente)
{
    Nodo<elemento> *anterior, *actual;
    elemento auxiliar;
    int i, j;

    if(this->primero != NULL)
    {
        anterior = this->primero;
        actual = anterior->siguiente();
        for(i = 2; i <= this->tamano; i++)
        {
            for(j = 1; j <= this->tamano - i + 1; j++)
            {
                if(ascendente && anterior->obtenerElemento() > actual->obtenerElemento())
                {
                    auxiliar = anterior->obtenerElemento();
                    anterior->modificarElemento(actual->obtenerElemento());
                    actual->modificarElemento(auxiliar);
                }
                else if(!ascendente && anterior->obtenerElemento() < actual->obtenerElemento())
                {
                    auxiliar = anterior->obtenerElemento();
                    anterior->modificarElemento(actual->obtenerElemento());
                    actual->modificarElemento(auxiliar);
                }
                anterior = anterior->siguiente();
                actual = actual->siguiente();
            }
            anterior = this->primero;
            actual = anterior->siguiente();
        }
    }
}

template <class elemento>
 Lista <elemento>::~Lista()
{
    Nodo<elemento> *actual;
	actual = this->primero;
	while(actual != NULL)
	{
		actual = this->primero;
		this->primero = this->primero->siguiente();
		delete actual;
	}
    this->tamano = 0;
}



#endif