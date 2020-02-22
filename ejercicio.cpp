#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>

#include "lista.h"
using namespace std;

void principal();
int main()
{
	principal();

	return 0;
}


void principal()
{
	//Archivos
	ifstream entrada;
	ofstream salida;

	//Variables
	int cantidad_elementos_distintos,casos_prueba,cont;
	int numero,repeticion,auxiliar;
	
	//Lista
	Lista<int> *numeros,*repeticiones;
	numeros = new Lista<int>;
	repeticiones = new Lista<int>;

	//Abriendo Archivos
	entrada.open("entrada.in",ios::in);	
	salida.open("salida.out",ios::out);

	if(entrada.fail() || salida.fail())
	{
		cout<<"No se puedo abrir el archivo";
		exit(1);
	}

	cont = 0;
	entrada>>casos_prueba;//leyendo cantida de casos prueba
	

	while (cont < casos_prueba)
	{
		 //leyendo los elementos de cada caso para poder iterar
		entrada>>cantidad_elementos_distintos;

		//iteramos n casos 
		while(cantidad_elementos_distintos > 0)
		{		
			// leemos el numero y la cantidad de veces que se repite
			entrada>>numero>>repeticion; 

			//Insertamos ambos valores en listas separadas
			numeros->insertar(numero, numeros->longitud() + 1);
			repeticiones->insertar(repeticion, repeticiones->longitud() + 1);

			cantidad_elementos_distintos--;
		}
		//ordenamos
		numeros->ordenar(true);
		repeticiones->ordenar(true);
		//escribiendo
		salida<<"Lista#"<<cont + 1<<endl;

		for (int i = 1; i <= numeros->longitud(); i++)
		{
			//almaceno en auxiliar numero
			auxiliar = numeros->consultar(i);


			for (int j = 1; j <= repeticiones->consultar(i); j++)
			{
				//numero almacenado en auxiliar lo almaceno n repeticiones en el archivo de salida
				salida<<auxiliar;

			}
			
	
		}
		salida<<endl;
		salida<<endl;

		//Vaciando las listas: tengo una duda aqui, intente vaciarlas con el destructor pero solo me ingresaba los datos la primera vez
		numeros = new Lista<int>;
		repeticiones = new Lista<int>;
		cont++;
	}
	

	
	salida.close();
	entrada.close();
}
