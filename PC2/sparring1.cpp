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
int main () {
    int n=10;
    int code[10]={100, 200, 100, 300, 100, 500, 300, 100, 400, 400};
    //float precio[10]={25.3, 15.6, 30.7, 16.3, 28.4, 20.5, 15.2, 20.5, 15.2, 20.8};
    float precio[10]={100, 200, 100, 300, 100, 500, 300, 100, 400, 400};
    //Solo imrpime y suma precios basico para ver como funciona
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (code[i] > code [j]) {

            }
        }
    }
    int aux_code;
    float aux_precio;
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
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

    //Eliminacion y suma de precios... tambien promedio
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (code[i]==code[j]) {
                precio[i]=precio[i]+precio[j];
                int k=j;
                while (k<n-1) {
                    code[k]=code[k+1];
                    precio[k]=precio[k+1];
                    k++;
                }
                n--;
                j--;
            }
        }
    }
    cout<<"\nCodigo\t\tSuma\t\tPromedio de Rebajas"<<endl;
    for (int i=0; i<n; i++) {
        cout<<code[i]<<"\t\t"<<precio[i]<<endl;
    }

    return 0;
}