#ifndef BARCOPESQUERO_H
#define BARCOPESQUERO_H
#include "./Barco.h"
class Barco;

class BarcoPesquero : public Barco
{
private:
    int Capacidad;
    int Carga;

public:
    BarcoPesquero();
    BarcoPesquero(int capacidad, int carga);
    BarcoPesquero(int capacidad, int carga, std::string nombre, std::string id);

    int getCapacidad();
    int getCarga();

    void setCapacidad(int capacidad);
    void setCarga(int carga);

    virtual ~BarcoPesquero();
};

#endif /* BARCOPESQUERO_H */
