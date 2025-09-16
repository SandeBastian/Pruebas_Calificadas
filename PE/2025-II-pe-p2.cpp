/*reciba un numero entero positivo de 6 cifras, el algoritmo debe calcular el producto de digitos pares y la suma de digitos imapre
(mostrar en consola) luego determinar si la suma de digitos impares es mayor que el producto de digitos  pares. Si es asi, debe
imprimir el numero original invertido. sino imprime el numero sin modificar
*/
#include <iostream>
using namespace std;
int main () {
    int n, aux, r, sumImp=0, prodPar=1, inv=0;
    do {
        cout<<"Ingrese el numero (positivo de 6 cifras): ";
        cin >> n;
    }while (n<100000||n>1000000);
    aux=n;
    while (aux>0) {
        r=aux%10;
        aux=aux/10;
        if (r%2!=0) {
            sumImp=sumImp+r;
        }else {
            prodPar=prodPar*r;
        }
    }
    r=0;
    aux=n;
    if (sumImp>prodPar) {
        while (aux>0) {
            r=aux%10;
            aux=aux/10;
            inv=inv*10+r;
        }
        cout<<"Producto de digitos pares: "<<prodPar<<endl;
        cout<<"Suma de digitos Impares: "<<sumImp<<endl;
        cout<<"Numero Invertido: "<<inv<<endl;
    }else {
        cout<<"Producto de digitos pares: "<<prodPar<<endl;
        cout<<"Suma de digitos Impares: "<<sumImp<<endl;
        cout<<"Numero Original sin invertir: "<<n<<endl;
    }
    return 0;
}