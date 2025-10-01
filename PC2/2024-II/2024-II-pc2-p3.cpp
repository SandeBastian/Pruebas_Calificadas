/*
Dados dos conjuntos 𝐴 y 𝐵 de 𝑚 y 𝑛 elementos enteros, se define la distancia entre los conjuntos 𝐴 y 𝐵
como el número de elementos de la diferencia simétrica de dichos conjuntos con sus elementos indexados.
Ejemplo:
Conjunto 𝐴:{1;3;5;7}
Conjunto A con sus elementos indexado: 𝐴_𝐼𝑛𝑑 ={1_1; 3_2; 5_3;7_4 }
Conjunto 𝐵:{1;2;4;5}
Conjunto B con sus elementos indexado 𝐵_𝐼𝑛𝑑= {1_1; 2_2; 4_3;5_4 }
Diferencia simétrica de 𝐴_𝐼𝑛𝑑 y 𝐵_𝐼𝑛𝑑: (𝐴_𝐼𝑛𝑑−𝐵_𝐼𝑛𝑑 )∪(𝐵_𝐼𝑛𝑑−𝐴_𝐼𝑛𝑑 )={2_2;3_2;4_3;5_3;5_4; 7_4 }
La distancia entre 𝐴 y 𝐵 es: 6
Nota: Validar que los elementos de un conjunto no se repitan.
*/