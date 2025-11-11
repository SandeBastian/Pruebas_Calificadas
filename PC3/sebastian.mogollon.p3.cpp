#include <iostream>
using namespace std;

typedef char cadena[201];

void propagar(cadena texto, int pos) {

    if (texto[pos] == '\0') return;

    if (!((texto[pos]>='A'&& texto[pos]<='Z')||(texto[pos]>='a'&&texto[pos]<='z')||(texto[pos] >= '0' && texto[pos] <= '9'))) {
        char simbolo = texto[pos];
        int i = pos + 1;

        while (texto[i] >= '0' && texto[i] <= '9') {
            texto[i] = simbolo;
            i++;
        }
        propagar(texto, i);
    } else {
              propagar(texto, pos + 1);
    }
}

int main() {
    cadena texto;
    cout << "Ingrese texto: ";
    cin.getline(texto, 201);

    propagar(texto, 0);

    cout << "Resultado: " << texto << endl;
    return 0;
}