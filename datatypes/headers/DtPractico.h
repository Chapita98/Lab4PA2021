#ifndef DTPRACTICO_H
#define DTPRACTICO_H
#include "DtClase.h"
#include <iostream>

class DtPractico : public DtClase
{
private:

public:
	DtPractico();
	DtPractico(int _id, std::string _video, std::string _nombre, DtFecha _fechaCom, DtFecha _fechaFin);

	virtual ~DtPractico();
    	//void print(std::ostream&);
};
#endif /* DTPRACTICO_H */
