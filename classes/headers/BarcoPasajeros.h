#ifndef BARCOPASAJEROS_H
#define BARCOPASAJEROS_H
#include "./Barco.h"
#include "./TipoTamanio.h"
class Barco;

class BarcoPasajeros : public Barco
{
private:
	int cantPasajeros;
	TipoTamanio tamanio;

public:
	BarcoPasajeros();
	BarcoPasajeros(int _cantPasajeros, TipoTamanio _tamanio);
	BarcoPasajeros(int _cantpasajeros, TipoTamanio _tamanio, std::string _id, std::string _nombre);

	int getCantPasajeros();
	TipoTamanio getTamanio();

	void setCantPasajeros(int _cantPasajeros);
	void setTamanio(TipoTamanio _tamanio);

	virtual ~BarcoPasajeros();
};

#endif /* BARCOPASAJEROS_H */
