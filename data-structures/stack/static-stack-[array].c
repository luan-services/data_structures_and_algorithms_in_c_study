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
disperdício de alocação de memória 

!!! stacks estáticas são feitas diretamente no código e pelo fato de terem valor fisíco, não é possível nem útil criar o arquivo para ser uma
library de stacks, por isso não definiremos um struct */

int isEmpty(int top) { // O (1)
    if (top <= -1) {
        return 1;
    }
    return 0;
};

int isFull(int top, int size) { // O (1)
    if (top + 1 == size ) {
        return 1;
    }
    return 0;
};

void push(int* stack, int data, int *top, int size) { // O (1)
    if (isFull(*top, size)) {
        printf("Erro: Estouro da pilha (Stack Overflow)\n");
        return;
    };
    *top = *top + 1;
    *(stack + *top) = data;
};

// pop não remove itens já colocados, ele apenas define um topo novo, assim o item nunca será acessado, e ao colocar algo na stack, ele será
// sobrescrito
void pop(int *top) {  // O (1)
    if (isEmpty(*top)) {
        printf("Erro: A pilha está vazia (Stack Underflow)\n");
        return;
    };
    (*top) --;
};

// peek ou (top) é uma função para ver o valor do topo da stack
int peek(int* stack, int top) {
    if (isEmpty(top)) {
        printf("Erro: A pilha está vazia (Stack Underflow)\n");
        return -1;
    };
    return stack[top];
}

// int -> o tipo do retorno da função
// int argc -> int que representa a qtd de argumentos passados ao rodar o código, ex no terminal roda: test.exe "OI" "eu", resultado será 2
// char *argv[] -> array contendo os argumentos, argv[0] sempre será o nome do programa, ex: argv[0] = test, argv[1] = OI, argv[2] = eu
int main(int argc, char *argv[]) {

    int size = 10; // define um tamanho para a stack;
    int stack[size]; // se implementa dessa forma, criando um array vazio com espaço para n elementos.
    int top = -1; // precisa criar um int para sinalizar qual index do array é o topo da lista (o index do último valor inserido)
    // o topo precisa sendo -1 indica que não há nenhum valor adicionado à pilha

    printf("Testing stack -> 1 = yes | 0 = no\n\n");
    printf("Stack is empty? %i\n", isEmpty(top));
    
    printf("Pushing 13 to the stack...\n");
    push(stack, 13, &top, size);

    printf("Pushing 27 to the stack...\n");
    push(stack, 27, &top, size);

    printf("Current top (peek()) of stack (last value): %i\n", peek(stack, top));

    printf("Removing (pop()) last value from the stack... \n");
    pop(&top);
    
    printf("Current top (peek()) of stack (last value): %i\n", peek(stack, top));

    printf("Pushing 7 to the stack...\n");
    push(stack, 7, &top, size);

    printf("Pushing 21 to the stack...\n");
    push(stack, 21, &top, size);

    printf("Pushing 4 to the stack...\n");
    push(stack, 4, &top, size);

    printf("Pushing 72 to the stack...\n");
    push(stack, 72, &top, size);

    printf("Pushing 9 to the stack...\n");
    push(stack, 9, &top, size);

    printf("Pushing 0 to the stack...\n");
    push(stack, 0, &top, size);

    printf("Pushing 14 to the stack...\n");
    push(stack, 14, &top, size);

    printf("Pushing 60 to the stack...\n");
    push(stack, 60, &top, size);
    
    printf("Pushing 103 to the stack...\n");
    push(stack, 103, &top, size);

    printf("Stack is full? %i\n", isFull(top, size));

    printf("Pushing 666 to the stack...\n");
    push(stack, 666, &top, size);


    return 0;

}