/*
PRUEBA DE ENTRADA 2024-I
Pregunta 2 (de 8:32 a 9:02 am) 1.5 puntos
Crear un programa que reciba un número entero positivo N (donde N >1000), luego presente el número modificado de
tal forma que se eliminado de dicho número el mayor dígito. Si no hay un dígito mayor, el número no se modifica.
Ejemplo:
Se ingresa N = 17317
El mayor dígito: 7
Número modificado: 131
Nota: No puede emplear arreglos, ni cadenas
*/
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n, aux, r,mayorCif=0, finalNum=0;
    do {
        cout<<"Ingrese el numero n (n>1000): ";
        cin>>n;
    }while (n<=1000);
    aux=n;
    while (aux>0) {
        r=aux%10;
        aux=aux/10;
        if (r>mayorCif) {
            mayorCif=r;
        }
    }
    r=0;
    aux=n;
    int cont=0;
    while (aux>0) {
        r=aux%10;
        if (r==mayorCif) {
            aux=aux/10;
        }else {
            finalNum=r*(int)pow(10,cont)+finalNum;
            aux=aux/10;
            cont++;
        }
    }
    if (finalNum!=0) {
        cout<<"Mayor Digito: "<<mayorCif<<endl;
        cout<<"Numero Modificado: "<<finalNum;
    }else {
        cout<<"Sin Digito mayor. Numero sin modificar: "<< n;
    }
    return 0;
}