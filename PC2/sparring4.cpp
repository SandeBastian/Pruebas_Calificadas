#include <iostream>
using namespace std;
int main() {
    int n;
    cout<<"Ingrese n:";
    cin>>n;
    bool primo=true;
    int div=2;
    while (div<n) { //antes ponia el booleando adentro pero en este caso con break ya es suficiente y el booleano para el if
        if (n%div==0) {
            primo=false;
            break;
        }
        div++;
    }
    if (primo) cout<<"Es primo"<<endl;
    else cout<<"No es primo"<<endl;
    return 0;
}