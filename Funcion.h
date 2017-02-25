#pragma once
#include <sstream>
#include <string>
#include <iostream>

using std::stringstream;
using std::ostream;
using std::string;


class Funcion {
        friend ostream& operator<<(ostream& out, Funcion r);
        private:
                int grado;
                int* coeficientes;

        public:
                Funcion();
                Funcion(int, int*);

                int getGrado();
                void setGrado(int);

                int getCoeficiente(int);
                void setCoeficiente(int,int);

                Funcion operator+(Funcion);
                Funcion operator-(Funcion);
        	Funcion operator*(Funcion);
        	Funcion operator/(Funcion);
                string operator==(Funcion);
                string operator!=(Funcion);
                //string operator++(Funcion);

                string toString()const;
};
