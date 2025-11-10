#include <iostream>
using namespace std;
int main() {
    int n;
    do {
        cout<<"Ingrese la cantidad d numero: ";
        cin>>n;
        if (n<1||n>50) cout<<"Error, cantidad invalida."<<endl;
    }while (n<1||n>50);
    int a[n]={0};
    // 59 22 59 101 22 151 59
    for ( int i=0; i<n; i++) {
        do {
            cout<<"Ingrese numeros (de 2 y 3 cifras): ";
            cin>>a[i];
            if (a[i]<10||a[i]>999) cout<<"Error, numero invalido. "<<endl;
        }while (a[i]<10||a[i]>999);
    }
    for ( int i=n-1; i>=0; i--) {
        for ( int j=0; j<n; j++) {
            if (i!=j) {
                if (a[i]==a[j]) {
                    //cout<<i<<"x"<<j<<endl;
                    for (int k=j; k<n-1; k++) {
                        a[k]=a[k+1];
                    }
                    j--;
                    n--;
                    i--;
                }
            }
        }
    }
    cout<<n<<endl;
    cout<<"\nMat: "<<endl;
    for (int i=0; i<n; i++) cout<<a[i]<<" ";

    int prom=0;
    for (int i=0; i<n; i++) {
        prom=prom+a[i];
    }
    prom=prom/n;
    for (int i=0; i<n; i++) {
        bool primo=true;
        for (int j=2; j<a[i]; j++) {
            if (a[i]%j==0) {
                primo=false;
            }
        }
        if (primo) {
            for (int j=n; j>i; j--) {
                a[j]=a[j-1];
            }
            n++;
            i++;
        }
    }
    cout<<endl;
    cout<<n<<endl;
    cout<<"\nMat: "<<endl;
    for (int i=0; i<n; i++) cout<<a[i]<<" ";
}