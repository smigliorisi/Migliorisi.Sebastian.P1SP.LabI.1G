/*
 * Mascotas.c
 *
 *  Created on: 13 may. 2022
 *      Author: Sebastian Migliorisi
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN_SebaLib.h"
#include "Mascotas.h"
#include "datawarehouse.h"

/**
 * \brief Carga la descripcion de un Tipo indicada por un id
 *
 * \param descripcion variable donde se carga el dato
 * \param id id a buscar
 * \param tipo vector de datos de eTipo
 * \param tamtip tamaño de la lista
 * \return 0- No se encontro el id / 1- Descripcion cargada
 */
int cargarDescripcionTipo(char descripcion[], int id, eTipo tipo[], int tamtip)
{
	int retorno=0;
	int tamanio;
	for(int i=0;i<tamtip;i++)
	{
		if(tipo[i].id==id)
		{
			tamanio=sizeof(tipo[i].descripcion);
			strncpy(descripcion, tipo[i].descripcion, tamanio);
			retorno=1;
		}
	}
	return retorno;
}
/**
 * \brief Carga la descripcion de un Color indicada por un id
 *
 * \param descripcion variable donde se carga el dato
 * \param id id a buscar
 * \param color vector de datos de eColor
 * \param tamcol tamaño de la lista
 * \return 0- No se encontro el id / 1- Descripcion cargada
 */
int cargarDescripcionColor(char descripcion[], int id, eColor color[], int tamcol)
{
	int retorno=0;
	int tamanio;
	for(int i=0;i<tamcol;i++)
	{
		if(color[i].id==id)
		{
			tamanio=sizeof(color[i].descripcion);
			strncpy(descripcion, color[i].descripcion, tamanio);
			retorno=1;
		}
	}
	return retorno;
}

void mostrarMascota (eMascota masc, eTipo tipo[], int tamtip, eColor color[], int tamcol)
{
	char descripcionTipo[20];
	char descripcionColor[20];
	cargarDescripcionTipo(descripcionTipo, masc.idTipo, tipo, tamtip);
	cargarDescripcionColor(descripcionColor, masc.idColor, color, tamcol);

	printf("%d	%10s	%10s     %10s   %d   %c\n", masc.id, masc.nombre, descripcionTipo, descripcionColor, masc.edad, masc.vacunado);
}

void mostrarMascotas (eMascota vec[], int tam, eTipo tipo[], int tamtip, eColor color[], int tamcol)
{
	int vacio=0;

	printf("\n******* Lista de Mascotas *******\n");
	printf("Id          nombre     Tipo     Color      Edad       Vacunado\n\n");

	ordenarMascotas(vec, tam);
	for(int i=0;i<tam;i++)
	{
		if (vec[i].isEmpty==0)
		{
			mostrarMascota(vec[i],tipo, tamtip, color, tamcol);
			vacio=1;
		}
	}
	if(!vacio)
		printf("\n******* No hay mascotas que listar *******\n\n");
}

void ordenarMascotas(eMascota vec[], int tam)
{
	eMascota auxMascota;

	for(int i=0;i<tam-1;i++)
	{
		for(int j=i+1;j<tam;j++)
		{
			if(vec[i].idTipo > vec[j].idTipo)
			{
				auxMascota=vec[i];
				vec[i]=vec[j];
				vec[j]=auxMascota;
			}
			else if (vec[i].idTipo == vec[j].idTipo && vec[i].nombre > vec[j].nombre)
			{
				auxMascota=vec[i];
				vec[i]=vec[j];
				vec[j]=auxMascota;
			}
		}
	}

}
/**
 * \brief Inicializa un vector eMascota
 *
 * \param vec vector a inicializar
 * \param tam tamaño del vector
 */
void inicializarMascotas(eMascota vec[], int tam)
{
	for(int i=0; i<tam; i++)
	{
		vec[i].isEmpty=1;
	}
}
/**
 * \brief Hardcodea variables de eMascota
 *
 * \param vec vector a cargar
 * \param cant cant de datos a cargar
 */
void hardCodearMascotas(eMascota vec[], int cant)
{
	for(int i=0;i<cant;i++)
	{
		vec[i].id=hId[i];
		strncpy(vec[i].nombre,hNombre[i],sizeof(vec[i]));
		vec[i].idTipo=hIdTipo[i];
		vec[i].idColor=hIdColor[i];
		vec[i].edad=hEdad[i];
		vec[i].vacunado=hVacunado[i];
	}
}
/**
 * \brief Busca un indice libre de una lista eMascota
 *
 * \param vec vector a analizar
 * \param tam tamaño del vector
 * \return
 */
int buscarLibre (eMascota vec[], int tam)
{
	int indice=-1;

	for(int i=0; i<tam; i++)
		if(vec[i].isEmpty)
		{
			indice=i;
			break;
		}
	return indice;
}
/**
 * \brief Busca un indice libre de una lista eMascota
 *
 * \param idx id a buscar
 * \param vec vector a analizar
 * \param tam tamaño del vector
 * \return
 */
int buscarMascota (int idx, eMascota vec[], int tam)
{
	int indice=-1;

	for(int i=0;i<tam;i++)
		if(vec[i].id == idx && vec[i].isEmpty==0)
		{
			indice=i;
			break;
		}

	return indice;
}
/**
 * \brief Muestra una lista de los Tipos
 *
 * \param tipo vector eTipo con los datos
 * \param tam tamaño de la lista
 */
void listarTipos (eTipo tipo[], int tam)
{
	printf("\n******* Lista de Tipos *******\n");
	printf("Id     Descripción \n\n");

	for(int i=0;i<tam;i++)
	{
		printf("%d          %10s\n", tipo[i].id, tipo[i].descripcion);
	}
}
/**
 * \brief Muestra una lista de los Colores
 *
 * \param color vector eColor con los datos
 * \param tam tamaño de la lista
 */
