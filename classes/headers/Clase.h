#ifndef CLASE_H
#define CLASE_H
#include <string>
#include "./../../datatypes/headers/DtFecha.h"
#include "./Mensaje.h"
#include "./../../ICollection/interfaces/ICollectible.h"
//#include "./../../ICollection/interfaces/ICollection.h"
//#include "./../../ICollection/interfaces/IDictionary.h"
#include "./../../ICollection/collections/List.h"
#include "./../../ICollection/collections/OrderedDictionary.h"
#include "./../../ICollection/Integer.h"

class Clase : public ICollectible
{
private:
	int id;
	std::string video;
	std::string nombre;
	DtFecha *fechaCom;
	DtFecha *fechaFin;
	IDictionary * mensajes;

public:
	Clase();
	Clase(int _id, std::string _nombre, DtFecha *_fechaCom);

	int getId();
	std::string getVideo();
	std::string getNombre();
	DtFecha *getFechaCom();
	DtFecha *getFechaFin();
	IDictionary *getMensajes();

	void setId(int _id);
	void setVideo(std::string _video);
	void setNombre(std::string _nombre);
	void setFechaCom(DtFecha *_fechaCom);
	void setFechaFin(DtFecha *_fechaFin);
	void setMensaje(Mensaje *m);

	bool estaEnVivo();
	void finalizar(int url, DtFecha *fecha);
	Mensaje *crearMensaje(std::string contenido, DtFecha *fecha);
	Mensaje *crearRespuesta(std::string contenido, Mensaje *m, DtFecha *fecha);
	void BorrarInstancias();

	virtual ~Clase();
	friend std::ostream& operator<<(std::ostream&, Clase*);
    virtual void print(std::ostream&)=0;
};

#endif /* CLASE_H */
