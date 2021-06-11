#ifndef ISISTEMA_H
#define ISISTEMA_H

class ISistema
{
private:
	
public:
	ISistema();
	
	virtual AltaUsuario(int ci, std::string nombre, std::string email, std::string contrasenia, std::string url);
	virtual AltaUsuario(std::string instituto, std::string nombre, std::string email, std::string contrasenia, std::string url);
	virtual ListarAsignaturas();
	virtual ListarClasesVivo(std::string email),
	virtual ListarDocentesNoAsignados();
	virtual ListarEstudiantesInscriptos();
	virtual ListarMensajes(std::string idClase);
	virtual SeleccionAsignatura(int id);
	virtual SeleccionDocente(std::string email);
	virtual SeleccionClase(int id);
	virtual SeleccionEstudiante(int ci);
	virtual CreaClase(std::string nombre, DtFecha fechaComienzo);
	virtual CreaClase(std::string nombre, DtFecha fechaComienzo, iCollection listaEstudiantes);//maybe
	virtual CrearMensaje(std::string texto, int idRespuesta);
	virtual CrearMensaje(std::string texto);
	virtual MostrarDatos();
	virtual MostrarTiempoAsistenciaClase();
	virtual ObtenerClase();
	virtual AgregarAsistenciaDif(DtFecha fechaCom, DtFecha fechaFin);	
	
	virtual ~ISistema();
};

#endif /* ISISTEMA_H */
