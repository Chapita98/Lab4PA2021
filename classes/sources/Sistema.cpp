#include "./../headers/Sistema.h"
Sistema::Sistema() {}

void Sistema::obtenerFechaDelSistema(int &dia, int &mes, int &anio)
{
    std::time_t t = std::time(0);
    std::tm *now = std::localtime(&t);
    anio = (now->tm_year + 1900);
    mes = (now->tm_mon + 1);
    dia = now->tm_mday;
}

void Sistema::mostrarFecha(DtFecha fecha)
{
    std::cout << "\nDia: " << fecha.getDia() << std::endl;
    std::cout << "\nAño: " << fecha.getAnio() << std::endl;
    std::cout << "\nMes: " << fecha.getMes() << std::endl;
}

void Sistema::fechaAutomatica()
{
    obtenerFechaDelSistema(dia, mes, anio);
}

void Sistema::imprimirTextoPrincipal()
{
    std::cout << "\e[0;92mBienvenido -" << dia << "/" << mes << "/" << anio << "- Elija una opción\e[0m:";
    std::cout << "\n\e[0;92m1)\e[0m Administrador.\n";
    std::cout << "\e[0;92m2)\e[0m Docente.\n";
    std::cout << "\e[0;92m3)\e[0m Estudiante.\n";
    std::cout << "\e[0;92m4)\e[0m Cargar datos de prueba.\n";
    std::cout << "Pulse \e[0;92m5\e[0m para salir.\n\nOpcion: \e[0;92m";
}

Sistema::~Sistema() {}
