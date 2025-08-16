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

/*
no caso abaixo a lista se inicia com null, sendo necesário fazer as funções de inserção serem capazes de lidar com o caso da lista ser NULL,
ou seja, nesses casos, as funções precisam retornar o nó.

se houvesse uma função para iniciar a lista com algum valor, ex: createList(char value); as funções de inserção poderiam retornar void, apenas
usando esse endereço inicial e fazendo as modificações.
*/

// em primeiro lugar, define-se o 'objeto' nó.
typedef struct Node {
    char data; // data pode ser qualquer tipo, aqui faremos com char. 
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
    // next é sempre um ponteiro, faz o próximo endereço ser list, caso a lista esteja vazia, próximo endereço é null, caso contrário, 
    // é o primeiro valor da lista
    node->next = list;
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
    return list;
};

Node* insertAtIndex(Node* list, char data, int index) {
    // cria um nó e insere o valor dentro
    Node* node = (Node *) malloc(sizeof(Node));
    if (node == NULL) {
        printf("Error: Memory allocation for linked list failed.\n");
        exit(1);
    };
    node->data = data; // é o mesmo que (*node).data

    if (index == 0) { // caso o indíce seja 0 faz a inserção padrão no inicio da lista O (1)
        node->next = list;
        return node;
    };

    // ponteiro temporário que recebe o endereço que está em list
    Node* temp = list;
    int count = 0;

    // garante que se temp seja NULL (ou seja, a lista seja vazia, ou o indice seja maior que a qtd de nós da lista) o while vai parar
    // o nó anterior ao indice necessário precisa apontar para o nó atual, por isso o while para quando count é 1 à menos que index 
    while (temp != NULL && index > count + 1) { // O (N)
        temp = temp -> next;
        count ++;
    };

    if (temp == NULL) { // garante que caso o indíce seja maior que a quantidade de nós, a função falhe.
        printf("Error: Insert index out of linked list bounds.\n");
        free(node);
        exit(1);
    };

    // nó criado aponta para o próximo de nó indice - 1, nó indice - 1 aponta para nó criado
    node->next = temp->next;
    temp->next = node;

    return list;
};

Node* removeValue(Node* list, char value) {
    Node* temp = list;

    // caso 1: lista vazia
    if (temp == NULL) {
        return list;
    };

    // caso 2: o nó a ser removido é o primeiro da lista
    if (temp->data == value) {
        list = temp->next;
        free(temp);
        return list; // retorna o novo início da lista
    }

    // caso 3: O nó a ser removido está em algum lugar no meio ou no fim
    while (temp->next != NULL) { // O (N), enquanto o próximo nó existir, checa se ele contém o valor a er removido
        if (temp->next->data == value) { // caso o próximo nó seja o valor
            Node* tempRemove = temp->next; // cria um nó temporário para receber o nó a ser removido
            temp->next = tempRemove->next; // pega o endereço next do nó atual e faz ele ser o next do próximo nó
            free(tempRemove); // libera o nó a ser removido;
            return list;
        };
        // caso o próximo nó não seja o valor, avança
        temp = temp->next; 
    };

    // se o valor não foi encontrado em nenhum caso.
    return list; // retorna a lista inalterada
};

Node* removeAll(Node* list, char value) {
    Node* current = list;
    Node* previous = NULL;
    
    // percorre a lista para remover todas as ocorrências
    while (current != NULL) {
        if (current->data == value) {

            if (previous == NULL) { // caso 1: nó a ser removido é o primeiro da lista
                list = current->next; // primeiro da lista passa a ser o segundo
                free(current); // libera o nó a ser removido
                current = list;  // passa pro próximo nó e continua o loop
            } else { // caso 2: nó a ser removido está no meio ou fim da lista
                previous->next = current->next; // pega o anterior e aponta para o próximo do nó a ser removido
                free(current); // libera o nó a ser removido
                current = previous->next; // passa pro próximo nó e continua o loop
            }
        } else { // se o nó atual não for o que queremos remover, só avança
            previous = current;
            current = current->next;
        }
    }
    return list;
}

