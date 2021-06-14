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
