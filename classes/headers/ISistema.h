#ifndef ISISTEMA_H
#define ISISTEMA_H
#include <string>
#include "./../../datatypes/headers/DtFecha.h"
#include "./../../ICollection/collections/List.h"

class ISistema
{
private:

public:


	/*virtual void imprimirTextoPrincipal() = 0;
	virtual void menu1() = 0;
	virtual void menu2() = 0;
	virtual void menu3() = 0;
	virtual void menu4() = 0;

	virtual void AltaUsuario(int ci, std::string nombre, std::string email, std::string contrasenia, std::string url) = 0;
	virtual void AltaUsuario(std::string instituto, std::string nombre, std::string email, std::string contrasenia, std::string url) = 0;
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
	virtual void CreaClase(std::string nombre, DtFecha fechaComienzo, List estudiantes) = 0;//maybe
	virtual void CrearMensaje(std::string texto, int idRespuesta) = 0;
	virtual void CrearMensaje(std::string texto) = 0;
	virtual void MostrarDatos() = 0;
	virtual void MostrarTiempoAsistenciaClase() = 0;
	virtual void ObtenerClase() = 0;
	virtual void AgregarAsistenciaDif(DtFecha fechaCom, DtFecha fechaFin) = 0;*/

	virtual ~ISistema();
};

#endif /* ISISTEMA_H */
