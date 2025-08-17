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

////////////////////////////////////////////////////// preciso modificar

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

Node* insertAtIndex(Node* tail, char data, int index) {
    // cria um nó e insere o valor dentro
    Node* node = (Node *) malloc(sizeof(Node));
    if (node == NULL) {
        printf("Error: Memory allocation for linked list failed.\n");
        exit(1);
    };

    node->data = data; // é o mesmo que (*node).data


    // caso 1: a lista está vazia
    if (tail == NULL) {
        printf("Error: Insert index out of linked list bounds.\n");
        free(node);
        exit(1);
    };

    // caso 2: inserir no index 0
    if (index == 0) { // caso o indíce seja 0 faz a inserção padrão no inicio da lista O (1)
        node->next = tail->next;
        tail->next = node;
        return tail;
    };


    // ponteiro temporário que recebe o endereço do elemento 0
    Node* temp = tail->next;
    int count = 0;

    // caso 3: inserir no meio ou fim
    while (temp != tail && index - 1 > count) { // O (N)
        temp = temp -> next;
        count ++;
    };

    // caso tenha chegado na tail e count ainda não for = index 
    if (temp == tail && index - 1 > count) { // garante que caso o indíce seja maior que a quantidade de nós, a função falhe.
        printf("Error: Insert index out of linked list bounds.\n");
        free(node);
        exit(1);
    };

    // nó criado aponta para o próximo de nó indice - 1, nó indice - 1 aponta para nó criado
    node->next = temp->next;
    temp->next = node;

    // caso 3.1: inserção no fim, o index é o último da lista, node passa a ser tail
    if (index - 1 == count) {
        return node;
    };

    // caso 3.2: inserção no meio, retorna tail
    return tail;
};

Node* removeValue(Node* tail, char value) {

    if (tail == NULL) {
        return NULL;
    };

    // pega o primeiro valor da lista;
    Node* temp = tail->next;
    Node* tempPrev = tail;

    // caso 0: lista com apenas um nó e o valor é o nó
    if (temp == tail && tail->data == value) {
        free(tail);
        return NULL;
    };

    while(temp != tail && temp->data != value) {
        tempPrev = temp;
        temp = temp->next;
    };

    // caso 1.1: chegou ao fim e não achou o valor
    if (temp == tail && temp->data != value) {
        return tail;
    } else if (temp != tail && temp->data == value) { // caso 2.2: não chegou ao fim e achou o valor
        tempPrev->next = temp->next;
        free(temp);
        return tail;
    } else { // caso 2.3: chegou ao fim e achou o valor
        tempPrev->next = tail->next;
        free(temp);
        // Se após a remoção só resta um nó, retorna NULL
        if (tempPrev == tempPrev->next) {
            return NULL;
        }
        return tempPrev;
    }
}

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

void clearList(Node* tail) {
    if (tail == NULL) {
        return;
    }
    
    Node* current = tail->next;
    Node* head = tail->next;
    Node* temp;

    do {
        temp = current;
        current = current->next;
        free(temp);
    } while (current != head);

}

// int -> o tipo do retorno da função
// int argc -> int que representa a qtd de argumentos passados ao rodar o código, ex no terminal roda: test.exe "OI" "eu", resultado será 2
// char *argv[] -> array contendo os argumentos, argv[0] sempre será o nome do programa, ex: argv[0] = test, argv[1] = OI, argv[2] = eu
int main() {
    
    /* em listas circulares, list sempre vai apontar para o último elemento da lista, ao invés do primeiro.*/

    // inicia a lista como um ponteiro para um nó NULL, é necessário que seja um ponteiro pois seu endereço precisa mudar sempre que a lista
    // cresce ou diminui.
    Node* list = NULL;

    
    list = insertAtStart(list, 'A');
    list = insertAtEnd(list, 'B');
    list = insertAtEnd(list, 'C');
    list = insertAtEnd(list, 'D');
    list = insertAtStart(list, 'X');

    printf("List: ");
    printList(list); 

    
    printf("\nList after removing value 'C': ");
    list = removeValue(list, 'C');
    printList(list);

    list = removeAtIndex(list, 2);
    printf("\nList after removing value at index 2: ");
    printList(list); 

    clearList(list);
    printf("\nList memory cleared.");
    
    return 0;
};