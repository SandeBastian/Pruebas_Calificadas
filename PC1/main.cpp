#include <iostream>
using namespace std;

int main(){
    int n;

    do{
        cout << "Ingresar la cantidad de estudiantes:\n";
        cout << "(Numero entero mayor a 0 y menor a 8)\n";
        cin >> n;
    } while (n >= 8 || n <= 0);

    int ans = 0; // respuesta final

    for (int i=1; i<=n; i++){
        int code;
        do{
            cout << "\nIngresar el codigo del estudiante " << i << ":\n";
            cout << "(Numero entero positivo de 4 cifras)\n";
            cin >> code;
        } while (code < 1000 || code > 9999);

        int nota;
        do{
            cout << "Ingresar la nota del estudiante " << i << ":\n";
            cout << "(Numero entero entre 0 y 20 inclusive)\n";
            cin >> nota;
        } while (nota < 0 || nota > 20);

        int control = 0;
        int new_code = 0;

        while (nota > 0){ // esto se ejcuta 1 o 2 veces (depende de la nota)
            int d = nota%10; // se debe eliminar d del code
            int pot10 = 1; // como el anterior problema
            // asumimos que si hay 0 a la izquierda se eliminan
            // si no quedan digitos, supongo que se mostrara un mensaje correspondiente
            // cantidad de digitos = 0 para este caso
            while (code > 0){
                int _d = code%10;
                if (_d != d){
                    new_code += _d * pot10;
                    pot10 *= 10;
                }
                code /= 10;
            }
            code = new_code;
            new_code = 0;
            nota /= 10;
        }

        control = code;

        if (control > 0)
            cout << "Estudiante " << i << "\t\t\t Control : " << control << "\n";
        else{
            cout << "Estudiante " << i << "\t\t\t Control :\n";
            cout << "Se han eliminado todos los digitos\n";
        }

        int cnt = 0;
        while (control > 0){
            cnt++;
            control /= 10;
        }

        ans = ans * 10 + cnt;
    }

    cout << "\nEl numero formado por la secuencia de la cantidad de digitos\n";
    cout << "de los valores de la variable control es: " << ans << "\n";


    return 0;
}