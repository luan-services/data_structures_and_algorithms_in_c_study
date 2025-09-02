#include <stdio.h> // isso é uma diretiva de pré-processador. A palavra #include instrui o compilador a incluir o conteúdo de 
// um arquivo de cabeçalho (header file) em nosso programa. Neste caso, estamos incluindo o arquivo stdio.h (Standard Input/Output), 
// que contém as funções para operações de entrada e saída de dados, como a função printf().
#include <stdbool.h> // Necessário para usar 'bool', 'true' e 'false'

#include <string.h> // necessário para usar strcpy, função de passar strings para arrays de char.

#include <stdlib.h> // necessário para tratar ponteiros com funções malloc, free, calloc, realloc, etc.


/* uma pilha é uma coleção de elementos na qual a adição de um novo elemento e a remoção de um elemento existente ocorrem sempre na mesma 
extremidade. Essa extremidade é comumente chamada de topo da pilha.

O princípio que rege o funcionamento de uma pilha é o LIFO (Last-In, First-Out), que em português significa "O Último a Entrar é o 
Primeiro a Sair". Imagine uma pilha de pratos: o último prato que você coloca sobre a pilha será o primeiro que você irá retirar. Os 
elementos em uma pilha se comportam da mesma maneira. 

existem dois tipos de pilhas: estáticas (feita de arrays) e dinâmicas (feita de nó (linked lists)) */

/*
a pilha do exemplo abaixo é feita num array, ou seja, é uma pilha estática, ela possui uma implementação mais simples e direta, porém não 
tem tamanho variável, existe um limite para o tamanho dela que precisa ser pré-definido, e caso ela não ocupe todo o espaço, isso causa um
disperdício de alocação de memória */

// int -> o tipo do retorno da função
// int argc -> int que representa a qtd de argumentos passados ao rodar o código, ex no terminal roda: test.exe "OI" "eu", resultado será 2
// char *argv[] -> array contendo os argumentos, argv[0] sempre será o nome do programa, ex: argv[0] = test, argv[1] = OI, argv[2] = eu
int main(int argc, char *argv[]) {

    return 0;

}