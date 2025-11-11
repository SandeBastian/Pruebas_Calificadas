#include <iostream>
using namespace std;

void generarSubconjuntos(int a[], int n, int pos, int subconj[], int m) {
    if (pos == n) {
        cout << "(";
        for (int i = 0; i < m; i++) {
            cout << a[subconj[i]];
            if (i < m - 1) cout << ",";
        }
        cout << ") ";
        return;
    }
    generarSubconjuntos(a, n, pos + 1, subconj, m);

    subconj[m] = pos;
    generarSubconjuntos(a, n, pos + 1, subconj, m + 1);
}

int main() {
    int n;
    cout << "Ingrese longitud: ";
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) {
        cout << "a[" << i + 1 << "]: ";
        cin >> a[i];
    }

    int subconj[n];
    cout << "\nSubconjuntos:\n";
    generarSubconjuntos(a, n, 0, subconj, 0);
    cout << endl;

    return 0;
}
