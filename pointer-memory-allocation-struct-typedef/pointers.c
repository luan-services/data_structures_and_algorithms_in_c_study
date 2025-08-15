#include <stdio.h> // isso é uma diretiva de pré-processador. A palavra #include instrui o compilador a incluir o conteúdo de 
// um arquivo de cabeçalho (header file) em nosso programa. Neste caso, estamos incluindo o arquivo stdio.h (Standard Input/Output), 
// que contém as funções para operações de entrada e saída de dados, como a função printf().
#include <stdbool.h> // Necessário para usar 'bool', 'true' e 'false'

#include <stdlib.h> // necessário para tratar ponteiros com funções malloc, free, calloc, realloc, etc.

// A stack é uma área de memória usada principalmente para variáveis locais e parâmetros de funções. A heap é uma área de memória usada 
// para alocação dinâmica — ou seja, você decide quanto e quando alocar. Ela é controlada pelo programador. ponteiros podem ser
// criados tanto na stack quanto na heap, ponteiros que recebem dados e endereços de variáveis comums
// ficam na stack, ponteiros que usam alocação dinamica com maloc() são criados na heap e precisam ser liberados
// com free.


/* exemplo 3: função exemplo para testar ponteiros com ints*/
void testingIntPointers(int a, int *b) {

    a = 46;
    *b = 120;

};

/* exemplo 3: função exemplo para testar ponteiros com arrays*/
int* testingArrPointers(int arrA[], int *arrB) {

    arrA[0] = 1200;
    arrB[0] = 2000;

    int arrC[2] = {100, 200};
    return arrC;
};

// int -> o tipo do retorno da função
// int argc -> int que representa a qtd de argumentos passados ao rodar o código, ex no terminal roda: test.exe "OI" "eu", resultado será 2
// char *argv[] -> array contendo os argumentos, argv[0] sempre será o nome do programa, ex: argv[0] = test, argv[1] = OI, argv[2] = eu
int main(int argc, char *argv[]) {

    /* ponteiros são variáveis que guardam  o endereço de um valor. para acessar o endereço, basta usar o nome da varíavel, ex: p. porém, se
    você quer acessar o valor para qual o ponteiro aponta, basta colocar * antes do nome, ex: *p. dessa forma, o código vai buscar o valor 
    guardado dentro do endereço apontado por p.
    
    ponteiros para valores já existem são tratados de forma diferentes de ponteiros alocados na memória com malloc(), eles ficam na stack
    não é necessário liberá-los, alguns exemplos estão abaixo: */

    /* 
    
    */


    /* exemplo 1: ponteiro para um int e seus endereços */

    // define um int x;
    int x = 10; 

    // cria um ponteiro p, que recebe o endereço de x;
    int *p = &x;
    
    // define um outro int, y, que recebe o valor dentro do endereço que p está apontando (10);
    int y = *p;

    // modifica o valor de x para 15;
    x = 15;

    // printamos o endereço da varíavel X e o valor dela.  
    printf("Endereço de x (usando &x): %p Valor de X: %i\n", &x, x);

    // printamos o endereço de p e o valor dele. Nota-se que é o mesmo endereço da variável x e o mesmo valor, significa que qualquer mudança
    // aqui, causa uma mudança em X.   
    printf("Endereço de p (usando p): %p Valor de P(o mesmo de X): %i\n", p, *p);

    // printamos o endereço da varíavel Y e o valor dela, nota-se que y usa o valor antigo de X, mas tem endereço e valor próprio.
    printf("Endereço de y (usando &y): %p Valor de Y: %i\n\n\n", &y, y);

    //
    
    /* exemplo 2: ponteiro em arrays */

    // define um array numbers com 5 elementos, o nome de um array é um ponteiro constante para o primeiro elemento do array, se você printar
    // numbers, você recebe o endereço do primeiro número, o 1.
    int numbers[5] = {1,4,5,7,10};

    // cria um ponteiro para o array, e passa o endereço do array enviando 'numbers'.
    int *numbersPointer = numbers;

    /* para acessar qualquer valor subsequente do array, fazemos arr[x], o que significa: arr (endereço base do array, que aponta pro elemento
    0 + (x * tipo do array), isso significa que fazer [1], nada mais é que multiplicar o tamanho do tipo do array (4 bytes) por 2. isso
    dá 8 bytes, que é somado ao endereço base do array e vai diretamente para o segundo elemento. */

    /* é importante notar que o código não sabe onde o array 'termina', apenas calculamos onde os próximos elementos vão estar na memória com
    base no endereço do primeiro elemento */ 

    // define um ponteiro que recebe o endereço do segundo elemento do array.
    int *p1 = &numbers[1];

    // modifica o valor do array para 452, percebe-se que o valor de x não muda, permanece sendo o antigo valor de numbers[1].
    *p1 = 452;


    // printamos o endereço inicial do array, o valor de arr[1] usando [] e usando ponteiros.
    printf("Endereço do array (usando o nome do array): %p\n", numbers);
    printf("Valor do indice 1 do array (usando [1]): %i\n", numbers[1]);
    printf("Valor do indice 1 do array (usando ponteiro ao invés de [1]): %i\n\n", *(numbers + 1));


    // criamos um ponteiro que recebe o endereço do primeiro valor do array.
    int *pArr = numbers; // &numbers[0]

    /* imprimimos o valor de cada número do array de 4 formas diferentes:
        usando o ponteiro que recebe o endereço do array, pode ser feito *(pArr + i), mas também é possível, e muito útil usar indices no
        ponteiro  pArr[i].
        usando o array em si, usando o índice numbers[i] ou diretamente com endereço *(numbers + i)
    */
    for (int i = 0; i < 5; i ++) {
        printf("numbers[%i]: %i, %i, %i, %i\n\n\n", i, *(pArr + i), pArr[i], *(numbers + i), numbers[i]);
    };

    /* exemplo 3: ponteiro em funções */

    int a = 40;
    int b = 70;

    /* a função abaixo pede um valor e um endereço. passamos o valor de A e o endereço de B, dentro dela, ela faz:
        a = 46;
        *b = 120;
    isso fará que a seja 46 apenas dentro do escopo da função, porém modificará permanentemente o valor de b fora da função */
    testingIntPointers(a, &b);


    int arrA[4] = {20, 22, 24, 26};
    int arrB[4] = {30, 33, 36, 39};

    /* a função abaixo pede int arrA[], int *arrB, pode parecer diferente, mas as duas formas que o array está sendo escrito pedem a mesma
    coisa: o endereço base do array.
    diferente de ints e chars, é impossível passar cópias de arrays para funções, a função só aceita endereços para o array em sí.
    
        arrA[0] = 1200;
        arrB[0] = 2000;

    dentro dela, ela chama as duas operações, e é possível notar que o valor dos arrays muda fora do escopo também.

    ela também retorna o endereço do arrC criado dentro dela, e é possivel notar que é 0, pois arrays criados dentro de escopo de funções são
    desfeitos após a função terminar */

    int *arrC = testingArrPointers(arrA, &arrB[0]); // essas duas formas estão passando a mesma coisa: o endereço para o valor inicial de cada array. &arrB[0]
    // também pode, e deve, ser passado como arrB apenas.

    printf("Valor de arrA[0]: %i Valor de arrB[0]: %i\n", arrA[0], arrB[0]);

    printf("Endereço de arrC: %i", arrC); // printa 0 pois o endereço não existe já que recebe o endereço de um array criado dentro de função.

    return 0;
}