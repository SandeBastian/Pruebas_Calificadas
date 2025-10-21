#include <iostream>
#include <cmath>
using namespace std;
int main () {
    int n;
    bool convexo = false;
    float x[4];
    float y[4];
    do {
        cout<<"A: "<<endl;
        cout<<"x1: "; cin>>x[0];
        cout<<"y1: "; cin>>y[0];
        cout<<"B: "<<endl;
        cout<<"x2: "; cin>>x[1];
        cout<<"y2: "; cin>>y[1];
        cout<<"C: "<<endl;
        cout<<"x3: "; cin>>x[2];
        cout<<"y3: "; cin>>y[2];
        cout<<"D: "<<endl;
        cout<<"x4: "; cin>>x[3];
        cout<<"y4: "; cin>>y[3];
        convexo = true;
        for (int i=0; i<4; i++) {
            float areaOpuesta=abs((x[(i+1)%4]*y[(i+2)%4]+x[(i+2)%4]*y[(i+3)%4]+x[(i+3)%4]*y[(i+1)%4])-(y[(i+1)%4]*x[(i+2)%4]+y[(i+2)%4]*x[(i+3)%4]+y[(i+3)%4]*x[(i+1)%4]))*0.5;
            float s1=abs((x[i]*y[(i+1)%4]+x[(i+1)%4]*y[(i+2)%4]+x[(i+2)%4]*y[i]) - (y[i]*x[(i+1)%4]+y[(i+1)%4]*x[(i+2)%4]+y[(i+2)%4]*x[i]))*0.5;
            float s2=abs((x[i]*y[(i+2)%4]+x[(i+2)%4]*y[(i+3)%4]+x[(i+3)%4]*y[i]) - (y[i]*x[(i+2)%4]+y[(i+2)%4]*x[(i+3)%4]+y[(i+3)%4]*x[i]))*0.5;
            float s3=abs((x[i]*y[(i+3)%4]+x[(i+3)%4]*y[(i+1)%4]+x[(i+1)%4]*y[i]) - (y[i]*x[(i+3)%4]+y[(i+3)%4]*x[(i+1)%4]+y[(i+1)%4]*x[i]))*0.5;
            if (areaOpuesta == s1+s2+s3) {
                convexo = false;
            }
        }
        if (not convexo) cout<<"Error. No es un cuadrilatero convexo, vuelva a ingresar los vertices"<<endl;
    }while (not convexo);

    float px,py;
    cout<<"Punto P: "<<endl;
    cout<<"Px:"; cin>>px;
    cout<<"Py:"; cin>>py;

    //Verificar que este adentro de uno de los dos triangulos ABC o ACD

    float areaOp1 = abs((x[0]*y[1]+x[1]*y[2]+x[2]*y[0])-(y[0]*x[1]+y[1]*x[2]+y[2]*x[0]))*0.5;

    float s1 = abs((px*y[0]+x[0]*y[1]+x[1]*py)-(py*x[0]+y[1]*x[2]+y[2]*x[0]))*0.5;
    float s2 = abs((px*y[1]+x[1]*y[2]+x[2]*py)-(py*x[1]+y[1]*x[2]+y[2]*px))*0.5;
    float s3 = abs((px*y[0]+x[0]*y[2]+x[2]*py)-(py*x[0]+y[0]*x[2]+y[2]*px))*0.5;



    float areaOp2 = abs((x[0]*y[2]+x[2]*y[3]+x[3]*y[0])-(y[0]*x[2]+y[2]*x[3]+y[3]*x[0]))*0.5;

    float s4 = abs((px*y[0]+x[0]*y[2]+x[2]*py)-(py*x[0]+y[0]*x[2]+y[2]*px))*0.5;
    float s5 = abs((px*y[2]+x[2]*y[3]+x[3]*py)-(py*x[2]+y[2]*x[3]+y[3]*px))*0.5;
    float s6 = abs((px*y[0]+x[0]*y[3]+x[3]*py)-(py*x[0]+y[0]*x[3]+y[3]*px))*0.5;


    if (areaOp1 == s1 + s2 + s3 or areaOp2 == s4 + s5 + s6) {
        cout<<"El punto se encuentra dentro de la region";
    } else cout<<"El punto se encuentra fuera de la region";
    return 0;
}