#include "./../headers/Sistema.h"
Sistema::Sistema() {
    this->usuarios = new OrderedDictionary;
    this->asignaturas = new OrderedDictionary;
}

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
                    Sistema::AsignacionDeDocentesAUnaAsignatura();
                    break;
                }
                case 4: //Eliminación de asignatura
                {
                    Sistema::EliminacionDeAsignatura();
                    break;
                }
                case 5: //Tiempo de dictado de clases
                {
                    Sistema::TiempoDeDictadoDeClases();
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
    std::string email, contrasenia;
    bool bandera = true;
    std::cout << "\nIngrese email: ";
    std::cin >> email;
    std::cout << "\nIngrese contraseña: ";
    std::cin >> contrasenia;
    try
    {
        InicioSesion(email, contrasenia, 2);
        while (bandera == true)
        {
            Sistema::imprimirMenuDocente();
            std::cin >> opcionUsuario;
            std::cout << "\e[0m";
            std::cin.clear();
            switch (opcionUsuario)
            {
                case 1: //Inicio de clase
                {
                    Sistema::InicioDeClase();
                    break;
                }
                case 2: //Finalización de clase
                {
                    Sistema::FinalizacionDeClase();
                    break;
                }
                case 3: //Tiempo de asistencia a clase
                {
                    Sistema::TiempoDeAsistenciaAClase();
                    break;
                }
                case 4: //Listado de Clases
                {
                    Sistema::ListadoDeClases();
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
    }
    catch (std::invalid_argument &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void Sistema::menuCaso3()
{
    int opcionUsuario;
    bool bandera = true;
    std::string email, contrasenia;
    std::cout << "\nIngrese email: ";
    std::cin >> email;
    std::cout << "\nIngrese contraseña: ";
    std::cin >> contrasenia;
    try
    {
        while (bandera == true)
        {
            InicioSesion(email, contrasenia, 1);
            Sistema::imprimirMenuEstudiante();
            std::cin >> opcionUsuario;
            std::cout << "\e[0m";
            std::cin.clear();
            switch (opcionUsuario)
            {
                case 1: //Envío de mensaje
                {
                    //EnvioDeMensaje();
                    break;
                }
                case 2: //Inscripción a las asignaturas
                {
                    Sistema::InscripcionALasAsignaturas();
                    break;
                }
                case 3: //Asistencia a clase en vivo
                {
                    Sistema::AsistenciaAClaseEnVivo();
                    break;
                }
                case 4: //Reproduccion en diferido
                {
                    Sistema::ReproduccionEnDiferido();
                    break;
                }
                case 5: //Finalizar Asistencia
                {
                    Sistema::FinalizarAsistencia();
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
    }
    catch (std::invalid_argument &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void Sistema::menuCaso4()
{
    // INGRESO DATOS DE PRUEBA
}

void Sistema::InicioSesion(std::string email, std::string contrasenia, int i)
{
    IKey *k = new String(email);
    if(i == 1)
    {
        if(!this->usuarios->member(k))
        {
            throw std::invalid_argument("\e[0;31mEl email ingresado no es correcto.\e[0m");
        }
        Usuario * u = (Usuario *)this->usuarios->find(k);
        if (dynamic_cast<Estudiante *>(u))
        {
            Estudiante *e = new Estudiante;
            e = dynamic_cast<Estudiante *>(u);
            if(e->getContrasenia().compare(contrasenia) != 0)
            {
                throw std::invalid_argument("\e[0;31mLa contraseña ingresada no es correcta.\e[0m");
            }
            this->actual = e;
        }
        else
        {
            throw std::invalid_argument("\e[0;31mEl Usuario ingresado no es un estudiante.\e[0m");
        }
    }
    if(i == 2)
    {
        if(!this->usuarios->member(k))
        {
            throw std::invalid_argument("\e[0;31mEl email ingresado no es correcto.\e[0m");
        }
        Usuario * u = (Usuario *)this->usuarios->find(k);
        if (dynamic_cast<Docente *>(u))
        {
            Docente *d = new Docente;
            d = dynamic_cast<Docente *>(u);
            if(d->getContrasenia().compare(contrasenia) != 0)
            {
                throw std::invalid_argument("\e[0;31mLa contraseña ingresada no es correcta.\e[0m");
            }
            this->actual = d;
        }
        else
        {
            throw std::invalid_argument("\e[0;31mEl Usuario ingresado no es un docente.\e[0m");
        }
    }
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
                std::cin >> instituto;
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
                IKey *k = new String(email);
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
            IKey *k = new String(email);
            this->usuarios->add(k, d);
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
    std::string nombre;
    int op, id;
    try
    {
        std::cout << "\nIngrese el id de la asigtatura: ";
        std::cin >> id;
        std::cout << "\nIngrese nombre de la asigtatura: ";
        std::cin >> nombre;
        std::cout << "\nDesea confirmar? \n1-Si: \n2-No: ";
        std::cin >> op;
        switch (op)
        {
            case 1:
            {
                Asignatura *a = new Asignatura(id, nombre);
                IKey *k = new Integer(id);
                this->asignaturas->add(k, a);
                std::cout << "\nAsignatura agregada\n";
                break;
            }
            case 2:
            {
                std::cout << "\n\e[0;33mVolviendo al menu principal\e[0m\n\n";
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
            d = dynamic_cast<Docente *>(u);
            if(!d->estaAsignado(id))
            {
                docs->add(d);
            }
        }
        i->next();
    }
    return docs;

}

ICollection *Sistema::ListarDocentesAsignados(IKey *id)
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
            d = dynamic_cast<Docente *>(u);
            if(d->estaAsignado(id))
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
        Clase *c = as->crearClase(nombre, DtFecha(this->dia, this->mes, this->anio, this->seg, this->minuto, this->hora), doc->getAsignacion(id)->getTipo());
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

void Sistema::InscripcionALasAsignaturas()
{
    try
    {
        bool flag = true;
        int op, id;
        while(flag)
        {
            ICollection *asig = new List;
            asig = ListarAsignaturasNoInscriptas();
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
                throw std::invalid_argument("\n\e[0;31mLa asignatura ingresada no es correcta.\n\e[0m");
            }
            as = SeleccionAsignatura(id);
            std::cout << "\nDesea confirmar? ";
            std::cout << "\n1-Si: ";
            std::cout << "\n2-No: ";
            std::cin >> op;
            switch (op)
            {
                case 1:
                {
                    Estudiante *e = new Estudiante;
                    e = dynamic_cast<Estudiante *>(this->actual);
                    e->setAsignatura(as);
                    break;
                }
                case 2:
                {
                    delete as;
                    delete asig;
                    std::cout << "\nVolviendo al menu principal";
                    break;
                }
                default:
                    throw std::invalid_argument("\e[0;31mLa opcion ingresada no es correcta.\e[0m");
                    break;
            }

            std::cout << "\nDesea seguir inscribiendose? ";
            std::cout << "\n1-Si: ";
            std::cout << "\n2-No: ";
            std::cin >> op;
            switch (op)
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
                    throw std::invalid_argument("\e[0;31mLa opcion ingresada no es correcta.\e[0m");
                    break;
            }
        }
    }
    catch (std::invalid_argument &e)
    {
        std::cout << "\nError: " << e.what() << std::endl;
        std::cout << "\n\e[0;33mVolviendo al menu principal\e[0m\n\n";
    }

}

ICollection *Sistema::ListarAsignaturasNoInscriptas()
{
    IIterator *i = this->asignaturas->getIterator();
    Asignatura *a;
    ICollection *asig = new List;
    Estudiante *e = new Estudiante;
    e = dynamic_cast<Estudiante *>(this->actual);
    while(i->hasCurrent())
    {
        a = (Asignatura *) i->getCurrent();
        if (!e->estaInscripto(a->getId()))
        {
            asig->add(a);
        }
        i->next();
    }
    return asig;
}

void Sistema::ReproduccionEnDiferido()
{
    try
    {
        int id, op;
        ICollection *asig = new List;
        asig = ListarAsignaturasNoInscriptas();
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
        IKey *k = new Integer(id);
        as = (Asignatura *)asignaturas->find(k);
        if(asig->member(as))
        {
            throw std::invalid_argument("\n\e[0;31mLa asignatura ingresada no es correcta.\n\e[0m");
        }
        as = SeleccionAsignatura(id);
        ICollection *cl = new List;
        cl = as->getClasesDif();
        i = cl->getIterator();
        Clase *c;
        while(i->hasCurrent())
        {
            c = (Clase *) i->getCurrent();
            std::cout << c->getNombre() << "--------" << c->getId()<< std::endl;
            i->next();
        }
        std::cout << "\nIngrese id";
        std::cin >> id;
        c = SeleccionClase(id, as->getId());
        std::cout << "Asignatura: " << as->getNombre() << "--------" << as->getId()<< std::endl;
        std::cout << "Clase: " << c->getNombre() << "--------" << c->getId()<< std::endl;
        std::cout << "\nDesea confirmar? ";
        std::cout << "\n1-Si: ";
        std::cout << "\n2-No: ";
        std::cin >> op;
        switch (op)
        {
            case 1:
            {
                Estudiante *e = new Estudiante;
                e = dynamic_cast<Estudiante *>(this->actual);
                DtFecha *f = new DtFecha(this->dia, this->mes, this->anio, this->seg, this->minuto, this->hora);
                e->setAsisDif(id, f);
                //mostrar mensajes de la clase
                break;
            }
            case 2:
            {
                delete as;
                delete asig;
                delete cl;
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

Clase *Sistema::SeleccionClase(int idC, int idA)
{
    IKey *k = new Integer(idA);
    IDictionary *cl = new OrderedDictionary;
    Asignatura *a = (Asignatura *)this->asignaturas->find(k);
    cl = a->getClases();
    k = new Integer(idC);
    Clase * c = (Clase *) cl->find(k);
    return c;
}

ICollection *Sistema::ListarAsignaturasInscriptas()
{
    IIterator *i = this->asignaturas->getIterator();
    Asignatura *a;
    ICollection *asig = new List;
    Estudiante *e = new Estudiante;
    e = dynamic_cast<Estudiante *>(this->actual);
    while(i->hasCurrent())
    {
        a = (Asignatura *) i->getCurrent();
        if (e->estaInscripto(a->getId()))
        {
            asig->add(a);
        }
        i->next();
    }
    return asig;
}

void Sistema::FinalizacionDeClase()
{
    try
    {
        int id, op;
        Docente *d = new Docente;
        d = (Docente *)this->actual;
        IDictionary *cl = new OrderedDictionary;
        cl = d->getClasesVivo();
        IIterator *i = cl->getIterator();
        Clase *c;
        while(i->hasCurrent())
        {
            c = (Clase *) i->getCurrent();
            std::cout << c->getNombre() << "--------" << c->getId()<< std::endl;
            i->next();
        }
        std::cout << "\nIngrese id";
        std::cin >> id;
        IKey *k = new Integer(id);
        if(!cl->member(k))
        {
            throw std::invalid_argument("\e[0;31mLa opcion ingresada no es correcta.\e[0m");
        }
        //mostrar id, nombre, tipo y fecha inicio con outstream maybe
        std::cout << "\nDesea confirmar? ";
        std::cout << "\n1-Si: ";
        std::cout << "\n2-No: ";
        std::cin >> op;
        switch (op)
        {
            case 1:
            {
                d->finalizarClase(id, DtFecha(this->dia, this->mes, this->anio, this->seg, this->minuto, this->hora));
                break;
            }
            case 2:
            {
                delete d;
                delete c;
                delete cl;
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

void Sistema::EliminacionDeAsignatura()
{
    try
    {
        int id, op;
        ListarAsignaturas();
        Asignatura *a;
        std::cout << "\nIngrese id: ";
        std::cin >> id;
        IKey *k = new Integer(id);
        if(!this->asignaturas->member(k))
        {
            throw std::invalid_argument("\e[0;31mLa asignatura ingresada no es correcta.\e[0m");
        }
        a = SeleccionAsignatura(id);
        std::cout << "\nDesea confirmar? ";
        std::cout << "\n1-Si: ";
        std::cout << "\n2-No: ";
        std::cin >> op;
        switch (op)
        {
            case 1:
            {
                this->asignaturas->remove(k);
                ICollection *est = new List;
                est = ListarEstudiantesInscriptos(id);
                IIterator *i = est->getIterator();
                Estudiante *e;
                while(i->hasCurrent())
                {
                    e = (Estudiante *) i->getCurrent();
                    e->BorrarAsignatura(id);
                    i->next();
                }
                ICollection *docs = new List;
                docs = ListarDocentesAsignados(k);
                i = docs->getIterator();
                Docente *d;
                IDictionary *cl = new OrderedDictionary;
                cl = a->getClases();
                while(i->hasCurrent())
                {
                    d = (Docente *) i->getCurrent();
                    d->BorrarAsignacion(id, cl);
                    i->next();
                }
                a->BorrarInstancias();
                delete a;
                break;
            }
            case 2:
            {
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

void Sistema::TiempoDeDictadoDeClases()
{
    int horasCom,minutosCom,segundosCom,horasFin,minutosFin,segundosFin,total;
    try
    {
        Asignatura * a;
        Clase * c;
        IIterator *i = this->asignaturas->getIterator();
        IIterator *j = a->getClases()->getIterator();

        while(i->hasCurrent())
        {
            a = (Asignatura *) i->getCurrent();
            std::cout << a->getNombre() << ":\n   ";
            while(j->hasCurrent())
            {
                c = (Clase *) j->getCurrent();

                horasCom = c->getFechaCom().getHora() * 3600;
                minutosCom = c->getFechaCom().getMinuto() * 60;
                segundosCom = c->getFechaCom().getSegundo();

                horasFin = c->getFechaFin().getHora() * 3600;
                minutosFin = c->getFechaFin().getMinuto() * 60;
                segundosFin = c->getFechaFin().getSegundo();

                total = ((horasFin + minutosFin + segundosFin) - (horasCom + minutosCom + segundosCom));
                std::cout << c->getNombre() << ": " << total << " minutos\n";
                j->next();
            }

            i->next();
        }
    }
    catch(std::out_of_range &e)
    {
        std::cerr << "No hay Asignaturas o clases: " << e.what() << std::endl;
    }
}

void Sistema::AsistenciaAClaseEnVivo()
{
    try
    {
        int id, op;
        ICollection *asig = new List;
        asig = ListarAsignaturasInscriptas();
        IIterator *i = asig->getIterator();
        Asignatura *a;
        while(i->hasCurrent())
        {
            a = (Asignatura *) i->getCurrent();
            std::cout << a->getNombre() << "--------" << a->getId()<< std::endl;
            i->next();
        }
        std::cout << "\nIngrese id: ";
        std::cin >> id;
        a = SeleccionAsignatura(id);
        if(!asig->member(a))
        {
            throw std::invalid_argument("\e[0;31mLa asignatura ingresada no es correcta.\e[0m");
        }
        ICollection *cl = new List;
        cl = a->getClasesVivo();
        i = cl->getIterator();
        Clase *c;
        while(i->hasCurrent())
        {
            c = (Clase *) i->getCurrent();
            std::cout << c->getNombre() << "--------" << c->getId()<< std::endl;
            i->next();
        }
        std::cout << "\nIngrese id: ";
        std::cin >> id;
        c = SeleccionClase(id, a->getId());
        if(!cl->member(c))
        {
            throw std::invalid_argument("\e[0;31mLa asignatura ingresada no es correcta.\e[0m");
        }
        std::cout << a->getNombre() << "--------" << a->getId()<< std::endl;
        std::cout << c->getNombre() << "--------" << c->getId()<< std::endl;
        std::cout << "\nDesea confirmar? ";
        std::cout << "\n1-Si: ";
        std::cout << "\n2-No: ";
        std::cin >> op;
        switch (op)
        {
            case 1:
            {
                Estudiante *e;
                e = (Estudiante *) this->actual;
                //DtFecha *f = new DtFecha(this->dia, this->mes, this->anio, this->seg, this->minuto, this->hora);
                AsistenciaOnline *aO = e->crearAsisOn(id, a->getId(), DtFecha(this->dia, this->mes, this->anio, this->seg, this->minuto, this->hora));
                e->setAsisOn(id, aO);
                std::cout << "\nAsistencia guardada";
                break;
            }
            case 2:
            {
                delete asig;
                delete cl;
                delete c;
                delete a;
                std::cout << "\nVolviendo al menu principal";
                break;
            }
            default:
                throw std::invalid_argument("\e[0;31mLa opcion ingresada no es correcta.\e[0m");
                break;
        }

    }
    catch(std::out_of_range &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void Sistema::FinalizarAsistencia()
{
    try
    {
        int op, id;
        std::cout << "\nElija una opcion ";
        std::cout << "\n1-En vivo: ";
        std::cout << "\n2-En diferido: ";
        std::cin >> op;
        switch (op)
        {
            case 1:
            {
                Estudiante *e;
                e= (Estudiante *) this->actual;
                IDictionary *aO = new OrderedDictionary;
                aO = e->getAsistenciasOn();
                IIterator *i = aO->getIterator();
                AsistenciaOnline *a;
                while(i->hasCurrent())
                {
                    a = (AsistenciaOnline *) i->getCurrent();
                    std::cout << a->getIdClase()<< std::endl;
                    i->next();
                }
                std::cout << "\nIngrese id: ";
                std::cin >> id;
                IKey *k = new Integer(id);
                if(!aO->member(k))
                {
                     throw std::invalid_argument("\e[0;31mEl id ingresado es incorrecto.\e[0m");
                }
                a = (AsistenciaOnline* )aO->find(k);
                std::cout << "\nDesea confirmar ";
                std::cout << "\n1-Si: ";
                std::cout << "\n2-No: ";
                std::cin >> op;
                switch (op)
                {
                    case 1:
                    {
                        DtFecha *f = new DtFecha(this->dia, this->mes, this->anio, this->seg, this->minuto, this->hora);
                        a->setFechaFin(f);
                        break;
                    }
                    case 2:
                    {
                        delete aO;
                        delete a;
                        std::cout << "\nVolviendo al menu principal";
                        break;
                    }
                    default:
                        throw std::invalid_argument("\e[0;31mLa opcion ingresada no es correcta.\e[0m");
                        break;
                }
            }
            case 2:
            {
                Estudiante *e;
                e = (Estudiante *)this->actual;
                IDictionary *aD = new OrderedDictionary;
                aD = e->getAsistenciasDif();
                IIterator *i = aD->getIterator();
                AsistenciaDiferida *a;
                while(i->hasCurrent())
                {
                    a = (AsistenciaDiferida *) i->getCurrent();
                    std::cout << a->getIdClase()<< std::endl;
                    i->next();
                }
                std::cout << "\nIngrese id: ";
                std::cin >> id;
                IKey *k = new Integer(id);
                if(!aD->member(k))
                {
                     throw std::invalid_argument("\e[0;31mEl id ingresado es incorrecto.\e[0m");
                }
                a = (AsistenciaDiferida*) aD->find(k);
                std::cout << "\nDesea confirmar ";
                std::cout << "\n1-Si: ";
                std::cout << "\n2-No: ";
                std::cin >> op;
                switch (op)
                {
                    case 1:
                    {
                        DtFecha *f = new DtFecha(this->dia, this->mes, this->anio, this->seg, this->minuto, this->hora);
                        a->setFechaFin(f);
                        break;
                    }
                    case 2:
                    {
                        delete aD;
                        delete a;
                        std::cout << "\nVolviendo al menu principal";
                        break;
                    }
                    default:
                        throw std::invalid_argument("\e[0;31mLa opcion ingresada no es correcta.\e[0m");
                        break;
                }
            }

            default:
                throw std::invalid_argument("\e[0;31mLa opcion ingresada no es correcta.\e[0m");
                break;
        }
    }
    catch(std::out_of_range &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void Sistema::TiempoDeAsistenciaAClase()
{
    try
    {
        int id, prom;
        Docente *d;
        d = (Docente *) this->actual;
        ICollection *asig = new List;
        asig = ListarAsignaturasAsignadas(d);
        IIterator *i = asig->getIterator();
        Asignatura *a;
        while(i->hasCurrent())
        {
            a = (Asignatura *) i->getCurrent();
            std::cout << a->getNombre() << "--------" << a->getId();
            i->next();
        }
        std::cout << "\nIngrese id: ";
        std::cin >> id;
        a = SeleccionAsignatura(id);
        if(!asig->member(a))
        {
            throw std::invalid_argument("\e[0;31mLa asignatura ingresada no es correcta.\e[0m");
        }
        ICollection *cl = new List;
        cl = ListarClasesPorAsig(a);
        i = cl->getIterator();
        Clase *c;
        while(i->hasCurrent())
        {
            c = (Clase *) i->getCurrent();
            prom = PromedioAsistenciaClase(c->getId(), id);
            std::cout << c->getId() << "--------" << prom;
            i->next();
        }
    }
    catch(std::out_of_range &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

ICollection *Sistema::ListarClasesPorAsig(Asignatura *a)
{
    Docente *d;
    d = (Docente *) this->actual;
    IDictionary *cl = a->getClases();
    ICollection *lista = new List;
    IIterator *i = cl->getIterator();
    Clase *c;
    IKey *k;
    while(i->hasCurrent())
    {
        c = (Clase *) i->getCurrent();
        k = new Integer(c->getId());
        if(d->getClases()->member(k))
        {
            lista->add(c);
        }
        i->next();
    }
    return lista;
}

int Sistema::PromedioAsistenciaClase(int idC, int idA)
{
    int n = 0, t = 0;
    ICollection *est = new List;
    est = ListarEstudiantesInscriptos(idA);
    IIterator *i = est->getIterator();
    Estudiante *e;
    AsistenciaOnline *a;
    IKey *k = new Integer(idC);
    while(i->hasCurrent())
    {
        e = (Estudiante *) i->getCurrent();
        if(e->getAsistenciasOn()->member(k))
        {
            a = e->getAsistenciaOn(idC);
            t = a->TiempodeAsistencia() + t;
            n++;
        }
        i->next();
    }
    t = t /n;
    return t;
}

void Sistema::ListadoDeClases()
{
    try
    {
        int id;
        Docente *d;
        d = (Docente *) this->actual;
        ICollection *asig = new List;
        asig = ListarAsignaturasAsignadas(d);
        IIterator *i = asig->getIterator();
        Asignatura *a;
        while(i->hasCurrent())
        {
            a = (Asignatura *) i->getCurrent();
            std::cout << a->getNombre() << "--------" << a->getId();
        }
        std::cout << "\nIngrese id: ";
        std::cin >> id;
        a = SeleccionAsignatura(id);
        if(!asig->member(a))
        {
            throw std::invalid_argument("\e[0;31mLa asignatura ingresada no es correcta.\e[0m");
        }
        IDictionary *cl = a->getClases();
        Clase *c;
        i = cl->getIterator();
        Docente *d2;
        while(i->hasCurrent())
        {
            c = (Clase *) i->getCurrent();
            //std::cout << c; mostrar con outstream
            d2 = DocenteDeClase(c->getId(), id);
            std::cout << "Docente: " << d2->getNombre();
        }

    }
    catch(std::out_of_range &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

Docente *Sistema::DocenteDeClase(int idC, int idA)
{
    IKey *k = new Integer(idA);
    ICollection *doc = ListarDocentesAsignados(k);
    k = new Integer(idC);
    IIterator *i = doc->getIterator();
    Docente *d;
    while(i->hasCurrent())
    {
        d = (Docente *) i->getCurrent();
        if(d->getClases()->member(k))
        {
            break;
        }
        else
        {
            i->next();
        }
    }
    return d;
}

void Sistema::EnvioDeMensaje()
{
    try
    {
        int id, op;
        std::string msj;
        Clase *c;
        if (dynamic_cast<Estudiante *>(this->actual))
        {
            Estudiante *e;
            e = (Estudiante *)this->actual;
            IDictionary *as = new OrderedDictionary;
            as = e->getAsistenciasOn();
            IIterator *i = as->getIterator();
            AsistenciaOnline *aO;
            while(i->hasCurrent())
            {
                aO = (AsistenciaOnline *) i->getCurrent();
                if(aO->getFechaFin()==NULL)
                {
                    std::cout << aO->getIdClase() << std::endl;
                }
                i->next();
            }
            std::cout << "\nIngrese id: ";
            std::cin >> id;
            IKey *k = new Integer(id);
            if(!as->member(k))
            {
                throw std::invalid_argument("\e[0;31mLa asignatura ingresada no es correcta.\e[0m");
            }
            aO=(AsistenciaOnline* ) as->find(k);
            c = SeleccionClase(id, aO->getIdAsig());
        }
        else
        {
            Docente *d;
            d = (Docente *)this->actual;
            IDictionary *cl = new OrderedDictionary;
            cl = d->getClasesVivo();
            IIterator *i = cl->getIterator();
            while(i->hasCurrent())
            {
                c = (Clase *) i->getCurrent();
                std::cout << c->getId() << std::endl;
                i->next();
            }
            std::cout << "\nIngrese id: ";
            std::cin >> id;
            IKey *k = new Integer(id);
            if(!cl->member(k))
            {
                throw std::invalid_argument("\e[0;31mLa asignatura ingresada no es correcta.\e[0m");
            }
            c = (Clase *)cl->find(k);
        }
        ListarMensajes(c);
        Mensaje *m;
        std::cout << "\nEs una respuesta? ";
        std::cout << "\n1-Si: ";
        std::cout << "\n2-No: ";
        std::cin >> op;
        switch (op)
        {
            case 1:
            {
                std::cout << "\nIngrese id de mensaje a responder: ";
                std::cin >> id;
                Mensaje *m2;
                m2 = SeleccionMensaje(c, id);
                std::cout << "\nIngrese mensaje: ";
                std::cin >> msj;
                m = c->crearRespuesta(msj, m2, DtFecha(this->dia, this->mes, this->anio, this->seg, this->minuto, this->hora));
                break;
            }
            case 2:
            {
                std::cout << "\nIngrese mensaje: ";
                std::cin >> msj;
                //DtFecha *f = DtFecha(this->dia, this->mes, this->anio, this->seg, this->minuto, this->hora);
                m = c->crearMensaje(msj, DtFecha(this->dia, this->mes, this->anio, this->seg, this->minuto, this->hora));
                break;
            }
            default:
                throw std::invalid_argument("\e[0;31mLa opcion ingresada no es correcta.\e[0m");
                break;
        }
        std::cout << "\nDesea confirmar? ";
        std::cout << "\n1-Si: ";
        std::cout << "\n2-No: ";
        std::cin >> op;
        switch(op)
        {
            case 1:
            {
                c->setMensaje(m);
                std::cout << "\nMensaje enviado";
                break;
            }
            case 2:
            {
                std::cout << "\nVolviendo al menu principal";
                break;
            }
            default:
                throw std::invalid_argument("\e[0;31mLa opcion ingresada no es correcta.\e[0m");
                break;
        }
    }
    catch(std::out_of_range &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void Sistema::ListarMensajes(Clase *c)
{
    IDictionary *msj = new OrderedDictionary;
    msj = c->getMensajes();
    IIterator *i = msj->getIterator();
    Mensaje *m;
    while(i->hasCurrent())
    {
        m = (Mensaje*) i->getCurrent();
        //std::cout<< m; outstream
        i->next();
    }
}

Mensaje *Sistema::SeleccionMensaje(Clase *c, int id)
{
    IKey *k = new Integer(id);
    if(!c->getMensajes()->member(k))
    {
        throw std::invalid_argument("\e[0;31mEl id ingresado es incorrecto.\e[0m");
    }
    Mensaje *m;
    m = (Mensaje *) c->getMensajes()->find(k);
    return m;
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
    std::cout << "\e[0;92m5)\e[0m Finalizar asistencia.\n";
    std::cout << "Pulse \e[0;92m6\e[0m para salir.\n\nOpcion: \e[0;92m";
}
Sistema::~Sistema() {}
