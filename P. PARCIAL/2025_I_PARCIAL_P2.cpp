#include <iostream>
using namespace std;
int main() {
     int a[5], b[5], c;
     cout<<"Ingrese la cifras de A (de izq a derecha): "<<endl;
     for ( int i=0; i<5; i++) {
         do {
             cout<<"A ["<<i+1<<"]: ";
             cin>>a[i];
             if (a[i]<0||a[i]>9) cout<<"Error, valor invalido."<<endl;
         }while (a[i]<0||a[i]>9);
     }
     cout<<"Ingrese la cifras de B (de izq a derecha): "<<endl;
     for ( int i=0; i<5; i++) {
         do {
             cout<<"B ["<<i+1<<"]: ";
             cin>>b[i];
             if (b[i]<0||b[i]>9) cout<<"Error, valor invalido"<<endl;
         }while (b[i]<0||b[i]>9);
     }
    do {
        cout<<"Ingrese el digito C: ";
        cin>>c;
        if (c<0||c>9) cout<<"Error, valor invalido."<<endl;
    }while (c<0||c>9);

     int m[5+5]={0};
     int sz=0;
     for (int i=0; i<5; i++) {
         if (a[i]%2!=0) {
             m[sz]=a[i];
             cout<<m[sz]<<" ";
             sz++;
         }
     }
    cout<<endl;
    int pos=sz;
     for (int i=0; i<5; i++) {
         if (b[i]%2==0) {
             m[sz]=b[i];
             cout<<m[sz]<<" ";
             sz++;
         }
     }
    cout<<"\nA y B: "<<endl;
    for (int i=0; i<sz; i++) {
        cout<<m[i]<<" ";
    }

     for (int i=0; i<sz-1; i++) {
         for (int j=i; j<sz; j++) {
             if (m[i]<m[j]) {
                 int aux=m[i];
                 m[i]=m[j];
                 m[j]=aux;
             }
         }
     }
    cout<<"\nA y B: "<<endl;
    for (int i=0; i<sz; i++) {
        cout<<m[i]<<" ";
    }
    int cont=1;
    int d[sz]={0};
    int k=sz-1, l=0;
    while (cont<=sz) {
        if (cont%2!=0) {
            d[cont-1]=m[k--];
            cont++;
        }else {
            d[cont-1]=m[l++];
            cont++;
        }
    }
    int n=0;
    while (n<sz) {
        if (d[n]==c||d[n]==0) { //agregue el 0 pero creo que no es necesario
            for (int i=n; i<sz-1; i++) {
                d[i]=d[i+1];
            }
            sz--;
        }else {
            n++;
        }
    }
    cout<<"\nMatriz ZigZag: "<<endl;
    for (int i=0; i<sz; i++) {
        cout<<d[i]<<" ";
    }
    return 0;
}