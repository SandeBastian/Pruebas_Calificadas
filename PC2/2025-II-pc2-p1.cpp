#include <iostream>
using namespace std;
int main() {
    int n;
    float m[3][30][10]={0}; //ultima dimension 8+1+1 (para colocar el codigo y ademas el promedio)
    int cte=0; //Variable para Asignar un codigo a cada alumno de manera creciente (+10)
    float prom[30*3]={0}; //arreglo para guardar promedios
    int cont=0; //variable inicializada en 0 para el indice del arreglo "prom"
    int alum=30; //variable para controlar las iteraciones segun la cantidad de alumnos
    int secc1=30, secc2=30, secc3=30; //cantidad de alumnos de cada seccion (max 30)

    do {
        cout<<"Cantidad de alumnos de la seccion 1: ";
        cin>>secc1;
        if (secc1<0||secc1>30) cout<<"Error. Cantidad de alumnos invalida."<<endl;
    }while (secc1<0||secc1>30);
    do {
        cout<<"Cantidad de alumnos de la seccion 2: ";
        cin>>secc2;
        if (secc2<0||secc2>30) cout<<"Error. Cantidad de alumnos invalida."<<endl;
    }while (secc2<0||secc2>30);
    do {
        cout<<"Cantidad de alumnos de la seccion 3: ";
        cin>>secc3;
        if (secc3<0||secc3>30) cout<<"Error. Cantidad de alumnos invalida."<<endl;
    }while (secc3<0||secc3>30);

    for (int i = 0; i < 3; i++) {
        if (i==0) alum=secc1;
        if (i==1) alum=secc2;
        if (i==2) alum=secc3;
        for (int j = 0; j < alum; j++) {
            for (int k = 0; k < 10; k++) {
                if (k!=0&&k!=9){
                    m[i][j][k] = rand()%21;
                    prom[cont] = prom[cont] + m[i][j][k];
                }else if (k==0) {
                    m[i][j][k]=100+cte*10;
                    cte++;
                }
            }
            cont++;
        }
    }
    for (int i=0; i<30*3; i++) {
        prom[i]=prom[i]/8;
    }
    cont=0;
    for (int i = 0; i < 3; i++) {
        if (i==0) alum=secc1;
        if (i==1) alum=secc2;
        if (i==2) alum=secc3;
        for (int j = 0; j < alum; j++) {
            m[i][j][9]=prom[cont++];
        }
    }

    for (int i = 0; i < 3; i++) {
        if (i==0) alum=secc1;
        if (i==1) alum=secc2;
        if (i==2) alum=secc3;
        for (int j = 0; j < alum; j++) {
            if (m[i][j][9]<6) {
                for (int k=j; k<alum-1; k++) {
                    for (int l=0; l<10; l++) {
                        m[i][k][l]=m[i][k+1][l];
                    }
                }
                alum--;
                j--;
            }
        }
        if (i==0) secc1=alum;
        if (i==1) secc2=alum;
        if (i==2) secc3=alum;
    }

    for (int i = 0; i < 3; i++) {
        if (i==0) alum=secc1;
        if (i==1) alum=secc2;
        if (i==2) alum=secc3;
        cout<<"Seccion "<<i+1<<" : "<<endl;
        cout<<"Codigo\tNota 1\tNota 2\tNota 3\tNota4\tNota 5\tNota 6\tNota 7\tNota 8\tProm"<<endl;
        for (int j = 0; j < alum; j++) {
            for (int k = 0; k < 10; k++) {
                cout<<m[i][j][k]<<"\t";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}