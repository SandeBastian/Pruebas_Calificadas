/*
La Sucesión de Collatz (o conjetura 3n+1) para un número “n”, es una secuencia de números definida por las siguientes reglas: si el
número es par, se divide por 2; si es impar, se multiplica por 3 y se le suma 1. Esta secuencia continúa hasta que el número llega a 1.
Ejemplo, de la secuencia para 6 es: 6, 3, 10, 5, 16, 8, 4, 2, 1 (longitud 9). Elabore un programa en C++ que pida al usuario un número
entero positivo. El programa debe implementar una función llamada SucesionCollatzMasLarga que, para todos los números desde 1 hasta
el número ingresado por el usuario, calcule la longitud de su Sucesión de Collatz.
La función SucesionCollatzMasLarga debe devolver el número (dentro del rango dado) que produce la secuencia de Collatz más larga,
junto con la longitud de esa secuencia. El programa principal debe mostrar este número y su longitud.

Ejemplo: Si a la función se le ingresa 4, la función calculara las sucesiones para:

Número: 1, Longitud de la secuencia: 1 (1)
Número: 2, Longitud de la secuencia: 2 (2 -> 1)
Número: 3, Longitud de la secuencia: 8 (3 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1)
Número: 4, Longitud de la secuencia: 3 (4 -> 2 -> 1)

La función devolverá: número que genera la sucesión más larga: 3; longitud de la sucesión 8.
El programa principal imprimirá estos valores.
*/
#include <iostream>
using namespace std;

int SucesionCollatzMasLarga(int n, int &mLargo) {
    int mayor=1;
    int largo=1;
    mLargo=1;
    for (int i = 1; i <= n; i++) {
        int aux = i;
        largo=1;
        while (aux!=1) {
            if (aux%2==0) {
                aux=aux/2;
                largo++;
            }
            else {
                aux=aux*3+1;
                largo++;
            }
        }
        if (mLargo<largo) {
            mLargo=largo;
            mayor=i;
        }
    }
    return mayor;
}

int main () {
    int n;
    int mLargo;
    cout<<"Ingresa el Numero: ";
    cin>>n;
    cout<<"El numero que genera la sucesion mas larga es: "<<SucesionCollatzMasLarga(n, mLargo)<<endl;
    cout<<"y su longitud de la sucesion es: "<<mLargo<<endl;
    return 0;
}