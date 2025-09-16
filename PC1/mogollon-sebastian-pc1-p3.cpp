#include <iostream>
using namespace std;
int main() {
    int n, num;
    do {
        cout<<"Ingrese un cantidad de numeros n (n<=8): ";
        cin>>n;
    }while (n<0||n>8);
    for (int i=0; i<n; i++) {
        cout<<"Ingrese un numero "<<i+1<<": ";
        cin>>num;

    }
    return 0;
}