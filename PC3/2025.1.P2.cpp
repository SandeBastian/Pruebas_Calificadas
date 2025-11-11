/*
Crear una función que reciba una cadena de texto y devuelva la suma de los números encontrados en la
cadena y la cantidad de números enteros y reales encontrados. Debe considerar una función que dado un
digito lo convierte a número.
Por ejemplo:
Si la cadena es
Juan tiene dos cursos aprobados con 14.5 y 13 pero tiene uno desaprobado con 9.3
Entonces el resultado debe ser:
Suma 36.8
Números enteros: 1
Números reales: 2
*/
#include <iostream>
using namespace std;
typedef char cadena[151];



int main () {
    cadena texto;
    cout<<"Ingrese cadena de texto: ";
    cin.getline(texto, 151);
    cout<<"texto: "<<texto<<endl;
    //cout<<texto[4]<<endl; //pruebas
    int i=0;
    int contReal=0;
    int contEnt=0;
    float num=0;
    float sum=0;
    while (texto[i]!='\0') {
        while (!(texto[i]>='0'&&texto[i]<='9')&&texto[i]!='\0') {
            i++;
        }
        //Encuentra un numero
        bool esInt=true;
        if (texto[i]>='0'&&texto[i]<='9') {
            float fact=10;
            while (texto[i]>='0'&&texto[i]<='9') {
                num=num*10+(texto[i]-'0');
                i++;
            }
            //cout<<"Num: "<<num<<endl;
            if (texto[i]=='.') {
                contReal++;
                i++;
                esInt=false;
                while (texto[i]>='0'&&texto[i]<='9') {
                    num=num+(texto[i]-'0')/fact;
                    fact*=10;
                    i++;
                }
            }
            if (esInt) {
                contEnt++;
            }
        }
        //Sale del numero
        //cout<<"#num:"<<num<<endl;
        sum=sum+num;
        num=0;
    }

    cout<<"Suma: "<<sum<<endl;
    cout<<"Numeros Enteros: "<<contEnt<<endl;
    cout<<"Numeros Reales: "<<contReal<<endl;
    return 0;
}