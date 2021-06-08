#ifndef BARCO_H
#define BARCO_H

#include <string>

class Barco
{
private:
	std::string id;
	std::string nombre;

public:
	Barco();
	Barco(std::string _id, std::string _nombre);

	std::string getId();
	std::string getNombre();

	void setId(std::string _id);
	void setNombre(std::string _nombre);

	virtual ~Barco();
};

#endif /* BARCO_H */
