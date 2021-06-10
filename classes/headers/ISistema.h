#ifndef ISISTEMA_H
#define ISISTEMA_H

class ISistema
{
private:
	
public:
	ISistema();
	
	void AltaUsuario();
	void AltaAsignatura();
	void AsignacionDocentes();
	void InscripcionAsignaturas();
	void InicioClase();
	void FinalizacionClase();
	void EnvioMensaje();
	void AsistenciaVivo();
	void TiempoDictado();
	void TiempoAsistencia();
	void EliminacionAsignatura();

	void ReproduccionDiferido();
	void ListadoClases();

	virtual ~ISistema();
};

#endif /* ISISTEMA_H */
