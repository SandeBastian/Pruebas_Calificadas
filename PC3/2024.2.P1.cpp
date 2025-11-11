/*
*Escriba un programa en C++ en el que se definan tres (3) funciones: CREAR, PREPARAR y MOSTRAR.
En la función CREAR se debe crear un arreglo bidimensional de orden nxm lleno de números aleatorios de 3 cifras.
Para llenar una celda con un valor aleatorio debe utilizar el siguiente código
    #include <time.h>
    …
    main(){
    srand(time(NULL));
    …
    matriz[i][j]=100+rand()%(900); //asigna un número aleatorio de 100 a 999
    …

La función PREPARAR debe encontrar los valores máximo y mínimo dentro de la matriz.

La función MOSTRAR debe presentar en pantalla:
    -La matriz creada,
    -El mayor valor contenido dentro de la matriz, las veces que se repite este valor y las posiciones donde se encuentra.
    -El menor valor contenido dentro de la matriz, las veces que se repite este valor y las posiciones donde se encuentra.
Ver ejemplo en la página siguiente
*/
#include <iostream>
#include <time.h>
using namespace std;

void CREAR(int mat[][100], int m, int n) {
    srand(time(NULL));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j]=100 + rand() % 900;
        }
    }
}

void PREPARAR(int mat[][100], int m, int n, int &max, int &min) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] > max) max = mat[i][j];
            if (mat[i][j] < min) min = mat[i][j];
        }
    }
}

void MOSTRAR(int mat[][100], int m, int n, int &max, int &min, int &contMax, int &contMin) {
    cout<<"\nMatriz: "<<endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j]==max) contMax++;
            if (mat[i][j]==min) contMin++;
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\nEl mayor valor es: "<<max<<endl;
    cout<<"Veces que se repite: "<<contMax<<endl;
    cout<<"Posiciones: ";
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if (mat[i][j]==max) cout<<"("<<i+1<<", "<<j+1<<") ";
        }
    }
    cout<<"\nEl menor valor es: "<<min<<endl;
    cout<<"Veces que se repite: "<<contMin<<endl;
    cout<<"Posiciones: ";
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if (mat[i][j]==min) cout<<"("<<i+1<<", "<<j+1<<") ";
        }
    }

}

int main () {
    int m, n;
    int max=0, min=99999;
    int contMax=0, contMin=0;
    cout<<"Cantidad de Filas: "; cin>>m;
    cout<<"Cantidad de columnas: "; cin>>n;
    int mat[m][100];
    CREAR (mat, m, n);
    PREPARAR(mat, m, n, max, min);
    MOSTRAR(mat, m, n, max, min, contMax, contMin);
    cout<<"\nMax: "<<max<<endl;
    cout<<"Min: "<<min<<endl;
    return 0;
}