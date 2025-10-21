#include <iostream>
using namespace std;
int main () {
    //srand(time(NULL));
    int n;
    do {
        cout<<"Ingrese el orden de la matriz: ";
        cin>>n;
        if (n<0) cout<<"Error, valor invalido.";
    }while (n<0);
    int a[n][n]={0};

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            a[i][j]=100+rand()%900;
        }
    }
    cout<<"Matriz A: "<<endl;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    int cont=0; //Nos servira mas tarde para saber hasta donde debo agregar impares en este algoritmo
    int auxM[n*n]={0};
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (a[i][j]%2!=0) {
                auxM[cont++]=a[i][j];
            }
        }
    }
    int contI=cont;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (a[i][j]%2==0) {
                auxM[cont++]=a[i][j];
            }
        }
    }
    for (int i=0; i<contI-1; i++) {
        for (int j=i; j<contI; j++) {
            if (auxM[i]>auxM[j]) {
                int aux=auxM[j];
                auxM[j]=auxM[i];
                auxM[i]=aux;
            }
        }
    }
    for (int i=contI; i<cont-1; i++) {
        for (int j=i; j<cont; j++) {
            if (auxM[i]<auxM[j]) {
                int aux=auxM[j];
                auxM[j]=auxM[i];
                auxM[i]=aux;
            }
        }
    }
    int k=0;
    int b[n][n]={0};
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (k<contI) {
                b[i][j]=auxM[k++];
            }else {
                b[i][j]=auxM[k++];
            }
        }
    }
    cout<<"Matriz B: "<<endl;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}