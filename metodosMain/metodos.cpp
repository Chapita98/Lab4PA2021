#include "./definiciones.h"

const int MAX_PUERTOS = 30;
const int MAX_BARCOS = 30;
int cantidadPuertos = 0;
DtPuerto *dtPuertos = new DtPuerto();
Puerto *puertos[MAX_PUERTOS];
Barco *barcos[MAX_BARCOS];
int cantidadBarcos = 0;
int dia, mes, anio = 0;

void obtenerFechaDelSistema(int &dia, int &mes, int &anio)
{
    std::time_t t = std::time(0);
    std::tm *now = std::localtime(&t);
    anio = (now->tm_year + 1900);
    mes = (now->tm_mon + 1);
    dia = now->tm_mday;
}

void imprimirTextoPrincipal()
{
    colorAlTexto();
    std::cout << "\n\e[0;92m1)\e[0m Agregar Puerto.\n";
    std::cout << "\e[0;92m2)\e[0m Agregar Barco.\n";
    std::cout << "\e[0;92m3)\e[0m Listar Puertos.\n";
    std::cout << "\e[0;92m4)\e[0m Agregar Arribo.\n";
    std::cout << "\e[0;92m5)\e[0m Obtener Informacion de Arribos en Puerto.\n";
    std::cout << "\e[0;92m6)\e[0m Eliminar Arribos.\n";
    std::cout << "\e[0;92m7)\e[0m Listar Barcos.\n";
    std::cout << "Pulse \e[0;92m0\e[0m para salir.\n\nOpcion: \e[0;92m";
}

void colorAlTexto()
{
    std::cout << "\e[0;92mBienvenido -" << dia << "/" << mes << "/" << anio << "- Elija una opción\e[0m:";
}

void fechaAutomatica()
{
    obtenerFechaDelSistema(dia, mes, anio);
}

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

void menuCaso5()
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
}

Puerto *obtenerIdPuerto(std::string paramId)
{
    for (int i = 0; i < cantidadPuertos; i++)
    {
        if (puertos[i]->getId() == paramId)
        {
            return puertos[i];
        }
    }
    return NULL;
}

Barco *obtenerIdBarco(std::string paramId)
{
    for (int i = 0; i < cantidadBarcos; i++)
    {
        if (barcos[i]->getId() == paramId)
        {
            return barcos[i];
        }
    }
    return NULL;
}

void agregarBarco(DtBarco *barco)
{
    if (dynamic_cast<DtBarcoPasajeros *>(barco))
    {
        DtBarcoPasajeros *b = dynamic_cast<DtBarcoPasajeros *>(barco);
        BarcoPasajeros *bp = new BarcoPasajeros(b->getCantPasajeros(), b->getTamanio(), b->getId(), b->getNombre());
        barcos[cantidadBarcos] = bp;
        cantidadBarcos++;
    }
    else
    {
        DtBarcoPesquero *b = dynamic_cast<DtBarcoPesquero *>(barco);
        BarcoPesquero *bp = new BarcoPesquero(b->getCapacidad(), b->getCarga(), b->getId(), b->getNombre());
        barcos[cantidadBarcos] = bp;
        cantidadBarcos++;
    }
    std::cout << "\n\e[0;92mBarco agregado\e[0m\n\n";
}

void agregarPuerto(std::string id, std::string nombre, const DtFecha &fechaCreacion)
{
    Puerto *p = new Puerto(id, nombre, fechaCreacion, 0);
    puertos[cantidadPuertos] = p;
    cantidadPuertos++;
    std::cout << "\n\e[0;92mPuerto agregado\e[0m\n\n";
}

DtBarco **listarBarcos()
{
    DtBarco **dtbarcos = new DtBarco *[cantidadBarcos];
    for (int i = 0; i < cantidadBarcos; i++)
    {
        if (dynamic_cast<BarcoPasajeros *>(barcos[i]))
        {
            BarcoPasajeros *b = dynamic_cast<BarcoPasajeros *>(barcos[i]);
            dtbarcos[i] = new DtBarcoPasajeros(b->getCantPasajeros(), b->getTamanio(), b->getNombre(), b->getId());
        }
        else
        {
            BarcoPesquero *b = dynamic_cast<BarcoPesquero *>(barcos[i]);
            dtbarcos[i] = new DtBarcoPesquero(b->getCapacidad(), b->getCarga(), b->getNombre(), b->getId());
        }
    }
    return dtbarcos;
}

DtPuerto *listarPuertos()
{
    DtPuerto *dtpuertos = new DtPuerto[cantidadPuertos];
    for (int i = 0; i < cantidadPuertos; i++)
    {
        dtpuertos[i] = DtPuerto(puertos[i]->getId(), puertos[i]->getNombre(), puertos[i]->getFechaCreacion(), puertos[i]->getCantArribos());
    }
    mostrarListaPuertos();
    return dtpuertos;
}

