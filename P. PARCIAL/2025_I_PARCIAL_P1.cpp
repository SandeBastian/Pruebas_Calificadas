#include <iostream>
using namespace std;
int main() {
    int n;
    //srand(time(NULL));
    do {
        cout<<"Ingrese el orden del cubo: ";
        cin>>n;
        if (n<0) cout<<"Error, valor invalido."<<endl;
    }while (n<0);
    int cubo[n][n][n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                cubo[i][j][k]=100+rand()%900;
            }
        }
    }

    int aux[n*n*n]={0};
    int p=0;
    int cont=0;
    while (p<n) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (i+j==n-1) {
                    aux[cont]=cubo[i][j][p];
                    cont++;
                    cout<<aux[cont-1]<<" ";
                }
            }
        }
        cout<<endl;
        p++;
    }
    /*
    //IMPRIME CARAS
    for (int i=0; i<n; i++) {
        cout<<"Cara "<<i+1<<": "<<endl;
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                cout<<cubo[j][k][i]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    cout<<"\naux: ";
    for (int i=0; i<cont; i++) cout<<aux[i]<<" ";
    cout<<cont<<endl;
    */
    int mat[n][n]={0};
    p=0;
    cont=0;
    while (p<n) {
        for (int i=0; i<n; i++) {
            mat[i][p]=aux[cont++];
        }
        p++;
    }
    cout<<"\nMatriz: "<<endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    int primos[n*n]={0};
    cont=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            bool primo=true;
            int div=2;
            while (div<mat[i][j]) {
                if (mat[i][j]%div==0) {
                    primo=false;
                }
                div++;
            }
            if (primo) {
                primos[cont++]=mat[i][j];
            }
        }
    }
    cout<<"Arreglo Primos: "<<endl;
    for (int i=0; i<cont; i++) {
        cout<<primos[i]<<" ";
    }
}