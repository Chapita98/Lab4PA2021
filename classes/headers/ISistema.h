#ifndef ISISTEMA_H
#define ISISTEMA_H

class ISistema
{
private:
	
public:
	ISistema();
	
	
	virtual void imprimirTextoPrincipal();
	virtual void menu1();
	virtual void menu2();
	virtual void menu3();
	virtual void menu4();
		
	virtual void AltaUsuario(int ci, std::string nombre, std::string email, std::string contrasenia, std::string url);
	virtual void AltaUsuario(std::string instituto, std::string nombre, std::string email, std::string contrasenia, std::string url);
	virtual void ListarAsignaturas();
	virtual void ListarClasesVivo(std::string email),
	virtual void ListarDocentesNoAsignados();
	virtual void ListarEstudiantesInscriptos();
	virtual void ListarMensajes(std::string idClase);
	virtual void SeleccionAsignatura(int id);
	virtual void SeleccionDocente(std::string email);
	virtual void SeleccionClase(int id);
	virtual void SeleccionEstudiante(int ci);
	virtual void CreaClase(std::string nombre, DtFecha fechaComienzo);
	virtual void CreaClase(std::string nombre, DtFecha fechaComienzo, iCollection listaEstudiantes);//maybe
	virtual void CrearMensaje(std::string texto, int idRespuesta);
	virtual void CrearMensaje(std::string texto);
	virtual void MostrarDatos();
	virtual void MostrarTiempoAsistenciaClase();
	virtual void ObtenerClase();
	virtual void AgregarAsistenciaDif(DtFecha fechaCom, DtFecha fechaFin);	
	
	virtual ~ISistema();
};

#endif /* ISISTEMA_H */
