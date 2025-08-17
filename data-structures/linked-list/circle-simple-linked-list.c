#include <stdio.h> // isso é uma diretiva de pré-processador. A palavra #include instrui o compilador a incluir o conteúdo de 
// um arquivo de cabeçalho (header file) em nosso programa. Neste caso, estamos incluindo o arquivo stdio.h (Standard Input/Output), 
// que contém as funções para operações de entrada e saída de dados, como a função printf().
#include <stdbool.h> // Necessário para usar 'bool', 'true' e 'false'

#include <string.h> // necessário para usar strcpy, função de passar strings para arrays de char.

#include <stdlib.h> // necessário para tratar ponteiros com funções malloc, free, calloc, realloc, etc.


/* listas encadeadas circulares são uma variação das listas encadeadas simples, com uma diferença chave: o último nó da lista aponta para 
o primeiro nó em vez de apontar para NULL. Uma lista ligada circular pode ser tanto simples quanto dupla, porém trataremos a simples.

a diferença está na maneira como os nós estão conectados.

nó único: se a lista tiver apenas um nó, o ponteiro dele aponta para si mesmo.
múltiplos nós: em uma lista com vários nós, o ponteiro do último nó aponta para o primeiro.
ponteiro tail (ou cauda): É comum manter um ponteiro para o último nó (tail ou last), pois o primeiro nó (head) pode ser facilmente acessado 
a partir dele (tail->next).
*/

// em primeiro lugar, define-se o 'objeto' nó.
typedef struct Node {
    char data; // data pode ser qualquer tipo, aqui faremos com char. 
    struct Node* next; // fazemos também um ponteiro que guarda o endereço do próximo valor na lista (precisa colocar struct pois o tipo Node
    // ainda não existe)
} Node;

// funçao para inserir um novo elemento no início da lista, retorna um ponteiro para o novo início da lista.
Node* insertAtStart(Node* tail, char data) { // O (1)
    // aloca memória para um novo nó
    Node* node = (Node *) malloc(sizeof(Node));
    if (node == NULL) {
        printf("Error: Memory allocation for linked list failed.\n");
        exit(1);
    };
    // coloca o dado necessário
    node->data = data;

    // se a lista está vazia
    if (tail == NULL) {
        node->next = node; // o primeiro e ultimo elemento aponta para sí mesmo.
        return node;
    }
    
    
    node->next = tail->next; // o próximo elemento de node aponta para o primeiro elemento da lista
    tail->next = node; // 'tail', o ultimo elemento da lista, aponta para node (que é o novo primeiro)
    return tail; // retorna tail
};

Node* insertAtEnd(Node* tail, char data) { // O (n)
    Node* node = (Node *) malloc(sizeof(Node));
    if (node == NULL) {
        printf("Error: Memory allocation for linked list failed.\n");
        exit(1);
    };

    // coloca o dado no nó e aponta o nó para NULL, pois será o último nó da lista
    node->data = data;

    // se a lista está vazia
    if (tail == NULL) {
        node->next = node; // o primeiro e ultimo elemento aponta para sí mesmo.
        return node;
    }

    node->next = tail->next;
    tail->next = node; // 'tail', o ultimo elemento da lista, aponta para node (que é o novo primeiro)
    return node; // retorna node, que é o novo ultimo elemento
};

Node* removeValue(Node* tail, char value) {
    if (tail == NULL) {
        return NULL;
    }

    Node* head = tail->next;
    Node* current = head;
    Node* previous = tail;
    bool found = false;

    do {
        if (current->data == value) {
            found = true;
            break;
        }
        previous = current;
        current = current->next;
    } while (current != head);

    if (!found) {
        printf("Valor '%c' não encontrado na lista.\n", value);
        return tail;
    }

    // Se o valor estiver no único nó da lista
    if (current == head && previous == tail) {
        free(current);
        return NULL;
    }

    // Se o valor estiver no primeiro nó (head)
    if (current == head) {
        tail->next = current->next;
        free(current);
        return tail;
    }

    // Se o valor estiver no último nó (tail)
    if (current == tail) {
        previous->next = head;
        free(current);
        return previous; // O anterior se torna o novo tail
    }

    // Se o valor estiver no meio da lista
    previous->next = current->next;
    free(current);
    return tail;
}

