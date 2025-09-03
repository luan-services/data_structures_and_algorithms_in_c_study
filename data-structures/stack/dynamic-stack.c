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

/* a pilha do exemplo abaixo é feita com nó da linked list, ou seja, é uma pilha dinâmica, a implementação é mais complexa, porém tem tamanho
variável e é mais útil que a pilha estática

!!! uma pilha dinâmica também parte do princípio LIFO, porém, ao invés de adicionar valores ao FIM da linked list [O (n)], ela aproveita a 
natureza ordenada da linked list para fazer o TOP (ultimo valor), ser o head da linked list (valor inicial), removendo e inserindo sempre
ao início da lista [O (1)] */

typedef struct Node { // cria um nó da linked list, data será um int
    int data;
    struct Node* next;
} Node;

typedef struct Stack { // define o tipo stack
    Node* top;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("Error: Memory allocation for linked list failed.\n");
        exit(1);
    };
    return stack;
};

// int -> o tipo do retorno da função
// int argc -> int que representa a qtd de argumentos passados ao rodar o código, ex no terminal roda: test.exe "OI" "eu", resultado será 2
// char *argv[] -> array contendo os argumentos, argv[0] sempre será o nome do programa, ex: argv[0] = test, argv[1] = OI, argv[2] = eu
int main(int argc, char *argv[]) {

    Stack* stack = NULL;
    stack = createStack();

    return 0;

}