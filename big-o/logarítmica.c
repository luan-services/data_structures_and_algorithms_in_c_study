#include <stdio.h> // isso é uma diretiva de pré-processador. A palavra #include instrui o compilador a incluir o conteúdo de 
// um arquivo de cabeçalho (header file) em nosso programa. Neste caso, estamos incluindo o arquivo stdio.h (Standard Input/Output), 
// que contém as funções para operações de entrada e saída de dados, como a função printf().
#include <stdbool.h> // Necessário para usar 'bool', 'true' e 'false'

// Complexidade logarítmica é aquela que é inversamente exponencial ao numero de entradas, a cada passo a quantidade é dividida em 2, se a
// quantidade de entradas for 8, o numero de chamadas máximo será 4.


// função recursiva de calculo de mdc, conhecida como algoritmo de euclides.
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

// int -> o tipo do retorno da função
// int argc -> int que representa a qtd de argumentos passados ao rodar o código, ex no terminal roda: test.exe "OI" "eu", resultado será 2
// char *argv[] -> array contendo os argumentos, argv[0] sempre será o nome do programa, ex: argv[0] = test, argv[1] = OI, argv[2] = eu
int main(int argc, char *argv[]) {
    
    // array em ordem crescente.
    int numbers[] = {1,2,5,7,12,15,26,32,47,78,102};
    int length = sizeof(numbers) / sizeof(numbers[0]);
    int search = 15;

    printf("Index of %i: %i", search, binarySearchRecursive(numbers, 0, length - 1, search));

    return 0;
}