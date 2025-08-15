#include <stdio.h> // isso é uma diretiva de pré-processador. A palavra #include instrui o compilador a incluir o conteúdo de 
// um arquivo de cabeçalho (header file) em nosso programa. Neste caso, estamos incluindo o arquivo stdio.h (Standard Input/Output), 
// que contém as funções para operações de entrada e saída de dados, como a função printf().
#include <stdbool.h> // Necessário para usar 'bool', 'true' e 'false'

#include <string.h> // necessário para usar strcpy, função de passar strings para arrays de char.

#include <stdlib.h> // necessário para tratar ponteiros com funções malloc, free, calloc, realloc, etc.


/* uma lista ligada simples é uma estrutura em que cada elemento é um objeto chamado nó (node), cada nó contém um campo de dados e um ponteiro 
que aponta para o próximo nó. A lista só pode ser percorrida em uma única direção (para frente), do head até o final. O ponteiro do último 
nó aponta para NULL.
*/

// em primeiro lugar, define-se o 'objeto' nó.
typedef struct Node {
    char data; // data pode ser qualquer tipo, aqui faremos com char. 
    struct Node* next; // fazemos também um ponteiro que guarda o endereço do próximo valor na lista (precisa colocar struct pois o tipo Node
    // ainda não existe)
} Node;

// funçao para inserir um novo elemento no início da lista, retorna um ponteiro para o novo início da lista.
Node* insertAtStart(Node* list, char data) {
    // aloca memória para um novo nó
    Node* node = (Node *) malloc(sizeof(Node));
    if (node == NULL) {
        printf("Error: Memory allocation for linked list failed.\n");
        exit(1);
    };
    // coloca o dado necessário
    node->data = data;
    // faz o próximo endereço ser list, caso a lista esteja vazia, próximo endereço é null, caso contrário, é o primeiro valor da lista
    node->next = list;
    return node;
};

// int -> o tipo do retorno da função
// int argc -> int que representa a qtd de argumentos passados ao rodar o código, ex no terminal roda: test.exe "OI" "eu", resultado será 2
// char *argv[] -> array contendo os argumentos, argv[0] sempre será o nome do programa, ex: argv[0] = test, argv[1] = OI, argv[2] = eu
int main(int argc, char *argv[]) {

    // inicia a lista como um nó null.
    Node* list = NULL;

    // insere o valor e retorna um ponteiro para o primeiro nó da lista.
    list = insertAtStart(list, 'A');



    return 0;
}