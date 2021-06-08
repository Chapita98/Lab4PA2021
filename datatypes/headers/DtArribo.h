#ifndef DTARRIBO_H
#define DTARRIBO_H
#include "./DtFecha.h"
#include "./DtBarco.h"
class DtBarco;

class DtArribo
{
private:
    DtBarco *barcoQueArriba;
    DtFecha fechaDeArribo;
    float carga;

public:
    // Constructor
    DtArribo();
    DtArribo(DtBarco *barcoQueArriba, DtFecha fechaDeArribo, float carga);
    // Getters
    DtBarco* getBarcoQueArriba();
    DtFecha getFechaDeArribo();
    float getCarga();

    virtual ~DtArribo();
};

#endif /* DTARRIBO_H */
