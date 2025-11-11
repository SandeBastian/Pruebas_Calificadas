#include <iostream>
#include <cstring>
using namespace std;

struct Encuest {
    char sex;
    char resp[11];
};

void IngresasDatos(int n, Encuest pers[]) {
    char sexo;
    for (int i = 0; i < n; i++) {
        cout << "Sexo de Persona [" << i + 1 << "]: ";
        cin >> sexo;
        pers[i].sex = toupper(sexo);
        cout << "Respuesta de Persona [" << i + 1 << "]: ";
        cin >> pers[i].resp;
    }
}

int main() {
    int n;
    cout << "Ingrese la cantidad de encuestados: ";
    cin >> n;

    Encuest pers[n];
    IngresasDatos(n, pers);

    char sexo;
    for (int i = 0; i < n; i++) {
        cout << "Sexo de Persona [" << i + 1 << "]: ";
        cin >> sexo;
        pers[i].sex = toupper(sexo);
        cout << "Respuesta de Persona [" << i + 1 << "]: ";
        cin >> pers[i].resp;
    }

    cout << "\nSexo\tRespuesta" << endl;
    for (int i = 0; i < n; i++) {
        cout << pers[i].sex << "\t" << pers[i].resp << endl;
    }

    int contM = 0, contF = 0;
    for (int i = 0; i < n; i++) {
        if (pers[i].sex == 'M') contM++;
        else if (pers[i].sex == 'F') contF++;
    }

    cout << "\nPorcentaje de participacion:" << endl;
    cout << "Masculino: " << (contM * 100.0 / n) << "%" << endl;
    cout << "Femenino: " << (contF * 100.0 / n) << "%" << endl;

    int noSabe[10] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            if (pers[i].resp[j] == '0') noSabe[j]++;
        }
    }

    int maxNoSabe = 0, pregNoSabe = 0;
    for (int j = 0; j < 10; j++) {
        if (noSabe[j] > maxNoSabe) {
            maxNoSabe = noSabe[j];
            pregNoSabe = j;
        }
    }
    cout << "\nPregunta con mayor porcentaje de 'No sabe': " << pregNoSabe + 1 << endl;

    int sumM[10] = {0}, sumF[10] = {0}, cantM[10] = {0}, cantF[10] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            int valor = pers[i].resp[j] - '0';
            if (pers[i].sex == 'M') {
                sumM[j] += valor;
                cantM[j]++;
            } else {
                sumF[j] += valor;
                cantF[j]++;
            }
        }
    }

    float promM[10], promF[10];
    for (int j = 0; j < 10; j++) {
        promM[j] = cantM[j] ? (float)sumM[j] / cantM[j] : 0;
        promF[j] = cantF[j] ? (float)sumF[j] / cantF[j] : 0;
    }

    float maxM = 0, maxF = 0;
    for (int j = 0; j < 10; j++) {
        if (promM[j] > maxM) maxM = promM[j];
        if (promF[j] > maxF) maxF = promF[j];
    }

    cout << "\nPregunta/s con mejor opinion del sexo masculino: ";
    for (int j = 0; j < 10; j++) {
        if (promM[j] == maxM) cout << j + 1 << " ";
    }

    cout << "\nPregunta/s con mejor opinion del sexo femenino: ";
    for (int j = 0; j < 10; j++) {
        if (promF[j] == maxF) cout << j + 1 << " ";
    }

    cout << endl;
    return 0;
}
