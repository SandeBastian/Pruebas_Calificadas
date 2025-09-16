/*lea 2 num enteros posi (diferentes). determinar la cantidad de nros que existen entre el menor y el mayor de los numeros leidos,
cuya suma de digitos sea 7, debe mostrar la cantidad de numeros que cumplen la condicion dada y los números que la cumplen. Ejemplo
zi los numeros son 200 y 100

 */
#include <iostream>
using namespace std;
int main() {
    int n, m, i, aux, cont=0, mayor, menor, suma=0, r;
    do {
        cout<<"Ingrese n: "; cin>>n;
        cout<<"Ingrese m: "; cin>>m;
        if (n==m) {
            cout<<"Error. Los numeros deben ser diferentes."<<endl;
        }
        if (n<=0 || m<=0) {
            cout<<"Error. Los numeros no son enteros positivos"<<endl;
        }
    }while (n<=0 || m<=0 || n==m);
    if (n>m) {
        mayor=n;
        menor=m;
    }else {
        mayor=m;
        menor=n;
    }
    for ( i=menor+1; i<mayor; i++) {
        aux=i;
        suma=0;
        while (aux>0) {
            r=aux%10;
            aux=aux/10;
            suma=suma+r;
        }
        if (suma==7) {
            cont++;
            cout<<i<<endl;
        }
    }
    cout<<"Hay "<<cont<<" numero/s cuya suma de digitos es 7"<<endl;
    return 0;
}