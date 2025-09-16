/*
PRIMERA PRACTICA CALIFICADA 2025-I
Pregunta 1 (de 8:00 a 8:33 am) 5 puntos
Diseñe un algoritmo que permita ingresar “n” (n<=10) números enteros positivos de entre 2 y 4 cifras (inclusive).
Se garantiza que algunos de los números ingresados serán primos y otros no.
Se pide:
    a)Presentar el menor de los números primos ingresados y la cantidad de veces que aparece.
    b)Presentar el número “P”, que se forma concatenando la suma de cifras de todos los números
    no primos ingresados, en el orden en que se introdujeron.

Por ejemplo, para n=10
Entrada: 200, 21, 17, 400, 23, 17, 608, 35, 202, 1011
Salida: Menor primo: 17, número de apariciones: 2

P =23414843
Note que: P =23414843, es formado por las sumas: 2+0+0=2, 2+1=3, 4+0+0=4, 6+0+8=14, 3+5=8, 2+0+2=4, 1+0+1+1=3

Nota: Resolver sin emplear arreglos, ni cadenas, ni funciones.
*/
#include <iostream>
using namespace std;
int main () {
    int n, num, aux, j=0, i=0, minPri=99999, cont=0, sumaCif=0,newNum=0, r;
    do {
        cout<<"Ingrese la cantidad de valores 'n' (0 < n <= 10): ";
        cin>>n;
        if (n<1||n>10) cout<<"Error. Cantidad Invalida"<<endl;
    }while (n<1||n>10);
    for (i=0; i<n; i++) {
        do {
            cout<<"Ingrese el numero ["<<i+1<<"]: ";
            cin>>num;
            if (num<10||num>9999) cout<<"Error. Numero Invalido"<<endl;
        }while (num<10||num>9999);

        bool flag=true;
        j=1;
        while (j<num&&flag) {
            if (num%j==0) {
                if (!(j==num||j==1)) flag=false;
            }
            j++;
        }
        if (flag) {
            if (num<minPri) {
                minPri=num;
                cont=1;
            }
            else if (num==minPri) {
                cont++;
            }
        }else {
            aux=num;
            sumaCif=0;
            while (aux>0) {
                r=aux%10;
                aux=aux/10;
                sumaCif=sumaCif+r;
            }
            cout<<sumaCif<<endl;
            if (sumaCif<10) newNum=newNum*10+sumaCif;
            else if (sumaCif<100) newNum=newNum*100+sumaCif;
        }
    }
    cout<<"Menor Primo: "<<minPri<<"\t"<<"Numero de Apariciones: "<<cont<<endl;
    cout<<"P: "<<newNum<<endl;
    return 0;
}
