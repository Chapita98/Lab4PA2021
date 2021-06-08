#ifndef DTBARCOPESQUERO_H
#define DTBARCOPESQUERO_H
#include <string>
#include <iostream>
#include "DtBarco.h"

class DtBarcoPesquero : public DtBarco
{
private:
    int capacidad;
    int carga;

public:
    DtBarcoPesquero();
    DtBarcoPesquero(int capacidad, int carga);
    DtBarcoPesquero(int capacidad, int carga, std::string id, std::string nombre);

    int getCapacidad();
    int getCarga();

    virtual ~DtBarcoPesquero();
    void print(std::ostream&);
};

#endif /* DTBARCOPESQUERO_H */
