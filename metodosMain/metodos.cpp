#include "./definiciones.h"

const int MAX_PUERTOS = 30;
const int MAX_BARCOS = 30;
int cantidadPuertos = 0;
DtPuerto *dtPuertos = new DtPuerto();
Puerto *puertos[MAX_PUERTOS];
Barco *barcos[MAX_BARCOS];
int cantidadBarcos = 0;
int dia, mes, anio = 0;

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

void mostrarArribos(DtArribo dtarribos[], int cant)
{
    for (int i = 0; i < cant; i++)
    {
        std::cout << "\nBarco que Arriba:\n " << dtarribos[i].getBarcoQueArriba() << std::endl;
        std::cout << "\nCarga despacho: " << dtarribos[i].getCarga() << std::endl;
        mostrarFecha(dtarribos[i].getFechaDeArribo());
    }
}