#include <iostream>
#include <stdexcept>

#include "./metodosMain/definiciones.h"

using namespace std;

int main(int argc, char **argv)
{
	int opcionUsuario;
	bool bandera = true;
	fechaAutomatica();
	while (bandera == true)
	{
		imprimirTextoPrincipal();
		std::cin >> opcionUsuario;
		std::cout << "\e[0m";
		std::cin.clear();
		try
		{
			switch (opcionUsuario)
			{
			case 0: //CASO SALIDA DE SISTEMA
			{
				bandera = false;
				break;
			}
			case 1: //AGREGAR PUERTO
			{
				menuCaso1();
				break;
			}
			case 2: //AGREGAR BARCO
			{
				menuCaso2();
				break;
			}
			case 3: //LISTAR PUERTOS
			{
				menuCaso3();
				break;
			}
			case 4: //AGREGAR ARRIBO
			{
				menuCaso4();
				break;
			}
			case 5: //OBTENER INFORMACION DE ARRIBOS EN PUERTO
			{
				menuCaso5();
				break;
			}
			case 6: //ELIMINAR ARRIBOS
			{
				menuCaso6();
				break;
			}
			case 7: //LISTAR BARCOS
			{
				menuCaso7();
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