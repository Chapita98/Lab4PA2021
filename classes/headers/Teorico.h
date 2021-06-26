#ifndef TEORICO_H
#define TEORICO_H
#include "./Clase.h"
#include "./../../datatypes/headers/DtFecha.h"

class Clase;

class Teorico : public Clase
{
private:
    int asistentes;

public:
    Teorico();
    Teorico(int _asistentes);
    Teorico(int _asistentes, int _id, std::string _nombre, DtFecha *_fechaCom);

    int getAsistentes();

    void setAsistentes(int _asistentes);
    void print(std::ostream&);

    virtual ~Teorico();
};

#endif /* TEORICO_H */
