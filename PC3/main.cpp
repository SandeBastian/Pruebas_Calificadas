#include <iostream>
using namespace std;

int main () {
    char cadena='5';
    float num=0;
    float fact=10;
    cout<<"Cadena: "<<cadena;
    num=num+(cadena-'0')/fact;
    cout<<"\nNum: "<<num;
    return 0;
}
/*Se ha realizado encuesta sobre la uni de 10 preguntas. Cada encuestado sexo M
masculino F femenino y cadena de 10 digitos del 0 al 5 que corresponde a las
respustas de las preguntas. El valor 0 coresponde a "No sabe, no opina".
Luego de ingesar debe determinar:
a) porcentaje de participacion m y F
b que pregunta tuvo mayor porcentaje de no sabe
c que pregunta o preguntas fueron las que tuvieron la mejor opinion del sexo masculno
d que preguntea o preguntas  tuvieron mejor opinion del sex femmenino

F 0115453325
M 1002235522
M 0103405434
F 5204355445f
F 0103405434
M 1312234322
F 1002235522
F 4314350045


*/