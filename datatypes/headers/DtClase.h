#ifndef DTCLASE_H
#define DTCLASE_H

#include <string>

class DtClase
{
private:
	int id
	std::string video;
	std::string nombre;
	DtFecha fechaCom;
	DtFecha fechaFin;

public:
	DtClase();
	DtClase(int _id, std::string _video, std::string _nombre, DtFecha _fechaCom, DtFecha _fechaFin);

	int getId();
	std::string getVideo();
	std::string getNombre();
	DtFecha getFechaCom();
	DtFecha getFechaFin();

	virtual ~Clase();
	

	/*friend std::ostream& operator<<(std::ostream&, DtBarco*);
 	   virtual void print(std::ostream&)=0;*/
};

#endif /* DTCLASE_H */
  

