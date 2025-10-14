#include <iostream>
using namespace std;

int main() {
    const int n = 5;
    int M[n][n], N[n][n];

    // Generar matriz M con valores (puedes cambiarlos o llenarlos manualmente)
    cout << "Ingrese la matriz M (valores entre 0 y 7):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            do {
                cout << "M[" << i << "][" << j << "]: ";
                cin >> M[i][j];
            } while (M[i][j] < 0 || M[i][j] > 7);
        }
    }

    // Calcular N con medianas de vecinos
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int vec[9], sz = 0;

            // Recorremos los vecinos válidos (sin salirnos de la matriz)
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    int ni = i + di, nj = j + dj;
                    if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                        vec[sz] = M[ni][nj];
                        sz++;
                    }
                }
            }

            // Ordenamiento burbuja (sin sort)
            for (int a = 0; a < sz - 1; a++) {
                for (int b = a + 1; b < sz; b++) {
                    if (vec[a] > vec[b]) {
                        int aux = vec[a];
                        vec[a] = vec[b];
                        vec[b] = aux;
                    }
                }
            }

            // Mediana (si par → promedio y redondeo)
            if (sz % 2 != 0)
                N[i][j] = vec[sz / 2];
            else {
                float med = (vec[sz/2 - 1] + vec[sz/2]) / 2.0;
                if (med - (int)med >= 0.5) N[i][j] = (int)med + 1;
                else N[i][j] = (int)med;
            }
        }
    }

    // Mostrar matriz N
    cout << "\nMatriz N generada:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << N[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
