/*
PRUEBA DE ENTRADA 2024-I
Pregunta 3 (de 9:04 a 9:34 am) 2 puntos
En una isla lejana hay 100 habitantes, todos ellos tienen o bien ojos verdes o bien ojos marrones. Todos ven el
color de los ojos de los otros, pero no el propio. Está prohibido hablar entre ellos de ese tema y no hay espejo
ni nada parecido que les permita ver el color propio. Pero hay una ley que dice que, si alguien descubre que tiene
los ojos verdes, tiene que abandonar la isla inexorablemente a las 7 de la mañana del día siguiente. Todos los pobladores
tienen la misma capacidad lógica para para razonar. Un día, una persona llega de visita a la isla y, mientras, los mira a
todos, dice: ¡Qué bueno es ver al menos una persona con ojos verdes después de tanto tiempo de estar en alta mar!, Si había
n habitantes con los ojos verdes, cuántos de ellos abandonarían la isla un día después de la llegada del visitante, cuantos 2
días después, y así sucesivamente hasta el enésimo día después. Explicar cómo dedujo su respuesta.
 */
#include <iostream>
using namespace std;
int main() {
    int n;
    cout<<"-Existen 100 habitantes"<<endl;
    cout<<"-Existen 'n' habitantes con ojos verdes"<<endl;
    do {
        cout<<"\nNumero de Habitantes de Ojos verdes (n) <<Sugerencia pruebe con 1,2,3, sucesivamente>>: ";
        cin>>n;
    }while (n<0);
    if (n==0){
       cout<<"Nadie se va de la isla. Nadie tiene ojos verdes"<<endl;
    }else{
        cout<<"El Visitante confirma que existe almenos 1 (o mas) habitantes de ojos verdes"<<endl;
        cout<<"Conocimiento de la/s persona/s con ojos verdes:"<<endl;
        cout<<"-Hay ["<<100-n<<"] personas de ojos marrones"<<endl;
        cout<<"-Hay ["<<n-1<<"] personas de ojos verdes"<<endl;
        for (int i=0;i<n; i++) {
            if (i+1==n) {
                cout<<"*Dia ["<<i+1<<"]:"<<endl;
                cout<<"-Ahora. La/s persona/s de ojos verdes tiene/n el conocimiento de que hay ["<<100-n<<"] personas de ojos marrones"<<endl;
                if (i==0) {
                    cout<<"-La persona con ojos verdes solo puede ver ["<<n-1<<"] personas de ojos verdes"<<endl;
                    cout<<"->La persona de ojos verdes ahora sabe que tiene ojos verdes, entonces abandona de la isla."<<endl;
                }else {
                    cout<<"-Las personas de ojos verdes (cada una de las personas con ojos verdes) solo puede ver ["<<n-1<<"] personas de ojos verdes"<<endl;
                    cout<<"->Las personas de ojos verdes ahora saben que tienen ojos verdes, las ["<<i+1<<"] personas abandonan la isla."<<endl;
                }
            }else {
                cout<<"Dia ["<<i+1<<"] (7 am): "<<endl;
                cout<<"-Como nadie se fue, significa que cada persona de ojos verdes esperaba que otro/s se fuese de la isla"<<endl;
                cout<<"-Esto implica y confirma a todos (las personas de ojos verdes) que hay ["<<i+1<<"+1] personas de ojos verdes"<<endl;
            }
        }
    }
    return 0;
}