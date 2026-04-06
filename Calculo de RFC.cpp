/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Persona {
private:
    string nombreCompleto, apellidoPaterno, apellidoMaterno, fechaNacimiento;

    // Convertir a mayúsculas
    string mayusculas(string texto) {
        transform(texto.begin(), texto.end(), texto.begin(), ::toupper);
        return texto;
    }

    // Obtener primer nombre válido (ignora JOSE y MARIA)
    string obtenerPrimerNombre() {
        string palabra = "", nombreValido = "";

        for (int i = 0; i < nombreCompleto.length(); i++) {
            if (nombreCompleto[i] == ' ') {
                if (palabra != "JOSE" && palabra != "MARIA")
                    return palabra;
                palabra = "";
            } else {
                palabra += nombreCompleto[i];
            }
        }
        return palabra; // último nombre
    }

    // Buscar vocal interna
    char obtenerVocalInterna(string apellido) {
        for (int i = 1; i < apellido.length(); i++) {
            char c = apellido[i];
            if (c=='A'||c=='E'||c=='I'||c=='O'||c=='U') {
                return c;
            }
        }
        return 'X';
    }

    // Evitar palabras inconvenientes
    string validarPalabra(string rfc) {
        string malas[] = {"BUEI","PUTO","CACA","LOCO"};
        for (string palabra : malas) {
            if (rfc == palabra) {
                rfc[3] = 'X';
            }
        }
        return rfc;
    }

public:
    void capturarDatos() {
        cout << "Nombre(s): ";
        getline(cin, nombreCompleto);

        cout << "Apellido paterno: ";
        getline(cin, apellidoPaterno);

        cout << "Apellido materno (X si no tiene): ";
        getline(cin, apellidoMaterno);

        cout << "Fecha (DD/MM/AAAA): ";
        getline(cin, fechaNacimiento);

        // Convertir a mayúsculas
        nombreCompleto = mayusculas(nombreCompleto);
        apellidoPaterno = mayusculas(apellidoPaterno);
        apellidoMaterno = mayusculas(apellidoMaterno);
    }

    string generarRFC() {
        string rfc = "";

        string nombre = obtenerPrimerNombre();

        // 1 y 2
        rfc += apellidoPaterno[0];
        rfc += obtenerVocalInterna(apellidoPaterno);

        // 3
        if (apellidoMaterno == "" || apellidoMaterno == "X")
            rfc += 'X';
        else
            rfc += apellidoMaterno[0];

        // 4
        rfc += nombre[0];

        // Validar palabra
        rfc = validarPalabra(rfc);

        // Fecha
        string dia = fechaNacimiento.substr(0,2);
        string mes = fechaNacimiento.substr(3,2);
        string anio = fechaNacimiento.substr(8,2);

        rfc += anio + mes + dia;

        return rfc;
    }
};

int main() {
    Persona p;

    p.capturarDatos();

    cout << "\nRFC generado (sin homoclave): " << p.generarRFC() << endl;

    return 0;
}