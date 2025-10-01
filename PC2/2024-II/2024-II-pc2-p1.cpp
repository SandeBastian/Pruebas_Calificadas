/*
PC2 2024-II UNI-II FIIS
Pregunta 1 (de 8:00 a 8:33 am) 6 puntos
Escriba un programa en C++ que reciba dos arreglos de enteros positivos A y B de m y n elementos.
Los datos de cada arreglo no deben contener valores repetidos. Luego construya un arreglo C que
contenga los elementos del conjunto unión de A y B, ordenados de menor a mayor. Debe resolver sin
utilizar algoritmos de ordenamiento.
Ejemplo:
A = {6; 12; 8; 16; 21; 11}
B = {9; 16; 14; 27; 8; 18; 24; 13}
C = {27; 24; 21; 18; 16; 14; 13; 12; 11; 9, 8; 6}
*/
#include <iostream>
using namespace std;
int main() {
    int m = 6, n = 8;
    int A[m]={};
    for (int i = 0; i < m; i++) {
        int j=0;
        bool yaEsta = false; //cuando creia que solo debia estar fuera del for pero no reiniciaba en el do while
        do{
            cout<<"Ingresa elemento A["<<i+1<<"]: ";
            cin>>A[i];
            yaEsta = false;
            while (j<i) {
                if (A[i]==A[j]) {
                    yaEsta=true;
                    cout<<"Error. Valor no valido."<<endl;
                    break;
                }
                j++;
            }
        }while (yaEsta); //Si no esta osea (yaEsta=false) entonces sale del bucle
    }

    int B[n]={};
    for (int i = 0; i < n; i++) {
        int j=0;
        bool yaEsta = false; //cuando creia que solo debia estar fuera del for pero no reiniciaba en el do while
        do{
            cout<<"Ingresa elemento B["<<i+1<<"]: ";
            cin>>B[i];
            yaEsta = false;
            while (j<i) {
                if (B[i]==B[j]) {
                    yaEsta=true;
                    cout<<"Error. Valor no valido."<<endl;
                    break;
                }
                j++;
            }
        }while (yaEsta); //Si no esta osea (yaEsta=false) entonces sale del bucle
    }

    int C[m+n];
    int size=m+n;
    int aux;
    for (int i=0; i<m; i++) {
        C[i]=A[i];
    }
    for (int i=0; i<n; i++) { // PAra este for hay otra forma mas intuitiva de acomodar el B en el C?
        C[m+i]=B[i];
    }
    for (int i=0; i<size-1; i++) {
        for (int j=i+1; j<size; j++) {
            if (C[i]>C[j]) {
                aux=C[i];
                C[i]=C[j];
                C[j]=aux;
            }
        }
    }

    for (int i=0; i<size; i++) {
        if (C[i]==C[i+1]) {
            for (int j=i; j<size; j++) {
                C[j]=C[j+1];
            }
            i--;
            size--;
        }
    }
    cout<<"A = { ";
    for (int i=0; i<m; i++) {
        cout<<A[i]<<" ";
    }
    cout<<"}"<<endl;
    cout<<"B = { ";
    for (int i=0; i<n; i++) {
        cout<<B[i]<<" ";
    }
    cout<<"}"<<endl;
    cout<<"C = { ";
    for (int i=0; i<size; i++) {
        cout<<C[i]<<" ";
    }
    cout<<"}"<<endl;
    return 0;
}