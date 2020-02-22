#ifndef N_NODO
#define N_NODO

#include <iostream>

using namespace std;

template <class elemento>

class Nodo
{
    private:
        elemento info;
        Nodo <elemento> *prox;

    public:
        Nodo();
        Nodo(elemento nuevo_elemento); //Declaramos el Nodo
        elemento obtenerElemento();// retorna el elemento
        void modificarElemento(elemento elemento_modificar); // modifica el elemnto
        Nodo<elemento>* siguiente(); // retornando apuntador a siguiente
        void modificarSiguiente(Nodo <elemento>* siguiente);
};

template <class elemento>
Nodo<elemento>::Nodo()//Metodo constructor
{
	elemento *aux;
	aux = new elemento;
	this->info = *aux;
	this->prox = NULL;
}


template <class elemento>
Nodo<elemento>::Nodo(elemento nuevo_elemento)//Metodo constructor
{
  this->info = nuevo_elemento;
  this->prox = NULL;
}


template <class elemento>
elemento Nodo<elemento>::obtenerElemento() //obtener Elemento
{
    return this->info;
}

template <class elemento>
void Nodo<elemento>::modificarElemento(elemento elemento_modificar)//Modificando elemento
{
    this->info = elemento_modificar;
}

template <class elemento>
Nodo<elemento>* Nodo<elemento>::siguiente()
{
    return this->prox;
}


// hace que un elemento apunte a la lista o al puntero que le pasamos por parametro(siguiente) 
template <class elemento>
void Nodo<elemento>::modificarSiguiente(Nodo <elemento>*siguiente)
{
    this->prox = siguiente;
}

#endif