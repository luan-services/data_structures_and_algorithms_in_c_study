#include <stdio.h> // isso é uma diretiva de pré-processador. A palavra #include instrui o compilador a incluir o conteúdo de 
// um arquivo de cabeçalho (header file) em nosso programa. Neste caso, estamos incluindo o arquivo stdio.h (Standard Input/Output), 
// que contém as funções para operações de entrada e saída de dados, como a função printf().
#include <stdbool.h> // Necessário para usar 'bool', 'true' e 'false'

// Complexidade quadrática é aquela que é exponencial ao número de entradas, se a quantidade de entradas for 2, o tempo é 4, se for 4, o 
// tempo é 16.

// ao fazer m[][cols] o que eu estou definindo é que vou passar um array de inteiros cujo cada elemento é um array de 3 inteiros. ou seja, 
// não importa o tamanho de linhas, mas o tamanho de colunas deve ser [cols] obrigatóriamente.
// e como os dados são acessados dessa forma? ao passar um array para a função, ela recebe o ENDEREÇO inicial do array, e ao chamar 
// arr[1][0], por exemplo, o seguinte acontece:

// a função sabe que o tamanho de cada valor do array é [cols], então ela faz - endereço do array + (1 * (sizeof(int)), assim ele sabe 
// exatamente o endereço de arr[1][x]
// por fim, como ele fez arr[1][0], ele soma (0 *sizeof(int)) ao endereço, para finalmente chegar ao elemento [1][0] do array.


void printMatrix(int lines, int cols, int arr[][cols]) { // O (n²) complexidade quadrática, pois possui um for dentro de outro for.
    
    for (int i = 0 ; i < lines ; i ++) { // O (n)
        for (int j = 0 ; j < cols ; j ++) { // O (n)
            printf("%i", arr[i][j]);
            if (j == cols -1) {
                printf("\n");
            }
            else {
                printf(" ");
            };
        }
    };

}

// int -> o tipo do retorno da função
// int argc -> int que representa a qtd de argumentos passados ao rodar o código, ex no terminal roda: test.exe "OI" "eu", resultado será 2
// char *argv[] -> array contendo os argumentos, argv[0] sempre será o nome do programa, ex: argv[0] = test, argv[1] = OI, argv[2] = eu
int main(int argc, char *argv[]) {
    
    int matrix[3][3] = {{1, 4, 3}, {2, 3, 5}, {7, 8, 9}};
    // calcula o tamanho em memória do array (20 bytes) e divide pelo tamanho em memória do primeiro element (int 4 bytes) = 5
    int lineLength = sizeof(matrix) / sizeof(matrix[0]);
    int colLenght = sizeof(matrix[0]) / sizeof(matrix[0][0]);

    printMatrix(lineLength, colLenght, matrix);

    return 0;
}