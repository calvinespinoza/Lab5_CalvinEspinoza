Main:	Main.o Funcion.o
	g++ Main.o Funcion.o -o Main

Main.o:	Funcion.h Main.cpp
	g++ -c Main.cpp

Funcion.o:	Funcion.cpp Funcion.h
	g++ -c Funcion.cpp

clean:
	rm *.o Main
