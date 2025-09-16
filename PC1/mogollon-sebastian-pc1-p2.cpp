/*
recibir cuatro fechas 3 variables dia mes y año, luego presentar las fechas ordenadas decrecientemente respecto del año
en caso de años iguales ordenados en forma creciente respecto del mes; en caso de años y meses iguales ordenados en forma
decreciente respecto del dia. si las 4 fechas son.
13  12   2021
7   8   2002
15  11  2025
6   12  2021

Entonces a la respuesta debe ser:
15  11  2025
13  12  2021
6   12  2021
7   8   2002
no usar arreglos cadenas, ni funciones, ni instrucciones repetitivas y no debe tener mas de cinco comparaciones para
el ordenamiento de las fechas
reitero NO DEBE TENER MAS DE 5 COMPARACIONES NI USES COSAS EEXTRÑAS COMO SWAP SIGUE MI SECUENCIA DE COUT
DEBES CONCATENER CADA FECHA EN ORDEN DE AÑO, MES Y DIA, COMPARARLAS Y ASI GENERAR LO QUE PIDE PERO DEBES CONCATENAR PARA
LOGRAR COMPARAR

*/
#include <iostream>
using namespace std;
int main() {
    int anio1, anio2, anio3, anio4, mes1, mes2, mes3, mes4, dia1, dia2, dia3, dia4;
    cout<<"Ingrese la fecha 1 (en orden --> dia/mes/anio): ";
    cin>>dia1>>mes1>>anio1;
    cout<<"Ingrese la fecha 2 (en orden --> dia/mes/anio): ";
    cin>>dia2>>mes2>>anio2;
    cout<<"Ingrese la fecha 3 (en orden --> dia/mes/anio): ";
    cin>>dia3>>mes3>>anio3;
    cout<<"Ingrese la fecha 4 (en orden --> dia/mes/anio): ";
    cin>>dia4>>mes4>>anio4;

    long f1 = anio1 * 10000 + (100 - mes1) * 100 + dia1;
    long f2 = anio2 * 10000 + (100 - mes2) * 100 + dia2;
    long f3 = anio3 * 10000 + (100 - mes3) * 100 + dia3;
    long f4 = anio4 * 10000 + (100 - mes4) * 100 + dia4;

    if (f1 >= f2 && f1 >= f3 && f1 >= f4) {
        cout << dia1 << " " << mes1 << " " << anio1 << endl;
        if (f2 >= f3 && f2 >= f4) {
            cout << dia2 << " " << mes2 << " " << anio2 << endl;
            if (f3 >= f4) {
                cout << dia3 << " " << mes3 << " " << anio3 << endl;
                cout << dia4 << " " << mes4 << " " << anio4 << endl;
            } else {
                cout << dia4 << " " << mes4 << " " << anio4 << endl;
                cout << dia3 << " " << mes3 << " " << anio3 << endl;
            }
        } else if (f3 >= f2 && f3 >= f4) {
            cout << dia3 << " " << mes3 << " " << anio3 << endl;
            if (f2 >= f4) {
                cout << dia2 << " " << mes2 << " " << anio2 << endl;
                cout << dia4 << " " << mes4 << " " << anio4 << endl;
            } else {
                cout << dia4 << " " << mes4 << " " << anio4 << endl;
                cout << dia2 << " " << mes2 << " " << anio2 << endl;
            }
        } else {
            cout << dia4 << " " << mes4 << " " << anio4 << endl;
            if (f2 >= f3) {
                cout << dia2 << " " << mes2 << " " << anio2 << endl;
                cout << dia3 << " " << mes3 << " " << anio3 << endl;
            } else {
                cout << dia3 << " " << mes3 << " " << anio3 << endl;
                cout << dia2 << " " << mes2 << " " << anio2 << endl;
            }
        }
    } else if (f2 >= f1 && f2 >= f3 && f2 >= f4) {
        cout << dia2 << " " << mes2 << " " << anio2 << endl;
        if (f1 >= f3 && f1 >= f4) {
            cout << dia1 << " " << mes1 << " " << anio1 << endl;
            if (f3 >= f4) {
                cout << dia3 << " " << mes3 << " " << anio3 << endl;
                cout << dia4 << " " << mes4 << " " << anio4 << endl;
            } else {
                cout << dia4 << " " << mes4 << " " << anio4 << endl;
                cout << dia3 << " " << mes3 << " " << anio3 << endl;
            }
        } else if (f3 >= f1 && f3 >= f4) {
            cout << dia3 << " " << mes3 << " " << anio3 << endl;
            if (f1 >= f4) {
                cout << dia1 << " " << mes1 << " " << anio1 << endl;
                cout << dia4 << " " << mes4 << " " << anio4 << endl;
            } else {
                cout << dia4 << " " << mes4 << " " << anio4 << endl;
                cout << dia1 << " " << mes1 << " " << anio1 << endl;
            }
        } else {
            cout << dia4 << " " << mes4 << " " << anio4 << endl;
            if (f1 >= f3) {
                cout << dia1 << " " << mes1 << " " << anio1 << endl;
                cout << dia3 << " " << mes3 << " " << anio3 << endl;
            } else {
                cout << dia3 << " " << mes3 << " " << anio3 << endl;
                cout << dia1 << " " << mes1 << " " << anio1 << endl;
            }
        }
    } else if (f3 >= f1 && f3 >= f2 && f3 >= f4) {
        cout << dia3 << " " << mes3 << " " << anio3 << endl;
        if (f1 >= f2 && f1 >= f4) {
            cout << dia1 << " " << mes1 << " " << anio1 << endl;
            if (f2 >= f4) {
                cout << dia2 << " " << mes2 << " " << anio2 << endl;
                cout << dia4 << " " << mes4 << " " << anio4 << endl;
            } else {
                cout << dia4 << " " << mes4 << " " << anio4 << endl;
                cout << dia2 << " " << mes2 << " " << anio2 << endl;
            }
        } else if (f2 >= f1 && f2 >= f4) {
            cout << dia2 << " " << mes2 << " " << anio2 << endl;
            if (f1 >= f4) {
                cout << dia1 << " " << mes1 << " " << anio1 << endl;
                cout << dia4 << " " << mes4 << " " << anio4 << endl;
            } else {
                cout << dia4 << " " << mes4 << " " << anio4 << endl;
                cout << dia1 << " " << mes1 << " " << anio1 << endl;
            }
        } else {
            cout << dia4 << " " << mes4 << " " << anio4 << endl;
            if (f1 >= f2) {
                cout << dia1 << " " << mes1 << " " << anio1 << endl;
                cout << dia2 << " " << mes2 << " " << anio2 << endl;
            } else {
                cout << dia2 << " " << mes2 << " " << anio2 << endl;
                cout << dia1 << " " << mes1 << " " << anio1 << endl;
            }
        }
    } else {
        cout << dia4 << " " << mes4 << " " << anio4 << endl;
        if (f1 >= f2 && f1 >= f3) {
            cout << dia1 << " " << mes1 << " " << anio1 << endl;
            if (f2 >= f3) {
                cout << dia2 << " " << mes2 << " " << anio2 << endl;
                cout << dia3 << " " << mes3 << " " << anio3 << endl;
            } else {
                cout << dia3 << " " << mes3 << " " << anio3 << endl;
                cout << dia2 << " " << mes2 << " " << anio2 << endl;
            }
        } else if (f2 >= f1 && f2 >= f3) {
            cout << dia2 << " " << mes2 << " " << anio2 << endl;
            if (f1 >= f3) {
                cout << dia1 << " " << mes1 << " " << anio1 << endl;
                cout << dia3 << " " << mes3 << " " << anio3 << endl;
            } else {
                cout << dia3 << " " << mes3 << " " << anio3 << endl;
                cout << dia1 << " " << mes1 << " " << anio1 << endl;
            }
        } else {
            cout << dia3 << " " << mes3 << " " << anio3 << endl;
            if (f1 >= f2) {
                cout << dia1 << " " << mes1 << " " << anio1 << endl;
                cout << dia2 << " " << mes2 << " " << anio2 << endl;
            } else {
                cout << dia2 << " " << mes2 << " " << anio2 << endl;
                cout << dia1 << " " << mes1 << " " << anio1 << endl;
            }
        }
    }

    return 0;
}