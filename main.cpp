#include "./classes/headers/Fabrica.h"

using namespace std;

int main()
{
	Fabrica f;
	ISistema *s = f.getSistema;
	int opcionUsuario;
	bool bandera = true;
	s->fechaAutomatica();
	while (bandera == true)
	{
		s->imprimirTextoPrincipal();
		std::cin >> opcionUsuario;
		std::cout << "\e[0m";
		std::cin.clear();
		try
		{
			switch (opcionUsuario)
			{
			case 5: //CASO SALIDA DE SISTEMA
			{
				bandera = false;
				break;
			}
			case 1: //Administrador
			{
				s->menuCaso1();
				break;
			}
			case 2: //Docente
			{
				s->menuCaso2();
				break;
			}
			case 3: //Estudiante
			{
				s->menuCaso3();
				break;
			}
			case 4: //Cargar datos de prueba
			{
				s->menuCaso4();
				break;
			}
			default:
				throw std::invalid_argument("\n\e[0;31mLa opcion ingresada no es correcta.\n\e[0m");
			}
		}
		catch (std::invalid_argument &e)
		{
			std::cerr << e.what() << endl;
		}
	}
	return 0;
}
