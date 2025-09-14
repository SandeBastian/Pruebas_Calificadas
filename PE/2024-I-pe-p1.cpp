/*
PRUEBA DE ENTRADA 2024-I
Pregunta 1 (de 8:00 a 8:30 am) 1.5 puntos
Proponer un algoritmo que reciba un número entero positivo de cinco (5) cifras, sume las tres (3)
primeras cifras y las tres (3) últimas cifras; luego presente la suma de las dos sumas obtenidas.
Ejemplo:
Se ingresa N = 12317
La suma de las 3 primeras cifras es: 6
La suma de las 3 últimas cifras es: 11
La suma total es 17.
Nota: No puede emplear arreglos, ni cadenas.
*/
#include <cmath> //necesario para el pow
#include <iostream>
using namespace std;
int main () {
    int n, sumaUlti=0, sumaPrim=0, cont, aux;
    cout<<"Ingrese el numero:"; cin>>n;
    aux=n;
    cont=0;
    while (cont<3) {
        sumaUlti=sumaUlti+aux%10;
        aux=aux/10;
        cont++;
    }
    cont=4;
    aux=n;
    while (cont>1) {
        sumaPrim=sumaPrim+aux/pow(10,cont);
        aux=aux%(int)pow(10,cont);
        cont--;
    }
    cout<<"Suma de las primeras 3 cifras: "<<sumaPrim<<endl;
    cout<<"Suma de las ultimas 3 cifras: "<<sumaUlti<<endl;

    return 0;
}

/*
aux = n;
cont = 0;
while (cont < 3) {
    sumaUlti = sumaUlti + aux % 10;
    aux = aux / 10;
    cont++;
}
aux = n / 100;
cont = 0;
while (cont < 3) {
    sumaPrim = sumaPrim + aux % 10;
    aux = aux / 10;
    cont++;
}
*/