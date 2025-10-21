#include <iostream>
using namespace std;
int main() {
    //srand(time(NULL));
    int m[5][5]={0};
    for (int i=0;i<5;i++) {
        for (int j=0;j<5;j++) {
            m[i][j]=rand()%8;
        }
    }
    cout<<"\nMatriz:"<<endl;
    for (int i=0;i<5;i++) {
        for (int j=0;j<5;j++) {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    float n[9];
    int cont=0;
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            if ((i>0&&i<4)&&(j>0&&j<4)) {
                cont=0;
                cout<<"\nn "<<i<<"x"<<j<<": "<<endl;
                for (int k=i-1; k<=i+1; k++) {
                    for (int l=j-1; l<=j+1; l++) {
                        n[cont++]=m[k][l];
                        cout<<m[k][l]<<" ";
                    }
                    cout<<endl;
                }

                cout<<"\nn "<<i<<"x"<<j<<": "<<endl;
                for (int k=0; k<cont; k++) {
                    cout<<n[k]<<" ";
                }
                cout<<endl;
                
            }
            if (i==0&&j==0) {
                m[i][j]=1;
            }
        }
    }
    cout<<"\nMatriz:"<<endl;
    for (int i=0;i<5;i++) {
        for (int j=0;j<5;j++) {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}