Node* removeAtIndex(Node* list, int index) {
    Node* temp = list;

    // caso 1: a lista está vazia
    if (temp == NULL) { // caso o índice 0 seja NULL, a lista está vazia
        return list;
    }

    // caso 2: O nó a ser removido é o primeiro da lista (index 0)
    if (index == 0) {

        list = temp->next; // nó 0 recebe o endereço do nó 1
        free(temp); // libera o nó a ser removido
        return list;
    };
    
    int count = 0;

    // caso 2: o nó a ser removido está em alguma outra posição
    while (temp != NULL && index > count + 1) {
        count++;
        temp = temp->next;
    }

    // caso o índice a ser removido seja maior que a lista;
    if (temp == NULL || temp->next == NULL) {
        return list;
    };

    Node* tempRemove = temp->next;
    temp->next = tempRemove->next;
    free(tempRemove);
    return list;
};

void printList(Node* list) {

    Node *temp;
    temp = list;

    while (temp != NULL) {  // O (N)
        printf("%c ", temp->data); // printando chars, é necessário mudar baseado no tipo do dado
        temp = temp->next;
    };

    printf("\n");
};

void printByIndex(Node* list, int index) {

    Node *temp;
    temp = list;

    int count = 0;

    while (temp != NULL && index > count ) {  // O (N)
        temp = temp->next;
        count ++;
    };
    
    if (temp == NULL) { // garante que caso o indíce seja maior que a quantidade de nós, a função falhe.
        printf("Error: Print index out of linked list bounds.\n");
        exit(1);
    };

    printf("%c\n", temp->data); // printando char, é necessário mudar baseado no tipo do dado
};

char getValueAtIndex(Node* list, int index) {

    Node *temp = list;

    int count = 0;

    while (temp != NULL && index > count ) {  // O (N)
        temp = temp->next;
        count ++;
    };
    
    if (temp == NULL) { // garante que caso o indíce seja maior que a quantidade de nós, a função falhe.
        printf("Error: Print index out of linked list bounds.\n");
        exit(1);
    };

    return temp->data;
};

int getValueIndex(Node* list, char value) {

    Node *temp = list;

    int count = 0;

    while (temp != NULL) {  // O (N)
        if (temp->data == value) {
            return count;
        }
        temp = temp->next;
        count ++;
    };
    
    // caso temp seja null o valor não foi encontrado
    printf("Error: Value not found on list.\n");
};

void clearList(Node* list) {
    while (list != NULL) {
        Node* temp = list;
        list = list->next;
        free(temp);
    };
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
    list = insertAtIndex(list, 'C', 2);
    list = insertAtIndex(list, 'X', 1);
    list = insertAtEnd(list, 'B'); // adicionando outro 'B' para testar removeAll
    list = insertAtEnd(list, 'B'); // adicionando outro 'B' para testar removeAll
    
    printf("List: ");
    printList(list);
    printf("List index 3: ");
    printByIndex(list, 3);

    // search by index
    char ch = getValueAtIndex(list, 2);
    printf("\nValue at Index 2: %c\n", ch); 

    // search index by char
    int index = getValueIndex(list, 'X');
    printf("Index of first occurrence of 'X': %d\n", index); 
    index = getValueIndex(list, 'B');
    printf("Index of first occurrence of 'B': %d\n", index); 
    

    list = removeValue(list, 'X');
    printf("\nList after removing value 'X': ");
    printList(list);

    list = removeAtIndex(list, 2);
    printf("List after removing value at index 2: ");
    printList(list); 

    list = removeAll(list, 'B');
    printf("List after removing all occurrences of 'B': ");
    printList(list); 

    
    clearList(list);
    printf("\nList memory cleared.");

    return 0;

}