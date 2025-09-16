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