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
    char data;
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

void push(Stack* stack, char data) {
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


/* FUNÇÕES UTEIS COM STACK */

// função para inverter string
void reverseString(char *str) { // O (n)
    char* temp = str;
    Stack* stack = createStack();

    while (*temp != '\0') { // O (n)
        push(stack, *temp);
        temp = temp + 1;
    };

    temp = str;

    while (*temp != '\0') { // O (n)
        *temp = stack->top->data;
        pop(stack);
        temp = temp + 1;
    };

    freeStack(stack);
};

// função que checa se uma string contém aberturas e fechamentos de parenteses corretos
int isBalanced(char* str) {
    Stack* stack = createStack();
    char* temp = str;

    while (*temp != '\0') { // percorre todos os chars da string
        if (*temp == '(' || *temp == '[' || *temp == '{') { // se o char for um char de abertura de parentêses, coloca na stack
            push(stack, *temp);
        } 
        else if (*temp == ')' || *temp == ']' || *temp == '}') { // caso seja de fechamento, faz:

            // caso 1: se a stack está vazia quer dizer que não existe parentêses nenhum de abertura anterior, ou seja, não está balanceado
            if (isEmpty(stack)) { 
                freeStack(stack);
                return 0;
            }

            // caso 2: existe uma abertura mas não combina com o fechamento atual, não está balanceado
            if ((stack->top->data == '(' && *temp != ')') || (stack->top->data == '[' && *temp != ']') || (stack->top->data == '{' && *temp != '}')) {
                freeStack(stack);
                return 0;
            }

            // caso 3: está tudo correto e balanceado, limpa a pilha e continua percorrendo a lista.
            pop(stack);
        };
        temp = temp + 1;
    };

    if (stack->top != NULL) { // caso 4: percorreu a lista inteira e há um parenteses dentro da stack (abriu mas não achou fechamento)
        freeStack(stack);
        return 0;
    }

    freeStack(stack);
    return 1;
};


// int -> o tipo do retorno da função
// int argc -> int que representa a qtd de argumentos passados ao rodar o código, ex no terminal roda: test.exe "OI" "eu", resultado será 2
// char *argv[] -> array contendo os argumentos, argv[0] sempre será o nome do programa, ex: argv[0] = test, argv[1] = OI, argv[2] = eu
int main(int argc, char *argv[]) {

    Stack* stack = NULL;
    stack = createStack();

    /* exemplo 1: funções básicas da stack */

    printf("Testing stack -> 1 = yes | 0 = no\n\n");
    printf("Stack is empty? %i\n", isEmpty(stack));
    
    printf("Pushing 'a' to the stack...\n");
    push(stack, 'a');

    printf("Pushing 'B' to the stack...\n");
    push(stack, 'B');

    printf("Current top of stack (first value): %c\n", stack->top->data);

    printf("Removing (pop()) last value from the stack... \n");
    pop(stack);
    
    printf("Current top of stack (first value): %c\n", stack->top->data);

    printf("Pushing 'D' to the stack...\n");
    push(stack, 'D');

    printf("Pushing 'c' to the stack...\n");
    push(stack, 'c');

    printf("Pushing 'k' to the stack...\n");
    push(stack, 'k');

    printf("Pushing '7' to the stack...\n");
    push(stack, '7');

    printf("Pushing 'k' to the stack...\n");
    push(stack, 'k');

    printf("Pushing 'm' to the stack...\n");
    push(stack, 'm');

    printf("Pushing 'j' to the stack...\n");
    push(stack, 'j');

    printf("Pushing 'o' to the stack...\n");
    push(stack, 'o');
    
    printf("Pushing 'm' to the stack...\n");
    push(stack, 'm');

    printf("Stack is full? No, dynamic stacks has no size limit.\n");

    printf("Pushing 'z' to the stack...\n");
    push(stack, 'z');

    printf("Deletando stack e liberando memória...\n\n\n");
    freeStack(stack);

    /* exemplo 2: Invertendo uma string com stack */

    char str[] = "Ola, Mundo!";

    printf("Reverse String Function Test\n\n");
    printf("String: %s\n", str);

    printf("Reversing...\n");
    
    reverseString(&str[0]);
    printf("Reversed String: %s\n\n\n", str);
    
    /* exemplo 3: Avaliando prefixos de expressão com parentêses (),[],{}
        essa função checa se todos os parentêses no texto estão fechando corretamente */

    char expression[] = "In the realm of {curiosity}, where [ideas] echo within (minds), there exists a pattern: {[ (dreams + doubts) * (hope - fear) ] / (time + effort)}.\n\n Every step {forward} feels like (progress), even if [uncertain]. The key lies in balancing { [ (courage) + (patience) ] } with (persistence).";
    
    printf("Balanced Text Function Test\n\n");
    printf("String: %s\n\n", expression);

    printf("Testing...\n");

    printf("Result isBalanced (1 = true | 0 = false): %i\n\n\n", isBalanced(expression));
    
    return 0;
}