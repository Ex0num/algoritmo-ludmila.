/*
 ============================================================================
 Name        : CLASE-6_EJERCICIO_Algoritmo_Ludmila.c
 Author      : Gabriel Lopez G
 Version     :
 Copyright   : GLG
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

	#include <stdio.h>
	#include <stdlib.h>
	#define LENArrayMauricio 5

	int minimoNumArrayInt (int* arrayInt, int tamanoArrayInt, int desdeQuePosicionEmpiezo ,int* pNumeroMinimoCalculado, int* pIndiceMinimoCalculado); //firma

	int main(void)
	{
		int arrayDeMauricio[LENArrayMauricio] = {21,5,15,18,9};

		//aca empieza la funcion de ordenar algoritmo.

		int auxiliar;
		int valorMin;
		int indiceMin;
		int limite;

		limite = LENArrayMauricio - 1;

		minimoNumArrayInt (arrayDeMauricio, LENArrayMauricio, 0 , &valorMin, &indiceMin); //llamo a mi funcion

		for ( int i = 0 ; i < limite ; i++  )
		{
			minimoNumArrayInt (arrayDeMauricio, LENArrayMauricio, i ,&valorMin, &indiceMin); //calculo el minimo desde i

			if ( i != indiceMin)
			{
				auxiliar = arrayDeMauricio[i];
				arrayDeMauricio[i] = valorMin;
				arrayDeMauricio[indiceMin] = auxiliar;
			}

		}


		// FOR para mostrar resultados.

		for ( int ii = 0 ; ii < LENArrayMauricio ; ii++ )
		{
			printf ("\nIndice: %d Valor: %d \n", ii, arrayDeMauricio[ii]);
		}
	}


	//FUNCION DEL MINIMO

	int minimoNumArrayInt (int* arrayInt, int tamanoArrayInt, int desdeQuePosicionEmpiezo ,int* pNumeroMinimoCalculado, int* pIndiceMinimoCalculado)
		{
			int retorno;
			retorno = -1;

			if ( arrayInt != NULL && tamanoArrayInt >= 0 && pNumeroMinimoCalculado != NULL && pIndiceMinimoCalculado != NULL && desdeQuePosicionEmpiezo >= 0)
			{
				int minimo;
				int indice;

				minimo = arrayInt[desdeQuePosicionEmpiezo];
				indice = arrayInt[desdeQuePosicionEmpiezo];

				for (int i = desdeQuePosicionEmpiezo ; i < tamanoArrayInt ; i++ )
				{
					if ( arrayInt[i] < minimo )
					{
						minimo = arrayInt[i];
						indice = i;
					}
				}

				retorno = 0;
				*pNumeroMinimoCalculado = minimo;
				*pIndiceMinimoCalculado = indice;
			}
			return retorno;
		}
