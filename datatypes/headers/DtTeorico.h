#ifndef DTTEORICO_H
#define DTTEORICO_H
#include <string>
#include <iostream>
#include "DtClase.h"

class DtTeorico : public DtClase
{
private:
    int asistentes;

public:
    DtTeorico();
    DtTeorico(int _asistentes);
    DtTeorico(int _asistentes, int _id, std::string _video, std::string _nombre, DtFecha _fechaCom, DtFecha _fechaFin);

    int getAsistentes();

    virtual ~DtTeorico();
    //void print(std::ostream&);
};

#endif /* DTTEORICO_H */
