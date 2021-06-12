#include "./../headers/Sistema.h"
Sistema::Sistema() {}

void menuCaso1()
{
    int opcionUsuario;
    bool bandera = true;
    while (bandera == true)
    {
        imprimirMenuAdministrador();
        std::cin >> opcionUsuario;
        std::cout << "\e[0m";
        std::cin.clear();
        try
        {
            switch (opcionUsuario)
            {
                case 1: //Alta de usuario
                {
                    AltaDeUsuario();
                    break;
                }
                case 2: //Alta de asignatura
                {
                    AltaDeAsignatura();
                    break;
                }
                case 3: //Asignación de docentes a una asignatura
                {
                    AsignaciónDeDocentesAUnaAsignatura();
                    break;
                }
                case 4: //Eliminación de asignatura
                {
                    EliminaciónDeAsignatura();
                    break;
                }
                case 5: //Tiempo de dictado de clases
                {
                    TiempoDeDictadoDeClases();
                    break;
                }
                case 6: //Tiempo de dictado de clases
                {
                    ConfiguracionRelojInterno();
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
            std::cerr << e.what() << endl;
        }
    }
}

void menuCaso2()
{
    int opcionUsuario;
    bool bandera = true;
    while (bandera == true)
    {
        imprimirMenuDocente();
        std::cin >> opcionUsuario;
        std::cout << "\e[0m";
        std::cin.clear();
        try
        {
            switch (opcionUsuario)
            {
                case 1: //Inicio de clase
                {
                    InicioDeClase();
                    break;
                }
                case 2: //Finalización de clase
                {
                    FinalizaciónDeClase();
                    break;
                }
                case 3: //Tiempo de asistencia a clase
                {
                    TiempoDeAsistenciaAClase();
                    break;
                }
                case 4: //Listado de Clases
                {
                    ListadoDeClases();
                    break;
                }
                case 5: //Tiempo de dictado de clases
                {
                    EnvíoDeMensaje();
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
            std::cerr << e.what() << endl;
        }
    }
}
void menuCaso3()
{
    int opcionUsuario;
    bool bandera = true;
    while (bandera == true)
    {
        imprimirMenuEstudiante();
        std::cin >> opcionUsuario;
        std::cout << "\e[0m";
        std::cin.clear();
        try
        {
            switch (opcionUsuario)
            {
                case 1: //Envío de mensaje
                {
                    EnvíoDeMensaje();
                    break;
                }
                case 2: //Inscripción a las asignaturas
                {
                    InscripciónALasAsignaturas();
                    break;
                }
                case 3: //Asistencia a clase en vivo
                {
                    AsistenciaAClaseEnVivo();
                    break;
                }
                case 4: //Reproduccion en diferido
                {
                    ReproduccionEnDiferido();
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
            std::cerr << e.what() << endl;
        }
    }
}
void menuCaso4()
{
    // INGRESO DATOS DE PRUEBA
}


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
