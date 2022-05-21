/*
 * Mascotas.h
 *
 *  Created on: 13 may. 2022
 *      Author: Sebastian Migliorisi
 */

#ifndef MASCOTAS_H_
#define MASCOTAS_H_

typedef struct {
	int id;
	char descripcion[20];

} eTipo;

typedef struct {
	int id;
	char descripcion[20];

} eColor;

typedef struct {
	int id;
	char nombre[20];
	int idTipo;
	int idColor;
	int edad;
	char vacunado;
	int isEmpty;
} eMascota;

void mostrarMascota (eMascota bic, eTipo tipo[], int tamtip, eColor color[], int tamcol);
void mostrarMascotas (eMascota vec[], int tam, eTipo tipo[], int tamtip, eColor color[], int tamcol);
int cargarDescripcionTipo(char descripcion[], int id, eTipo tipo[], int tamtip);
int cargarDescripcionColor(char descripcion[], int id, eColor color[], int tamcol);
void ordenarMascotas(eMascota vec[], int tam);
void inicializarMascotas(eMascota vec[], int tam);
void hardCodearMascotas(eMascota vec[], int cant);
void listarTipos (eTipo tipo[], int tam);
void listarColor (eColor color[], int tam);
int altaMascota (int idx, eMascota vec[], int tam, eTipo tipo[], int tamtip, eColor color[],int tamcol);
void modificarMascota (eMascota vec[], int tam, eTipo tipo[], int tamtip, eColor color[],int tamcol);
void bajaMascota (eMascota vec[], int tam,  eTipo tipo[], int tamtip, eColor color[],int tamcol);
int buscarMascota (int idx, eMascota vec[], int tam);
int checkEmpty(eMascota* list, int len);

#endif /* MASCOTAS_H_ */
