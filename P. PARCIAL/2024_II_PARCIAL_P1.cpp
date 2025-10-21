#include <iostream>
using namespace std;
int main() {
    int n;
    srand(time(NULL));
    do {
        cout<<"Ingrese el orden de la matriz: ";
        cin>>n;
        if (n<=0) cout<<"Error. Valor invalido."<<endl;
    }while (n<=0);
    int matA[n][n];
    for ( int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            matA[i][j]=100+rand()%900;
        }
    }
    cout<<"Matriz A"<<endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout<<matA[i][j]<<"\t";
        }
        cout<<endl;
    }
    int aux[n*n]={0};
    int cant=0, hasta=0;
    int matB[n][n]={0};

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (matA[i][j]%2!=0) {
                aux[cant]=matA[i][j];
                cant++;
            }
        }
    }

    int auxM;
    for (int i=0; i<cant-1; i++) {
        for (int j=i; j<cant; j++) {
            if (aux[i]>aux[j]) {
                auxM=aux[i];
                aux[i]=aux[j];
                aux[j]=auxM;
            }
        }
    }

    int auxP=cant;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (matA[i][j]%2==0) {
                aux[cant]=matA[i][j];
                cant++;
            }
        }
    }
    for (int i=auxP; i<cant-1; i++) {
        for (int j=i; j<cant; j++) {
            if (aux[i]<aux[j]) {
                auxM=aux[i];
                aux[i]=aux[j];
                aux[j]=auxM;
            }
        }
    }
   /*
    (int i=0; i<cant; i++) {
        cout<<aux[i]<<" ";
    }
    cout<<endl;
    */
    int cont=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            matB[i][j]=aux[cont];
            cont++;
        }
    }

    cout<<"Matriz B"<<endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout<<matB[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}