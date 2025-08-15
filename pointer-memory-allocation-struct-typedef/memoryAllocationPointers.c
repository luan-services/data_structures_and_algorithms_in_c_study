#include <stdio.h> // isso é uma diretiva de pré-processador. A palavra #include instrui o compilador a incluir o conteúdo de 
// um arquivo de cabeçalho (header file) em nosso programa. Neste caso, estamos incluindo o arquivo stdio.h (Standard Input/Output), 
// que contém as funções para operações de entrada e saída de dados, como a função printf().
#include <stdbool.h> // Necessário para usar 'bool', 'true' e 'false'

#include <stdlib.h> // necessário para tratar ponteiros com funções malloc, free, calloc, realloc, etc.

// A stack é uma área de memória usada principalmente para variáveis locais e parâmetros de funções. A heap é uma área de memória usada 
// para alocação dinâmica — ou seja, você decide quanto e quando alocar. Ela é controlada pelo programador. ponteiros podem ser
// criados tanto na stack quanto na heap, ponteiros que recebem dados e endereços de variáveis comums ficam na stack, ponteiros que usam 
// alocação dinamica com maloc() são criados na heap e precisam ser liberados com free.

/* A stack é usada para variáveis locais e argumentos de funções. A alocação e desalocação de memória na stack é automática e muito rápida.

A heap é uma área de memória maior e mais flexível, onde a alocação dinâmica acontece. É o programador quem gerencia essa memória, o que 
significa que você precisa alocar e, mais importante, desalocar essa memória manualmente.*/

// funçao auxiliar para gerar array.
int* generateArr(int size) {
    // retorna um endereço NULL, caso o tamanho seja 0 ou menos
    if (size <= 0) {
        return NULL;
    }

    // cria um array com malloc(), ele vai ter um espaço na memória heap e não vai ser 
    // removido com o fim da função  
    int *pArr = (int *) malloc(size * sizeof(int));

    if (pArr == NULL) {
        printf("Erro ao alocar memória!\n");
        return NULL;
    }

    return pArr;
};

// int -> o tipo do retorno da função
// int argc -> int que representa a qtd de argumentos passados ao rodar o código, ex no terminal roda: test.exe "OI" "eu", resultado será 2
// char *argv[] -> array contendo os argumentos, argv[0] sempre será o nome do programa, ex: argv[0] = test, argv[1] = OI, argv[2] = eu
int main(int argc, char *argv[]) {

    /* exemplo 1: int p */

    // declarando um ponteiro qualquer de um inteiro
    int *p;

    // a função malloc(n) serve para alocar um espaço de memória de n bytes, ela retorna um endereço
    // de memória com um ponteiro do tipo VOID, por conta disso é necessário fazer o casting (int *),
    // que é modificar o tipo de ponteiro para o tipo que precisamos (no caso, int)
    p = (int *) malloc(sizeof(int));

    // proteção para caso por algum motivo a memória não seja alocada
    if (p == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    };

    *p = 10;

    printf("Ponteiro com malloc()\nEndereço: %i valor: %i\n\n", p, *p);

    // precisamos liberar o espaço de memória alocado, após usar o ponteiro.
    free(p);

    /* exemplo 2: int array */
    int length = 5;
    // alocamos memória para 5 ints.
    int *pArr = (int *) malloc(sizeof(int) * length);

    // proteção para caso por algum motivo a memória não seja alocada
    if (pArr == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    };

    printf("Array de int com ponteiros com malloc\n");
    for (int i = 0; i < length; i ++) {
        // como visto anteriormente, arrays nada mais são que conjuntos de ponteiros de um 
        // certo tipo, ordenados, e fazer pArr[i] é o mesmo que *(pArr + i), que significa
        // pular i endereços de x em x bytes (sendo x o tipo do array).
        pArr[i] = (i * 1) + 3;
        printf("pArr[%i] - Endereço: %i Valor: %i\n", i, &pArr[i], pArr[i]);
    };
    free(pArr);
    printf("\nArray de int com ponteiros liberado com sucesso.\n\n");

    /* exemplo 2: int array com calloc() */

    length = 10;

    // calloc é muito parecido com malloc(), porém ele inicializa ints com 0, e chars com 
    // \0 'string vazia', em malloc() esses espaços são inciados com 'lixo' e você tem que
    // dar um valor para eles antes de chamar.  
    int *pArrTwo = (int *) calloc(length, sizeof(int));

    // proteção para caso por algum motivo a memória não seja alocada
    if (pArrTwo == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    };
    printf("Array de int com ponteiros com calloc\n");
    for (int i = 0; i < length; i ++) {
        printf("pArrTwo[%i] - Endereço: %i Valor: %i\n", i, &pArrTwo[i], pArrTwo[i]);
    };
    free(pArrTwo);
    printf("\nArray de int com ponteiros liberado com sucesso.\n\n");

    /* exemplo 3: realloc() */
    
    // inicialmente aloca 3 inteiros
    int *pArrThree = (int *) malloc(3 * sizeof(int)); 

    // proteção para caso por algum motivo a memória não seja alocada
    if (pArrThree == NULL) {
        printf("Erro ao realocar memória!\n");
        return 1;
    };

    printf("Array de int com ponteiros antes de aumentar\n");
    for (int i = 0; i < 3; i++) {
        pArrThree[i] = (i * 1) + 2;
        printf("pArrThree[%i] - Endereço: %i Valor: %i\n", i, &pArrThree[i], pArrThree[i]);
    };


    // realloc serve para criar mais espaço no ponteiro, é necessário que o casting (int *)
    // seja o mesmo do anterior, e é preciso fazer p = realloc porque o realloc pode mudar
    // TODO o array de endereço caso não haja espaço no endereço original, por isso é preciso
    // usar o return dele para o novo endereço.
    pArrThree = (int *) realloc(pArrThree, 5 * sizeof(int));

    // proteção para caso por algum motivo a memória não seja alocada
    if (pArrThree == NULL) {
        printf("Erro ao realocar memória!\n");
        return 1;
    ;}

    printf("\nArray de int com ponteiros após aumentar\n");
    // Agora, o array tem 5 posições. Vamos preencher as novas.
    for (int i = 0; i < 5; i++) {
        if (i < 3) {
            printf("pArrThree[%i] - Endereço: %i Valor: %i\n", i, &pArrThree[i], pArrThree[i]);
        } else {
            pArrThree[i] = (i * 2) + 2;
            printf("pArrThree[%i] - Endereço: %i Valor: %i\n", i, &pArrThree[i], pArrThree[i]);
        };
    };

    free(pArrThree);
    printf("\nArray de int com ponteiros pArrThree liberado com sucesso.\n\n");

    /* exemplo 4: arrays criados em funções que se mantém */

    length = 4;
    int *pArrFour = generateArr(length);

    
    printf("Array gerado em função\n");
    for (int i = 0; i < length; i++) {
        pArrFour[i] = (i * 1) + 5;
        printf("pArrFour[%i] - Endereço: %i Valor: %i\n", i, &pArrFour[i], pArrFour[i]);
    };
    printf("\nArray de int com ponteiros pArrThree liberado com sucesso.\n\n");
    free(pArrFour);


    return 0;
};