/*
PRIMERA PRACTICA CALIFICADA 2025-I
Suponga que las posiciones de los casilleros de un tablero de ajedrez se identifican por un numero de 2 cifras,
ejemplo 34 representa el casillero de la fila 3 y la columna 4. En base a lo anterior desarrolle un algoritmo en
C++ que reciba las posiciones de dos caballos y determine si se atacan mutuamente. Los caballos se atacan si están
en los casilleros extremos de una L formada por 4 casilleros.

Ejemplo 1: 42 y 54 se atacan

Ejemplo 2: 42 y 64 no se atacan

   1  2  3  4  5  6  7  8
1  11 12 13 14 15 16 17 18
2  21 22 23 24 25 26 27 28
3  31 32 33 34 35 36 37 38
4  41 42 43 44 45 46 47 48
5  51 52 53 54 55 56 57 58
6  61 62 63 64 65 66 67 68
7  71 72 73 74 75 76 77 78
8  81 82 83 84 85 86 87 88

Nota: Resolver sin emplear arreglos, ni cadenas, ni funciones.
*/
#include <iostream>
using namespace std;

int main() {
   int pos1, pos2;
   cout << "Ingrese la posicion del primer caballo (2 cifras): ";
   cin >> pos1;
   cout << "Ingrese la posicion del segundo caballo (2 cifras): ";
   cin >> pos2;

   // separar fila y columna
   int f1 = pos1 / 10;
   int c1 = pos1 % 10;
   int f2 = pos2 / 10;
   int c2 = pos2 % 10;

   // calcular diferencia sin abs()
   int df, dc;
   if (f1 > f2) df = f1 - f2;
   else df = f2 - f1;

   if (c1 > c2) dc = c1 - c2;
   else dc = c2 - c1;

   // verificar movimiento en L
   if ( (df == 2 && dc == 1) || (df == 1 && dc == 2) )
      cout << "Los caballos se atacan." << endl;
   else
      cout << "Los caballos NO se atacan." << endl;

   return 0;
}