/*
 * Função para remover um nó em um índice específico da lista.
 * Recebe o ponteiro para o último nó (tail) e o índice a ser removido.
 * Retorna o ponteiro para o novo último nó (tail).
 */
Node* removeAtIndex(Node* tail, int index) {
    if (tail == NULL) {
        printf("Erro: A lista está vazia.\n");
        return NULL;
    }
    
    Node* head = tail->next;
    Node* current = head;
    Node* previous = tail;
    int count = 0;

    // Caso de remoção do primeiro nó (index 0)
    if (index == 0) {
        if (head == tail) { // Se há apenas um nó na lista
            free(head);
            return NULL;
        }
        tail->next = head->next;
        free(head);
        return tail;
    }

    // Caso de remoção de qualquer outro nó
    do {
        if (count == index) {
            // Se o nó a ser removido é o tail
            if (current == tail) {
                previous->next = head;
                free(current);
                return previous;
            } else { // Nó a ser removido está no meio
                previous->next = current->next;
                free(current);
                return tail;
            }
        }
        previous = current;
        current = current->next;
        count++;
    } while (current != head);

    printf("Erro: Índice %d fora dos limites da lista.\n", index);
    return tail;
}

void printList(Node* tail) {
    if (tail == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    Node* current = tail->next; // Começa pelo primeiro nó (head)
    
    // Percorre a lista até voltar ao primeiro nó
    do {
        printf("%c ", current->data);
        current = current->next;
    } while (current != tail->next);

    printf("\n");
}

Node* clearList(Node* tail) {
    if (tail == NULL) {
        return NULL;
    }
    
    Node* current = tail->next;
    Node* head = tail->next;
    Node* temp;

    do {
        temp = current;
        current = current->next;
        free(temp);
    } while (current != head);

    return NULL;
}

// int -> o tipo do retorno da função
// int argc -> int que representa a qtd de argumentos passados ao rodar o código, ex no terminal roda: test.exe "OI" "eu", resultado será 2
// char *argv[] -> array contendo os argumentos, argv[0] sempre será o nome do programa, ex: argv[0] = test, argv[1] = OI, argv[2] = eu
int main() {
    
    /* em listas circulares, list sempre vai apontar para o último elemento da lista, ao invés do primeiro.*/

    // inicia a lista como um ponteiro para um nó NULL, é necessário que seja um ponteiro pois seu endereço precisa mudar sempre que a lista
    // cresce ou diminui.
    Node* list = NULL;

    printf("Inserindo elementos no início e fim da lista.\n");
    list = insertAtStart(list, 'A');
    list = insertAtEnd(list, 'B');
    list = insertAtEnd(list, 'C');
    list = insertAtEnd(list, 'D');

    printf("Lista: ");
    printList(list); // Saída: A B C D

    printf("\nInserindo 'X' no início.\n");
    list = insertAtStart(list, 'X');
    printf("Lista: ");
    printList(list); // Saída: X A B C D

    printf("\nRemovendo valor 'C'.\n");
    list = removeValue(list, 'C');
    printf("Lista: ");
    printList(list); // Saída: X A B D

    printf("\nRemovendo valor do índice 2.\n");
    list = removeAtIndex(list, 2);
    printf("Lista: ");
    printList(list); // Saída: X A D

    printf("\nTentando remover um valor que não existe ('Z').\n");
    list = removeValue(list, 'Z');
    printf("Lista: ");
    printList(list); // Saída: X A D

    printf("\nLimpando a lista.\n");
    list = clearList(list);
    printf("Lista depois de ser limpa: ");
    printList(list);

    return 0;
};