void listarColor (eColor color[], int tam)
{
	printf("\n******* Lista de Colores *******\n");
	printf("Id     Descripción \n\n");

	for(int i=0;i<tam;i++)
	{
		printf("%d          %10s\n", color[i].id, color[i].descripcion);
	}
}

int altaMascota (int idx, eMascota vec[], int tam, eTipo tipo[], int tamtip, eColor color[],int tamcol)
{
	int retorno=0;
	eMascota auxMascota;
	int indice = buscarLibre(vec,tam);
	if(indice==-1)
	{
		printf("Sistema Completo\n\n");

	}
	else
	{
		if(buscarMascota(idx,vec,tam)==-1)
		{
			  	if(utn_getString(auxMascota.nombre,"Ingrese nombre\n","ERROR (Rango->0,20)\n",0,20,2)==0 &&
				   utn_getNumeroInt(&auxMascota.edad,"Ingrese edad\n","ERROR (Rango->1,99)\n",1,99,2)==0 &&
				   utn_getCharacter(&auxMascota.vacunado,"La mascota esta vacunada? Ingrese 's' o 'n'\n","ERROR ('s' para confirmar)",'n','s',2)==0
				)
				{
					listarTipos(tipo,tamtip);
					if(utn_getNumeroInt(&auxMascota.idTipo,"Ingrese id de tipo\n","ERROR (Rango->1,5)\n",1,5,2)==0)
					{
						listarColor(color,tamcol);
						if(utn_getNumeroInt(&auxMascota.idColor,"Ingrese id de color\n","ERROR (Rango->1,5)\n",1,5,2)==0)
						{
							auxMascota.isEmpty=0;
							auxMascota.id=idx;
							vec[indice]=auxMascota;
							retorno=1;
						}
						else
							printf("No se ingresó el Mascota por errores en el ingreso de datos\n");
					}
					else
						printf("No se ingresó el Mascota por errores en el ingreso de datos\n");
				}
				else
					printf("No se ingresó el Mascota por errores en el ingreso de datos\n");
		}
		else
		{
			printf("Ya existe un Mascota registrado con ese id \n\n");
		}
	}
	return retorno;
}

void modificarMascota (eMascota vec[], int tam, eTipo tipo[], int tamtip, eColor color[],int tamcol)
{
	int id;
	int i;
	int opcion;
	char confirma;
	eMascota auxMascota;

	printf("\n******* Modificar Mascota *******\n");
	if(utn_getNumeroInt(&id,"Ingrese id\n","ERROR (Rango->0,10000)\n",0,10000,2)==0)
	{
		i = buscarMascota(id,vec,tam);
		if(i==-1)
		{
			printf("No hay registro de un Mascota con el id: %d\n", id);
		}
		else
		{
			mostrarMascota(vec[i],tipo,tamtip,color,tamcol);

			if(utn_getCharacter(&confirma,"Confirma el Mascota seleccionado?\n","ERROR ('s' para confirmar)",'n','s',2)==0 && confirma=='s')
			{
				do
				{
					if(utn_getNumeroInt(&opcion,"\n Ingrese variable a modificar: 1-Tipo 2-Vacunado 3-Salir\n", "ERROR (Rango 1->3)",1,3,2)==0)
					{
						switch(opcion)
						{
							case 1:
								listarTipos(tipo,tamtip);
								if(utn_getNumeroInt(&auxMascota.idTipo,"Ingrese id de tipo\n","ERROR (Rango->1,5)\n",1,5,2)==0)
								{
									vec[i].idTipo=auxMascota.idTipo;
									printf("Se realizó la modificación con éxito\n");
								}
								else
									printf("\nNo se modificaron datos\n");
								break;
							case 2:
								if(utn_getCharacter(&auxMascota.vacunado,"Ingrese si la mascota esta vacunada ('s' o 'n')\n","ERROR ('s' para confirmar)",'n','s',2)==0)
								{
									vec[i].vacunado=auxMascota.vacunado;
									printf("Se realizó la modificación con éxito\n");
								}
								else
									printf("\nNo se modificaron datos\n");
								break;
							case 3:
								break;
						}
					}
				}while(opcion!=3);
			}
			else
			{
				printf("Se canceló la operación\n");
			}
		}
	}
}

void bajaMascota (eMascota vec[], int tam,  eTipo tipo[], int tamtip, eColor color[],int tamcol)
{
	int id;
	int indice;
	char confirma;

	printf("\n******* Baja de Mascota *******\n");
	if(utn_getNumeroInt(&id,"Ingrese id\n","ERROR (Rango->0,10000)\n",0,10000,2)==0)
	{
		indice = buscarMascota(id,vec,tam);
		if(indice==-1)
		{
			printf("No hay registro de un Mascota con el id: %d\n", id);
		}
		else
		{
			mostrarMascota(vec[indice],tipo,tamtip,color,tamcol);

			if(utn_getCharacter(&confirma,"Confirma la baja?\n","ERROR ('s' para confirmar)",'n','s',2)==0 && confirma=='s')
			{
				vec[indice].isEmpty=1;
				printf("Se realizó la baja con éxito\n");
			}
			else
			{
				printf("Se canceló la operación\n");
			}
		}
	}

}

/**
 * \brief Indica si la lista está vacía
 *
 * \param list Employee*
 * \param len int
 * \return -1 Error - 0 Vacia - 1 No vacía
 */
int checkEmpty(eMascota* list, int len)
{
	int retorno=-1;
	retorno=0;
	for(int i=0; i<len; i++)
	{
		if(list[i].isEmpty==0)
		{
			retorno=1;
			break;
		}
	}

	return retorno;
}
