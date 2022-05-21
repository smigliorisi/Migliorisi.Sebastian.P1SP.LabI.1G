/*
 * Trabajo.c
 *
 *  Created on: 13 may. 2022
 *      Author: Sehastian Migliorisi
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN_SebaLib.h"
#include "mascotas.h"
#include "Trabajo.h"

/**
 * \brief Muestra una lista de los Servicios
 *
 * \param servicio vector de tipo eServicio
 * \param tam tamaño de la lista
 */
void listarServicios (eServicio servicio[], int tam)
{
	printf("\n******* Lista de Servicios *******\n");
	printf("Id           Descripción    Precio\n\n");

	for(int i=0;i<tam;i++)
	{
		printf("%d          %10s         %.2f\n", servicio[i].id, servicio[i].descripcion, servicio[i].precio);
	}
}
/**
 * \brief Busca un indice libre de una lista eTrabajo
 *
 * \param vec vector a analizar
 * \param tam tamaño del vector
 * \return -1 si no hay espacio libre / numero de indice libre en caso contrario
 */
int buscarLibreT (eTrabajo vec[], int tam)
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
 * \brief Busca un id de una lista eTrabajo
 *
 * \param idx id a buscar
 * \param vec vector a analizar
 * \param tam tamaño del vector
 * \return -1 si no hay espacio libre / numero de indice encontrado en caso contrario
 */
int buscarTrabajo (int idx, eTrabajo vec[], int tam)
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

void mostrarServicios (eServicio servicio[], int tam)
{
	printf("\n***** Listado de Servicios *****\n");
	printf("\n Id Descripcion Precio \n");

	for(int i=0;i<tam;i++)
	{
		printf(" %d    %10s    %5.2f\n", servicio[i].id, servicio[i].descripcion, servicio[i].precio);
	}
}
/**
 * \brief Inicializa un vector eTrabajo
 *
 * \param vec vector a inicializar
 * \param tam tamaño del vector
 */
void inicializarTrabajos(eTrabajo vec[], int tam)
{
	for(int i=0; i<tam; i++)
	{
		vec[i].isEmpty=1;
	}
}

int altaTrabajo (int id, eTrabajo trabajos[], int tam, eMascota mascotas[], int tambic, eTipo tipo[], int tamtip, eColor color[], int tamcol, eServicio servicio[], int tamser)
{
	int retorno=0;
	int idMascota;
	int idServicio;
	eTrabajo auxTrabajo;
	int indice = buscarLibreT(trabajos,tam);
	if(indice==-1)
	{
		printf("Sistema Completo\n\n");

	}
	else
	{
		if(buscarTrabajo(id,trabajos,tam)==-1)
		{
				mostrarMascotas(mascotas,tambic,tipo,tamtip,color,tamcol);
				if(utn_getNumeroInt(&idMascota,"Ingrese id de Mascota\n","ERROR (Rango->0,10000)\n",0,10000,2)==0 && buscarMascota(idMascota, mascotas,tambic)!=-1)
				{
					mostrarServicios(servicio,tamser);
					if(utn_getNumeroInt(&idServicio,"Ingrese id servicio\n","ERROR (Rango->0,3)\n",0,3,2)==0)
					{
						if(
						utn_getNumeroInt(&auxTrabajo.fecha.dia,"Ingrese dia\n","ERROR (Rango->0,31)\n",0,31,2)==0 &&
						utn_getNumeroInt(&auxTrabajo.fecha.mes,"Ingrese mes\n","ERROR (Rango->0,12)\n",0,12,2)==0 &&
						utn_getNumeroInt(&auxTrabajo.fecha.anio,"Ingrese año\n","ERROR (Rango->1900,2022)\n",1900,2022,2)==0
						)
						{
									auxTrabajo.isEmpty=0;
									auxTrabajo.id=id;
									auxTrabajo.idServicio=idServicio;
									auxTrabajo.idMascota=idMascota;
									trabajos[indice]=auxTrabajo;
									retorno=1;
						}
					}
					else
						printf("No existe es id de comida\n");
				}
				else
					printf("No existe es id de Mascota\n");
		}
		else
		{
			printf("Ya existe un Trabajo registrado con ese id \n\n");
		}
	}
	return retorno;
}
/**
 * \brief Carga la nombre de una Mascota indicada por un id
 *
 * \param nombreMascota variable donde se carga el dato
 * \param mascotas vector de datos de eMascota
 * \param tam tamaño de la lista
 * \param idMascota id a buscar
 * \return 0- No se encontro el id / 1- Descripcion cargada
 */
int cargarMascota(char* nombreMascota,eMascota mascotas[],int tam,int idMascota)
{
	int retorno=-1;
	int size;
	if(nombreMascota!=NULL)
	{
		retorno=0;
		for(int i=0;i<tam;i++)
		{
			if(mascotas[i].id==idMascota)
			{
				size=sizeof(mascotas[i].nombre);
				strncpy(nombreMascota, mascotas[i].nombre, size);
				retorno=1;
			}
		}
	}
	return retorno;
}
/**
 * \brief Carga la descripcion de un Servicio indicado por un id
 *
 * \param descripcionServicio variable donde se carga el dato
 * \param servicios vector de datos de eServicio
 * \param tam tamaño de la lista
 * \param idServicio id a buscar
 * \return 0- No se encontro el id / 1- Descripcion cargada
 */
int cargarServicio(char* descripcionServicio,eServicio servicios[],int tam,int idServicio)
{
	int retorno=-1;
	int size;
	if(descripcionServicio!=NULL)
	{
		retorno=0;
		for(int i=0;i<tam;i++)
		{
			if(servicios[i].id==idServicio)
			{
				size=sizeof(servicios[i].descripcion);
				strncpy(descripcionServicio, servicios[i].descripcion, size);
				retorno=1;
			}
		}
	}
	return retorno;
}

void mostrarTrabajo(eTrabajo trabajo, eMascota mascotas[], int tambic, eServicio servicios[], int tamser)
{
	char nombreMascota[20];
	char descripcionServicio[20];
	cargarMascota(nombreMascota, mascotas, tambic, trabajo.idMascota);
	cargarServicio(descripcionServicio, servicios, tamser, trabajo.idServicio);

	printf(" %d          %d %10s  %10s     %d/%d/%d\n", trabajo.id, trabajo.idMascota, nombreMascota, descripcionServicio, trabajo.fecha.dia, trabajo.fecha.mes, trabajo.fecha.anio);
}

void mostrarTrabajos(eTrabajo trabajos[], int tamtra, eMascota mascotas[], int tambic, eServicio servicios[], int tamser)
{
	int flag=0;
	printf("\n***** Listado de Trabajos *****\n");
	printf("\n IdTrabajo   IdMascota   nombre   Descripcion   Fecha \n");

	for(int i=0;i<tamtra;i++)
	{
		if(trabajos[i].isEmpty==0)
		{
			mostrarTrabajo(trabajos[i], mascotas, tambic, servicios, tamser);
			flag=1;
		}
	}
	if(flag==0)
		printf("\nNo hay trabajos para mostrar\n");
}
