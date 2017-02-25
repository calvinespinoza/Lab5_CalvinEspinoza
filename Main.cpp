#include <iostream>
#include "Funcion.h"
#include <vector>

using namespace std;

void imprimirVector(vector<Funcion>);

int main()
{
        char resp = 'Y';
        int opcion = 0;
        vector<Funcion> funciones;
        vector<Funcion> respuestas;
        while (resp == 'Y') {
                opcion = 0;
                cout << endl;
                cout << "MENU" << endl;
                cout << "1. Crear Funcion"<< endl;
                cout << "2. Sumar Funciones"<< endl;
                cout << "3. Restar Funciones"<< endl;
                cout << "4. Multiplicar Funciones"<< endl;
                cout << "5. Dividir Funciones"<< endl;
                cout << "6. Sacar Factor Comun"<< endl;
                cout << "7. Evaluar Iguales"<< endl;
                cout << "8. Evaluar Diferentes"<< endl;
                cout << "9. Flujo de Salida"<< endl;
                cout << "10. Salir" << endl;
                cout << "Ingrese su opcion: " << endl;
                cin >> opcion;

                if (opcion == 1)
                {
                        int grado;

                        cout << "Ingresar el grado de la funcion: " << endl;
                        cin >> grado;

                        int* coeficientes = new int[grado+1];
                        int value = 0;

                        for (int i = grado; i >= 0; i--) {
                                cout << "x^ " << i << ": ";
                                cin >> value;
                                coeficientes[i] = value;
                        }
                        Funcion f = Funcion(grado, coeficientes);
                        cout << f.getCoeficiente(0);
                        funciones.push_back(f);

                }
                else if (opcion == 2)
                {
                        int option1 = 0, option2 = 0;
                        imprimirVector(funciones);
                        cout << "Ingrese su primera opcion: " << endl;
                        cin >> option1;

                        Funcion f1 = funciones.at(option1-1);

                        imprimirVector(funciones);
                        cout << "Ingrese su segunda opcion: " << endl;
                        cin >> option2;

                        Funcion f2 = funciones.at(option2-1);

                        Funcion f3 = f1+ f2;
                        cout << f3 << endl;
                        respuestas.push_back(f3);
                }
                else if (opcion == 3)
                {
                        int option1 = 0, option2 = 0;
                        imprimirVector(funciones);
                        cout << "Ingrese su primera opcion: " << endl;
                        cin >> option1;

                        Funcion f1 = funciones.at(option1-1);

                        imprimirVector(funciones);
                        cout << "Ingrese su segunda opcion: " << endl;
                        cin >> option2;

                        Funcion f2 = funciones.at(option2-1);

                        Funcion f3 = f1 - f2;
                        cout << f3 << endl;
                        respuestas.push_back(f3);
                }
                else if (opcion == 7)
                {
                        int option1 = 0, option2 = 0;
                        imprimirVector(funciones);
                        cout << "Ingrese su primera opcion: " << endl;
                        cin >> option1;

                        Funcion f1 = funciones.at(option1-1);

                        imprimirVector(funciones);
                        cout << "Ingrese su segunda opcion: " << endl;
                        cin >> option2;

                        Funcion f2 = funciones.at(option2-1);

                        string str = f1 == f2;
                        cout << str;
                        cout << endl;

                }
                else if (opcion == 8)
                {
                        int option1 = 0, option2 = 0;
                        imprimirVector(funciones);
                        cout << "Ingrese su primera opcion: " << endl;
                        cin >> option1;

                        Funcion f1 = funciones.at(option1-1);

                        imprimirVector(funciones);
                        cout << "Ingrese su segunda opcion: " << endl;
                        cin >> option2;

                        Funcion f2 = funciones.at(option2-1);

                        string str = f1 != f2;
                        cout << str;
                        cout << endl;

                }
                else if (opcion == 9)
                {
                        imprimirVector(funciones);
                }

                else if (opcion == 10)
                {
                        return 0;
                }





                }
        return 0;
}


void imprimirVector(vector <Funcion> function)
{
        for (int j = 0; j < function.size(); j++) {
                cout << j+1 << ") " << function.at(j) << endl;
        }
}
