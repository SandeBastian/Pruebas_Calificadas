/*

Crear una función RECURSIVA que permita recibir una línea de texto que contiene valores enteros.
Luego la función debe retornar la suma de dichos valores enteros.
Por ejemplo:
La función recibe la línea de texto:
EL LUNES OBTUVO UN PUNTAJE DE 30, EL MARTES UN PUNTAJE DE 50 Y EL MIERCOLES UN PUNTAJE DE 40. Luego la función retorna: 120
Nota: la función no debe tener procesos repetitivos, pero si emplear otras funciones RECURSIVAS.
*/
#include <iostream>
using namespace std;

bool esPalindroma(string cadena, int inicio, int final) {
    if (inicio==final) return true;
    if (cadena[inicio]!=cadena[final]) return false;
    return esPalindroma(cadena, inicio+1, final-1);
}


int main () {
    string texto;
    cout<<"Ingrese el texto: ";
    getline(cin, texto);


    while (texto[i]!='\0') {
        while (!(texto[i]>='0'&&texto[i]<='9')&&texto[i]!='\0') {
            i++;
        }
        if (texto[i]>='0'&&texto[i]<='9') {
            while (texto[i]>='0'&&texto[i]<='9') {
                num=num*10+(texto[i]-'0');
                i++;
            }
        }
        //Sale del numero
        //cout<<"#num:"<<num<<endl;
        sum=sum+num;
        num=0;
    }

    cout<<"El texto: "<<texto<<endl;
    return 0;
}