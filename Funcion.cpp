#include "Funcion.h"

using namespace std;

Funcion::Funcion()
{
        grado = 0;
        coeficientes = new int[grado+1];
        for (int i = 0; i < grado + 1; i++) {
                coeficientes[i]= 0;
        }
}

Funcion::Funcion(int degree,int* coefficients)
{
        grado = degree;
        coeficientes = new int[grado+1];
        for (int i = 0; i < grado + 1; i++) {
                coeficientes[i] = coefficients[i];
        }
}

int Funcion::getGrado()
{
        return grado;
}

void Funcion::setGrado(int num)
{
        grado = num;
}

int Funcion::getCoeficiente(int index)
{
        return coeficientes[index];
}

void Funcion::setCoeficiente(int num, int index)
{
        coeficientes[index] = num;
}

ostream& operator<<(ostream& out, Funcion r){
    out << r.toString();
    return out;
}

Funcion Funcion::operator+ (Funcion op) {
        Funcion retval;
        int size;
        if(op.getGrado() > this -> grado)
        {
                size = op.getGrado();
        } else {
                size = grado;
        }
        retval.setGrado(size);
        for (int i = 0; i < size+1; i++) {
                if (i <= op.getGrado() || i <= this -> grado)
                {
                        retval.setCoeficiente(this -> coeficientes[i] + op.getCoeficiente(i),i);
                } else if (i > op.getGrado()){
                        retval.setCoeficiente(coeficientes[i],i);
                } else {
                        retval.setCoeficiente(op.getCoeficiente(i),i);
                }
        }
	return retval;
}

Funcion Funcion::operator- (Funcion op) {
        Funcion retval;
        int size;
        if(op.getGrado() > this -> grado)
        {
                size = op.getGrado();
        } else {
                size = grado;
        }
        retval.setGrado(size);
        for (int i = 0; i < size+1; i++) {
                if (i <= op.getGrado() || i <= this -> grado)
                {
                        retval.setCoeficiente(this -> coeficientes[i] - op.getCoeficiente(i),i);
                } else if (i > op.getGrado()){
                        retval.setCoeficiente(coeficientes[i],i);
                } else {
                        retval.setCoeficiente(op.getCoeficiente(i),i);
                }
        }
	return retval;
}

/*
Funcion Funcion::operator* (Funcion op) {
	Funcion retval(op.value * this -> value);
	return retval;
}

Funcion Funcion::operator/ (Funcion op) {
	Funcion retval(op.value / this -> value);
	return retval;

}*/
string Funcion::operator== (Funcion op)
{
        bool verif = false;
        if (op.getGrado() != this -> grado)
        {
                return "No son iguales";
        }
        else
        {
                for (int i = 0; i < this -> grado; i++) {
                        if (op.getCoeficiente(i) == this -> coeficientes[i])
                        {
                                verif = true;

                        }
                        else {
                                return "No son iguales";
                        }
                }
        }
        if(verif)
        {
                return "Si son iguales";
        }
}

string Funcion::operator!= (Funcion op)
{
        bool verif = false;
        if (op.getGrado() != this -> grado)
        {
                return "Si son diferentes";
        }
        else
        {
                for (int i = 0; i < this -> grado; i++) {
                        if (op.getCoeficiente(i) == this -> coeficientes[i])
                        {
                                verif = true;

                        }
                        else {
                                return "Si son diferentes";
                        }
                }
        }
        if(verif)
        {
                return "No son diferentes";
        }
}


int Funcion::operator++ ()
{
        int value = 1;
        int retval = 1;
        int cont = 0;
        int c = 0;
        for (int value = 0; value < 10; value++) {
                for (int i = 0; i < this -> grado; i++) {
                        this -> coeficientes[i];
                        if (c%value == 0) {
                                cont++;
                        }
                        if (cont == grado){
                                retval = value;
                        }
                }
        }
        return retval;
}

string Funcion::toString()const {
	stringstream ss;
	for (int i = grado; i >= 0; i--) {
                if (i == 0){
                        ss << coeficientes[i];
                } else {
                        ss << coeficientes[i] <<"x^" << i << " + ";
                }
	}
	return ss.str();
}
