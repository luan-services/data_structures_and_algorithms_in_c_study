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
    printf("Endereço de y (usando &y): %p Valor de Y: %i\n", &y, y);
    

    return 0;
}