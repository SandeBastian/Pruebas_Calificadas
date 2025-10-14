/*
Diseñe un programa que permita almacenar en dos vectores de caracteres los dígitos de dos números en el sistema de numeración de
base b (2 ≤ 𝒃 ≤ 9). Luego sin convertir a decimal los números, almacenar en otro vector los dígitos del producto de dichos números.
Finalmente presentar los dígitos del producto de dichos números.
Ejemplo:
Base del sistema de numeración: 6
Los dígitos del primer número en base 6:
1 0 5 3 5
Los dígitos del segundo número base 6:
4 1 2 0
Los dígitos del producto de los números:
4 5 1 4 5 0 4 0
Nota: Validar la base b y que los dígitos de los números ingresados se encuentren en el sistema de numeración de base b.
Resolver sin utilizar funciones.

for (int i=0; i<sz; i++) {
        cout<<p[i]<<" ";
    }
*/
#include <iostream>
using namespace std;
int main () {
    int b;
    do {
        cout<<"Ingrese la base n (2 <= n <=9): ";
        cin>>b;
        if (b<2||b>9) cout<<"Error. Base invalida."<<endl;
    }while (b<2||b>9);
    int m;
    do {
        cout<<"Longitud del Numero X: ";
        cin>>m;
        if (m<0) cout<<"Error. Longitud Invalida"<<endl;
    }while (m<0);
    int x[m];
    for (int i=0; i<m; i++) {
        do {
            cout<<"Ingrese X["<<i+1<<"]: ";
            cin>>x[i];
            if (x[i]<0||x[i]>=b) cout<<"Error. Cifra invalida."<<endl;
        }while (x[i]<0||x[i]>=b);
    }

    int n;
    do {
        cout<<"Longitud del Numero Y: ";
        cin>>n;
        if (n<0) cout<<"Error. Longitud Invalida"<<endl;
    }while (n<0);
    int y[n];
    for (int i=0; i<n; i++) {
        do {
            cout<<"Ingrese Y["<<i+1<<"]: ";
            cin>>y[i];
            if (y[i]<0||y[i]>=b) cout<<"Error. Cifra invalida."<<endl;
        }while (y[i]<0||y[i]>=b);
    }
    int sz=n+m;
    int p[sz]={0};

    for (int i=m-1; i>=0; i--) {
        for (int j=n-1; j>=0; j--) {
            int prod=x[i]*y[j];
            p[j+i+1]=p[j+i+1]+prod;
        }
    }
   for (int i=sz-1; i>=0; i--) {
       int q=p[i]/b;
       p[i]=p[i]%b;
       p[i-1]=p[i-1]+q;
       //cout<<p[i]<<endl;
   }
    int j=0;
    while (p[j]==0) j++;
    cout<<"Los digitos del producto de los numeros: "<<endl;
    while (j<sz) {
        cout<<p[j]<<" ";
        j++;
    }
    return 0;
}
