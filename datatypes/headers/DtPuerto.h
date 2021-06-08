#ifndef DTPUERTO_H
#define DTPUERTO_H
#include <string>
#include "./DtFecha.h"

class DtPuerto
{
private:
    std::string id;
    std::string nombre;
    DtFecha fechaCreacion;
    int cantArribos;
    bool isValid();

public:
    DtPuerto();
    DtPuerto(std::string id, std::string nombre, DtFecha fechaCreacion, int cantArribos);

    std::string getId();
    std::string getNombre();
    DtFecha getFechaCreacion();
    int getCantArribos();

    virtual ~DtPuerto();
};

#endif /* DTPUERTO_H */
