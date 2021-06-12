#ifndef SISTEMA_H
#define SISTEMA_H
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <string>
#include <string.h>

#include "./../../ICollection/interfaces/IDictionary.h"
#include "./../../ICollection/interfaces/IKey.h"
#include "./../../ICollection/Integer.h"
#include "./../../ICollection/String.h"
#include "Usuario.h"
#include "Asignatura.h"
#include "Asignacion.h"
#include "Tipo.h"
#include "AsistenciaDiferida.h"
#include "AsistenciaOnline.h"
#include "Clase.h"
#include "Docente.h"
#include "Estudiante.h"
#include "Mensaje.h"
#include "Monitoreo.h"
#include "Practico.h"
#include "Sistema.h"
#include "Teorico.h"

#include "./../../datatypes/headers/DtClase.h"
#include "./../../datatypes/headers/DtFecha.h"
#include "./../../datatypes/headers/DtMonitoreo.h"
#include "./../../datatypes/headers/DtPractico.h"
#include "./../../datatypes/headers/DtTeorico.h"
#include "./../../ICollection/collections/List.h"


#include "ISistema.h"

class Sistema : public ISistema
{
private:
	IDictionary * usuarios;
	IDictionary * asignaturas;
	int dia, mes, anio;
public:
	Sistema();
    void obtenerFechaDelSistema(int &dia, int &mes, int &anio);
	void imprimirTextoPrincipal();
	void menu1();
	void menu2();
	void menu3();
	void menu4();

	void fechaAutomatica();
	void mostrarFecha(DtFecha fecha);


	void AltaDeUsuario();
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
	void CreaClase(std::string nombre, DtFecha fechaComienzo, List estudiantes);//maybe
	void CrearMensaje(std::string texto, int idRespuesta);
	void CrearMensaje(std::string texto);
	void MostrarDatos();
	void MostrarTiempoAsistenciaClase();
	void ObtenerClase();
	void AgregarAsistenciaDif(DtFecha fechaCom, DtFecha fechaFin);

	virtual ~Sistema();
};

#endif /* SISTEMA_H */
