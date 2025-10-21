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

    int matA[n][n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            matA[i][j]=100+rand()%900;
        }
    }
    // Imprime Matriz
    cout<<"Matriz A: "<<endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout<<matA[i][j]<<" ";
        }
        cout<<endl;
    }
    int auxP[n*n]={0};
    int auxI[n*n]={0};
    int cant1=0;

    // Empieza Impares
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (matA[i][j]%2!=0) {
                auxI[cant1++]=matA[i][j];
            }
        }
    }
    cout<<"\nauxI: ";
    for (int i=0; i<cant1; i++) {
        cout<<auxI[i]<<" ";
    }
    cout<<endl;

    for (int i=0; i<cant1-1; i++) {
        for (int j=i; j<cant1; j++) {
            if (auxI[i]>auxI[j]) {
                int aux=auxI[i];
                auxI[i]=auxI[j];
                auxI[j]=aux;
            }
        }
    }

    cout<<"\nauxI: ";
    for (int i=0; i<cant1; i++) {
        cout<<auxI[i]<<" ";
    }
    cout<<endl;


    // Empieza Pares
    int cant2=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (matA[i][j]%2==0) {
                auxP[cant2++]=matA[i][j];
            }
        }
    }
    cout<<"\nauxP: ";
    for (int i=0; i<cant2; i++) {
        cout<<auxP[i]<<" ";
    }
    cout<<endl;

    for (int i=0; i<cant2-1; i++) {
        for (int j=i; j<cant2; j++) {
            if (auxP[i]<auxP[j]) {
                int aux=auxP[i];
                auxP[i]=auxP[j];
                auxP[j]=aux;
            }
        }
    }
    cout<<"\nauxP: ";
    for (int i=0; i<cant2; i++) {
        cout<<auxP[i]<<" ";
    }
    cout<<endl;
    int matB[n][n]={0};
    int k1=0, k2=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (k1<cant1) {
                matB[i][j]=auxI[k1++];
            }else {
                matB[i][j]=auxP[k2++];
            }
        }
    }

    cout<<"Matriz B: "<<endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout<<matB[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}