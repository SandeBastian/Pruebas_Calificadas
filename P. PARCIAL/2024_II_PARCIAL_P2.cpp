#include <iostream>
using namespace std;
int main() {
    int n;
    do {
        cout<<"Ingrese el orden de la matriz n-diagonal: ";
        cin>>n;
    } while (n<0);
    int mat[n][n+1]={0};
    int cont1=0;
    int i=0, j=0;
    while (cont1<n*(n+1)) {
        mat[i][j]=cont1+1;
        cout<<i<<"x"<<j<<"I"<<mat[i][j]<<" ";
        cont1++;
        i++;
        j++;
        if (i==n) {
            i=0;
        }
        if (j==n+1) {
            j=0;
        }
    }
    cout<<"\nMatriz:"<<endl;
    for ( i=0; i<n; i++) {
        for ( j=0; j<n+1; j++) {
         cout<<mat[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"Matriz despues de eliminacion:"<<endl;
    for (i=0; i<n; i++) {
        for (j=0; j<n+1; j++) {
            if (i!=j) {
                cout<<mat[i][j]<<"\t";
            }
        }
        cout<<endl;
    }
    return 0;
}