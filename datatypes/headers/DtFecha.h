#ifndef DTFECHA_H
#define DTFECHA_H
#include <iostream>

class DtFecha : public ICollectible
{
private:
    int dia;
    int mes;
    int anio;
    bool isValid();

public:
    DtFecha();
    DtFecha(int dia, int mes, int anio);
    int getDia();
    int getMes();
    int getAnio();
    bool operator==(const DtFecha &df) const;
    bool operator<(const DtFecha &df) const;
    virtual ~DtFecha();
};

#endif
