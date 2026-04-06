/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

int main() {
    float num1, num2;

    cout << "Ingresa el primer valor: ";
    cin >> num1;

    cout << "Ingresa el segundo valor: ";
    cin >> num2;

    cout << "\nResultados:\n";

    cout << "Suma: " << num1 + num2 << endl;
    cout << "Resta: " << num1 - num2 << endl;
    cout << "Multiplicacion: " << num1 * num2 << endl;

    if (num2 != 0) {
        cout << "Division: " << num1 / num2 << endl;
    } else {
        cout << "Division: No se puede dividir entre cero" << endl;
    }

    return 0;
}