#include "./../headers/Sistema.h"
Sistema::Sistema() {}

void Sistema::menuCaso1()
{
    int opcionUsuario;
    bool bandera = true;
    while (bandera == true)
    {
        Sistema::imprimirMenuAdministrador();
        std::cin >> opcionUsuario;
        std::cout << "\e[0m";
        std::cin.clear();
        try
        {
            switch (opcionUsuario)
            {
                case 1: //Alta de usuario
                {
                    Sistema::AltaDeUsuario();
                    break;
                }
                case 2: //Alta de asignatura
                {
                    Sistema::AltaDeAsignatura();
                    break;
                }
                case 3: //Asignación de docentes a una asignatura
                {
                    //AsignacionDeDocentesAUnaAsignatura();
                    break;
                }
                case 4: //Eliminación de asignatura
                {
                    //EliminacionDeAsignatura();
                    break;
                }
                case 5: //Tiempo de dictado de clases
                {
                    //TiempoDeDictadoDeClases();
                    break;
                }
                case 6: //Tiempo de dictado de clases
                {
                    //ConfiguracionRelojInterno();
                    break;
                }
                case 7: //CASO SALIDA DE SISTEMA
                {
                    bandera = false;
                    break;
                }
            default:
                throw std::invalid_argument("\n\e[0;31mLa opcion ingresada no es correcta.\n\e[0m");
            }
        }
        catch (std::invalid_argument &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}

void Sistema::menuCaso2()
{
    int opcionUsuario;
    bool bandera = true;
    while (bandera == true)
    {
        Sistema::imprimirMenuDocente();
        std::cin >> opcionUsuario;
        std::cout << "\e[0m";
        std::cin.clear();
        try
        {
            switch (opcionUsuario)
            {
                case 1: //Inicio de clase
                {
                    //InicioDeClase();
                    break;
                }
                case 2: //Finalización de clase
                {
                    //FinalizacionDeClase();
                    break;
                }
                case 3: //Tiempo de asistencia a clase
                {
                    //TiempoDeAsistenciaAClase();
                    break;
                }
                case 4: //Listado de Clases
                {
                    //ListadoDeClases();
                    break;
                }
                case 5: //Tiempo de dictado de clases
                {
                    //EnvioDeMensaje();
                    break;
                }
                case 6: //CASO SALIDA DE SISTEMA
                {
                    bandera = false;
                    break;
                }
            default:
                throw std::invalid_argument("\n\e[0;31mLa opcion ingresada no es correcta.\n\e[0m");
            }
        }
        catch (std::invalid_argument &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}

void Sistema::menuCaso3()
{
    int opcionUsuario;
    bool bandera = true;
    while (bandera == true)
    {
        Sistema::imprimirMenuEstudiante();
        std::cin >> opcionUsuario;
        std::cout << "\e[0m";
        std::cin.clear();
        try
        {
            switch (opcionUsuario)
            {
                case 1: //Envío de mensaje
                {
                    //EnvioDeMensaje();
                    break;
                }
                case 2: //Inscripción a las asignaturas
                {
                    //InscripcionALasAsignaturas();
                    break;
                }
                case 3: //Asistencia a clase en vivo
                {
                    //AsistenciaAClaseEnVivo();
                    break;
                }
                case 4: //Reproduccion en diferido
                {
                    //ReproduccionEnDiferido();
                    break;
                }
                case 5: //CASO SALIDA DE SISTEMA
                {
                    bandera = false;
                    break;
                }
            default:
                throw std::invalid_argument("\n\e[0;31mLa opcion ingresada no es correcta.\n\e[0m");
            }
        }
        catch (std::invalid_argument &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}

void Sistema::menuCaso4()
{
    // INGRESO DATOS DE PRUEBA
}


void Sistema::AltaDeUsuario(){
    std::string instituto, nombre, email, contrasenia, url;
    int ci, opcion;

    try
    {   std::cout << "\nIngrese email";
        std::cin >> email;
        std::cout << "\nIngrese nombre";
        std::cin >> nombre;
        std::cout << "\nIngrese contrasenia";
        std::cin >> contrasenia;
        std::cout << "\nIngrese url";
        std::cin >> url;
        std::cout << "\nIngrese Opcion: ";
        std::cout << "\n1-Estudiante: ";
        std::cout << "\n2-Docente: ";
        std::cin >> opcion;
        switch (opcion)
        {
            case 1:
            {
                std::cout << "\nIngrese cedula de identidad: ";
                std::cin >> ci;
                Sistema::AltaEstudiante(ci, nombre, email, contrasenia, url);
                break;
            }
            case 2:
            {
                std::cout << "\nIngrese instituto: ";
                Sistema::AltaDocente(instituto, nombre, email, contrasenia, url);
                break;
            }
            default:
                throw std::invalid_argument("\e[0;31mLa opcion ingresada no es correcta.\e[0m");
                break;
        }
    }
    catch (std::invalid_argument &e)
    {
        std::cout << "\nError: " << e.what() << std::endl;
        std::cout << "\n\e[0;33mVolviendo al menu principal\e[0m\n\n";
    }
}

void Sistema::AltaEstudiante(int ci, std::string nombre, std::string email, std::string contrasenia, std::string url)
{
    Estudiante *e = new Estudiante(ci, email, nombre, url, contrasenia);
    int op;
    std::cout << "\nDesea confirmar? ";
    std::cout << "\n1-Si: ";
    std::cout << "\n2-No: ";
    std::cin >> op;
    switch (op)
        {
            case 1:
            {
                IKey *k = new Integer (ci);
                usuarios->add(k, e);
                std::cout << "\nUsuario Agregado";
                break;
            }
            case 2:
            {
                delete e;
                std::cout << "\nVolviendo al menu principal";
                break;
            }
            default:
                throw std::invalid_argument("\e[0;31mLa opcion ingresada no es correcta.\e[0m");
                break;
        }

}

void Sistema::AltaDocente(std::string instituto, std::string nombre, std::string email, std::string contrasenia, std::string url)
{
    Docente *d = new Docente(instituto, email, nombre, url, contrasenia);
    int op;
    std::cout << "\nDesea confirmar? ";
    std::cout << "\n1-Si: ";
    std::cout << "\n2-No: ";
    std::cin >> op;
    switch (op)
    {
        case 1:
        {
            IKey *k = new String (email);
            usuarios->add(k, d);
            std::cout << "\nUsuario Agregado";
            break;
        }
        case 2:
        {
            delete d;
            std::cout << "\nVolviendo al menu principal";
            break;
        }
        default:
            throw std::invalid_argument("\e[0;31mLa opcion ingresada no es correcta.\e[0m");
            break;
    }
}

void Sistema::AltaDeAsignatura()
{
    /*std::string nombre;

    try
    {   std::cout << "\nIngrese nombre";
        std::cin >> nombre;
        AltaEstudiante(ci, nombre, email, contrasenia, url);
    }
    catch (std::invalid_argument &e)
    {
        std::cout << "\nError: " << e.what() << std::endl;
        std::cout << "\n\e[0;33mVolviendo al menu principal\e[0m\n\n";
    }*/
}
void Sistema::AsignacionDeDocentesAUnaAsignatura()
{
    try
    {
        int id, asig, op;
        std::string email;
        Tipo tipo;
        ListarAsignaturas();
        std::cout << "\nIngrese id";
        std::cin >> id;
        IKey *k = new Integer(id);
        if(this->asignaturas->member(k))
        {
            ICollection *docs = new List;
            docs = ListarDocentesNoAsignados(k);
            IIterator *i = docs->getIterator();
            Docente * d;
            while(i->hasCurrent())
            {
                d = (Docente *) i->getCurrent();
                std::cout << d->getNombre() << "--------" << d->getEmail()<< std::endl;
                i->next();
            }
            std::cout << "\nIngrese email";
            std::cin >> email;
            d = SeleccionDocente(email);
            if(d!=NULL)
            {
                std::cout << "\nElija el tipo de asignacion: \n\e[0;92m1)\e[0m Teorico\n\e[0;92m2)\e[0m Practico\n\e[0;92m3)\e[0m Monitoreo\n";
                std::cin >> asig;
                switch (asig)
                {
                case TEORICO:
                {
                    tipo = Tipo::TEORICO;
                    break;
                }
                case PRACTICO:
                {
                    tipo = Tipo::PRACTICO;
                    break;
                }
                case MONITOREO:
                {
                    tipo = Tipo::MONITOREO;
                    break;
                }
                default:
                {
                    throw std::invalid_argument("\e[0;31mAsignacion invalida\e[0m");
                    break;
                }
                }
                std::cout << "\nDesea confirmar? \n1-Si\n2-No";
                std::cin >> op;
                switch (op)
                {
                case 1:
                {
                    Asignacion *a = d->crearAsignacion(tipo, id);
                    d->setAsignacion(a, k);
                    std::cout << "\nDocente Asignado";
                    break;
                }
                case 2:
                {
                    delete d;
                    delete docs;
                    std::cout << "\nVolviendo al menu principal";
                    break;
                }
                default:
                    throw std::invalid_argument("\e[0;31mLa opcion ingresada no es correcta.\e[0m");
                    break;
                }
            }
            else
            {
                throw std::invalid_argument("\e[0;31mEl usuario ingresado no existe.\e[0m");
            }
        }
        else
        {
            throw std::invalid_argument("\e[0;31mLa asignatura ingresada no existe.\e[0m");
        }
    }
    catch (std::invalid_argument &e)
    {
        std::cout << "\nError: " << e.what() << std::endl;
        std::cout << "\n\e[0;33mVolviendo al menu principal\e[0m\n\n";
    }
}

void Sistema::ListarAsignaturas()
{
    IIterator *i = this->asignaturas->getIterator();
    //ICollection *asig = new List;
    Asignatura * a;
    while(i->hasCurrent())
    {
        a = (Asignatura *) i->getCurrent();
        std::cout << a->getNombre() << "--------" << a->getId()<< std::endl;
        i->next();
    }

}

Asignatura *Sistema::SeleccionAsignatura(int id)
{
    IKey *k = new Integer(id);
    Asignatura * asig = (Asignatura *) this->asignaturas->find(k);
    return asig;
}

Docente *Sistema::SeleccionDocente(std::string email)
{
    IKey *k = new String(email);
    if(this->usuarios->member(k))
    {
        Docente * doc = (Docente *) this->usuarios->find(k);
        return doc;
    }
    else
    {
        return NULL;
    }
}

ICollection *Sistema::ListarDocentesNoAsignados(IKey *id)
{
    IIterator *i = this->usuarios->getIterator();
    Usuario *u;
    ICollection *docs = new List;
    while(i->hasCurrent())
    {
        u = (Usuario *) i->getCurrent();
        if (dynamic_cast<Docente *>(u))
        {
            Docente *d = new Docente;
            d = dynamic_cast<Docente *>(d);
            if(!d->estaAsignado(id))
            {
                docs->add(d);
            }
        }
        i->next();
    }
    return docs;

}

void Sistema::InicioDeClase()
{
    int id, op;
    std::string email, nombre, emEs;
    std::cout << "\nIngrese email"; //depende de si usamos un inicio de sesion ig
    std::cin >> email;
    Docente * doc = SeleccionDocente(email);
    try
    {
        if(doc==NULL)
        {
            throw std::invalid_argument("\n\e[0;31mEl docente ingresado no existe.\n\e[0m");
        }
        ICollection *asig = new List;
        asig = ListarAsignaturasAsignadas(doc);
        IIterator *i = asig->getIterator();
        Asignatura *as;
        while(i->hasCurrent())
        {
            as = (Asignatura *) i->getCurrent();
            std::cout << as->getNombre() << "--------" << as->getId()<< std::endl;
            i->next();
        }
        std::cout << "\nIngrese id";
        std::cin >> id;
        Integer *id2 = new Integer(id);
        if(!asig->member(id2))
        {
            throw std::invalid_argument("\n\e[0;31mLa asignatura ingresada no esta asignada al docente.\n\e[0m");
        }
        as = SeleccionAsignatura(id);
        std::cout << "\nIngrese nombre";
        std::cin >> nombre;
        //std::cout << "\nIngrese Fecha y hora de comienzo (dd/mm/aa/HH/MM)";/
        Clase *c = as->crearClase(nombre, DtFecha(this->dia, this->mes, this->anio), doc->getAsignacion(id)->getTipo());
        if(doc->getAsignacion(id)->getTipo() == Tipo::MONITOREO)
        {
            bool flag= true;
            Monitoreo *m = new Monitoreo;
            m = dynamic_cast<Monitoreo *>(c);
            while(flag)
            {
                ICollection *es = new List;
                es = ListarEstudiantesInscriptos(id);
                IIterator *i = es->getIterator();
                Estudiante * e;
                while(i->hasCurrent())
                {
                    e = (Estudiante *) i->getCurrent();
                    std::cout << e->getNombre() << "--------" << e->getEmail()<< std::endl;
                    i->next();
                }
                std::cout << "\nIngrese email";
                std::cin >> emEs;
                IKey *k = new String(emEs);
                e = (Estudiante *)this->usuarios->find(k);
                if(es->member(e))
                {
                    m->setEstudiante(e);
                }
                else
                {
                    std::cout << "\nEmail ingresado no es correcto";
                }
                std::cout << "\nDesea seguir ingresando estudiantes?";
                std::cin >> op;
                switch(op)
                {
                case 1:
                {
                    flag = true;
                    break;
                }
                case 2:
                {
                    flag = false;
                    break;
                }
                default:
                    throw std::invalid_argument("\n\e[0;31mLa opcion ingresada no es correcta.\n\e[0m");
                }
            }
            //mostrar clase con outstream

        }
        if(doc->getAsignacion(id)->getTipo() == Tipo::TEORICO)
        {
            Teorico *t = new Teorico;
            t = dynamic_cast<Teorico *>(c);
            //mostrar clase con outstream
        }
        if(doc->getAsignacion(id)->getTipo() == Tipo::PRACTICO)
        {
            Practico *p = new Practico;
            p = dynamic_cast<Practico *>(c);
            //mostrar clase con outstream
        }
        std::cout << "\nDesea confirmar? ";
        std::cout << "\n1-Si: ";
        std::cout << "\n2-No: ";
        std::cin >> op;
        switch (op)
        {
            case 1:
            {
                doc->setClase(c);
                as->setClase(c);
                std::cout << "\nClase iniciada";
                break;
            }
            case 2:
            {
                delete c;
                std::cout << "\nVolviendo al menu principal";
                break;
            }
            default:
                throw std::invalid_argument("\e[0;31mLa opcion ingresada no es correcta.\e[0m");
                break;
        }

    }
    catch (std::invalid_argument &e)
    {
        std::cout << "\nError: " << e.what() << std::endl;
        std::cout << "\n\e[0;33mVolviendo al menu principal\e[0m\n\n";
    }

}

ICollection *Sistema::ListarAsignaturasAsignadas(Docente *d)
{
    ICollection *as = NULL ;
    as = d->getAsignaturas();
    IIterator *i = as->getIterator();
    Asignatura *a;
    ICollection *asig = new List;
    IKey *k = new Integer(0);
    while(i->hasCurrent())
    {
        k = (Integer *)i->getCurrent();
        a = (Asignatura *) this->asignaturas->find(k);
        asig->add(a);
        i->next();
    }
    return asig;
}

ICollection *Sistema::ListarEstudiantesInscriptos(int id)
{
    IIterator *i = this->usuarios->getIterator();
    Usuario *u;
    ICollection *es = new List;
    while(i->hasCurrent())
    {
        u = (Usuario *) i->getCurrent();
        if (dynamic_cast<Estudiante *>(u))
        {
            Estudiante *e = new Estudiante;
            e = dynamic_cast<Estudiante *>(u);
            if(e->estaInscripto(id))
            {
                es->add(e);
            }
        }
        i->next();
    }
    return es;
}

void Sistema::obtenerFechaDelSistema(int &dia, int &mes, int &anio)
{
    std::time_t t = std::time(0);
    std::tm *now = std::localtime(&t);
    this->anio = (now->tm_year + 1900);
    this->mes = (now->tm_mon + 1);
    this->dia = now->tm_mday;
}

void Sistema::mostrarFecha(DtFecha fecha)
{
    std::cout << "\nDia: " << fecha.getDia() << std::endl;
    std::cout << "\nAño: " << fecha.getAnio() << std::endl;
    std::cout << "\nMes: " << fecha.getMes() << std::endl;
}

void Sistema::fechaAutomatica()
{
    Sistema::obtenerFechaDelSistema(dia, mes, anio);
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

void Sistema::imprimirMenuAdministrador()
{
    std::cout << "\n\e[0;92m1)\e[0m Alta de usuario.\n";
    std::cout << "\e[0;92m2)\e[0m Alta de asignatura.\n";
    std::cout << "\e[0;92m3)\e[0m Asignación de docentes a una asignatura.\n";
    std::cout << "\e[0;92m4)\e[0m Eliminación de asignatura.\n";
    std::cout << "\e[0;92m5)\e[0m Tiempo de dictado de clases.\n";
    std::cout << "\e[0;92m6)\e[0m Configuracion del reloj interno.\n";
    std::cout << "Pulse \e[0;92m7\e[0m para salir.\n\nOpcion: \e[0;92m";
}

void Sistema::imprimirMenuDocente()
{
    std::cout << "\n\e[0;92m1)\e[0m Inicio de clase.\n";
    std::cout << "\e[0;92m2)\e[0m Finalización de clase.\n";
    std::cout << "\e[0;92m3)\e[0m Tiempo de asistencia a clase.\n";
    std::cout << "\e[0;92m4)\e[0m Listado de Clases.\n";
    std::cout << "\e[0;92m5)\e[0m Envío de mensaje.\n";
    std::cout << "Pulse \e[0;92m6\e[0m para salir.\n\nOpcion: \e[0;92m";
}

void Sistema::imprimirMenuEstudiante()
{
    std::cout << "\n\e[0;92m1)\e[0m Envío de mensaje.\n";
    std::cout << "\e[0;92m2)\e[0m Inscripción a las asignaturas.\n";
    std::cout << "\e[0;92m3)\e[0m Asistencia a clase en vivo.\n";
    std::cout << "\e[0;92m4)\e[0m Reproduccion en diferido.\n";
    std::cout << "Pulse \e[0;92m5\e[0m para salir.\n\nOpcion: \e[0;92m";
}
Sistema::~Sistema() {}
