/*
Dados dos conjuntos A y B de m y n elementos enteros, se define la distancia entre los conjuntos A y B
como el número de elementos de la diferencia simétrica de dichos conjuntos con sus elementos indexados.

Ejemplo:

Conjunto A = {1, 3, 5, 7}
Conjunto A con sus elementos indexados: A_Ind = {1_1, 3_2, 5_3, 7_4}

Conjunto B = {1, 2, 4, 5}
Conjunto B con sus elementos indexados: B_Ind = {1_1, 2_2, 4_3, 5_4}

Diferencia simétrica de A_Ind y B_Ind:
(A_Ind - B_Ind) ∪ (B_Ind - A_Ind) = {2_2, 3_2, 4_3, 5_3, 5_4, 7_4}

La distancia entre A y B es: 6

Nota: Validar que los elementos de un conjunto no se repitan.

*/
#include <iostream>
using namespace std;
int main() {
    int n;
    do {
        cout<<"Ingrese la cantidad de elementos de A: ";
        cin>>n;
        if (n<0) cout<<"El numero es invalido."<<endl;
    }while (n<0);
    int a[n];
    for (int i = 0; i < n; i++) {
        bool flag;
        do {
            flag=false;
            cout<<"Ingrese A ["<<i+1<<"]: ";
            cin>>a[i];
            int j=0;
            while (j<i) {
                if (a[i]==a[j]) {
                    flag=true;
                    cout<<"Error. El numero ya ha sido ingresado."<<endl;
                }
                j++;
            }
        }while (flag);
    }
    int m;
    do {
        cout<<"Ingres la cantidad de elementos de B: ";
        cin>>m;
        if (m<0) cout<<"El numero es invalido."<<endl;
    }while (m<0);

    int b[m];
    for (int i = 0; i < m; i++) {
        bool flag;
        do {
            flag=false;
            cout<<"Ingrese B ["<<i+1<<"]: ";
            cin>>b[i];
            int j=0;
            while (j<i) {
                if (b[i]==b[j]) {
                    flag=true;
                    cout<<"Error. El numero ya ha sido ingresado."<<endl;
                }
                j++;
            }
        }while (flag);
    }



    int c[n+m], ind[n+m];
    int sz=n+m;
    //ordenando A en C
    for (int i = 0; i < n; i++) {
        c[i]=a[i];
        ind[i]=i+1;
    }



    //ordenando B en C
    for (int i = 0; i < m; i++) {
        c[n+i]=b[i];
        ind[n+i]=i+1;
    }



    int eleAux, indAux;
    for (int i = 0; i < sz; i++) {
        for (int j = i; j < sz; j++) {
            if (c[i]>c[j]) {
                eleAux=c[i];
                c[i]=c[j];
                c[j]=eleAux;

                indAux=ind[i];
                ind[i]=ind[j];
                ind[j]=indAux;
            }
        }
    }

    for (int i=0; i<sz; i++) {
        if (i+1<sz&&c[i]==c[i+1]&&ind[i]==ind[i+1]) {
            for (int j=i; j<sz; j++) {
                c[j]=c[j+1];
                ind[j]=ind[j+1];
            }
            sz--; //elimina el primer valor
            for (int j=0; j<sz; j++) {
                c[j]=c[j+1];
                ind[j]=ind[j+1];
            }
            sz--; //elimina el segundo valor

            i--;//para que no se salte el siguiente numero si es que necesita eliminarse
        }
    }
    cout<<"\nConjunto A: {";
    for (int i=0; i<n; i++) {
        cout<<a[i]<<"_"<<i+1<<" ";
    }
    cout<<"}"<<endl;

    cout<<"Conjunto B: {";
    for (int i=0; i<m; i++) {
        cout<<b[i]<<"_"<<i+1<<" ";
    }
    cout<<"}"<<endl;

    cout<<"Diferencia Simetrica de A y B: {";
    for (int i=0; i<sz; i++) {
        cout<<c[i]<<"_"<<ind[i]<<" ";
    }
    cout<<"}"<<endl;

    cout<<"La distancia entre A y B:"<<sz<<endl;
    return 0;
}