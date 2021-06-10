#ifndef DEFINICIONES_H
#define DEFINICIONES_H
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <string>
#include <string.h>

#include "./../classes/headers/Usuario.h"
#include "./../classes/headers/Asignatura.h"
#include "./../classes/headers/Asignacion.h"
#include "./../classes/headers/Tipo.h"
#include "./../classes/headers/AsistenciaDiferida.h"
#include "./../classes/headers/AsistenciaOnline.h"
#include "./../classes/headers/Clase.h"
#include "./../classes/headers/Docente.h"
#include "./../classes/headers/Estudiante.h"
#include "./../classes/headers/Mensaje.h"
#include "./../classes/headers/Monitoreo.h"
#include "./../classes/headers/Practico.h"
#include "./../classes/headers/Sistema.h"
#include "./../classes/headers/Teorico.h"

#include "./../datatypes/headers/DtClase.h"
#include "./../datatypes/headers/DtFecha.h"
#include "./../datatypes/headers/DtMonitoreo.h"
#include "./../datatypes/headers/DtPractico.h"
#include "./../datatypes/headers/DtTeorico.h"

void menuCaso1();
void menuCaso2();
void menuCaso3();
void menuCaso4();
void imprimirTextoPrincipal();
void obtenerFechaDelSitema(int &dia, int &mes, int &anio);
void fechaAutomatica();
void mostrarFecha(DtFecha fecha);

extern const int MAX_PUERTOS;
extern const int MAX_BARCOS;
extern int cantidadPuertos;
extern DtPuerto *dtPuertos;
extern Puerto *puertos[];
extern Barco *barcos[];
extern int cantidadBarcos;
extern int dia, mes, anio;

#endif