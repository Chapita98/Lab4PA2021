#ifndef ASIGNATURA_H
#define ASIGNATURA_H
#include <string>

class Asignatura
{
private:
    int id;
    std::string nombre;

public:
    Asignatura();
    Asignatura(int _id, std::string _nombre);

    int getId();
    std::string getNombre();

    void setId(int _id);
    void setNombre(std::string _nombre);

    virtual ~Asignatura();
};

#endif /* ASIGNATURA_H */
