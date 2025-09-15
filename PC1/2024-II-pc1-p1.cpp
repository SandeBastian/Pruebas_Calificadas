/*
PRIMERA PRACTICA CALIFICADA 2024-II
Pregunta 1 (de 8:00 a 8:33 am) 5 puntos
Escriba un algoritmo, que reciba un número entero positivo N de 5 cifras y determine dos números A y B. El número A se
determina multiplicando los tres primeros dígitos de N contados de izquierda a derecha, el número B se determina multiplicando
los dos últimos dígitos de N. Si uno de los números resultantes es par y el otro impar forme un número equivalente a la
concatenación de los dígitos del número impar y el par. Si ambos números son pares o impares solo muestre un mensaje indicando
que los números no cumple la regla de que uno sea par y el otro impar.
Ejemplo 1:
N 43751
A 84
B 5
Número resultante de la concatenación 584

Ejemplo 2:
N 24643
A 48
B 12
No se cumplen laS condiciones por que los dos nueros son pares
*/
//n ent posi 5 cifr y determine 2 num,
//A= producto de los 3 primeros digitos contados de izq a derecha
//B= producto de los 2 ultimos digitos de N
//si 1 es par y otro impar se forma concatenacion igual= impar_par
//si ambos son pares o impares no se cumple nada
#include <iostream>
using namespace std;
int main() {
    int n, a=1, b=1, cont=0, r, aux, num=0;
    do {
        cout<<"Ingrese n (positivo de 5 cifras): ";
        cin>>n;
        if (n<10000||n>99999) cout<<"Error. Numero Invalido"<<endl;
    }while (n<10000||n>99999);
    aux=n;
    while (aux>0) {
        if (cont<2) {
            r=aux%10;
            aux=aux/10;
            b=b*r;
            cont++;
        }else {
            r=aux%10;
            aux=aux/10;
            a=a*r;
            cont++;
        }
    }
    cout<<"A: "<<a<<endl;
    cout<<"B: "<<b<<endl;
    if (a%2 != b%2) { //b*b=9*9 (max 2cif)  a*a*a=9*9*9=729 (max 3 cif)
        if (a%2==0) {
            if (a<10) num=b*10+a;
            else if (a<100) num=b*100+a;
            else if (a<1000) num=b*1000+a;
        }else {
            if (b<10) num=a*10+b;
            else if (b<100) num=a*100+b;
        }
        cout<<"Numero resultante de la concatenacion "<<num<<endl;
    }else {
        cout<<"No se cumplen las condiciones por que los dos nueros son "<<(a%2==0 ? "pares\n" : "impares\n");
    }
    return 0;
}