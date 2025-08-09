#include <stdio.h> // isso é uma diretiva de pré-processador. A palavra #include instrui o compilador a incluir o conteúdo de 
// um arquivo de cabeçalho (header file) em nosso programa. Neste caso, estamos incluindo o arquivo stdio.h (Standard Input/Output), 
// que contém as funções para operações de entrada e saída de dados, como a função printf().
#include <stdbool.h> // Necessário para usar 'bool', 'true' e 'false'

// Complexidade quadrática é aquela que é exponencial ao número de entradas, se a quantidade de entradas for 2, o tempo é 4, se for 4, o 
// tempo é 16.

// função recursiva de calculo de mdc, conhecida como algoritmo de euclides.
int findGreatestCommomDivisor(int a, int b) { // O ( log min(b,a)), pois a cada busca n se divide no mínimo em 2
    if (b == 0) {
        return a;
    };

    int rest = a % b;

    if (rest == 0) {
        return a;
    } else {
        return findGreatestCommomDivisor(b, rest); // O (log min(a,b))
    };
}