/*
Se desea leer el código (entero de 3 cifras) “codigo” y el precio unitario (real positivo) de un conjunto de n (n<=200) productos.
Se sabe que los códigos se pueden repetir (es información histórica). Se pide diseñar un algoritmo que lea esta información y luego:
Calcule el precio promedio por cada producto “promedio” y las  veces que el precio de cada producto estuvo por debajo su promedio
“# de rebajas”. Muestre un listado indicando el “codigo”, el “promedio” y el “# de rebajas”. Este listado debe mostrar sólo los
productos que hayan tenido rebajas (“# de rebajas” > 0) y debe  estar ordenado en base al código (crecientemente).
    ==Entrada==                 ==Salida==
    CODIGO      PRECIO          CODIGO      PROMEDIO        #DE_REBAJAS
    100         25.3            100         26.225          2
    200         15.6            300         15.75           1
    100         30.7            400         18              1
    300         16.3
    100         28.4
    500         20.5
    300         15.2
    100         20.5
    400         15.2
    400         20.8
*/
#include <iostream>
using namespace std;
int main (){
    int n;
    do {
        cout<<"Ingrese el numero de productos:";
        cin>>n;
        if (n<0||n>200) cout<<"Error. Numero no Valido"<<endl;
    }while (n<0||n>200);

    int code[n];
    float precio[n];
    for (int i=0; i<n; i++) {
        do {
            cout<<"Ingrese el Codido ["<<i+1<<"]: ";
            cin>>code[i];
            if (code[i]<100||code[i]>999) cout<<"Error. Codigo no Valido"<<endl;
        }while (code[i]<100||code[i]>999);
        do {
            cout<<"Ingrese el Precio ["<<i+1<<"]: ";
            cin>>precio[i];
            if (precio[i]<0) cout<<"Error. Precio no Valido"<<endl;
        }while (precio[i]<0);
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (code[i] > code [j]) {

            }
        }
    }
    int aux_code;
    float aux_precio;
    for (int i=0; i<n; i++) {
        for (int j=1; j<n; j++) {
            if (code[i]>code[j]) {
                aux_code=code[j];
                code[j]=code[i];
                code[i]=aux_code;

                aux_precio=precio[j];
                precio[j]=precio[i];
                precio[i]=aux_precio;
            }
        }
    }
    cout<<"Codigo\t\tSuma\t\tPromedio de Rebajas"<<endl;
    for (int i=0; i<n; i++) {
        cout<<code[i]<<"\t\t"<<precio[i]<<endl;
    }
    cout<<"Precio\t\tPromedio\t\t# de Rebajas"<<endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (code[i]==code[j]) {
                precio[i]=precio[i]+precio[j];
                int k=j;
                while (k<n-1) {
                    code[k]=code[k+1];
                    precio[k]=precio[k+1];
                    k++;
                }
                n--;
            }else {
                break;
            }
        }
    }

    return 0;
}