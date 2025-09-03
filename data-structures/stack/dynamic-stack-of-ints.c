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
    stack->top = NULL; // inicia o primeiro nó da stack como NULL para evitar criação de lixo
    return stack;
};

void push(Stack* stack, int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    if (node == NULL) {
        printf("Error: Memory allocation for linked list failed.\n");
        exit(1);
    };

    node->data = data; // coloca o dado no nó
    node->next = stack->top; // o próximo endereço do nó é o top da stack (o nó vira o novo topo)
    
    stack->top = node; // retorna o nó (novo topo)
};

void pop(Stack* stack) {
    if (stack->top == NULL) {
        return;
    }
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
};

int isEmpty(Stack* stack) {
    if (stack->top == NULL) {
        return 1;
    }
    return 0;
};

void freeStack(Stack* stack) {
    if (stack == NULL) {
        return;
    };

    while (!isEmpty(stack)) {
        pop(stack);
    }
};

/* FUNÇÕES DE AVALIAÇÃO DE EXPRESSOES PREFIX E SUFIX COM STACK */

// int -> o tipo do retorno da função
// int argc -> int que representa a qtd de argumentos passados ao rodar o código, ex no terminal roda: test.exe "OI" "eu", resultado será 2
// char *argv[] -> array contendo os argumentos, argv[0] sempre será o nome do programa, ex: argv[0] = test, argv[1] = OI, argv[2] = eu
int main(int argc, char *argv[]) {

    Stack* stack = NULL;
    stack = createStack();

    /* exemplo 1: funções básicas da stack */

    printf("Testing stack -> 1 = yes | 0 = no\n\n");
    printf("Stack is empty? %i\n", isEmpty(stack));
    
    printf("Pushing 13 to the stack...\n");
    push(stack, 13);

    printf("Pushing 27 to the stack...\n");
    push(stack, 27);

    printf("Current top of stack (first value): %i\n", stack->top->data);

    printf("Removing (pop()) last value from the stack... \n");
    pop(stack);
    
    printf("Current top (peek()) of stack (last value): %i\n", peek(stack->top->data));

    printf("Pushing 7 to the stack...\n");
    push(stack, 7);

    printf("Pushing 21 to the stack...\n");
    push(stack, 21);

    printf("Pushing 4 to the stack...\n");
    push(stack, 4);

    printf("Pushing 72 to the stack...\n");
    push(stack, 72);

    printf("Pushing 9 to the stack...\n");
    push(stack, 9);

    printf("Pushing 0 to the stack...\n");
    push(stack, 0);

    printf("Pushing 14 to the stack...\n");
    push(stack, 14);

    printf("Pushing 60 to the stack...\n");
    push(stack, 60);
    
    printf("Pushing 103 to the stack...\n");
    push(stack, 103);

    printf("Stack is full? No, dynamic stacks has no size limit.\n");

    printf("Pushing 666 to the stack...\n");
    push(stack, 666);

    printf("Deletando stack e liberando memória...\n\n\n");
    freeStack(stack);

    return 0;
}