void agregarArribo(std::string idPuerto, std::string idBarco, float cargaDespacho)
{
    Barco *b = obtenerIdBarco(idBarco);
    Puerto *p = obtenerIdPuerto(idPuerto);
    if ((dynamic_cast<BarcoPasajeros *>(b)))
    {
        if (cargaDespacho != 0)
        {
            throw std::invalid_argument("\e[0;31mLa cantidad de carga es incorrecta\e[0m");
        }
        else
        {
            for (int i = 0; i < cantidadPuertos; i++)
            {
                if (p->getId() == puertos[i]->getId())
                {
                    Arribo *a = new Arribo(DtFecha(dia, mes, anio), cargaDespacho, *b);
                    puertos[i]->setArribo(a);
                    int cant = puertos[i]->getCantArribos() + 1;
                    puertos[i]->setCantArribos(cant);
                }
            }
        }
    }
    else
    {
        BarcoPesquero *b1 = (dynamic_cast<BarcoPesquero *>(b));
        b1->Barco::operator=(*b);
        for (int i = 0; i < cantidadPuertos; i++)
        {
            if (puertos[i]->getId() == p->getId())
            {
                if (cargaDespacho <= 0)
                {
                    cargaDespacho = b1->getCarga() + (cargaDespacho * (-1));
                }
                else
                {
                    if (cargaDespacho > b1->getCarga())
                    {
                        throw std::invalid_argument("\n\e[0;31mLa cantidad de carga es incorrecta\e[0m");
                    }
                    else
                    {
                        if (cargaDespacho > b1->getCapacidad())
                        {
                            throw std::invalid_argument("\e[0;31mLa cantidad de carga es incorrecta\e[0m");
                        }
                        cargaDespacho = b1->getCarga() - cargaDespacho;
                    }
                }
                Arribo *a = new Arribo(DtFecha(dia, mes, anio), cargaDespacho, *b1);
                puertos[i]->setArribo(a);
                int cant = puertos[i]->getCantArribos() +1;
                puertos[i]->setCantArribos(cant);
            }
        }
    }
}

DtArribo *obtenerInfoArribosEnPuerto(std::string idpuerto)
{
    Puerto *p = obtenerIdPuerto(idpuerto);
    if (p == NULL)
    {
        throw std::invalid_argument("\e[0;31mNo existe un Puerto con esa id.\e[0m");
    }
    else
    {
        Arribo *a;
        int cant = p->getCantArribos();
        DtArribo *dtarribos = new DtArribo[cant];
        for (int i = 0; i < p->getCantArribos(); i++)
        {
            a = p->getArribo(i);
            Barco *b = a->getBarco();
            if (dynamic_cast<BarcoPasajeros *>(b))
            {
                BarcoPasajeros *_b = new BarcoPasajeros;
                _b = dynamic_cast<BarcoPasajeros *>(b);
                DtBarcoPasajeros *bp = new DtBarcoPasajeros(_b->getCantPasajeros(), _b->getTamanio(), _b->getNombre(), _b->getId());
                dtarribos[i] = DtArribo(bp, a->getFechaDeArribo(), a->getCarga());

            }
            else
            {
                BarcoPesquero *_b = new BarcoPesquero;
                _b = dynamic_cast<BarcoPesquero *>(b);
                DtBarcoPesquero *bp = new DtBarcoPesquero(_b->getCapacidad(), _b->getCarga(), _b->getNombre(), _b->getId());
                dtarribos[i] = DtArribo(bp, a->getFechaDeArribo(), a->getCarga());
            }
        }
        return dtarribos;
    }
}

void eliminarArribo(std::string id, const DtFecha &fecha)
{
    Puerto *p = obtenerIdPuerto(id);
    for (int i = 0; i <= p->getCantArribos(); i++)
    {
        if (p->getArribo(i)->getFechaDeArribo() == fecha)
        {
            if (p->getCantArribos() == 1)
            {
                delete p->getArribo(i);
                p->setCantArribos(0);
            }
            else
            {
                int ultimo = p->getCantArribos() - 1;
                delete p->getArribo(i);
                memmove(p->getArribo(i), p->getArribo(ultimo), ultimo);
                p->setCantArribos(ultimo);
            }
        }
    }
}

void mostrarListaPuertos()
{
    for (int i = 0; i < cantidadPuertos; i++)
    {
        std::cout << "\nId: " << puertos[i]->getId() << std::endl;
        std::cout << "Nombre: " << puertos[i]->getNombre() << std::endl;
        std::cout << "Fecha de creacion: " << std::endl;
        mostrarFecha(puertos[i]->getFechaCreacion());
        std::cout << "Cantidad de arribos: " << puertos[i]->getCantArribos() << std::endl
                  << std::endl;
    }
}

void mostrarFecha(DtFecha fecha)
{
    std::cout << "\nDia: " << fecha.getDia() << std::endl;
    std::cout << "\nAño: " << fecha.getAnio() << std::endl;
    std::cout << "\nMes: " << fecha.getMes() << std::endl;
}


void mostrarArribos(DtArribo dtarribos[], int cant)
{
    for (int i = 0; i < cant; i++)
    {
        std::cout << "\nBarco que Arriba:\n " << dtarribos[i].getBarcoQueArriba() << std::endl;
        std::cout << "\nCarga despacho: " << dtarribos[i].getCarga() << std::endl;
        mostrarFecha(dtarribos[i].getFechaDeArribo());
    }
}

