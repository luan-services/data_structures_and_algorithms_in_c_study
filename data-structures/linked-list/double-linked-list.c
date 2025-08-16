#include <stdio.h> // isso é uma diretiva de pré-processador. A palavra #include instrui o compilador a incluir o conteúdo de 
// um arquivo de cabeçalho (header file) em nosso programa. Neste caso, estamos incluindo o arquivo stdio.h (Standard Input/Output), 
// que contém as funções para operações de entrada e saída de dados, como a função printf().
#include <stdbool.h> // Necessário para usar 'bool', 'true' e 'false'

#include <string.h> // necessário para usar strcpy, função de passar strings para arrays de char.

#include <stdlib.h> // necessário para tratar ponteiros com funções malloc, free, calloc, realloc, etc.


/* uma lista ligada dupla é uma estrutura em que cada elemento é um objeto chamado nó (node), cada nó contém um campo de dados, um ponteiro 
que aponta para o próximo nó e outro que aponta para o nó anterior. Diferente da lista simples, ela pode ser percorrida tanto do head até 
o final, quanto do final até o head. 

no primeiro elemento (head): *prev é sempre NULL e *next sempre aponta para o próximo elemento
no ultimo elemento (tail): *prev sempre aponta para o próximo elemento e *next é sempre NULL
*/

/*
no caso abaixo a lista se inicia com null, sendo necesário fazer as funções de inserção serem capazes de lidar com o caso da lista ser NULL,
ou seja, nesses casos, as funções precisam retornar o nó.

se houvesse uma função para iniciar a lista com algum valor, ex: createList(char value); as funções de inserção poderiam retornar void, apenas
usando esse endereço inicial e fazendo as modificações.
*/

// em primeiro lugar, define-se o 'objeto' nó.
typedef struct Node {
    char data; // data pode ser qualquer tipo, aqui faremos com char. 
    struct Node* prev; // fazemos também um ponteiro que guarda o endereço do valor anterior na lista
    struct Node* next; // fazemos também um ponteiro que guarda o endereço do próximo valor na lista (precisa colocar struct pois o tipo Node
    // ainda não existe)
} Node;

// funçao para inserir um novo elemento no início da lista, retorna um ponteiro para o novo início da lista.
Node* insertAtStart(Node* list, char data) { // O (1)
    // aloca memória para um novo nó
    Node* node = (Node *) malloc(sizeof(Node));
    if (node == NULL) {
        printf("Error: Memory allocation for linked list failed.\n");
        exit(1);
    };
    // coloca o dado necessário
    node->data = data;
    // o primeiro elemento da lista SEMPRE tem o prev como NULL
    node->prev = NULL;
    // next é sempre um ponteiro, faz o próximo endereço ser list, caso a lista esteja vazia, próximo endereço é null, caso contrário, 
    // é o primeiro endereço da lista
    node->next = list;

    if (list != NULL) { // se a lista não está vazia, o endereço prev do antigo elemento 0 dela passa a ser node
        list->prev = node;
    };

    return node;
};

Node* insertAtEnd(Node* list, char data) { // O (n)
    Node* node = (Node *) malloc(sizeof(Node));
    if (node == NULL) {
        printf("Error: Memory allocation for linked list failed.\n");
        exit(1);
    };

    // coloca o dado no nó e aponta o nó para NULL, pois será o último nó da lista
    node->data = data;
    node->next = NULL;

    // se a lista está vazia, retorna o nó
    if (list == NULL) {
        node->prev = NULL;
        return node; // retorna o ponteiro node
    }
    /* precisamos criar um nó temporário que vai receber o endereço da lista, isso porque, em caso da lista ser NULL (estar vazia), a função
    precisa retornar um ponteiro para o ínicio dela, adicionando um return na função
    
    já que há um return na função, obrigatoriamente precisamos guardar uma referencia para o início da lista, porque se cairmos no caso 2 (a 
    lista possui elementos), vamos ter que percorrer todos esses elementos e retornar o endereço do elemento 1
    
    se fizermos isso com a referencia 'list' no final não vamos ter o endereço do elemento 1 para retornar, só o endereço do elemento 'ultimo',
    por isso criamos temp que vai ser nosso ponteiro dummy que vai até o fim da lista. */


    // aqui criamos um nó temporário, que vai receber o mesmo endereço que está em list (endereço do elemento 0), e irá andar até o último 
    // endereço da lista
    Node *temp = list;
    // vamos até o ultimo elemento
    while(temp->next != NULL) {
        temp = temp->next;
    }
    // acessamos o valor next do último elemento e fazemos o next dele apontar para o endereço do nó. (temp->next equivale à (*temp).next)
    temp->next = node;
    node->prev = temp;
    return list;
};

// int -> o tipo do retorno da função
// int argc -> int que representa a qtd de argumentos passados ao rodar o código, ex no terminal roda: test.exe "OI" "eu", resultado será 2
// char *argv[] -> array contendo os argumentos, argv[0] sempre será o nome do programa, ex: argv[0] = test, argv[1] = OI, argv[2] = eu
int main(int argc, char *argv[]) {

    // inicia a lista como um ponteiro para um nó NULL, é necessário que seja um ponteiro pois seu endereço precisa mudar sempre que a lista
    // cresce ou diminui.
    Node* list = NULL;

    // insere o valor e retorna um ponteiro para o primeiro nó da lista
    list = insertAtStart(list, 'A');
    list = insertAtEnd(list, 'B');
    
    

    return 0;

}