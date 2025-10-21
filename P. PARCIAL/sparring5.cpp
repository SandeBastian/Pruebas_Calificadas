#include <iostream>
using namespace std;
int main () {
    int n;
    do {
        cout<<"Ingrese el orden (nro de filas) de la matriz n-diagonal:";
        cin>>n;
        if (n<0) cout<<"Error, orden invalido."<<endl;
    }while (n<0);
    int mat[n][n+1]={0};
    int f=0,c=0;
    int cont=1;
    for (int i = 0; i < n*(n+1); i++) {
        mat[f++][c++]=cont++;
        if (f==n) f=0;
        if (c==n+1) c=0;
    }
    cout<<"\nMatriz n-diagonal: "<<endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n+1; j++) {
            cout<<mat[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"\nMatriz cuadrada: "<<endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n+1; j++) {
            if (i!=j) {
                cout<<mat[i][j]<<"\t";
            }
        }
        cout<<endl;
    }
    return 0;
}