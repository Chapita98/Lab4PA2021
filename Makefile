OBJETOS = Asignacion.o Asignatura.o AsistenciaDiferida.o AsistenciaOnline.o Clase.o \
Usuario.o Docente.o Estudiante.o Monitoreo.o Practico.o Sistema.o Teorico.o \
DtClase.o DtFecha.o DtMonitoreo.o DtPractico.o DtTeorico.o main.o \
List.o ListIterator.o ListNode.o OrderedDictionary.o OrderedDictionaryEntry.o \
ICollectible.o ICollection.o IDictionary.o IIterator.o IKey.o Integer.o String.o 

DEF = ./classes/headers/Clase.h ./classes/headers/Asignacion.h ./classes/headers/Asignatura.h ./classes/headers/AsistenciaDiferida.h \
./classes/headers/AsistenciaOnline.h ./classes/headers/Tipo.h ./classes/headers/Usuario.h ./classes/headers/Docente.h \
./classes/headers/Estudiante.h ./classes/headers/Monitoreo.h ./classes/headers/Practico.h ./classes/headers/Sistema.h ./classes/headers/ISistema.h \
./ICollection/collections/List.h ./ICollection/collections/ListIterator.h ./ICollection/collections/ListNode.h \
./ICollection/collections/OrderedDictionary.h ./ICollection/collections/OrderedDictionaryEntry.h \
./ICollection/interfaces/ICollectible.h ./ICollection/interfaces/ICollection.h ./ICollection/interfaces/IDictionary.h \
./ICollection/interfaces/IIterator.h ./ICollection/interfaces/IKey.h ./ICollection/Integer.h ./ICollection/String.h 

CC = g++
OPCIONES = -c -Wall

all: Lab4PA2021

Lab4PA2021: $(OBJETOS)
	$(CC) $(OBJETOS) -o Lab4PA2021

main.o: main.cpp Makefile ./classes/headers/ISistema.h $( ./classes/headers/)
	$(CC) $(OPCIONES) main.cpp

Practico.o: ./classes/headers/Practico.h ./classes/sources/Practico.cpp
	$(CC) $(OPCIONES) ./classes/sources/Practico.cpp

Teorico.o: ./classes/headers/Teorico.h ./classes/sources/Teorico.cpp
	$(CC) $(OPCIONES) ./classes/sources/Teorico.cpp

Sistema.o: ./classes/headers/Sistema.h ./classes/sources/Sistema.cpp ./classes/headers/ISistema.h
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

Asignacion.o: ./classes/headers/Asignacion.h ./classes/sources/Asignacion.cpp ./classes/headers/Tipo.h
	$(CC) $(OPCIONES) ./classes/sources/Asignacion.cpp

Clase.o: ./classes/headers/Clase.h ./classes/sources/Clase.cpp
	$(CC) $(OPCIONES) ./classes/sources/Clase.cpp

AsistenciaDiferida.o: ./classes/headers/AsistenciaDiferida.h ./classes/sources/AsistenciaDiferida.cpp
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

List.o: ./ICollection/collections/List.h ./ICollection/collections/List.cpp
	$(CC) $(OPCIONES) ./ICollection/collections/List.cpp

ListIterator.o: ./ICollection/collections/ListIterator.h ./ICollection/collections/ListIterator.cpp
	$(CC) $(OPCIONES) ./ICollection/collections/ListIterator.cpp

ListNode.o: ./ICollection/collections/ListNode.h ./ICollection/collections/ListNode.cpp
	$(CC) $(OPCIONES) ./ICollection/collections/ListNode.cpp

OrderedDictionary.o: ./ICollection/collections/OrderedDictionary.h ./ICollection/collections/OrderedDictionary.cpp
	$(CC) $(OPCIONES) ./ICollection/collections/OrderedDictionary.cpp

OrderedDictionaryEntry.o: ./ICollection/collections/OrderedDictionaryEntry.h ./ICollection/collections/OrderedDictionaryEntry.cpp
	$(CC) $(OPCIONES) ./ICollection/collections/OrderedDictionaryEntry.cpp

ICollectible.o: ./ICollection/interfaces/ICollectible.h ./ICollection/interfaces/ICollectible.cpp
	$(CC) $(OPCIONES) ./ICollection/interfaces/ICollectible.cpp

ICollection.o: ./ICollection/interfaces/ICollection.h ./ICollection/interfaces/ICollection.cpp
	$(CC) $(OPCIONES) ./ICollection/interfaces/ICollection.cpp

IDictionary.o: ./ICollection/interfaces/IDictionary.h ./ICollection/interfaces/IDictionary.cpp
	$(CC) $(OPCIONES) ./ICollection/interfaces/IDictionary.cpp

IIterator.o: ./ICollection/interfaces/IIterator.h ./ICollection/interfaces/IIterator.cpp
	$(CC) $(OPCIONES) ./ICollection/interfaces/IIterator.cpp

IKey.o: ./ICollection/interfaces/IKey.h ./ICollection/interfaces/IKey.cpp
	$(CC) $(OPCIONES) ./ICollection/interfaces/IKey.cpp

Integer.o: ./ICollection/Integer.h ./ICollection/Integer.cpp
	$(CC) $(OPCIONES) ./ICollection/Integer.cpp

String.o: ./ICollection/String.h ./ICollection/String.cpp
	$(CC) $(OPCIONES) ./ICollection/String.cpp

clean:
	rm -rf *o Lab4PA2021

rebuild:
	make clean
	make