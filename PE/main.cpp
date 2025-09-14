/*Ejemplo 5:
Para un conjunto de N fechas (d/m/a) se desea averiguar cuál es la más
reciente y el número de apariciones
Ejemplo:
N=6
12/10/2008 => 20081012
13/05/2007 => 20070513
14/06/2004 => 20040614
12/10/2009 => 20091012
11/06/2007 => 20070611
12/10/2009 => 20091012
La fecha más reciente es: 12/10/2009
Aparece: 2
*/
#include<iostream>
using namespace std;
int main(){
    int n,i,cont=0,num,max = 0, ap;
    int d,m,a;
    do{
        cout<<"Ingrese N="; cin>>n;
    }while(!(n>0));
    for(int i=0;i<n;i++){
        cout<<"fecha: "<<(i+1)<<endl;
        cout<<"d="<<endl;cin>>d;
        cout<<"m="<<endl;cin>>m;
        cout<<"a="<<endl;cin>>a;
        num = a*10000+m*100+d;
        if(num>max){
            max = num;
            ap=1;
        }else{
            if(num==max){
                ap++;
            }
        }
    }

    a = max/10000;
    max = max%10000;
    m = max/100;
    d = max%100;

    cout<<"La fecha es: "<<d<<"/"<<m<<"/"<<a<<endl;
    cout<<"#ro de aparaciones :"<<ap<<endl;
    return 0;
}