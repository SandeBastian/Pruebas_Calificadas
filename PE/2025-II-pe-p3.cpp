/*ingresa un numero cifras >=4. luego elimine de ese numero el mayor digito impar*/
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n, newNum=0, aux, r=0, mayImp=0, cont=0;
    do {
        cout<<"Ingrese n (positivo de 4 cifras o mas): ";
        cin>>n;
        if (n<1000) {
            cout<<"Error. Numero no valido."<<endl;
        }
    }while (n<1000);
    aux=n;
    while (aux>0) {
        r=aux%10;
        aux=aux/10;
        if (r%2!=0) {
            if (r>mayImp) {
                mayImp=r;
            }
        }
    }
    aux=n;
    r=0;
    while (aux>0) {
        r=aux%10;
        aux=aux/10;
        if (r!=mayImp) {
            newNum=r*(int)pow(10,cont)+newNum;
            cont++;
        }
    }
    if (mayImp!=0) {
        cout<<"Mayor digito impar es: "<<mayImp<<endl;
        cout<<"Numero modificado: "<<newNum<<endl;
    }else {
        cout<<"No hay digitos Impares."<<endl;
        cout<<"Numero sin modificar: "<<newNum<<endl;
    }
    return 0;
}