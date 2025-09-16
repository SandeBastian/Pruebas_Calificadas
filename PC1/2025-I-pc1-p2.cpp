/*
PRIMERA PRACTICA CALIFICADA 2025-I
Diseñe un programa que permita leer dos números enteros positivos cuyo número de cifras es mayor a 3.
Luego el programa debe crear el mayor número que se puede formar con los dígitos en común.
Ejemplo:

Entrada:
Primer número: 456702
Segundo número: 408937
Dígitos en común: 0, 4 y 7

Salida:
El mayor número formado por los dígitos en común es: 740

Nota: Resolver sin emplear arreglos, ni cadenas, ni funciones.
*/
#include <iostream>
using namespace std;
int main() {
    long long n, m, minNum, maxNum, r ,r1, r2, aux0,fact=1, numOrd=0, newNum=0, temp;
    //int fact=1, r, r1, r2;
    do {
        cout<<"Ingrese el numero n (de 4 o mas cifras): ";
        cin>>n;
        if (n<1000) cout<<"Error. Numero no valido."<<endl;
    }while (n<1000);
    do {
        cout<<"Ingrese el numero m (de 4 o mas cifras): ";
        cin>>m;
        if (m<1000) cout<<"Error. Numero no valido."<<endl;
    }while (m<1000);
    if (n<m) {
        minNum=n;
        maxNum=m;
    }
    else {
        minNum=m;
        maxNum=n;
    }
    for (int i=0; i<10; i++) {
        aux0=minNum;
        while (aux0>0) {
            r=aux0%10;
            aux0=aux0/10;
            if (r==i) {
                numOrd=r*fact+numOrd;
                fact=fact*10;
                break;
            }
        }
    }
    // cout<<numOrd<<endl; para ver donde fallaba y aqui no fue
    fact=1;
    temp=maxNum;
    bool existe=false;
    while (numOrd>0) {
        r1=numOrd%10;
        numOrd=numOrd/10;
        maxNum=temp; //Aqui era la falla pues no reiniciaba maxNum y este ya se habia hecho 0
        while (maxNum>0) {
            r2=maxNum%10;
            maxNum=maxNum/10;
            if (r1==r2) {
                newNum=fact*r1+newNum;
                fact=fact*10;
                existe=true;
                break;
            }
        }
    }
    if (existe) cout<<"El mayor numero formado por los digitos en comun es: "<<newNum<<endl;
    else cout<<"Los numeros no tienen ningun digito en comun"<<endl;
    return 0;
}