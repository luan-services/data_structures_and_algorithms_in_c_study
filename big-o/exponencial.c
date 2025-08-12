#include <stdio.h> // isso é uma diretiva de pré-processador. A palavra #include instrui o compilador a incluir o conteúdo de 
// um arquivo de cabeçalho (header file) em nosso programa. Neste caso, estamos incluindo o arquivo stdio.h (Standard Input/Output), 
// que contém as funções para operações de entrada e saída de dados, como a função printf().
#include <stdbool.h> // Necessário para usar 'bool', 'true' e 'false'

// Complexidade exponencial é aquela cujo o tempo é multiplicado por 2 a cada elemento extra.
// velocidade: impraticável para n > 30.

// um exemplo de 
int fibonacci(int n) {
    if (n <=1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n - 2); // faz mais duas chamadas pra cada entrada, sendo O (2^n)
    };
}

// int -> o tipo do retorno da função
// int argc -> int que representa a qtd de argumentos passados ao rodar o código, ex no terminal roda: test.exe "OI" "eu", resultado será 2
// char *argv[] -> array contendo os argumentos, argv[0] sempre será o nome do programa, ex: argv[0] = test, argv[1] = OI, argv[2] = eu
int main(int argc, char *argv[]) {
    
    int n = 60;
    int fib = fibonacci(n);

    printf("Fibonacci de %i: %i", n, fib);

    return 0;
}