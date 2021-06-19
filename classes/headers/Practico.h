#ifndef PRACTICO_H
#define PRACTICO_H
#include "./Clase.h"
class Clase;

class Practico : public Clase
{
private:

public:
	Practico();
	Practico(int _id, std::string _nombre, DtFecha _fechaCom);

	virtual ~Practico();
};

#endif /* PRACTICO_H */
