/*
 * Informes.c
 *
 *  Created on: 20 may. 2022
 *      Author: Sebastian Migliorisi
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN_SebaLib.h"
#include "Mascotas.h"
#include "Trabajo.h"
#include "Informes.h"


void informesTrabajos(eMascota lista[],int tam,eTrabajo trabajos[],int tamtra, eColor colores[],int tamcol, eTipo tipo[], int tamtip, eServicio servicios[],int tamser)
{
	int opcion;
	do
	{
		if(utn_getNumeroInt(&opcion, "\n***** Menu de Informes *****\n\n"
				"1-	Mostrar las mascotas del color seleccionado por el usuario.\n"
				"2-	Informar promedio de mascotas vacunadas sobre el total de mascotas.\n"
				"3-	Informar la o las mascotas de menor edad.\n"
				"4-	Listar de las mascotas separadas por tipo.\n"
				"5-	Elegir un color y un tipo y contar cuantas mascotas hay de ese color y ese tipo.\n"
				"6-	Mostrar el o los colores con más cantidad de mascotas\n"
				"7-	Pedir una mascota y mostrar todos los trabajos que se le hicieron a la misma.\n"
				"8-	Pedir una mascota e informar la suma de los importes de los servicios que se le hicieron a la misma\n"
				"9-	Pedir un servicio y mostrar las mascotas a las que se les realizo ese servicio y la fecha.\n"
				"10-     Pedir una fecha y mostrar todos los servicios realizados en la misma.\n"
				"11-     Salir\n",
				"\nReingrese Opcion ('1' a '11')\n",1,11,2)==0)
		{
			switch(opcion)
			{
				case 1:
					mostrarMascotasPorColor(lista, tam, colores, tamcol, tipo, tamtip);
					break;
				case 2:
					listarPromedioVacunados (lista, tam);
					break;
				case 3:
					informarMascotaMenorEdad(lista, tam, colores, tamcol, tipo, tamtip);
					break;
				case 4:
					listarMascotaPorTipo(lista, tam, colores, tamcol, tipo, tamtip);
					break;
				case 5:
					contarMascotaPorColorYTipo(lista, tam, colores, tamcol, tipo, tamtip);
					break;
				case 6:
					mostrarColoresMasElegidos(lista, tam, colores, tamcol, tipo, tamtip);
					break;
				case 7:
					trabajosPorMascota(lista, tam, colores, tamcol, tipo, tamtip, trabajos, tamtra, servicios, tamser);
					break;
				case 8:
					sumaDeImportesPorMascota(lista, tam, colores, tamcol, tipo, tamtip, trabajos, tamtra, servicios, tamser);
					break;
				case 9:
					mascotasPorServicio(lista, tam, colores, tamcol, tipo, tamtip, trabajos, tamtra, servicios, tamser);
					break;
				case 10:
					serviciosPorFecha(lista, tam, colores, tamcol, tipo, tamtip, trabajos, tamtra, servicios, tamser);
					break;
				case 11:
					break;
			}
		}

	}while(opcion!=11);
}

void mostrarMascotasPorColor (eMascota vec[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip)
{
	int color;
	int vacio=0;
	listarColor(colores, tamcol);
	if(utn_getNumeroInt(&color,"Ingrese id del color \n","ERROR (Rango->1,5)",1,5,2)==0)
	{
		printf("\n******* Lista de Mascotas    *******\n");
		printf("Id          nombre     Tipo     Color      Edad       Vacunado\n\n");

		for(int i=0;i<tam;i++)
		{
			if (vec[i].isEmpty==0 && vec[i].idColor==color)
			{
				mostrarMascota(vec[i],tipo, tamtip, colores, tamcol);
				vacio=1;
			}
		}
		if(!vacio)
			printf("\n******* No hay mascotas que listar *******\n\n");

	}
}

void mostrarMascotaPorTipo (eMascota vec[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip)
{
	int tipoElegido;
	int vacio=0;
	listarTipos(tipo, tamtip);
	if(utn_getNumeroInt(&tipoElegido,"Ingrese id del tipo \n","ERROR (Rango->1,5)",1,5,2)==0)
	{
		printf("\n******* Lista de Mascotas *******\n");
		printf("Id          nombre     Tipo     Color      Edad       Vacunado\n\n");

		for(int i=0;i<tam;i++)
		{
			if (vec[i].isEmpty==0 && vec[i].idTipo==tipoElegido)
			{
				mostrarMascota(vec[i],tipo, tamtip, colores, tamcol);
				vacio=1;
			}
		}
		if(!vacio)
			printf("\n******* No hay Mascotas que listar *******\n\n");

	}
}

void informarMascotaMenorEdad  (eMascota vec[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip)
{
	int vacio=0;
	float menorEdad=9999;

	for(int e=0;e<tam;e++)
	{
		if (vec[e].isEmpty==0 && vec[e].edad<menorEdad)
		{
			menorEdad=vec[e].edad;
			vacio=1;
		}
	}
	if(!vacio)
		printf("\n******* No hay Mascotas que listar *******\n\n");
	else
	{
		printf("******* Menor edad *******\n");
		printf("Id          nombre     Tipo     Color      Edad       Vacunado\n\n");
		for(int i=0;i<tam;i++)
		{
			if (vec[i].isEmpty==0 && menorEdad==vec[i].edad)
			{
				mostrarMascota(vec[i],tipo, tamtip, colores, tamcol);
			}
		}
	}
}

void listarMascotaPorTipo  (eMascota vec[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip)
{
	int vacio=0;
	char descripcionTipo[20];

	for(int e=1;e<=tamtip;e++)
	{
		cargarDescripcionTipo(descripcionTipo, e, tipo, tamtip);
		printf("\n******* Mascotas de tipo %s *******\n", descripcionTipo);

		printf("Id          nombre     Tipo     Color      Edad       Vacunado\n");

		for(int i=0;i<tam;i++)
		{
			if (vec[i].isEmpty==0 && vec[i].idTipo==e)
			{
				mostrarMascota(vec[i],tipo, tamtip, colores, tamcol);
				vacio=1;
			}
		}
		if(!vacio)
			printf("******* No hay Mascotas que listar *******\n");
	}
}

void contarMascotaPorColorYTipo (eMascota vec[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip)
{
	int vacio=0;
	int contador=0;
	int tipoElegido;
	int colorElegido;

	listarTipos(tipo, tamtip);
	if(utn_getNumeroInt(&tipoElegido,"Ingrese id del tipo \n","ERROR (Rango->1,4)",1,4,2)==0)
	{
		listarColor(colores,tamcol);
		if(utn_getNumeroInt(&colorElegido,"Ingrese id de color\n","ERROR (Rango->1,5)\n",1,5,2)==0)
		{
			for(int i=0;i<tam;i++)
			{
				if (vec[i].isEmpty==0 && vec[i].idColor==colorElegido && vec[i].idTipo==tipoElegido)
				{
					contador++;
					vacio=1;
				}
			}
			if(!vacio)
				printf("\n******* No hay Mascotas que listar *******\n\n");
			else
				printf("\n******* Hay %d Mascota/s de ese color y tipo *******\n\n", contador);

		}
	}
}

void mostrarColoresMasElegidos (eMascota vec[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip)
{
	int vacio=0;
	int contador[tamcol];
	int mayor=0;

	for(int e=0;e<tamcol;e++)
	{
		contador[e]=0;
	}
	for(int i=0;i<tam;i++)
	{
		if (vec[i].isEmpty==0)
		{
			contador[vec[i].idColor-1]++;
			if(contador[vec[i].idColor-1]>mayor)
				mayor=contador[vec[i].idColor-1];
			vacio=1;
		}
	}
	if(!vacio)
		printf("\n******* No hay Mascotas que listar *******\n\n");
	else
	{
		printf("******* Colores mas elegidos *******\n");
		printf("Id          nombre     Tipo     Color      Edad       Vacunado\n\n");
		for(int i=0;i<tam;i++)
		{
				if(vec[i].isEmpty==0 && mayor==contador[vec[i].idColor-1])
				{
					mostrarMascota(vec[i],tipo, tamtip, colores, tamcol);
					vacio=1;
				}
		}
	}
}


void trabajosPorMascota (eMascota mascotas[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip, eTrabajo trabajos[], int tamtra, eServicio servicios[],int tamser)
{
	int i;
	int id;
	char confirma='n';
	int flag=0;

	mostrarMascotas(mascotas,tam,tipo,tamtip,colores,tamcol);

	if(utn_getNumeroInt(&id,"Ingrese id\n","ERROR (Rango->0,20000)\n",0,20000,2)==0)
	{
		i = buscarMascota(id,mascotas,tam);
		if(i==-1)
		{
			printf("No hay registro de un Mascota con el id: %d\n", id);
		}
		else
		{
			mostrarMascota(mascotas[i],tipo,tamtip,colores,tamcol);

			if(utn_getCharacter(&confirma,"Confirma el Mascota seleccionado?\n","ERROR ('s' para confirmar)",'n','s',2)==0 && confirma=='s')
			{
				printf("\n***** Listado de Trabajos *****\n");
				printf("\n IdTrabajo   IdMascota   Nombre   Descripcion   Fecha \n");

				for(int i=0;i<tamtra;i++)
				{
					if(trabajos[i].isEmpty==0 && trabajos[i].idMascota==id)
					{
						mostrarTrabajo(trabajos[i], mascotas, tam, servicios, tamser);
						flag=1;
					}
				}
				if(flag==0)
					printf("\nNo hay trabajos para mostrar\n");
			}
		}
	}

}


void sumaDeImportesPorMascota (eMascota mascotas[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip, eTrabajo trabajos[], int tamtra, eServicio servicios[],int tamser)
{
	int i;
	int id;
	char confirma='n';
	int suma=0;

	mostrarMascotas(mascotas,tam,tipo,tamtip,colores,tamcol);

	if(utn_getNumeroInt(&id,"Ingrese id\n","ERROR (Rango->0,10000)\n",0,10000,2)==0)
	{
		i = buscarMascota(id,mascotas,tam);
		if(i==-1)
		{
			printf("No hay registro de un Mascota con el id: %d\n", id);
		}
		else
		{
			mostrarMascota(mascotas[i],tipo,tamtip,colores,tamcol);

			if(utn_getCharacter(&confirma,"Confirma el Mascota seleccionado?\n","ERROR ('s' para confirmar)",'n','s',2)==0 && confirma=='s')
			{

				for(int i=0;i<tamtra;i++)
					if(trabajos[i].isEmpty==0 && trabajos[i].idMascota==id)
						for(int e=0;e<tamser;e++)
							if(trabajos[i].idServicio==servicios[e].id)
								suma=suma+servicios[e].precio;
			}
			printf("La suma de importes de la misma es: %d\n", suma);

		}
	}

}

void mascotasPorServicio (eMascota mascotas[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip, eTrabajo trabajos[], int tamtra, eServicio servicios[],int tamser)
{
	int id;
	int vacio=0;

	listarServicios(servicios, tamser);
	if(utn_getNumeroInt(&id,"Ingrese id\n","ERROR (Rango->0,4)\n",0,4,2)==0)
	{
		printf("******* Mascotas con ese servicio  *******\n");
		printf("Id          nombre     Tipo     Color      Edad       Vacunado\n");

		for(int e=0;e<tam;e++)
		{
					if (trabajos[e].idServicio==id && mascotas[e].isEmpty==0)
					{
						printf("%d/%d/%d     ", trabajos[e].fecha.dia, trabajos[e].fecha.mes, trabajos[e].fecha.anio);
						mostrarMascota(mascotas[e],tipo, tamtip, colores, tamcol);
						vacio=1;
					}
		}
		if(!vacio)
			printf("\n******* No hay Mascotas que listar *******\n\n");
	}

}

void serviciosPorFecha (eMascota mascotas[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip, eTrabajo trabajos[], int tamtra, eServicio servicios[],int tamser)
{
	eTrabajo auxTrabajo;
	int vacio=0;

	if( utn_getNumeroInt(&auxTrabajo.fecha.dia,"Ingrese dia\n","ERROR (Rango->0,31)\n",0,31,2)==0 &&
		utn_getNumeroInt(&auxTrabajo.fecha.mes,"Ingrese mes\n","ERROR (Rango->0,12)\n",0,12,2)==0 &&
		utn_getNumeroInt(&auxTrabajo.fecha.anio,"Ingrese año\n","ERROR (Rango->1900,2022)\n",1900,2022,2)==0)
		{
			printf("\n***** Listado de Servicios para esa fecha *****\n");
			printf("\n Id Descripcion Precio \n");
			for(int i=0;i<tamser;i++)
			{
				for(int e=0;e<tamtra;e++)
				{
					if(auxTrabajo.fecha.dia==trabajos[e].fecha.dia && auxTrabajo.fecha.mes==trabajos[e].fecha.mes && auxTrabajo.fecha.anio==trabajos[e].fecha.anio && trabajos[e].idServicio==servicios[i].id)
					{
						printf(" %d    %10s    %5.2f\n", servicios[i].id, servicios[i].descripcion, servicios[i].precio);
						vacio=1;
					}
				}
			}
		}
	if(!vacio)
		printf("\n******* No hay Mascotas que listar *******\n\n");
}

void listarPromedioVacunados(eMascota mascotas[], int len)
{
	float promedio;
	float cantMasc=0;
	float cantVac=0;

	if(mascotas!=NULL && checkEmpty(mascotas, len)==1)
	{
		for(int i=0;i<len;i++)
		{
			if (mascotas[i].isEmpty==0)
			{
				if (mascotas[i].vacunado=='s')
				{
					cantVac++;
				}
				cantMasc++;
			}
		}
		promedio=(cantVac/cantMasc)*100;
		printf("\n******* Total de mascotas: %0.0f\n", cantMasc);
		printf("\n******* Cantidad vacunadas: %0.0f\n", cantVac);
		printf("\n******* Promedio de vascotas vacunadas: %0.2f\n", promedio);
	}
}

