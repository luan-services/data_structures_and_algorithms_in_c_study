#include <stdio.h> // isso é uma diretiva de pré-processador. A palavra #include instrui o compilador a incluir o conteúdo de 
// um arquivo de cabeçalho (header file) em nosso programa. Neste caso, estamos incluindo o arquivo stdio.h (Standard Input/Output), 
// que contém as funções para operações de entrada e saída de dados, como a função printf().
#include <stdbool.h> // Necessário para usar 'bool', 'true' e 'false'

#include <stdlib.h> // necessário para tratar ponteiros com funções malloc, free, calloc, realloc, etc.

// A stack é uma área de memória usada principalmente para variáveis locais e parâmetros de funções. A heap é uma área de memória usada 
// para alocação dinâmica — ou seja, você decide quanto e quando alocar. Ela é controlada pelo programador.

void testingPointers() {

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
        printf("numbers[%i]: %i, %i, %i, %i\n", i, *(pArr + i), pArr[i], *(numbers + i), numbers[i]);
    };
    // printamos todos os elementos do array usando ponteiros




    return 0;
}