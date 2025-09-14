/*
PRUEBA DE ENTRADA 2024-II
Pregunta 1 (de 8:00 a 8:30 am) 1.5 puntos
Crear un programa que lea un conjunto de N (N>3) números enteros positivos y luego indique cuántos de ellos son capicúa.
Por ejemplo:
N=5
Se ingresan los números: 12, 121, 2332, 413, 22
El total de números capicúa es: 3
Nota: No puede emplear arreglos, ni cadenas.
*/
#include <iostream>
using namespace std;
int main() {
    int n,num, aux=0, r=0, inv, cont=0;
    do {
        cout<<"Ingrese la cantidad de numeros (n>3): ";
        cin>>n;
    }while (n<=3);
    for (int i=0; i<n; i++) {
        cout<<"Ingrese el numero ("<<i+1<<"): ";
        cin>>num;
        aux=num;
        inv=0;
        while (aux>0) {
            r=aux%10;
            aux=aux/10;
            inv=inv*10+r;
        }
        if (inv==num) {
            cont++;
        }
    }
    cout<<"Total de numeros capicuas: "<<cont<<endl;
    return 0;
}
