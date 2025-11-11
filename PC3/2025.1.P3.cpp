/*
Diseñar una funcion que reciba una cadena de texto compuesta por letras, digitos y espacios, pero que contiene errores de formato. El
objetivo es corregir el texto siguiendo estas reglas:
▪ El texto solo debe contener letras y un único espacio entre palabras.
▪ Cada palabra puede tener digitos intercalados: estos deben eliminarse.
▪ Luego de eliminar los dígitos de cada palabra, se debe invertir el orden de sus letras.
▪ Finalmente, se deben eliminar todos los espacios en blanco innecesarios, es decir:
• Espacios múltiples entre palabras → dejar solo uno.
• Espacios antes o después del texto → eliminarlos.

Ejemplo:
Texto que se envía a la función:
_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
I A N U  O L 4 5 QUE FLOJERA COPIAR ESA CADENA

La funcion debe mostrar
Texto Corregido: UNI SOLO PARA GANADORES
Espacios eliminados: 4
Digitod: 6

*/

#include <iostream>
#include <cstring>
using namespace std;
typedef char cadena[201];


int main () {
    cadena texto;
    cout<<"Ingrese cadena de texto: ";
    cin.getline(texto, 201);
    cout<<"Texto Antes: "<<texto<<endl;
    //cout<<texto[4]<<endl; //pruebas
    int pos=0;
    int contDig=0;
    int longitud=strlen(texto);
    cout<<"Longitud: "<<longitud<<endl;
    bool primerCaracter=false;
    while (texto[pos]!='\0') {
        //eliminacion de todos los espacios iniciales
        if (!primerCaracter) {
            while (texto[pos]==' ') {
                for (int i=pos; i<longitud; i++) {
                    texto[i]=texto[i+1];
                }
                pos--;
                longitud--;
            }
            primerCaracter=true;
        }
        if (!((texto[pos]>='A'&&texto[pos]<='Z')||(texto[pos]>='a'&&texto[pos]<='z')||texto[pos]==' ')){
            for (int i=pos; i<longitud; i++) {
                texto[i]=texto[i+1];
            }
            contDig++;
            pos--;
            longitud--;
        }

        //elimina espacios cuando hay 2 ( i==' ' && i+1==' ' ) elimina i
        if ((texto[pos]==' '&&texto[pos+1]==' ')||(texto[pos]==' '&&texto[pos+1]=='\0')) {
            for (int i=pos; i<longitud; i++) {
                texto[i]=texto[i+1];
            }
            pos--;
            longitud--;
        }
        pos++;
    }

    pos=0;
    int inicio=0;
    int fin=0;
    while (texto[pos]!='\0') {
        inicio=pos;
        while (texto[pos]!=' '&&texto[pos]!='\0') {
            pos++;
        }
        fin = pos-1;
        while (inicio<fin) {
            char aux=texto[inicio];
            texto[inicio]=texto[fin];
            texto[fin]=aux;
            inicio++;
            fin--;
        }
        if (texto[pos]=='\0') break;
        pos++;
    }


    cout<<"\nTexto Despues (como arreglo): ";
    for (int i=0; i<longitud; i++) {
        cout<<texto[i];
    }
    cout<<"\nTexto Despues: "<<texto<<endl;
    return 0;
}