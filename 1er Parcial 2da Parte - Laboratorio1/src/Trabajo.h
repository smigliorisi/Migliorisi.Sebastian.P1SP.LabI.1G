/*
 * Trabajo.h
 *
 *  Created on: 13 may. 2022
 *      Author: Sebastian Migliorisi
 */

#ifndef TRABAJO_H_
#define TRABAJO_H_

typedef struct {
	int dia;
	int mes;
	int anio;

} eFecha;

typedef struct {
	int id;
	char descripcion[25];
	float precio;

} eServicio;


typedef struct {
	int id;
	int idMascota;
	int idServicio;
	eFecha fecha;
	int isEmpty;

} eTrabajo;


void listarServicios (eServicio servicio[], int tam);
void inicializarTrabajos(eTrabajo vec[], int tam);
void mostrarServicios (eServicio servicio[], int tam);
int buscarTrabajo (int idx, eTrabajo vec[], int tam);
int buscarLibreT (eTrabajo vec[], int tam);
int cargarBicicleta(char* marcaBicicleta,eMascota mascotas[],int tam,int idMascota);
int cargarServicio(char* descripcionServicio,eServicio servicios[],int tam,int idServicio);
void mostrarTrabajo(eTrabajo trabajo, eMascota mascotas[], int tambic, eServicio servicios[], int tamser);
void mostrarTrabajos(eTrabajo trabajos[], int tamtra, eMascota mascotas[], int tambic, eServicio servicios[], int tamser);
int altaTrabajo (int id, eTrabajo trabajos[], int tam, eMascota mascotas[], int tambic, eTipo tipo[], int tamtip, eColor color[], int tamcol, eServicio servicio[], int tamser);


#endif /* TRABAJO_H_ */
