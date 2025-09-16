/*
leeer numero entero pos numero de cif mayor a 3. luego el programa debe presentar la mediana de los digitos de dicho numero
4567071 0 1 4 5 6 7 7 M=5
si es par la cantidad se hace semi suma y si los digitos decimales de la mediana son 0.5 o mas se redondea al mayor
nno usar arreglos, funnciones, ni cadenas
*/
#include <iostream>
using namespace std;
int main() {
    int n, aux, num=0, r, cont=0, med=0, pos1, pos2;
    do {
        cout<<"Ingrese un numero n (con mas de 3 cifras): ";
        cin>>n;
        if (n<1000) cout<<"Error. Numero no valido"<<endl;
    }while (n<1000);
    for (int i=9; i>=0; i--) {
        aux=n;
        while (aux>0) {
            r=aux%10;
            aux=aux/10;
            if (i==r) {
                num=num*10+r;
            }
        }
    }
    aux=num;
    while (aux>0) {
        aux=aux/10;
        cont++;
    }
    aux=num;
    if (cont%2!=0) {
        int pos=(cont/2)+1;
        for (int i=1; i<=cont; i++) {
            r=aux%10;
            aux=aux/10;
            if (i==pos) {
                med=r;
                break;
            }
        }
    } else {
        pos1=cont/2;
        pos2=pos1+1;
        int val1=0, val2=0;
        for (int i=1; i<=cont; i++) {
            r=aux%10;
            aux=aux/10;
            if (i==pos1) val1=r;
            if (i==pos2) {
                val2=r;
                break;
            }
        }
        int suma=val1+val2;
        if (suma%2==0) med=suma/2;
        else med=(suma/2)+1;
    }
    cout<<"La mediana es: "<<med<<endl;
    return 0;
}
