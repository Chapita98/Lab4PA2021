#ifndef DTBARCOPASAJEROS_H
#define DTBARCOPASAJEROS_H
#include "./../../classes/headers/TipoTamanio.h"
#include "DtBarco.h"
#include <iostream>

class DtBarcoPasajeros : public DtBarco
{
private:
    int cantPasajeros;
    TipoTamanio tamanio;

public:
    DtBarcoPasajeros();
    DtBarcoPasajeros(int _cantPasajeros, TipoTamanio _tamanio);
    DtBarcoPasajeros(int _cantPasajeros, TipoTamanio _tamanio, std::string _id, std::string _nombre);

    int getCantPasajeros();
    TipoTamanio getTamanio();

    virtual ~DtBarcoPasajeros();
    void print(std::ostream&);
};
#endif /* DTBARCOPASAJEROS_H */
