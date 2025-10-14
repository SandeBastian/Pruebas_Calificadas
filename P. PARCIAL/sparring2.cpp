#include <iostream>
using namespace std;
int main () {
    int n;
    do {
        cout<<"Ingrese el orden de la matriz:";
        cin>>n;
        if (n<0) cout<<"Error, valor no valido."<<endl;
    }while (n<0);
    int mat[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j]=100+rand()%900;
        }
    }
    int pares[n*n], impares[n*n], contP=0, contI=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j]%2==0) {
                pares[contP++]=mat[i][j];
            }else {
                impares[contI++]=mat[i][j];
            }
        }
    }
    /*
    cout<<contP<<" ";
    for (int i = 0; i < contP; i++) cout<<pares[i]<<" ";
    cout<<endl;

    cout<<contI<<" ";
    for (int i = 0; i < contI; i++) cout<<impares[i]<<" ";
    cout<<endl;
    */
    for (int i = 0; i < contI-1; i++) {
        for (int j = i; j < contI; j++) {
            if (impares[i]>impares[j]) {
                int aux=impares[i];
                impares[i]=impares[j];
                impares[j]=aux;
            }
        }
    }
    for (int i = 0; i < contP-1; i++) {
        for (int j = i; j < contP; j++) {
            if (pares[i]<pares[j]) {
                int aux=pares[i];
                pares[i]=pares[j];
                pares[j]=aux;
            }
        }
    }

    int k=0;
    int mat1[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (k<contI) {
                mat1[i][j]=impares[k];
                k++;
            }else {
                mat1[i][j]=pares[k-contI];
                k++;
            }
        }
    }
    cout<<"mat 1"<<endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"mat 1"<<endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout<<mat1[i][j]<<" ";
        }
        cout<<endl;
    }
}