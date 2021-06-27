#ifndef SISTEMA_H
#define SISTEMA_H
#include "./ISistema.h"

class ISistema;

class Sistema : public ISistema
{
private:
	IDictionary * usuarios;
	IDictionary * asignaturas;
	DtFecha *fecha;
	Usuario *actual;
public:
	Sistema();

	void menuCaso1();
	void menuCaso2();
	void menuCaso3();
	void menuCaso4();
	void imprimirTextoPrincipal();
	void imprimirMenuAdministrador();
	void imprimirMenuDocente();
	void imprimirMenuEstudiante();
	void InicioSesion(std::string email, std::string contrasenia, int i);

	void AltaDeUsuario();
	void AltaDeAsignatura();
	void AsignacionDeDocentesAUnaAsignatura();
    void InicioDeClase();
    void InscripcionALasAsignaturas();
    void ReproduccionEnDiferido();
    void FinalizacionDeClase();
    void EliminacionDeAsignatura();
    void TiempoDeDictadoDeClases();
    void AsistenciaAClaseEnVivo();
    void FinalizarAsistencia();
    void TiempoDeAsistenciaAClase();
    void ListadoDeClases();
    void EnvioDeMensaje();
    void ModificarFechaSistema();
    void ConsultarFechaSistema();

	void AltaEstudiante(int ci, std::string nombre, std::string email, std::string contrasenia, std::string url);
	void AltaDocente(std::string instituto, std::string nombre, std::string email, std::string contrasenia, std::string url);
	void ListarAsignaturas();
	ICollection *ListarAsignaturasNoInscriptas();
	ICollection *ListarAsignaturasInscriptas();
	ICollection *ListarAsignaturasAsignadas(Docente *d);
	ICollection *ListarEstudiantesInscriptos(int id);
	ICollection *ListarDocentesNoAsignados(int id);
	ICollection *ListarDocentesAsignados(int id);
	ICollection *ListarClasesPorAsig(Asignatura *a);
	int PromedioAsistenciaClase(int idC, int idA);
	Docente *SeleccionDocente(std::string email);
	Asignatura *SeleccionAsignatura(int id);
	Clase *SeleccionClase(int idC, int idA);
	Docente *DocenteDeClase(int idC, int idA);
	void ListarMensajes(Clase *c);
	Mensaje *SeleccionMensaje(Clase *c, int id);
	ICollection *ListarAsistentes(int idC);

	virtual ~Sistema();
};

#endif /* SISTEMA_H */
