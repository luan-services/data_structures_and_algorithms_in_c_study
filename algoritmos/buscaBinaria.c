#include <stdio.h> // isso é uma diretiva de pré-processador. A palavra #include instrui o compilador a incluir o conteúdo de 
// um arquivo de cabeçalho (header file) em nosso programa. Neste caso, estamos incluindo o arquivo stdio.h (Standard Input/Output), 
// que contém as funções para operações de entrada e saída de dados, como a função printf().
#include <stdbool.h> // Necessário para usar 'bool', 'true' e 'false'


int binarySearchRecursive(int arr[], int first, int last, int param) { // O ( log n), pois a cada busca n se divide por 2
    // se o primeiro indíce for maior que o último
    if (first > last) {
        return -1;
    };
    // encontra o meio
    int middle = first + (last - first) / 2;


    if (arr[middle] == param) {
        return middle;
    } else if ( arr[middle] > param) {
        return binarySearchRecursive(arr, first, middle - 1, param);
    } else {
        return binarySearchRecursive(arr, middle + 1, last, param);
    };

}