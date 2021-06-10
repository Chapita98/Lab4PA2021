OBJETOS = Asignacion.o Asignatura.o AsistenciaDiferida.o AsistenciaOnline.o Clase.o \
Usuario.o Docente.o Estudiante.o Monitoreo.o Practico.o Sistema.o Teorico.o Tipo.o\
DtClase.o DtFecha.o DtMonitoreo.o DtPractico.o DtTeorico.o \
menus.o metodos.o main.o

DEF = ./classes/headers/Clase.h  ./classes/headers/Asignacion.h  ./classes/headers/Asignatura.h  ./classes/headers/AsistenciaDiferida.h  \
./classes/headers/AsistenciaOnline.h  ./classes/headers/Tipo.h ./classes/headers/Usuario.h  ./classes/headers/Docente.h  \
./classes/headers/Estudiante.h  ./classes/headers/Monitoreo.h  ./classes/headers/Practico.h  ./classes/headers/Sistema.h

CC = g++
OPCIONES = -c -Wall

all: Lab4PA2021

Lab4PA2021: $(OBJETOS)
	$(CC) $(OBJETOS) -o Lab4PA2021

main.o: main.cpp Makefile ./metodosMain/definiciones.h $( ./classes/headers/)
	$(CC) $(OPCIONES) main.cpp

menus.o: ./metodosMain/definiciones.h ./metodosMain/menus.cpp
	$(CC) $(OPCIONES) ./metodosMain/menus.cpp

metodos.o: ./metodosMain/definiciones.h ./metodosMain/metodos.cpp
	$(CC) $(OPCIONES) ./metodosMain/metodos.cpp

Practico.o: ./classes/headers/Practico.h ./classes/sources/Practico.cpp
	$(CC) $(OPCIONES) ./classes/sources/Practico.cpp

Teorico.o: ./classes/headers/Teorico.h ./classes/sources/Teorico.cpp
	$(CC) $(OPCIONES) ./classes/sources/Teorico.cpp

Tipo.o: ./classes/headers/Tipo.h ./classes/sources/Tipo.cpp
	$(CC) $(OPCIONES) ./classes/sources/Tipo.cpp

Sistema.o: ./classes/headers/Sistema.h ./classes/sources/Sistema.cpp
	$(CC) $(OPCIONES) ./classes/sources/Sistema.cpp

Docente.o: ./classes/headers/Docente.h ./classes/sources/Docente.cpp
	$(CC) $(OPCIONES) ./classes/sources/Docente.cpp

Usuario.o: ./classes/headers/Usuario.h ./classes/sources/Usuario.cpp
	$(CC) $(OPCIONES) ./classes/sources/Usuario.cpp

Estudiante.o: ./classes/headers/Estudiante.h ./classes/sources/Estudiante.cpp
	$(CC) $(OPCIONES) ./classes/sources/Estudiante.cpp

Monitoreo.o: ./classes/headers/Monitoreo.h ./classes/sources/Monitoreo.cpp
	$(CC) $(OPCIONES) ./classes/sources/Monitoreo.cpp

Asignatura.o: ./classes/headers/Asignatura.h ./classes/sources/Asignatura.cpp
	$(CC) $(OPCIONES) ./classes/sources/Asignatura.cpp

Asignacion.o: ./classes/headers/Asignacion.h ./classes/sources/Asignacion.cpp
	$(CC) $(OPCIONES) ./classes/sources/Asignacion.cpp

Clase.o: ./classes/headers/Clase.h ./classes/sources/Clase.cpp
	$(CC) $(OPCIONES) ./classes/sources/Clase.cpp

AsistenciaDiferida.o: ./classes/headers/AsistenciaDiferida.h ./classes/sources/AsistenciaDiferida.cpp ./classes/headers/Tipo.h
	$(CC) $(OPCIONES) ./classes/sources/AsistenciaDiferida.cpp

AsistenciaOnline.o: ./classes/headers/AsistenciaOnline.h ./classes/sources/AsistenciaOnline.cpp
	$(CC) $(OPCIONES) ./classes/sources/AsistenciaOnline.cpp

DtClase.o: ./datatypes/headers/DtClase.h ./datatypes/sources/DtClase.cpp
	$(CC) $(OPCIONES) ./datatypes/sources/DtClase.cpp

DtFecha.o: ./datatypes/headers/DtFecha.h ./datatypes/sources/DtFecha.cpp
	$(CC) $(OPCIONES) ./datatypes/sources/DtFecha.cpp

DtMonitoreo.o: ./datatypes/headers/DtMonitoreo.h ./datatypes/sources/DtMonitoreo.cpp
	$(CC) $(OPCIONES) ./datatypes/sources/DtMonitoreo.cpp
	
DtPractico.o: ./datatypes/headers/DtPractico.h ./datatypes/sources/DtPractico.cpp
	$(CC) $(OPCIONES) ./datatypes/sources/DtPractico.cpp

DtTeorico.o: ./datatypes/headers/DtTeorico.h ./datatypes/sources/DtTeorico.cpp
	$(CC) $(OPCIONES) ./datatypes/sources/DtTeorico.cpp


clean:
	rm -rf *o Lab4PA2021

rebuild:
	make clean
	make