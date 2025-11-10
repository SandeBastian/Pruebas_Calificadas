#include <iostream>
using namespace std;
//CON FUNCION SOLO FUNCION
bool esPalindroma(string cadena, int inicio, int final) {
    if (inicio==final) return true;
    if (cadena[inicio]!=cadena[final]) return false;
    return esPalindroma(cadena, inicio+1, final-1);
}

int main () {
    string cadena;
    cout<<"Ingrese la cadena: ";
    cin>>cadena;
    if (esPalindroma(cadena, 0, cadena.size()-1)) cout<<"Es palindroma"<<endl;
    else cout<<"No palindroma"<<endl;
    return 0;
 }