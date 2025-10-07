/*
Dados dos conjuntos A y B de m y n elementos enteros, se define la distancia entre los conjuntos A y B
como el número de elementos de la diferencia simétrica de dichos conjuntos con sus elementos indexados.

Ejemplo:

Conjunto A = {1, 3, 5, 7}
Conjunto A con sus elementos indexados: A_Ind = {1_1, 3_2, 5_3, 7_4}

Conjunto B = {1, 2, 4, 5}
Conjunto B con sus elementos indexados: B_Ind = {1_1, 2_2, 4_3, 5_4}

Diferencia simétrica de A_Ind y B_Ind:
(A_Ind - B_Ind) ∪ (B_Ind - A_Ind) = {2_2, 3_2, 4_3, 5_3, 5_4, 7_4}

La distancia entre A y B es: 6

Nota: Validar que los elementos de un conjunto no se repitan.

*/
#include <iostream>
using namespace std;

int main() {

    // reutilizamos código del problema 1
    // aunque en este caso sí se permiten valores negativos
    int m;
    do{
        cout << "Ingresar el valor de m (m > 0):\n";
        cin >> m;
        if (m <= 0) cout << "Error: valor no positivo\n";
    } while (m <= 0);
    int a[m];
    cout << "Ingresar " << m << " valores distintos\n";
    for (int i=0; i<m; i++){
        bool flag;
        do {
            cout << "Valor #" << i+1 << ":\n";
            cin >> a[i];

            flag = false;
            for (int j=0; j<i; j++){
                if (a[j] == a[i]) flag = true;
            }
            if (flag) cout << "Valor repetido\n";
        } while (flag);
    }
    //==================================================================================================
    int n;
    do{
        cout << "Ingresar el valor de n (n > 0):\n";
        cin >> n;
        if (n <= 0) cout << "Error: valor no positivo\n";
    } while (n <= 0);
    int b[n];
    cout << "Ingresar " << n << " valores distintos\n";
    for (int i=0; i<n; i++){
        bool flag;
        do {
            cout << "Valor #" << i+1 << ":\n";
            cin >> b[i];

            flag = false;
            for (int j=0; j<i; j++){
                if (b[j] == b[i]) flag = true;
            }
            if (flag) cout << "Error: Valor repetido\n";
        } while (flag);
    }
    //=====================================================================================================

    int c[n+m],ind[n+m]; // valores e indices
    int sz = n+m;

    for (int i=0; i<m; i++) {
        c[i] = a[i];
        ind[i] = i+1;
    }

    for (int i=0; i<n; i++){
        c[m+i] = b[i];
        ind[m+i] = i+1;
    }

    for (int i=0; i<sz; i++)
        for (int j=i+1; j<sz; j++)
            if (c[j] < c[i]){
                int aux = c[i];
                int aux_ind = ind[i];
                c[i] = c[j];
                c[j] = aux;
                ind[i] = ind[j];
                ind[j] = aux_ind;
            }


    cout << "C : ";
    for (int i=0; i<sz; i++) cout << c[i] << " " << ind[i] << "\n";
    cout << "\n";


    for (int i=0; i<sz; i++){
        // solo puede ocurrir la igualdad para dos valores consecutivos
        if (i+1 < sz && c[i] == c[i+1] && ind[i] == ind[i+1]) {
            // eliminamos ambos
            // cout << "eliminar " << i << " " << i + 1 << "\n";
            for (int j = i; j + 1 < sz; j++) {
                c[j] = c[j + 1];
                ind[j] = ind[j + 1];
            }
            sz--;
            for (int j = i; j + 1 < sz; j++) {
                c[j] = c[j + 1];
                ind[j] = ind[j + 1];
            }
            sz--;
            // i tiene un nuevo valor c[i]
            // por lo que podría se eliminado otra vez
            // tenemos que evaluarlo otra vez
            // como luego se hace i++, hacemos i--
            i--;
        }
    }

    cout << "A : ";
    for (int i=0; i<m; i++) cout << a[i] << " ";
    cout << "\n";

    cout << "B : ";
    for (int i=0; i<n; i++) cout << b[i] << " ";
    cout << "\n";

    cout << "DIFERENCIA SIMETRICA : (valor, indice)\n";
    for (int i=0; i<sz; i++) cout << " ( " << c[i] << ", " << ind[i] << " )\n";

    cout << "La distancia entre A y B es " << sz << "\n";

    return 0;
}