#include <stdio.h> // isso é uma diretiva de pré-processador. A palavra #include instrui o compilador a incluir o conteúdo de 
// um arquivo de cabeçalho (header file) em nosso programa. Neste caso, estamos incluindo o arquivo stdio.h (Standard Input/Output), 
// que contém as funções para operações de entrada e saída de dados, como a função printf().
#include <stdbool.h> // Necessário para usar 'bool', 'true' e 'false'

#include <stdlib.h> // necessário para tratar ponteiros com funções malloc, free, calloc, realloc, etc.

// A stack é uma área de memória usada principalmente para variáveis locais e parâmetros de funções. A heap é uma área de memória usada 
// para alocação dinâmica — ou seja, você decide quanto e quando alocar. Ela é controlada pelo programador. ponteiros podem ser
// criados tanto na stack quanto na heap, ponteiros que recebem dados e endereços de variáveis comums ficam na stack, ponteiros que usam 
// alocação dinamica com maloc() são criados na heap e precisam ser liberados com free.

/* A stack é usada para variáveis locais e argumentos de funções. A alocação e desalocação de memória na stack é automática e muito rápida.

A heap é uma área de memória maior e mais flexível, onde a alocação dinâmica acontece. É o programador quem gerencia essa memória, o que 
significa que você precisa alocar e, mais importante, desalocar essa memória manualmente.*/


// int -> o tipo do retorno da função
// int argc -> int que representa a qtd de argumentos passados ao rodar o código, ex no terminal roda: test.exe "OI" "eu", resultado será 2
// char *argv[] -> array contendo os argumentos, argv[0] sempre será o nome do programa, ex: argv[0] = test, argv[1] = OI, argv[2] = eu
int main(int argc, char *argv[]) {

    /* exemplo 1: int p */

    // declarando um ponteiro qualquer de um inteiro
    int *p;

    // a função malloc(n) serve para alocar um espaço de memória de n bytes, ela retorna um endereço
    // de memória com um ponteiro do tipo VOID, por conta disso é necessário fazer o casting (int *),
    // que é modificar o tipo de ponteiro para o tipo que precisamos (no caso, int)
    p = (int *) malloc(sizeof(int));

    *p = 10;

    printf("%i", *p);

    // precisamos liberar o espaço de memória alocado, após usar o ponteiro.
    free(p);



    return 0;
};