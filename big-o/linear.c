#include <stdio.h> // isso é uma diretiva de pré-processador. A palavra #include instrui o compilador a incluir o conteúdo de 
// um arquivo de cabeçalho (header file) em nosso programa. Neste caso, estamos incluindo o arquivo stdio.h (Standard Input/Output), 
// que contém as funções para operações de entrada e saída de dados, como a função printf().
#include <stdbool.h> // Necessário para usar 'bool', 'true' e 'false'


// Complexidade linear é aquela que é o tempo cresce proporcionalmente ao tamanho da entrada. Se dobrar o número de elementos, o 
// tempo dobra.
// boa para listas pequenas, tempo aumenta com muitos dados

// ponteiro aponta pro primeiro elemento.
int sum(int arr[], int size) { // O (n) complexidade linear, pois possui um for que itera sobre n elementos do array
    int sum = 0;
    for (int i = 0 ; i < size ; i ++) { // O (n)
        sum += arr[i];
    };
    return sum;
}

// int -> o tipo do retorno da função
// int argc -> int que representa a qtd de argumentos passados ao rodar o código, ex no terminal roda: test.exe "OI" "eu", resultado será 2
// char *argv[] -> array contendo os argumentos, argv[0] sempre será o nome do programa, ex: argv[0] = test, argv[1] = OI, argv[2] = eu
int main(int argc, char *argv[]) {
    
    int numbers[5] = {13, 4, -7, 12, 21};
    // calcula o tamanho em memória do array (20 bytes) e divide pelo tamanho em memória do primeiro element (int 4 bytes) = 5
    int length = sizeof(numbers) / sizeof(numbers[0]);

    // imprime todos os chars do firstStudent (formando a string Joao) e para quando chegar em '\0'
    printf("%i", sum(numbers, length));

    return 0;
}