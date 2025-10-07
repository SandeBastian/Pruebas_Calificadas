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
    //Eliminacion y suma de precios... tambien promedio
    for (int i=0; i<n-1; i++) {
        int j=i;
        while (j+1<n && code[i]==code[j+1]) {
            j++;
        }
        float prom=0;
        //Acumula promedio
        for (int k=i; k<=j; k++) {
            prom=prom+precio[k];
        }
        //Crea variables
        prom=prom/(j-i+1);
        int cnt = 0;
        //Calcula cantidad de productos con el mismo codigo
        for (int k=i; k<=j; k++) {
            if (precio[k] < prom) {
                cnt++;
            }
        }
        if (cnt > 0){
            cout << code[i] << "\t\t" << prom << "\t\t" << cnt << "\n";
        }
        i = j;
    }
    return 0;
}