#ifndef ASIGNATURA_H
#define ASIGNATURA_H
#include <string>
#include "Monitoreo.h"
#include "Practico.h"
#include "Teorico.h"
#include "Tipo.h"
#include "./../../ICollection/interfaces/ICollectible.h"
#include "./../../ICollection/interfaces/ICollection.h"
#include "./../../ICollection/collections/OrderedDictionary.h"
#include "./../../ICollection/Integer.h"
#include "./../../ICollection/collections/List.h"


class Asignatura : public ICollectible
{
private:
    int id;
    std::string nombre;
    IDictionary * clases;

public:
    Asignatura();
    Asignatura(int _id, std::string _nombre);

    int getId();
    std::string getNombre();
    IDictionary *getClases();
    ICollection *getClasesDif();
    ICollection *getClasesVivo();

    void setId(int _id);
    void setNombre(std::string _nombre);
    void setClase(Clase *c);
    Clase * crearClase(std::string nombre, DtFecha fechaComienzo, Tipo tipo);
    void BorrarInstancias();

    virtual ~Asignatura();
};

#endif /* ASIGNATURA_H */
