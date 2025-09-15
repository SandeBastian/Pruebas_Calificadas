/*
PRIMERA PRACTICA CALIFICADA 2024-II
Pregunta 2 (de 8:35 a 9:08 am) 5 puntos
Diseñe un programa que permita ingresar número entero positivo, cuyo número de cifras sea mayor a 4.
Modifique el número eliminado los dígitos iguales al promedio entero de los todos los dígitos del número.

Ejemplo 1
Número ingresado: 476405
Promedio entero de los dígitos: 4 = = (4+7+6+4+0+5)/6
Dígito a eliminar: 4
Número modificado: 7605

Ejemplo 2
Número ingresado: 454702
Promedio entero de los dígitos: 3 = (4+5+5+7+0+2)/6
Dígito a eliminar: 3
Número modificado: 454702

Nota: No puede emplear arreglos ni cadenas.
*/
#include <cmath>
#include <iostream>
using namespace std;
int main () {
    long long n, aux, newNum=0;
    int r, cont=0, prom=0;
    do {
        cout<<"Ingrese un numero entero positivo (mayor a 4 cifras): ";
        cin>>n;
        if (n<10000) cout<<"Error. Numero Invalido"<<endl;
    }while (n<10000);
    aux=n;
    while (aux>0) {
        r=aux%10;
        aux=aux/10;
        prom=prom+r;
        cont++;
    }
    prom=prom/cont;
    aux=n;
    cont=0;
    cout<<"Digito a eliminar: "<<prom<<endl;
    while (aux>0) {
        r=aux%10;
        aux=aux/10;
        if (r!=prom) {
            newNum=r*(long long)pow(10,cont)+newNum;
            cont++;
        }
    }
    if (n==newNum) cout<<"El numero no se modifica\n"<<"Numero Original: "<<n<<endl;
    else cout<<"Numero modificado: "<<newNum<<endl;
    return 0;
}