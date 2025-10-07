/*
Diseñe un algoritmo que reciba “n” (n<=50) números enteros (de 2 y 3 cifras) y los almacene en un arreglo (entre los “n”
números deben existir números primos). Luego calcule el promedio de los elementos del arreglo. Luego proceda a eliminar los
números pares menores al promedio y a duplicar (es decir, hacer que aparezcan 2 veces) los números primos mayores al
promedio anteriormente calculado.
Al terminar el proceso debe mostrar el arreglo resultante. Sólo debe utilizar una variable arreglo para realizar todas las
operaciones mencionadas. No debe utilizar funciones
Ejemplo:
    Si el arreglo inicial, de n=11, valores es:
    mat = {22 11 10 12 59 15 101 19 17 125 151}

    Promedio: 49.27
    Luego del proceso debe quedar así:
    mat = {11 59 59 15 101 101 19 17 125 151 151}
*/
#include <iostream>
using namespace std;
int main() {
    int n;
    int mat[100]={0};
    do {
        cout<<"Ingrese el tamano del arreglo que deseas ingresar:";
        cin>>n;
        if (n<0||n>100) cout<<"Error. Valor no valido."<<endl;
    }while (n<0||n>100);
    for (int i=0;i<n;i++) {
        cout<<"Ingrese el valor de mat["<<i+1<<"]: ";
        cin>>mat[i];
    }
    float prom=0;
    for (int i=0;i<n;i++) {
        prom=prom+mat[i];
    }
    prom=prom/n;
    cout<<"\nEl promedio es: "<<prom<<endl;
    for (int i=0;i<n;i++) {
        if (mat[i]<prom&&mat[i]%2==0) {
            for (int j=i;j<n-1;j++) {
                mat[j]=mat[j+1];
            }
            n--;
            i--;
        }
    }

    for (int i=0;i<n;i++) {
        bool primo=true;
        int div=2;
        while (div<mat[i]) {
            if (mat[i]%div==0) {
                primo=false;
                break;
            }
            div++;
        }
        if (primo) {
            if (mat[i]>prom) {
                for (int j=n-1;j>i;j--) {
                    mat[j+1]=mat[j];
                }
                n++;
                mat[i+1]=mat[i];
                i++;
            }
        }
    }
    cout<<"mat["<<n<<"]: { ";
    for (int i=0;i<n;i++) {
        cout<<mat[i]<<" ";
    }
    cout<<"}"<<endl;
    return 0;
}