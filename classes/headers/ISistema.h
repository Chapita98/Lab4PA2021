#ifndef ISISTEMA_H
#define ISISTEMA_H
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <string>
#include <string.h>
#include "./../../ICollection/collections/List.h"
#include "./../../ICollection/collections/ListIterator.h"
#include "./../../ICollection/collections/ListNode.h"
#include "./../../ICollection/collections/OrderedDictionary.h"
#include "./../../ICollection/collections/OrderedDictionaryEntry.h"

#include "./../../ICollection/interfaces/ICollectible.h"
#include "./../../ICollection/interfaces/ICollection.h"
#include "./../../ICollection/interfaces/IDictionary.h"
#include "./../../ICollection/interfaces/IIterator.h"
#include "./../../ICollection/interfaces/OrderedKey.h"
#include "./../../ICollection/interfaces/IKey.h"

#include "./../../ICollection/Integer.h"
#include "./../../ICollection/String.h"

#include "./Usuario.h"
#include "./Asignatura.h"
#include "./Asignacion.h"
#include "./Tipo.h"
#include "./AsistenciaDiferida.h"
#include "./AsistenciaOnline.h"
#include "./Clase.h"
#include "./Docente.h"
#include "./Estudiante.h"
#include "./Mensaje.h"
#include "./Monitoreo.h"
#include "./Practico.h"
#include "./Teorico.h"

#include "./../../datatypes/headers/DtClase.h"
#include "./../../datatypes/headers/DtFecha.h"
#include "./../../datatypes/headers/DtMonitoreo.h"
#include "./../../datatypes/headers/DtPractico.h"
#include "./../../datatypes/headers/DtTeorico.h"

class ISistema
{
private:

public:

    virtual void menuCaso1() = 0;
	virtual void menuCaso2() = 0;
	virtual void menuCaso3() = 0;
	virtual void menuCaso4() = 0;
	virtual void imprimirTextoPrincipal() = 0;
	virtual void imprimirMenuAdministrador() = 0;
	virtual void imprimirMenuDocente() = 0;
	virtual void imprimirMenuEstudiante() = 0;
	virtual void obtenerFechaDelSistema(int &dia, int &mes, int &anio) = 0;
	virtual void fechaAutomatica() = 0;
	virtual void mostrarFecha(DtFecha fecha) = 0;

	virtual void AltaDeUsuario() = 0;
	virtual void AltaDeAsignatura() = 0;
	virtual void AltaEstudiante(int ci, std::string nombre, std::string email, std::string contrasenia, std::string url) = 0;
	virtual void AltaDocente(std::string instituto, std::string nombre, std::string email, std::string contrasenia, std::string url) = 0;

	/*virtual void AsignacionDeDocentesAUnaAsignatura() = 0;
	virtual void EliminacionDeAsignatura() = 0;
	virtual void TiempoDeDictadoDeClases() = 0;
	virtual void ConfiguracionRelojInterno() = 0;
	virtual void InicioDeClase() = 0;
	virtual void FinalizacionDeClase() = 0;
	virtual void TiempoDeAsistenciaAClase() = 0;
	virtual void ListadoDeClases() = 0;
	virtual void EnvioDeMensaje() = 0;
	virtual void InscripcionALasAsignaturas() = 0;
	virtual void AsistenciaAClaseEnVivo() = 0;
	virtual void ReproduccionEnDiferido() = 0;


	virtual void ListarAsignaturas() = 0;
	virtual void ListarClasesVivo(std::string email) = 0;
	virtual void ListarDocentesNoAsignados() = 0;
	virtual void ListarEstudiantesInscriptos() = 0;
	virtual void ListarMensajes(std::string idClase) = 0;
	virtual void SeleccionAsignatura(int id) = 0;
	virtual void SeleccionDocente(std::string email) = 0;
	virtual void SeleccionClase(int id) = 0;
	virtual void SeleccionEstudiante(int ci) = 0;
	virtual void CreaClase(std::string nombre, DtFecha fechaComienzo) = 0;
	virtual void CreaClase(std::string nombre, DtFecha fechaComienzo, List estudiantes) = 0;
	virtual void CrearMensaje(std::string texto, int idRespuesta) = 0;
	virtual void CrearMensaje(std::string texto) = 0;
	virtual void MostrarDatos() = 0;
	virtual void MostrarTiempoAsistenciaClase() = 0;
	virtual void ObtenerClase() = 0;
	virtual void AgregarAsistenciaDif(DtFecha fechaCom, DtFecha fechaFin) = 0;*/

	virtual ~ISistema();
};

#endif /* ISISTEMA_H */
