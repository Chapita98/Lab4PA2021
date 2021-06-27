#include "./../headers/Sistema.h"
Sistema::Sistema() {
    this->usuarios = new OrderedDictionary;
    this->asignaturas = new OrderedDictionary;
    this->fecha = new DtFecha(01, 01, 2020, 00, 00, 00);
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
                case 6: //ModificarFechaSistema
                {
                    Sistema::ModificarFechaSistema();
                    break;
                }
                case 7: //ConsultarFechaSistema
                {
                    Sistema::ConsultarFechaSistema();
                    break;
                }
                case 8: //CASO SALIDA DE SISTEMA
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
                case 5: //Envio de mensaje
                {
                    Sistema::EnvioDeMensaje();
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
                    Sistema::EnvioDeMensaje();
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
    Asignatura *a1 = new Asignatura(1, "Programacion 1");//Teórico, Práctico, Monitoreo
    Asignatura *a2 = new Asignatura(2, "Programacion 2");//Teórico, Práctico, Monitoreo
    Asignatura *a3 = new Asignatura(3, "Programacion 3");//Teórico, Práctico
    IKey *k = new Integer(1);
    this->asignaturas->add(k, a1);
    k = new Integer(2);
    this->asignaturas->add(k, a2);
    k = new Integer(3);
    this->asignaturas->add(k, a3);

    // url, contrasenia quedan en como string
    Docente *d1 = new Docente("INCO", "juan@mail.com", "Juan Perez", "1", "1");
    Docente *d2 = new Docente("INCO", "maria@mail.com", "Maria Pires", "1", "1");
    Docente *d3 = new Docente("INCO", "jorge@mail.com", "Jorge Chacho", "1", "1");
    k = new String("juan@mail.com");
    this->usuarios->add(k, d1);
    k = new String("maria@mail.com");
    this->usuarios->add(k, d2);
    k = new String("jorge@mail.com");
    this->usuarios->add(k, d3);
    Asignacion *as1 = d1->crearAsignacion(Tipo::TEORICO, 1);
    k = new Integer(1);
    Asignacion *as2 = d2->crearAsignacion(Tipo::PRACTICO, 1);
    Asignacion *as3 = d3->crearAsignacion(Tipo::MONITOREO, 1);
    d1->setAsignacion(as1, k);
    d2->setAsignacion(as2, k);
    d3->setAsignacion(as3, k);

    Estudiante *e1 = new Estudiante(12345678, "roberto@mail.com", "Roberto Parra", "1", "1");
    Estudiante *e2 = new Estudiante(23456789, "ana@mail.com", "Ana Rodriguez", "1", "1");
    Estudiante *e3 = new Estudiante(34567890, "ramon@mail.com", "Ramon Valdez", "1", "1");
    k = new String("roberto@mail.com");
    this->usuarios->add(k, e1);
    k = new String("ana@mail.com");
     this->usuarios->add(k, e2);
    k = new String("ramon@mail.com");
     this->usuarios->add(k, e3);
    e1->setAsignatura(a1);
    e2->setAsignatura(a1);
    e2->setAsignatura(a2);
    e3->setAsignatura(a1);

    DtFecha *f = new DtFecha(01, 05, 2020, 0, 00, 9);
    Clase *c1 = a1->crearClase("Intro", f, Tipo::TEORICO);
    f = new DtFecha(01, 05, 2020, 0, 00, 10);
    c1->finalizar(1, f);
    a1->setClase(c1);
    d1->setClase(c1);
    f = new DtFecha(03, 05, 2020, 0, 00, 9);
    Clase *c2 = a1->crearClase("Tema 1", f, Tipo::TEORICO);
    f = new DtFecha(03, 05, 2020, 0, 00, 10);
    c2->finalizar(2, f);
    a1->setClase(c2);
    d1->setClase(c2);
    f = new DtFecha(8, 05, 2020, 0, 00, 9);
    Clase *c3 = a1->crearClase("Tema 2", f, Tipo::TEORICO);
    f = new DtFecha(8, 05, 2020, 0, 00, 10);
    c3->finalizar(3, f);
    a1->setClase(c3);
    d1->setClase(c3);
    f = new DtFecha(02, 05, 2020, 0, 00, 16);
    Clase *c4 = a1->crearClase("Pra 1", f, Tipo::PRACTICO);
    f = new DtFecha(02, 05, 2020, 0, 00, 17);
    c4->finalizar(4, f);
    a1->setClase(c4);
    d2->setClase(c4);
    f = new DtFecha(03, 05, 2020, 0, 00, 16);
    Clase *c5 = a1->crearClase("Pra 2", f, Tipo::PRACTICO);
    f = new DtFecha(03, 05, 2020, 0, 00, 17);
    a1->setClase(c5);
    c5->finalizar(5, f);
    d2->setClase(c5);

    f = new DtFecha(04, 05, 2020, 0, 00, 16);
    Clase *c6 = a1->crearClase("01/06/20", f, Tipo::MONITOREO);
    Monitoreo *m = (Monitoreo *) c6;
    f = new DtFecha(04, 05, 2020, 0, 00, 17);
    m->setEstudiante(e2);
    m->setEstudiante(e3);
    c6->finalizar(6, f);
    a1->setClase(m);
    d3->setClase(m);

    f = new DtFecha(01, 05, 2020, 0, 01, 9);
    AsistenciaOnline *aO1 = e1->crearAsisOn(c1->getId(), a1->getId(), f);
    e1->setAsisOn(c1->getId(), aO1);
    f = new DtFecha(01, 05, 2020, 0, 21, 9);
    aO1->finalizarAsistencia(f);
    f = new DtFecha(01, 05, 2020, 0, 02, 9);
    AsistenciaOnline *aO2 = e2->crearAsisOn(c1->getId(), a1->getId(), f);
    f = new DtFecha(01, 05, 2020, 0, 32, 9);
    aO2->finalizarAsistencia(f);
    e2->setAsisOn(c1->getId(), aO2);
    f = new DtFecha(01, 05, 2020, 0, 03, 9);
    AsistenciaOnline *aO3 = e3->crearAsisOn(c1->getId(), a1->getId(), f);
    f = new DtFecha(01, 05, 2020, 0, 43, 9);
    aO3->finalizarAsistencia(f);
    e3->setAsisOn(c1->getId(), aO3);
    f = new DtFecha(04, 05, 2020, 0, 00, 16);
    AsistenciaOnline *aO4 = e3->crearAsisOn(c6->getId(), a1->getId(), f);
    f = new DtFecha(04, 05, 2020, 0, 00, 17);
    aO4->finalizarAsistencia(f);
    e3->setAsisOn(c6->getId(), aO4);


    f = new DtFecha(12, 05, 2020, 0, 01, 9);
    e1->setAsisDif(c1->getId(), f);
    f = new DtFecha(01, 05, 2020, 0, 31, 9);
    e1->finalizarAsisDif(c1->getId(), f);

    f = new DtFecha(12, 05, 2020, 0, 01, 9);
    e2->setAsisDif(c2->getId(), f);
    f = new DtFecha(12, 05, 2020, 0, 41, 9);
    e2->finalizarAsisDif(c2->getId(), f);
    f = new DtFecha(13, 05, 2020, 0, 01, 10);
    e2->setAsisDif(c2->getId(), f);
    f = new DtFecha(13, 05, 2020, 0, 41, 11);
    e2->finalizarAsisDif(c2->getId(), f);
    f = new DtFecha(14, 05, 2020, 0, 01, 9);
    e2->setAsisDif(c2->getId(), f);
    f = new DtFecha(14, 05, 2020, 0, 41, 9);
    e2->finalizarAsisDif(c2->getId(), f);

    f = new DtFecha(1, 05, 2020, 0, 01, 9);
    Mensaje *m1 = c1->crearMensaje("Bienvenidos!", f);
    c1->setMensaje(m1);
    f = new DtFecha(1, 05, 2020, 0, 02, 9);
    Mensaje *m2 = c1->crearMensaje("Confirmen materiales por favor.", f);
    c1->setMensaje(m2);
    f = new DtFecha(4, 05, 2020, 0, 01, 16);
    Mensaje *m3 = c6->crearMensaje("Comparto pantalla.", f);
    c6->setMensaje(m3);
    f = new DtFecha(1, 05, 2020, 0, 05, 9);
    Mensaje *m4 = c1->crearRespuesta("Listo para aprender", m1, f);
    c1->setMensaje(m4);
    f = new DtFecha(1, 05, 2020, 0, 06, 9);
    Mensaje *m5 = c1->crearRespuesta("Me alegro", m4, f);
    c1->setMensaje(m5);
    f = new DtFecha(1, 05, 2020, 0, 05, 9);
    Mensaje *m6 = c1->crearRespuesta("Todo listo", m2, f);
    c1->setMensaje(m6);
    f = new DtFecha(1, 05, 2020, 0, 16, 05);
    Mensaje *m7 = c6->crearRespuesta("Ya la vemos", m3, f);
    c6->setMensaje(m7);
    std::cout << "\nDatos de prueba cargados" << std::endl;
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
    {   std::cout << "\nIngrese email: ";
        std::cin >> email;
        IKey *k = new String(email);
        if(this->usuarios->find(k))
        {
            throw std::invalid_argument("\e[0;31mEl email ingresado ya existe.\e[0m");
        }
        std::cout << "\nIngrese nombre: ";
        std::getline(std::cin >> std::ws, nombre);
        std::cout << "\nIngrese contraseña: ";
        std::cin >> contrasenia;
        std::cout << "\nIngrese url de imagen: ";
        std::cin >> url;
        std::cout << "\nIngrese Opcion: ";
        std::cout << "\n1-Estudiante: ";
        std::cout << "\n2-Docente: \n";
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
    std::cout << "\n2-No: \n";
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
    int op,id;
    try
    {
        std::cout << "\nIngrese el id de la asignatura: ";
        std::cin >> id;
        IKey *k = new Integer(id);
        if(this->asignaturas->find(k))
        {
            throw std::invalid_argument("\e[0;31mEl id ingresado ya existe.\e[0m");
        }
        std::cout << "\nIngrese nombre de la asignatura: ";
        std::getline(std::cin >> std::ws, nombre);
        std::cout << "\nDesea confirmar? \n1-Si: \n2-No: \n";
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
        if(this->asignaturas->isEmpty())
        {
            throw std::invalid_argument("\e[0;31mNo existen asignaturas.\e[0m");
        }
        if(this->usuarios->isEmpty())
        {
            throw std::invalid_argument("\e[0;31mNo existen usuarios.\e[0m");
        }
        int id, asig, op;
        std::string email;
        Tipo tipo;
        ListarAsignaturas();
        std::cout << "\nIngrese id asignatura: ";
        std::cin >> id;
        IKey *k = new Integer(id);
        if(!this->asignaturas->member(k))
        {
            throw std::invalid_argument("\e[0;31mLa asignatura ingresada no existe.\e[0m");
        }
        ICollection *docs = new List;
        docs = ListarDocentesNoAsignados(id);
        if(docs->isEmpty())
        {
            throw std::invalid_argument("\e[0;31mNo existen Docentes no asignados.\e[0m");
        }
        IIterator *i = docs->getIterator();
        Docente * d;
        std::cout << "Email docentes: "<< std::endl;
        while(i->hasCurrent())
        {
            d = (Docente *) i->getCurrent();
            std::cout << d->getEmail()<< std::endl;
            i->next();
        }
        std::cout << "\nIngrese email de docente: ";
        std::cin >> email;
        d = SeleccionDocente(email);
        if(!docs->member(d))
        {
             throw std::invalid_argument("\e[0;31mEl docente ingresado no existe.\e[0m");
        }
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
            throw std::invalid_argument("\e[0;31mAsignacion invalida\e[0m");
            break;
        }
        std::cout << "\nDesea confirmar? \n1-Si\n2-No\n";
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

void Sistema::ListarAsignaturas()
{
    IIterator *i = this->asignaturas->getIterator();
    Asignatura * a;
    std::cout << "Nombre            Id: "<< std::endl;
    while(i->hasCurrent())
    {
        a = (Asignatura *) i->getCurrent();
        std::cout <<a->getNombre()<<"           "<< a->getId()<< std::endl;
        i->next();
    }
}

Asignatura *Sistema::SeleccionAsignatura(int id)
{
    IKey *k = new Integer(id);
    Asignatura * asig;
    asig = (Asignatura *) this->asignaturas->find(k);
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

ICollection *Sistema::ListarDocentesNoAsignados(int id)
{
    IIterator *i = this->usuarios->getIterator();
    Usuario *u;
    ICollection *docs = new List;
    while(i->hasCurrent())
    {
        u = (Usuario *) i->getCurrent();
        if (dynamic_cast<Docente *>(u))
        {
            Docente *d = new Docente();
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

ICollection *Sistema::ListarDocentesAsignados(int id)
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
    std::string nombre, emEs;
    try
    {
        Docente *doc;
        doc = (Docente*) this->actual;
        ICollection *asig = new List;
        asig = ListarAsignaturasAsignadas(doc);
        if(asig->isEmpty())
        {
            throw std::invalid_argument("\n\e[0;31mEl docente no tiene asignaturas asignadas.\n\e[0m");
        }
        IIterator *i = asig->getIterator();
        Asignatura *as;
        std::cout << "Nombre            Id" << std::endl;
        while(i->hasCurrent())
        {
            as = (Asignatura *) i->getCurrent();
            std::cout << as->getNombre() << "           " << as->getId()<< std::endl;
            i->next();
        }
        std::cout << "\nIngrese id asignatura";
        std::cin >> id;
        as = SeleccionAsignatura(id);
        if(!asig->member(as))
        {
            throw std::invalid_argument("\n\e[0;31mLa asignatura ingresada no esta asignada al docente.\n\e[0m");
        }
        std::cout << "\nIngrese nombre de clase: ";
        std::getline(std::cin >> std::ws, nombre);
        Clase *c = as->crearClase(nombre, this->fecha, doc->getAsignacion(id)->getTipo());
        if(doc->getAsignacion(id)->getTipo() == Tipo::MONITOREO)
        {
            bool flag= true;
            Monitoreo *m = new Monitoreo;
            m = dynamic_cast<Monitoreo *>(c);
            ICollection *es = new List;
            while(flag)
            {
                es = ListarEstudiantesInscriptos(id);
                if(es->isEmpty())
                {
                    throw std::invalid_argument("\n\e[0;31mNo hay estudiantes inscriptos a la asignatura.\n\e[0m");
                }
                IIterator *i = es->getIterator();
                Estudiante * e;
                std::cout << "Email estudiantes: "<< std::endl;
                while(i->hasCurrent())
                {
                    e = (Estudiante *) i->getCurrent();
                    std::cout << e->getEmail()<< std::endl;
                    i->next();
                }
                std::cout << "\nIngrese email: ";
                std::cin >> emEs;
                IKey *k = new String(emEs);
                e = (Estudiante *)this->usuarios->find(k);
                if(es->member(e))
                {
                    if(m->estaHabilitado(e))
                    {
                        std::cout << "\nEl usuario ingresado ya fue habilitado.";
                    }
                    else
                    {
                        m->setEstudiante(e);
                    }
                }
                else
                {
                    std::cout << "\nEmail ingresado no es correcto";
                }
                std::cout << "\nDesea seguir ingresando estudiantes?";
                std::cout << "\n1-Si: ";
                std::cout << "\n2-No: \n";
                std::cin >> op;
                switch(op)
                {
                case 1:
                {
                    if(m->getCantidadEstudiantes()==15)
                    {
                        throw std::invalid_argument("\n\e[0;31mYa se llego al maximo de estudiantes permitidos.\n\e[0m");
                    }
                    flag = true;
                    break;
                }
                case 2:
                {
                    if(m->getCantidadEstudiantes()==0)
                    {
                        std::cout << "\nLa clase debe tener por lo menos un estudiante";
                        flag = true;
                    }
                    else
                    {
                        flag = false;
                    }
                    break;
                }
                default:
                    throw std::invalid_argument("\n\e[0;31mLa opcion ingresada no es correcta.\n\e[0m");
                }
            }
        }
        std::cout << c << std::endl;
        std::cout << "\nDesea confirmar? ";
        std::cout << "\n1-Si: ";
        std::cout << "\n2-No: \n";
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
    ICollection *as = new List;
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
            if(asig->isEmpty())
            {
                throw std::invalid_argument("\n\e[0;31mNo hay mas asignaturas para inscribir.\n\e[0m");
            }
            IIterator *i = asig->getIterator();
            Asignatura *as;
            std::cout << "Nombre:           Id: " << std::endl;
            while(i->hasCurrent())
            {
                as = (Asignatura *) i->getCurrent();
                std::cout << as->getNombre() << "           " << as->getId()<< std::endl;
                i->next();
            }
            std::cout << "\nIngrese id asignatura: ";
            std::cin >> id;
            as = SeleccionAsignatura(id);
            if(as==NULL)
            {
                throw std::invalid_argument("\n\e[0;31mLa asignatura ingresada no existe.\n\e[0m");
            }
            if(!asig->member(as))
            {
                throw std::invalid_argument("\n\e[0;31mLa asignatura ingresada no es correcta.\n\e[0m");
            }
            std::cout << "\nDesea confirmar? ";
            std::cout << "\n1-Si: ";
            std::cout << "\n2-No: \n";
            std::cin >> op;
            switch (op)
            {
                case 1:
                {
                    Estudiante *e = new Estudiante;
                    e = dynamic_cast<Estudiante *>(this->actual);
                    e->setAsignatura(as);
                    std::cout << "\nInscripcion registrada";
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

            std::cout << "\nDesea seguir inscribiendose? ";
            std::cout << "\n1-Si: ";
            std::cout << "\n2-No: \n";
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
        asig = ListarAsignaturasInscriptas();
        IIterator *i = asig->getIterator();
        Asignatura *as;
        if(asig->isEmpty())
        {
            throw std::invalid_argument("\e[0;31mNo esta inscripto a ninguna asignatura.\e[0m");
        }
        std::cout <<  "Nombre       Id" << std::endl;
        while(i->hasCurrent())
        {
            as = (Asignatura *) i->getCurrent();
            std::cout << as->getNombre() << "           " << as->getId()<< std::endl;
            i->next();
        }
        std::cout << "\nIngrese id asignatura: ";
        std::cin >> id;
        IKey *k = new Integer(id);
        as = (Asignatura *)this->asignaturas->find(k);
        if(!asig->member(as))
        {
            throw std::invalid_argument("\n\e[0;31mLa asignatura ingresada no es correcta.\n\e[0m");
        }
        as = SeleccionAsignatura(id);
        ICollection *cl = new List;
        cl = as->getClasesDif();
        if(cl->isEmpty())
        {
            throw std::invalid_argument("\n\e[0;31mNo hay clases para reproducir.\n\e[0m");
        }
        i = cl->getIterator();
        Clase *c;
        std::cout <<  "Nombre       Id" << std::endl;
        while(i->hasCurrent())
        {
            c = (Clase *) i->getCurrent();
            std::cout << c->getNombre() << "            " << c->getId()<< std::endl;
            i->next();
        }
        std::cout << "\nIngrese id clase: ";
        std::cin >> id;
        c = SeleccionClase(id, as->getId());
        std::cout << "Asignatura: " << as->getNombre() << "         " << as->getId()<< std::endl;
        std::cout << "Clase: " << c->getNombre() << "           " << c->getId()<< std::endl;
        std::cout << "\nDesea confirmar? ";
        std::cout << "\n1-Si: ";
        std::cout << "\n2-No: \n";
        std::cin >> op;
        switch (op)
        {
            case 1:
            {
                Estudiante *e = new Estudiante;
                e = dynamic_cast<Estudiante *>(this->actual);
                e->setAsisDif(id, fecha);
                if(c->getMensajes()->isEmpty())
                {
                    std::cout << "\nNo tiene mensajes";
                }
                else
                {
                     ListarMensajes(c);
                }
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

Clase *Sistema::SeleccionClase(int idC, int idA)
{
    IKey *k = new Integer(idA);
    IDictionary *cl = new OrderedDictionary;
    if(!this->asignaturas->member(k))
    {
        throw std::invalid_argument("\e[0;31mLa asignatura ingresada no existe.\e[0m");
    }
    Asignatura *a;
    a = (Asignatura *)this->asignaturas->find(k);
    cl = a->getClases();
    if(cl->isEmpty())
    {
        throw std::invalid_argument("\e[0;31mLa asignatura no tiene clases.\e[0m");
    }
    IKey *j = new Integer(idC);
    if(!cl->member(j))
    {
        throw std::invalid_argument("\e[0;31mLa clase ingresada no es correcta.\e[0m");
    }
    Clase * c;
    c = (Clase *) cl->find(j);
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
        if(cl->isEmpty())
        {
            throw std::invalid_argument("\e[0;31mNo hay clases en vivo.\e[0m");
        }
        IIterator *i = cl->getIterator();
        Clase *c;
        std::cout <<  "Nombre       Id" << std::endl;
        while(i->hasCurrent())
        {
            c = (Clase *) i->getCurrent();
            std::cout << c->getNombre() << "            " << c->getId()<< std::endl;
            i->next();
        }
        std::cout << "\nIngrese id clase: ";
        std::cin >> id;
        IKey *k = new Integer(id);
        if(!cl->member(k))
        {
            throw std::invalid_argument("\e[0;31mLa opcion ingresada no es correcta.\e[0m");
        }
        std::cout << c << std::endl;
        std::cout << "\nDesea confirmar? ";
        std::cout << "\n1-Si: ";
        std::cout << "\n2-No: \n";
        std::cin >> op;
        switch (op)
        {
            case 1:
            {
                d->finalizarClase(id, this->fecha);
                ICollection *asistentes = new List;
                asistentes = ListarAsistentes(id);
                if(!asistentes->isEmpty())
                {
                    IIterator *i = asistentes->getIterator();
                    Estudiante *e;
                    while(i->hasCurrent())
                    {
                        e = (Estudiante*) i->getCurrent();
                        e->finalizarAsisOn(id, this->fecha);
                        i->next();
                    }
                }
                if(dynamic_cast<Teorico *>(c))
                {
                    Teorico *t = new Teorico;
                    t = (Teorico *) c;
                    t->setAsistentes(asistentes->getSize());
                }
                std::cout << "\nClase finalizada ";
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

void Sistema::EliminacionDeAsignatura()
{
    try
    {
        int id, op;
        ListarAsignaturas();
        Asignatura *a;
        std::cout << "\nIngrese id asignatura: ";
        std::cin >> id;
        IKey *k = new Integer(id);
        if(!this->asignaturas->member(k))
        {
            throw std::invalid_argument("\e[0;31mLa asignatura ingresada no es correcta.\e[0m");
        }
        a = SeleccionAsignatura(id);
        std::cout << "\nDesea confirmar? ";
        std::cout << "\n1-Si: ";
        std::cout << "\n2-No: \n";
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
                    e->BorrarAsignatura(a->getId());
                    i->next();
                }
                IDictionary *cl = new OrderedDictionary;
                cl = a->getClases();
                IIterator *n = cl->getIterator();
                Clase *c;
                while(n->hasCurrent())
                {
                    c = (Clase *) n->getCurrent();
                    e->BorrarAsistencias(c->getId());
                    n->next();
                }
                ICollection *docs = new List;
                docs = ListarDocentesAsignados(id);
                IIterator *j = docs->getIterator();
                Docente *d;
                while(j->hasCurrent())
                {
                    d = (Docente *) j->getCurrent();
                    d->BorrarAsignacion(a->getId(), cl);
                    std::cout << d->getAsignaturas()->getSize() << std::endl;
                    j->next();
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
    int t = 0, h = 0 ,m =0;
    try
    {
        if(this->asignaturas->isEmpty())
        {
            throw std::invalid_argument("\e[0;31mNo hay asignaturas.\e[0m");
        }
        Asignatura * a;
        Clase * c;
        IIterator *i = this->asignaturas->getIterator();
        while(i->hasCurrent())
        {
            a = (Asignatura *) i->getCurrent();
            std::cout << a->getNombre() << ":\n   ";
            if(a->getClasesDif()->isEmpty())
            {
                std::cout << "No tiene clases.\n   ";
            }
            else
            {
                IIterator *j = a->getClasesDif()->getIterator();
                while(j->hasCurrent())
                {
                    c = (Clase *) j->getCurrent();
                    t = c->TiempoDictado() + t;
                    j->next();
                }
                m = t % 60;
                h = (t - m) / 60;
                std::cout << "Tiempo Dictado:   " << h << ":" << m << " hs" << std::endl;
            }
            i->next();
        }
    }
    catch(std::out_of_range &e)
    {
        std::cerr << e.what() << std::endl;
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
        std::cout <<  "Nombre       Id" << std::endl;
        while(i->hasCurrent())
        {
            a = (Asignatura *) i->getCurrent();
            std::cout << a->getNombre() << "            " << a->getId()<< std::endl;
            i->next();
        }
        std::cout << "\nIngrese id asignatura: ";
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
        std::cout <<  "Nombre       Id" << std::endl;
        while(i->hasCurrent())
        {
            c = (Clase *) i->getCurrent();
            std::cout << c->getNombre() << "            " << c->getId()<< std::endl;
            i->next();
        }
        std::cout << "\nIngrese id clase: ";
        std::cin >> id;
        c = SeleccionClase(id, a->getId());
        if(!cl->member(c))
        {
            throw std::invalid_argument("\e[0;31mLa asignatura ingresada no es correcta.\e[0m");
        }
        std::cout << "\n" << std::endl;
        std::cout << "Asignatura: " << a->getNombre() << "        " << a->getId()<< std::endl;
        std::cout << "Clase: " << c->getNombre() << "        " << c->getId()<< std::endl;
        std::cout << "\nDesea confirmar? ";
        std::cout << "\n1-Si: ";
        std::cout << "\n2-No: \n";
        std::cin >> op;
        switch (op)
        {
            case 1:
            {
                Estudiante *e;
                e = (Estudiante *) this->actual;
                AsistenciaOnline *aO;
                aO = e->crearAsisOn(id, a->getId(), this->fecha);
                e->setAsisOn(id, aO);
                std::cout << "\nAsistencia guardada";
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

void Sistema::FinalizarAsistencia()
{
    try
    {
        int op1, op2, id;
        std::cout << "\nElija una opcion ";
        std::cout << "\n1-En vivo: ";
        std::cout << "\n2-En diferido: \n";
        std::cin >> op1;
        switch (op1)
        {
            case 1:
            {
                Estudiante *e;
                e= (Estudiante *) this->actual;
                IDictionary *aO = new OrderedDictionary;
                aO = e->getAsistenciasOn();
                IIterator *i = aO->getIterator();
                AsistenciaOnline *a;
                std::cout <<  "Id clases asistiendo en vivo:" << std::endl;
                while(i->hasCurrent())
                {
                    a = (AsistenciaOnline *) i->getCurrent();
                    std::cout << a->getIdClase()<< std::endl;
                    i->next();
                }
                std::cout << "\nIngrese id clase: ";
                std::cin >> id;
                IKey *k = new Integer(id);
                if(!aO->member(k))
                {
                     throw std::invalid_argument("\e[0;31mEl id ingresado es incorrecto.\e[0m");
                }
                a = (AsistenciaOnline* )aO->find(k);
                std::cout << "\nDesea confirmar ";
                std::cout << "\n1-Si: ";
                std::cout << "\n2-No: \n";
                std::cin >> op2;
                switch (op2)
                {
                    case 1:
                    {
                        a->setFechaFin(this->fecha);
                        std::cout << "\nAsistencia Finalizada";
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
            case 2:
            {
                Estudiante *e;
                e = (Estudiante *)this->actual;
                IDictionary *aD = new OrderedDictionary;
                aD = e->getAsistenciasDif();
                IIterator *i = aD->getIterator();
                AsistenciaDiferida *a;
                std::cout <<  "Id clases asistiendo en diferido" << std::endl;
                while(i->hasCurrent())
                {
                    a = (AsistenciaDiferida *) i->getCurrent();
                    std::cout << a->getIdClase()<< std::endl;
                    i->next();
                }
                std::cout << "\nIngrese id clase: ";
                std::cin >> id;
                IKey *k = new Integer(id);
                if(!aD->member(k))
                {
                     throw std::invalid_argument("\e[0;31mEl id ingresado es incorrecto.\e[0m");
                }
                a = (AsistenciaDiferida*) aD->find(k);
                std::cout << "\nDesea confirmar ";
                std::cout << "\n1-Si: ";
                std::cout << "\n2-No: \n";
                std::cin >> op2;
                switch (op2)
                {
                    case 1:
                    {
                        a->setFechaFin(this->fecha);
                        std::cout << "\nAsistencia finalizada";
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
        std::cout <<  asig->getSize() << std::endl;
        if(asig->isEmpty())
        {
            throw std::invalid_argument("\e[0;31mNo tiene asignaturas asignadas.\e[0m");
        }
        IIterator *i = asig->getIterator();
        Asignatura *a;
        std::cout <<  "Nombre       Id" << std::endl;
        while(i->hasCurrent())
        {
            a = (Asignatura *) i->getCurrent();
            std::cout << a->getNombre() << "            " << a->getId();
            i->next();
        }
        std::cout << "\nIngrese id asignatura: ";
        std::cin >> id;
        a = SeleccionAsignatura(id);
        if(!asig->member(a))
        {
            throw std::invalid_argument("\e[0;31mLa asignatura ingresada no es correcta.\e[0m");
        }
        ICollection *cl = new List;
        cl = ListarClasesPorAsig(a);
        if(cl->isEmpty())
        {
            throw std::invalid_argument("\e[0;31mLa asignatura no tiene clases.\e[0m");
        }
        i = cl->getIterator();
        Clase *c;
        std::cout <<  "Id        Tiempo promedio de asistencia" << std::endl;
        while(i->hasCurrent())
        {
            c = (Clase *) i->getCurrent();
            prom = PromedioAsistenciaClase(c->getId(), id);
            std::cout << c->getId() << "            " << prom <<" minutos" << std::endl;
            i->next();
        }
    }
    catch(std::out_of_range &e)
    {
        std::cout << "\nError: " << e.what() << std::endl;
        std::cout << "\n\e[0;33mVolviendo al menu principal\e[0m\n\n";
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
    IKey *k = new Integer(0);
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
    est = ListarAsistentes(idC);
    IIterator *i = est->getIterator();
    Estudiante *e;
    AsistenciaOnline *a;
    while(i->hasCurrent())
    {
        e = (Estudiante *) i->getCurrent();
        a = e->getAsistenciaOn(idC);
        t = a->TiempodeAsistencia() + t;
        i->next();
    }
    n = est->getSize();
    if(n!= 0)
    {
        t = t / n;
    }
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
        if(asig->isEmpty())
        {
            throw std::invalid_argument("\n\e[0;31mEl docente no tiene asignaturas asignadas.\n\e[0m");
        }
        IIterator *i = asig->getIterator();
        Asignatura *a;
        std::cout <<  "Nombre       Id" << std::endl;
        while(i->hasCurrent())
        {
            a = (Asignatura *) i->getCurrent();
            std::cout << a->getNombre() << "            " << a->getId();
            i->next();
        }
        std::cout << "\nIngrese id asignatura: ";
        std::cin >> id;
        a = SeleccionAsignatura(id);
        if(!asig->member(a))
        {
            throw std::invalid_argument("\e[0;31mLa asignatura ingresada no es correcta.\e[0m");
        }
        IDictionary *cl = a->getClases();
        if(cl->isEmpty())
        {
            throw std::invalid_argument("\n\e[0;31mLa asignatura no tiene clases.\n\e[0m");
        }
        Clase *c;
        i = cl->getIterator();
        Docente *d2;
        while(i->hasCurrent())
        {
            if(!c->estaEnVivo())
            {
                c = (Clase *) i->getCurrent();
                std::cout <<  c << std::endl;
                d2 = DocenteDeClase(c->getId(), id);
                std::cout << "Docente: " << d2->getNombre();
                std::cout <<  "\n" << std::endl;
//>>>>>>> 04bb59cd53392a0ddf63cdca548b584ec2f89bfc
            }
            i->next();
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
    ICollection *doc = ListarDocentesAsignados(idA);
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
            if(as->isEmpty())
            {
                throw std::invalid_argument("\e[0;31mNo esta asistiendo a ninguna clase.\e[0m");
            }
            AsistenciaOnline *aO;
            std::cout << "Id Clases" << std::endl;
            while(i->hasCurrent())
            {
                aO = (AsistenciaOnline *) i->getCurrent();
                if(aO->getFechaFin()==NULL)
                {
                    std::cout << aO->getIdClase() << std::endl;
                }
                i->next();
            }
            std::cout << "\nIngrese id clase: ";
            std::cin >> id;
            IKey *k = new Integer(id);
            if(!as->member(k))
            {
                throw std::invalid_argument("\e[0;31mLa clase ingresada no es correcta.\e[0m");
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
            if(cl->isEmpty())
            {
                throw std::invalid_argument("\e[0;31mNo esta dictando ninguna clase.\e[0m");
            }
            IIterator *i = cl->getIterator();
            std::cout << "Id Clases" << std::endl;
            while(i->hasCurrent())
            {
                c = (Clase *) i->getCurrent();
                std::cout << c->getId() << std::endl;
                i->next();
            }
            std::cout << "\nIngrese id clase: ";
            std::cin >> id;
            IKey *k = new Integer(id);
            if(!cl->member(k))
            {
                throw std::invalid_argument("\e[0;31mLa asignatura ingresada no es correcta.\e[0m");
            }
            c = (Clase *)cl->find(k);
        }
        Mensaje *m;
        if(c->getMensajes()->isEmpty())
        {
           std::cout << "No hay mensajes.";
           op = 2;
        }
        else
        {
            ListarMensajes(c);
            std::cout << "\nEs una respuesta? ";
            std::cout << "\n1-Si: ";
            std::cout << "\n2-No: \n";
            std::cin >> op;
        }
        switch (op)
        {
            case 1:
            {
                std::cout << "\nIngrese id de mensaje a responder: ";
                std::cin >> id;
                Mensaje *m2;
                m2 = SeleccionMensaje(c, id);
                std::cout << "\nIngrese mensaje: ";
                std::getline(std::cin >> std::ws, msj);
                m = c->crearRespuesta(msj, m2, this->fecha);
                break;
            }
            case 2:
            {
                std::cout << "\nIngrese mensaje: ";
                std::getline(std::cin >> std::ws, msj);
                m = c->crearMensaje(msj, this->fecha);
                break;
            }
            default:
                throw std::invalid_argument("\e[0;31mLa opcion ingresada no es correcta.\e[0m");
                break;
        }
        std::cout << "\nDesea confirmar? ";
        std::cout << "\n1-Si: ";
        std::cout << "\n2-No: \n";
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
                delete m;
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
    std::cout << "Mensaje      Id" << std::endl;
    while(i->hasCurrent())
    {
        m = (Mensaje*) i->getCurrent();
        std::cout << m->getContenido() <<"          " << m->getId() << std::endl;
        if(m->esRespuesta())
        {
            std::cout << "Respuesta a: " << m->getRespuesta()->getContenido() << std::endl;
        }
        std::cout << "----------------------" << std::endl;
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

ICollection *Sistema::ListarAsistentes(int idC)
{
    ICollection *asis = new List;
    //Estudiante *e;
    Usuario *u;
    IIterator *i = this->usuarios->getIterator();
    while(i->hasCurrent())
    {
        u = (Usuario *) i->getCurrent();
        if(dynamic_cast<Estudiante *>(u))
        {
            Estudiante *e = new Estudiante;
            e = dynamic_cast<Estudiante *>(u);
            if(e->Asistio(idC))
            {
                asis->add(e);
            }
        }
        i->next();
    }
    return asis;
}



void Sistema::ModificarFechaSistema()
{
    try
    {
        int a, m, d, h, mi, s;
        std::cout << "\nIngrese año: ";
        std::cin >> a;
        if(a<2000 || a>2100)
        {
            throw std::invalid_argument("\e[0;31mEl año ingresado es incorrecto.\e[0m");
        }
        std::cout << "\nIngrese mes: ";
        std::cin >> m;
        if(m>12 || m<1)
        {
            throw std::invalid_argument("\e[0;31mEl mes ingresado es incorrecto.\e[0m");
        }
        std::cout << "\nIngrese dia: ";
        std::cin >> d;
        if(d>31 || d<1)
        {
            throw std::invalid_argument("\e[0;31mEl dia ingresado es incorrecto.\e[0m");
        }
        std::cout << "\nIngrese hora(Formato 24hs): ";
        std::cin >> h;
        if(h>24 || h<1)
        {
            throw std::invalid_argument("\e[0;31mLa hora ingresada es incorrecta.\e[0m");
        }
        std::cout << "\nIngrese minutos: ";
        std::cin >> mi;
        if(mi>59 || mi<0)
        {
            throw std::invalid_argument("\e[0;31mLos minutos ingresados son incorrectos.\e[0m");
        }
        std::cout << "\nIngrese segundos: ";
        std::cin >> s;
        if(s>59 || s<0)
        {
            throw std::invalid_argument("\e[0;31mLos segundos ingresados son incorrectos.\e[0m");
        }
         this->fecha = new DtFecha(d, m, a, s, mi, h);
    }
    catch(std::out_of_range &e)
    {
        std::cout << "\nError: " << e.what() << std::endl;
        std::cout << "\n\e[0;33mVolviendo al menu principal\e[0m\n\n";
    }
}

void Sistema::ConsultarFechaSistema()
{
    std::cout << this->fecha->getAnio() << "/" << this->fecha->getMes() << "/" << this->fecha->getDia() << std::endl;
	std::cout << this->fecha->getHora() << ":" << this->fecha->getMinuto() << ":" << this->fecha->getSegundo() << std::endl;
}

void Sistema::imprimirTextoPrincipal()
{
    std::cout << "\e[0;92mBienvenido -" << " Elija una opción\e[0m:";
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
    std::cout << "\e[0;92m6)\e[0m Modificar fecha del sistema.\n";
    std::cout << "\e[0;92m7)\e[0m Consultar fecha del sistema.\n";
    std::cout << "Pulse \e[0;92m8\e[0m para salir.\n\nOpcion: \e[0;92m";
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
