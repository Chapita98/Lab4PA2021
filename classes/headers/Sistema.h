#ifndef SISTEMA_H
#define SISTEMA_H
#include "./ISistema.h"

class ISistema;

class Sistema : public ISistema
{
private:
	IDictionary * usuarios;
	IDictionary * asignaturas;
	int dia, mes, anio;
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
	void obtenerFechaDelSistema(int &dia, int &mes, int &anio);
	void fechaAutomatica();
	void mostrarFecha(DtFecha fecha);

	void AltaDeUsuario();
	void AltaDeAsignatura();
	void AltaEstudiante(int ci, std::string nombre, std::string email, std::string contrasenia, std::string url);
	void AltaDocente(std::string instituto, std::string nombre, std::string email, std::string contrasenia, std::string url);

	void AsignacionDeDocentesAUnaAsignatura();
	void ListarAsignaturas();
	Asignatura *SeleccionAsignatura(int id);
	ICollection *ListarDocentesNoAsignados(IKey *id);
	Docente *SeleccionDocente(std::string email);
	/*void EliminacionDeAsignatura();
	void TiempoDeDictadoDeClases();
	void ConfiguracionRelojInterno();
	void InicioDeClase();
	void FinalizacionDeClase();
	void TiempoDeAsistenciaAClase();
	void ListadoDeClases();
	void EnvioDeMensaje();
	void InscripcionALasAsignaturas();
	void AsistenciaAClaseEnVivo();
	void ReproduccionEnDiferido();
	void AltaAsignatura();

	void ListarClasesVivo(std::string email);
	void ListarEstudiantesInscriptos();
	void ListarMensajes(std::string idClase);


	void SeleccionClase(int id);
	void SeleccionEstudiante(int ci);
	void CreaClase(std::string nombre, DtFecha fechaComienzo);
	void CreaClase(std::string nombre, DtFecha fechaComienzo, List estudiantes);//maybe
	void CrearMensaje(std::string texto, int idRespuesta);
	void CrearMensaje(std::string texto);
	void MostrarDatos();
	void MostrarTiempoAsistenciaClase();
	void ObtenerClase();
	void AgregarAsistenciaDif(DtFecha fechaCom, DtFecha fechaFin);*/

	virtual ~Sistema();
};

#endif /* SISTEMA_H */
