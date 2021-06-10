#ifndef SISTEMA_H
#define SISTEMA_H

class Sistema : public ISistema
{
private:
	
public:
	Sistema();
	
	void AltaUsuario(int ci, std::string nombre, std::string email, std::string contrasenia, std::string url);
	void AltaUsuario(std::string instituto, std::string nombre, std::string email, std::string contrasenia, std::string url);
	void ListarAsignaturas();
	void ListarClasesVivo(std::string email),
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
