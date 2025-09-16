/*
PRIMERA PRACTICA CALIFICADA 2024-II
Pregunta 3 (de 9:10 a 9:43 am) 5 puntos
Se ha tomado un examen sustitutorio de algoritmos a n estudiantes, donde n menor a 8 y por cada estudiante se tiene su código
(número de 4 cifras) y la nota que obtuvo'. Se pide escribir un programa que reciba el código y la nota de cada estudiante y
determine el valor de una variable "control" que se obtiene eliminando del código los dígitos que corresponden a la nota.
Finalmente muestre un número formado por la secuencia de la cantidad de dígitos de cada valor de "control".
Ejemplo, si los valores ingresados son:

    Código      Nota        Control
    4123        12          43
    2145        4           215
    5189        14          589
    6120        6           120
    3512        15          32

El número formado por la secuencia de la cantidad de dígitos de los valores de la variable control es 23332
Nota: No se puede emplear arreglos, cadenas, ni funciones.
*/
#include <iostream>
using namespace std;
int main () {
    int n, cod, nota, control=0, cont=0, aux1, aux2, r1, r2, fact, newNum=0;
    do {
        cout<<"Ingrese la cantidad de estudiantes (entre 0 y 8): ";
        cin>>n;
        if (n<0||n>8) cout<<"Error. Numero invalido"<<endl;
    }while (n<0||n>8);
    for (int i=0; i<n; i++) {
        do {
            cout<<"Ingrese el Codigo ["<<i+1<<"] (de 4 cifras): ";
            cin>>cod;
            if (cod<1000||cod>9999) cout<<"Error. Codigo invalido"<<endl;
        }while (cod<1000||cod>9999);
        do {
            cout<<"Ingrese la Nota ["<<i+1<<"] (entre 0 a 20): ";
            cin>>nota;
            if (nota<0||nota>20) cout<<"Error. Nota invalida"<<endl;
        }while (nota<0||nota>20);
        aux1=cod;
        aux2=nota;
        bool flag=true;
        while (flag) {
            r1=aux1%10;
            fact=1;
            control=0;
            cont=0;
            while (aux2>0) {
                r2=aux2%10;
                aux2=aux2/10;
                if (r1!=r2) {
                    aux1=r1*fact+aux1;
                    fact=fact*10;
                    cont++;
                }
                if (aux2==0) flag=false;
            }
        }
        newNum=newNum*10+cont;
        cout<<"Codigo"<<"\t\t\t"<<"Nota"<<"\t\t\t"<<"Control"<<endl;
        cout<<cod<<"\t\t\t"<<nota<<"\t\t\t"<<aux1<<endl;
    }
    cout<<"El numero formado por la concatenacion de la cantidad de digitos del control: "<<newNum<<endl;
    return 0;
}
/*
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
*/