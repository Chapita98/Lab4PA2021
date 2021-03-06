#ifndef MENSAJE_H
#define MENSAJE_H

#include "./../../datatypes/headers/DtFecha.h"
#include "./../../ICollection/interfaces/ICollectible.h"

class Mensaje : public ICollectible
{
private:
	int id;
	DtFecha *fechaEnvio;
	std::string contenido;
	Mensaje *respuesta;

public:
	Mensaje();
	Mensaje(int _id, DtFecha *_fechaEnvio, std::string _contenido);

	int getId();
	DtFecha *getFechaEnvio();
	std::string getContenido();
	Mensaje *getRespuesta();
	bool esRespuesta();


	void setId(int _id);
	void setFechaEnvio(DtFecha *_fechaEnvio);
	void setContenido(std::string _contenido);
	void setRespuesta(Mensaje *m);

	virtual ~Mensaje();
};

#endif /* MENSAJE_H */
