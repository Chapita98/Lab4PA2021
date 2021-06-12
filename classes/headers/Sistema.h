#ifndef SISTEMA_H
#define SISTEMA_H
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <string>
#include <string.h>

#include "./../../ICollection/interfaces/IDictionary.h"
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


#include "ISistema.h"

class Sistema : public ISistema
{
private:
	IDictionary * usuarios;
	IDictionary * asignaturas;
	int dia, mes, anio;
public:
	Sistema();
	
	void menucaso1();
	void menucaso2();
	void menuCaso3();
	void menuCaso4();
	void imprimirTextoPrincipal();
	void imprimirMenuAdministrador();
	void imprimirMenuDocente();
	void imprimirMenuEstudiante();
	void obtenerFechaDelSitema(int &dia, int &mes, int &anio);
	void fechaAutomatica();
	void mostrarFecha(DtFecha fecha);
	
	void AltaUsuario(int ci, std::string nombre, std::string email, std::string contrasenia, std::string url);
	void AltaUsuario(std::string instituto, std::string nombre, std::string email, std::string contrasenia, std::string url);
	void ListarAsignaturas();
	void ListarClasesVivo(std::string email);
	void ListarDocentesNoAsignados();
	void ListarEstudiantesInscriptos();
	void ListarMensajes(std::string idClase);
	void SeleccionAsignatura(int id);
	void SeleccionDocente(std::string email);
	void SeleccionClase(int id);
	void SeleccionEstudiante(int ci);
	void CreaClase(std::string nombre, DtFecha fechaComienzo);
	void CreaClase(std::string nombre, DtFecha fechaComienzo, iCollection listaEstudiantes);//maybe
	void CrearMensaje(std::string texto, int idRespuesta);
	void CrearMensaje(std::string texto);
	void MostrarDatos();
	void MostrarTiempoAsistenciaClase();
	void ObtenerClase();
	void AgregarAsistenciaDif(DtFecha fechaCom, DtFecha fechaFin);	
	
	virtual ~Sistema();
};

#endif /* SISTEMA_H */
