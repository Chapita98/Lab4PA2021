#include "./definiciones.h"

void menuCaso1()
{
    std::string id;
    std::string nombre;
    int d, m, a;
    bool flag = true;

    while (flag == true)
    {
        try
        {
            if (cantidadPuertos >= MAX_PUERTOS)
                throw std::invalid_argument("\e[0;31mLa cantidad maxima de Puertos a sido alcanzada.\e[0m");

            std::cout << "\nEscriba el id del Puerto: ";
            std::cin >> id;

            if (cantidadPuertos > 0)
            {
                if (obtenerIdPuerto(id) != NULL)
                {
                    throw std::invalid_argument("\e[0;31mYa existe un Puerto con esa id.\e[0m");
                }
            }

            std::cout << "\nEscriba el nombre del Puerto: ";
            std::cin >> nombre;

            std::cout << "\nIngrese Fecha de Creacion: ";
            std::cout << "\nDia: ";
            std::cin >> d;

            if(d>31 || d<1)
                throw std::invalid_argument("\e[0;31mEl dia ingresado no es correcto\e[0m");

            std::cout << "\nMes: ";
            std::cin >> m;
            if(m>12 || m<1)
                throw std::invalid_argument("\e[0;31mEl mes ingresado no es correcto\e[0m");

            std::cout << "\nAño: ";
            std::cin >> a;
            if(a<1900)
                throw std::invalid_argument("\e[0;31mEl año ingresado no es correcto\e[0m");
            agregarPuerto(id, nombre, DtFecha(d, m, a));
            flag = false;
        }
        catch (std::invalid_argument &e)
        {
            std::cout << "\nError: " << e.what() << std::endl;
            std::cout << "\n\e[0;33mVolviendo al menu principal\e[0m\n\n";
            flag = false;
            break;
        }
    }
}

void menuCaso2()
{
    std::string id;
    std::string nombre;
    int tipo, capacidad, carga, cantpas, tam;
    TipoTamanio tamanio;
    bool flag = true;
    while (flag == true)
    {
        try
        {
            if (cantidadBarcos >= MAX_BARCOS)
                throw std::invalid_argument("e[0;31mLa cantidad maxima de Barcos a sido alcanzada.\e[0m");

            std::cout << "\nEscriba el id del Barco: ";
            std::cin >> id;

            if (obtenerIdBarco(id) != NULL)
                throw std::invalid_argument("\e[0;31mYa existe un Barco con esa id\e[0m");

            std::cout << "\nEscriba el nombre del Barco: ";
            std::cin >> nombre;

            std::cout << "\nElija una opcion:\n\e[0;92m1)\e[0mBarco de Pasajeros\n\e[0;92m2)\e[0mBarco Pesquero\n";
            std::cin >> tipo;

            switch (tipo)
            {
            case 1:
            {
                std::cout << "\nIngrese cantidad de pasajeros: ";
                std::cin >> cantpas;

                std::cout << "\nElija un tamaño: \n\e[0;92m1)\e[0m Bote\n\e[0;92m2)\e[0m Crucero\n\e[0;92m3)\e[0m Galeon\n\e[0;92m4)\e[0m Transatlantico\n";
                std::cin >> tam;
                switch (tam)
                {
                case BOTE:
                {
                    tamanio = TipoTamanio::BOTE;
                    break;
                }
                case CRUCERO:
                {
                    tamanio = TipoTamanio::CRUCERO;
                    break;
                }
                case GALEON:
                {
                    tamanio = TipoTamanio::GALEON;
                    break;
                }
                case TRANSATLANTICO:
                {
                    tamanio = TipoTamanio::TRANSATLANTICO;
                    break;
                }
                default:
                {
                    throw std::invalid_argument("\e[0;31mTamanio invalido\e[0m");
                    break;
                }
                }
                DtBarcoPasajeros *b = new DtBarcoPasajeros(cantpas, tamanio, id, nombre);
                agregarBarco(b);
                break;
            }
            case 2:
            {
                std::cout << "\nIngrese capacidad: ";
                std::cin >> capacidad;
                std::cout << "\nIngrese carga: ";
                std::cin >> carga;

                if (carga > capacidad)
                    throw std::invalid_argument("\e[0;31mLa carga no puede ser mayor a su capacidad.\e[0m");

                if (carga < 0)
                    throw std::invalid_argument("\e[0;31mLa carga no puede ser negativa.\e[0m");

                DtBarcoPesquero *b = new DtBarcoPesquero(capacidad, carga, id, nombre);
                agregarBarco(b);
                break;
            }
            default:
                throw std::invalid_argument("\e[0;31mLa opcion ingresada no es correcta.\e[0m");
                break;
            }
            flag = false;
        }
        catch (std::invalid_argument &e)
        {
            std::cout << "\nError: " << e.what() << std::endl;
            std::cout << "\n\e[0;33mVolviendo al menu principal\e[0m\n\n";
            flag = false;
            break;
        }
    }
}

void menuCaso3()
{
    if (cantidadPuertos == 0)
    {
        std::cout << "\nNo hay puertos registrados\n";
    }
    else
    {
        listarPuertos();
    }
}

