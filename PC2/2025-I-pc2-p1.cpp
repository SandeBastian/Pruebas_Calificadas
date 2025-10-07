/*
Dado un arreglo cuadrado de orden K de enteros de dos cifras, escriba un programa en C++ que solicite al usuario las coordenadas (a, b)
de una celda del arreglo y solicite un valor L donde L ≤ K. Asuma que las coordenadas (a,b) son la esquina superior izquierda de un
subarreglo cuadrado de orden L, y calcule y muestre el producto de los elementos que se encuentran en la diagonal secundaria de este
subarreglo. Valide que el subarreglo definido sea válido dentro del arreglo original. Ejemplo, dado el arreglo cuadrado de orden K=7:
    0   1   2   3   4   5   6
0   27  60  10  56  21  70  74
1   63  93  71  78  57  91  11
2   40  19  26  76  32  87  41
3   85  93  16  91  47  71  11
4   18  16  59  55  47  16  35
5   24  48  56  48  77  48  37
6   19  90  33  34  57  14  28

Datos ingresados: (a, b) = (3,2) y L=4
El subarreglo pedido es la zona amarilla:
Se debe calcula: valor = 48x59x91x32 = 8246784
Nota: resolver con un soo arreglo y sin utilizar funciones.
**********************************************************************************
cout<<"Matriz:"<<endl;
    for (int i=0; i<k; i++) {
        for (int j=0; j<k; j++) {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
*******************************************************************************************
int prod=1;
    for (int i=0; i<l; i++) {
        for (int j=0; j<l; j++) {
            if (i+j==l-1) {
                prod=prod*subMat[i][j];
                cout<<subMat[i][j]<<" ";
                break;
            }
        }
    }
*/
#include <atomic>
#include <iostream>
using namespace std;
int main() {
    srand(time(NULL));
    int k;
    do {
        cout<<"Ingrese el orden del arreglo:";
        cin>>k;
        if (k<=0) cout<<"Error. El arreglo es invalido."<<endl;
    }while (k<=0);
    int mat[k][k];
    for (int i=0; i<k; i++) {
        for (int j=0; j<k; j++) {
            //cout<<"Ingresa mat["<<i+1<<"]"<<"["<<i+1<<"]: ";
            //cin>mat[i][j];
            mat[i][j]=10+rand()%90;
        }
    }
    cout<<"Matriz:"<<endl;
    for (int i=0; i<k; i++) {
        for (int j=0; j<k; j++) {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    int a, b;
    do {
        cout<<"Ingrese las coordenadas (a, b): "<<endl;
        cout<<"a:"; cin>>a;
        cout<<"b:"; cin>>b;
        if ((a<0||a>k)||(b<0||b>k)) cout<<"Error. Las coordenadas son invalidas"<<endl;
    }while ((a<0||a>k)||(b<0||b>k));

    int l;
    bool flag;
    do {
        flag=false;
        cout<<"Ingrese el orden del subarreglo:"<<endl;
        cout<<"L: "; cin>>l;
        if (l+a-1>k&&l+b-1>k&&l<=0) {
            cout<<"Error. El subarreglo es invalido"<<endl;
            flag=true;
        }
    }while (flag);
    //int subMat[l][l];
    int prod1=1;
    for (int i=0; i<l; i++) {
        for (int j=0; j<l; j++) {
            if (i+j==l-1) {
                prod1=prod1*mat[i+a-1][j+b-1];
                cout<<mat[i+a-1][j+b-1]<<" ";
                break;
            }
        }
    }

    cout<<"Produto: "<<prod1<<endl;
}