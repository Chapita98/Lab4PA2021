OBJETOS = Arribo.o Barco.o BarcoPasajeros.o BarcoPesquero.o Puerto.o \
DtArribo.o DtBarco.o DtBarcoPasajeros.o DtBarcoPesquero.o DtFecha.o DtPuerto.o \
metodos.o main.o

DEF = ./classes/headers/Puerto.h  ./classes/headers/Arribo.h  ./classes/headers/Barco.h  ./classes/headers/BarcoPasajeros.h  ./classes/headers/BarcoPesquero.h  ./classes/headers/TipoTamanio.h ./datatypes/headers/DtArribo.h  ./datatypes/headers/DtBarco.h  ./datatypes/headers/DtBarcoPasajeros.h  ./datatypes/headers/DtBarcoPesquero.h  ./datatypes/headers/DtFecha.h  ./datatypes/headers/DtPuerto.h

CC = g++
OPCIONES = -c -Wall

all: Lab4PA2021

Lab4PA2021: $(OBJETOS)
	$(CC) $(OBJETOS) -o Lab4PA2021

main.o: main.cpp Makefile ./metodosMain/definiciones.h $( ./datatypes/headers/)
	$(CC) $(OPCIONES) main.cpp

metodos.o: ./metodosMain/definiciones.h ./metodosMain/metodos.cpp
	$(CC) $(OPCIONES) ./metodosMain/metodos.cpp

DtFecha.o: ./datatypes/headers/DtFecha.h ./datatypes/sources/DtFecha.cpp
	$(CC) $(OPCIONES) ./datatypes/sources/DtFecha.cpp

DtPuerto.o: ./datatypes/headers/DtPuerto.h ./datatypes/sources/DtPuerto.cpp
	$(CC) $(OPCIONES) ./datatypes/sources/DtPuerto.cpp

DtBarco.o: ./datatypes/headers/DtBarco.h ./datatypes/sources/DtBarco.cpp
	$(CC) $(OPCIONES) ./datatypes/sources/DtBarco.cpp

DtArribo.o: ./datatypes/headers/DtArribo.h ./datatypes/sources/DtArribo.cpp
	$(CC) $(OPCIONES) ./datatypes/sources/DtArribo.cpp

DtBarcoPasajeros.o: ./datatypes/headers/DtBarcoPasajeros.h ./datatypes/sources/DtBarcoPasajeros.cpp
	$(CC) $(OPCIONES) ./datatypes/sources/DtBarcoPasajeros.cpp

DtBarcoPesquero.o: ./datatypes/headers/DtBarcoPesquero.h ./datatypes/sources/DtBarcoPesquero.cpp
	$(CC) $(OPCIONES) ./datatypes/sources/DtBarcoPesquero.cpp

Barco.o: ./classes/headers/Barco.h ./classes/sources/Barco.cpp
	$(CC) $(OPCIONES) ./classes/sources/Barco.cpp

Arribo.o: ./classes/headers/Arribo.h ./classes/sources/Arribo.cpp
	$(CC) $(OPCIONES) ./classes/sources/Arribo.cpp

Puerto.o: ./classes/headers/Puerto.h ./classes/sources/Puerto.cpp
	$(CC) $(OPCIONES) ./classes/sources/Puerto.cpp

BarcoPasajeros.o: ./classes/headers/BarcoPasajeros.h ./classes/sources/BarcoPasajeros.cpp ./classes/headers/TipoTamanio.h
	$(CC) $(OPCIONES) ./classes/sources/BarcoPasajeros.cpp

BarcoPesquero.o: ./classes/headers/BarcoPesquero.h ./classes/sources/BarcoPesquero.cpp
	$(CC) $(OPCIONES) ./classes/sources/BarcoPesquero.cpp


clean:
	rm -rf *o Lab4PA2021

rebuild:
	make clean
	make