void menuCaso4()
{
    std::string idPuerto;
    std::string idBarco;
    float carga;
    bool flag = true;

    while (flag == true)
    {
        try
        {
            std::cout << "\nEscriba el id de Puerto: ";
            std::cin >> idPuerto;
            if (obtenerIdPuerto(idPuerto) == NULL)
                throw std::invalid_argument("\e[0;31mNo existe un Puerto con esa id\e[0m");

            std::cout << "\nEscriba el id de Barco: ";
            std::cin >> idBarco;
            if (obtenerIdBarco(idBarco) == NULL)
                throw std::invalid_argument("\e[0;31mNo existe un Barco con esa id\e[0m");

            std::cout << "\nEscriba la carga: ";
            std::cin >> carga;
            agregarArribo(idPuerto, idBarco, carga);

            std::cout << "\nArribo añadido con exito\n";
            flag = false;
        }
        catch (std::invalid_argument &e)
        {
            std::cout << "\nError: " << e.what() << std::endl;
            std::cout << "\n\e[0;33mVolviendo al menu principal\e[0m\n\n";
            flag = false;
            break;
        }
    }
}

void obtenerFechaDelSistema(int &dia, int &mes, int &anio)
{
    std::time_t t = std::time(0);
    std::tm *now = std::localtime(&t);
    anio = (now->tm_year + 1900);
    mes = (now->tm_mon + 1);
    dia = now->tm_mday;
}

void mostrarFecha(DtFecha fecha)
{
    std::cout << "\nDia: " << fecha.getDia() << std::endl;
    std::cout << "\nAño: " << fecha.getAnio() << std::endl;
    std::cout << "\nMes: " << fecha.getMes() << std::endl;
}

void fechaAutomatica()
{
    obtenerFechaDelSistema(dia, mes, anio);
}

void imprimirTextoPrincipal()
{
    std::cout << "\e[0;92mBienvenido -" << dia << "/" << mes << "/" << anio << "- Elija una opción\e[0m:";
    std::cout << "\n\e[0;92m1)\e[0m Administrador.\n";
    std::cout << "\e[0;92m2)\e[0m Docente.\n";
    std::cout << "\e[0;92m3)\e[0m Estudiante.\n";
    std::cout << "\e[0;92m4)\e[0m Cargar datos de prueba.\n";
    std::cout << "Pulse \e[0;92m5\e[0m para salir.\n\nOpcion: \e[0;92m";
}

/**
* Se dejan como ejemplo
*/
/*void menuCaso5()
{
    std::string id;
    bool flag = true;
    while (flag == true)
    {
        try
        {
            std::cout << "\nEscriba el id del Puerto: ";
            std::cin >> id;

            if (obtenerIdPuerto(id) == NULL)
                throw std::invalid_argument("\e[0;31mNo existe un Puerto con esa id\e[0m");

            if(obtenerIdPuerto(id)->getCantArribos()==0)
                throw std::invalid_argument("\e[0;31mNo existen arribos en ese puerto\e[0m");

            DtArribo *dtarribos= obtenerInfoArribosEnPuerto(id);
            Puerto *p = obtenerIdPuerto(id);
            mostrarArribos(dtarribos, p->getCantArribos());
            flag = false;
        }
        catch (std::invalid_argument &e)
        {
            std::cout << "\nError: " << e.what() << std::endl;
            std::cout << "\nVolviendo al menu principal\n\n";
            flag = false;
            break;
        }
    }
}

void menuCaso6()
{
    std::string id;
    int d, m, a;
    bool flag = true;
    while (flag == true)
    {
        try
        {
            std::cout << "\nEscriba el id del Puerto: ";
            std::cin >> id;

            if (obtenerIdPuerto(id) == NULL)
                throw std::invalid_argument("\e[0;31mNo existe un Puerto con esa id\e[0m");

            std::cout << "\nIngrese dia: ";
            std::cin >> d;

            if(d>31 || d<1)
                throw std::invalid_argument("\e[0;31mEl dia ingresado no es correcto\e[0m");

            std::cout << "\nIngrese mes: ";
            std::cin >> m;
            if(m>12 || m<1)
                throw std::invalid_argument("\e[0;31mEl mes ingresado no es correcto\e[0m");

            std::cout << "\nIngrese año: ";
            std::cin >> a;
            if(a<1900)
                throw std::invalid_argument("\e[0;31mEl año ingresado no es correcto\e[0m");

            eliminarArribo(id, DtFecha(d, m, a));
            std::cout << "\n\e[1;92mArribo Eliminado\e[0m\n\n";
            flag = false;
        }
        catch (std::invalid_argument &e)
        {
            std::cout << "\nError: " << e.what() << std::endl;
            std::cout << "\n\e[0;33mVolviendo al menu principal\e[0m\n\n";
            flag = false;
            break;
        }
    }
}

void menuCaso7()
{
    if (barcos == 0)
    {
        std::cout << "\nNo hay Barcos registrados\n\n";
    }
    else
    {
        DtBarco **dtbarcos = listarBarcos();
        std::cout << std::endl;
        for (int i = 0; i < cantidadBarcos; i++)
        {
            if (dynamic_cast<DtBarcoPesquero *>(dtbarcos[i]))
                std::cout << "\e[0;36mBarco pesquero:\e[0m\n";
            else
                std::cout << "\e[0;36mBarco de pasajeros:\e[0m\n";
            std::cout << dtbarcos[i] << std::endl;

        }
    }
}*/