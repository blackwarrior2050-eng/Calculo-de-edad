/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

int main() {
    string nombre;
    int edad;

    cout << "Ingresa tu nombre: ";
    cin >> nombre;

    cout << "Ingresa tu edad: ";
    cin >> edad;

    if (edad >= 18) {
        cout << "Bienvenido " << nombre << ", eres mayor de edad" << endl;
    } else {
        cout << "Bienvenido " << nombre << ", eres menor de edad" << endl;
    }

    return 0;
}
