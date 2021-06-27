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

#include "./../../datatypes/headers/DtFecha.h"

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
	virtual void InicioSesion(std::string email, std::string contrasenia, int i) = 0;

	virtual void AltaDeUsuario() = 0;
	virtual void AltaDeAsignatura() = 0;
	virtual void AsignacionDeDocentesAUnaAsignatura() = 0;
    virtual void InicioDeClase() = 0;
    virtual void InscripcionALasAsignaturas() = 0;
    virtual void ReproduccionEnDiferido() = 0;
    virtual void FinalizacionDeClase() = 0;
    virtual void EliminacionDeAsignatura() = 0;
    virtual void TiempoDeDictadoDeClases() = 0;
    virtual void AsistenciaAClaseEnVivo() = 0;
    virtual void FinalizarAsistencia() = 0;
    virtual void TiempoDeAsistenciaAClase() = 0;
    virtual void ListadoDeClases() = 0;
    virtual void EnvioDeMensaje() = 0;
    virtual void ModificarFechaSistema() = 0;
    virtual void ConsultarFechaSistema() = 0;

	virtual void AltaEstudiante(int ci, std::string nombre, std::string email, std::string contrasenia, std::string url) = 0;
	virtual void AltaDocente(std::string instituto, std::string nombre, std::string email, std::string contrasenia, std::string url) = 0;
	virtual void ListarAsignaturas() = 0;
	virtual ICollection *ListarAsignaturasNoInscriptas() = 0;
	virtual ICollection *ListarAsignaturasInscriptas() = 0;
	virtual ICollection *ListarAsignaturasAsignadas(Docente *d) = 0;
	virtual ICollection *ListarEstudiantesInscriptos(int id) = 0;
	virtual ICollection *ListarDocentesNoAsignados(int id) = 0;
	virtual ICollection *ListarDocentesAsignados(int id) = 0;
	virtual ICollection *ListarClasesPorAsig(Asignatura *a) = 0;
	virtual int PromedioAsistenciaClase(int idC, int idA) = 0;
	virtual Docente *SeleccionDocente(std::string email) = 0;
	virtual Asignatura *SeleccionAsignatura(int id) = 0;
	virtual Clase *SeleccionClase(int idC, int idA) = 0;
	virtual Docente *DocenteDeClase(int idC, int idA) = 0;
	virtual void ListarMensajes(Clase *c) = 0;
	virtual Mensaje *SeleccionMensaje(Clase *c, int id) = 0;
	virtual ICollection *ListarAsistentes(int idC) = 0;

	virtual ~ISistema();
};

#endif /* ISISTEMA_H */
