#include <iostream>
#include <time.h>
using namespace std;
int main() {
    srand(time(NULL));
    int n;
    do {
        cout<<"Ingrese el orden de la matriz: ";
        cin>>n;
        if (n<=0||n%2==0) cout<<"Error, orden no valido"<<endl;
    }while (n<=0||n%2==0);

    int m[n][n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++ ) {
            m[i][j]=1+rand()%100;
        }
    }
    cout<<"\nMatriz: "<<endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout<<m[i][j]<<"\t";
        }
        cout<<endl;
    }
    int inf=n/4;
    int sup=(n*3)/4;
    int sz;
    /*
    do {
        cout<<"Ingrese el limite de fibonacci: ";
        cin>>sz;
        if (sz<=0) cout<<"Error, limite no valido"<<endl;
    }while (sz<=0);
    */
    int fib[100];
    fib [0]=1;
    fib [1]=1;
    for (int i=2; i<100; i++ ) {
        fib[i]=fib[i-1]+fib[i-2];
    }
    cout<<"Fib: "<<endl;
    for (int i=0; i<100; i++) cout<<fib[i]<<endl;
    return 0;
}