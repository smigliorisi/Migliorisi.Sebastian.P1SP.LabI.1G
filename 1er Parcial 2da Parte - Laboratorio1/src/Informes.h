/*
 * Informes.h
 *
 *  Created on: 20 may. 2022
 *      Author: Sebastian Migliorisi
 */

#ifndef INFORMES_H_
#define INFORMES_H_

void informesTrabajos(eMascota lista[],int tam,eTrabajo trabajos[],int tamtra, eColor colores[],int tamcol, eTipo tipo[], int tamtip, eServicio servicios[],int tamser);
void mostrarMascotasPorColor (eMascota vec[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip);
void mostrarMascotasPorTipo (eMascota vec[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip);
void informarMascotaMenorEdad  (eMascota vec[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip);
void listarMascotaPorTipo  (eMascota vec[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip);
void contarMascotaPorColorYTipo (eMascota vec[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip);
void mostrarColoresMasElegidos (eMascota vec[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip);
void trabajosPorMascota (eMascota mascotas[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip, eTrabajo trabajos[], int tamt, eServicio servicios[],int tamser);
void sumaDeImportesPorMascota (eMascota mascotas[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip, eTrabajo trabajos[], int tamtra, eServicio servicios[],int tamser);
void mascotasPorServicio (eMascota mascotas[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip, eTrabajo trabajos[], int tamtra, eServicio servicios[],int tamser);
void serviciosPorFecha (eMascota mascotas[], int tam, eColor colores[],int tamcol, eTipo tipo[], int tamtip, eTrabajo trabajos[], int tamtra, eServicio servicios[],int tamser);
void listarPromedioVacunados(eMascota mascotas[], int tam);


#endif /* INFORMES_H_ */
