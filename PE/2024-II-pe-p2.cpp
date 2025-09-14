/*
PRUEBA DE ENTRADA 2024-II
Pregunta 2 (de 8:32 a 8:57 am) 1.5 puntos
Desarrolle un programa en C++ que solicite ingresar números positivos para determinar la suma de los pares
y la suma de los impares. Debe solicitarse ingresar los números hasta que el usuario decida, además debe comprobarse
que el número ingresado debe ser positivo, de no ser así debe solicitar otro.
Nota: No puede emplear arreglos, ni cadenas
*/
#include <iostream>
using namespace std;
int main() {
    int n, num, sumaPar=0, sumaImp=0;
    do {
        cout<<"Ingrese la cantidad de numeros: ";
        cin>>n;
    }while (n<0);
    for (int i=0; i<n; i++) {
        do {
            cout<<"Ingrese el numero("<<i+1<<"): ";
            cin>>num;
        }while (num<=0);
        if (num%2==0) {
            sumaPar=sumaPar+num;
        }else {
            sumaImp=sumaImp+num;
        }
    }
    cout<<"Suma de numeros Pares: "<<sumaPar<<endl;
    cout<<"Suma de numeros Impares: "<<sumaImp<<endl;
    return 0;
}
