#include <iostream>
using namespace std;
//SIN FUNCIONES SOLO CONTADORES Y BUCLES
int main () {
    char cadena[1000];
    cout<<"Ingrese la cadena: ";
    cin>>cadena;
    int cont=0;
    while (cadena[cont]!='\0') {
        cont++;
    }
    int i=0;
    int f=cont-1;
    bool palindroma=true;
    while (i<f) {
        if (cadena[i]!=cadena[f]) {
            palindroma=false;
            break;
        }
        i++;
        f--;
    }
    if (palindroma) cout<<"Es palindroma"<<endl;
    else cout<<"No palindroma"<<endl;
    return 0;
 }