/*
PRUEBA DE ENTRADA 2024-II
Pregunta 3 (de 8:59 a 9:29 am) 2 puntos
Proponer un algoritmo que reciba un número entero positivo de cinco (5) cifras, calcule la suma de los
dígitos de posiciones impares y la suma de dígitos de posiciones pares (la posición de un dígito se lee
de derecha a izquierda y comienza desde el índice 1); luego presente el número resultante de concatenar
los dígitos de posiciones pares seguido con los dígitos de posiciones impares (De izquierda a derecha).
El orden en el que aparecerán los dígitos en la concatenación final dependerá del orden que tenían en el
número inicial. Por ejemplo, el último digito impar en el número resultante de la concatenación será el
que ocupaba la posición de último dígito impar en el número original.
Ejemplo:
Se ingresa N = 46315
Posiciones: 54321
La suma de los dígitos de posiciones impares: 12
La suma de los dígitos de posiciones pares : 7
Resultado de concatenación: 61435
Nota: No puede emplear arreglos, ni cadenas.
*/
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n, aux, r, posImp=0 ,posPar=0, contImp=0, contPar=0, sumaImp=0, sumaPar=0, conCat=0;
    do {
        cout<<"Ingrese un numero positivo: ";
        cin>>n;
    }while (n<=10000||n>=99999);
    aux=n;
    int cont=1;
    while (aux>0) {
        r=aux%10;
        aux=aux/10;
        if (cont%2!=0) {
            posImp=r*(int)pow(10,contImp)+posImp;
            contImp++; //Termina contando todos las veces que encuentra una cifra de pos Impar
            cont++;
            sumaImp=sumaImp+r;
        }else {
            posPar=r*(int)pow(10,contPar)+posPar;
            contPar++; //Termina contando todos las veces que encuentra una cifra de pos Par
            cont++;
            sumaPar=sumaPar+r;
        }
    }
    cout<<"Suma de digitos de posiciones Impares: "<<sumaImp<<endl;
    cout<<"Suma de digitos de posiciones Pares: "<<sumaPar<<endl;
    cout<<contImp<<endl;
    cout<<contPar<<endl;
    conCat=posPar*(int)pow(10,contImp)+posImp; //Como pide primero par dejo espacio con 0 para los impares y eso con el contador de impares
    cout<<"El resultado de concatenada es: "<<conCat<<endl;
    return 0;
}