#include <stdio.h> // isso é uma diretiva de pré-processador. A palavra #include instrui o compilador a incluir o conteúdo de 
// um arquivo de cabeçalho (header file) em nosso programa. Neste caso, estamos incluindo o arquivo stdio.h (Standard Input/Output), 
// que contém as funções para operações de entrada e saída de dados, como a função printf().
#include <stdbool.h> // Necessário para usar 'bool', 'true' e 'false'

#include <string.h> // necessário para usar strcpy, função de passar strings para arrays de char.

#include <stdlib.h> // necessário para tratar ponteiros com funções malloc, free, calloc, realloc, etc.

/* structs é um tipo de dado que permite agrupar diferentes variáveis em um único nome, parecido com objetos, porém não são o mesmo pois são
incapazes de armazenar métodos. typedef é uma forma de renomear nomes de tipos, por exemplo, é possível renomear int para INTEGER, fazendo o 
seguinte:
    typedef int INTEGER -> typedef [tipo_existe] [nome_para_novo_tipo]

juntar type def é uma ferramenta poderosa pois torna muito mais simples a criação de variáveis structs fazendo uma única chamada ao tipo,
exemplo:

struct sem typedef: struct Book bookOne; -> é preciso chamar 'struct Book'
struct com typedef: book bookOne; -> chama apenas o tipo 'book' definido. */

// exemplo de struct sem typedef
struct Book {
    char title[100];
    char year[5];
};

// exemplo de typedef para um un long long int.
typedef unsigned long long int ulli;

// int -> o tipo do retorno da função
// int argc -> int que representa a qtd de argumentos passados ao rodar o código, ex no terminal roda: test.exe "OI" "eu", resultado será 2
// char *argv[] -> array contendo os argumentos, argv[0] sempre será o nome do programa, ex: argv[0] = test, argv[1] = OI, argv[2] = eu
int main(int argc, char *argv[]) {

    /* exemplo 1: struct sem typedef */

    struct Book fantasyBook;
    // o operador '=' em C serve apenas para objetos únicos: ints, floats, char (unico), por isso, para modificar strings (que são ARRAYS de
    // chars), é necessário usar o métido strcpy, que vai copiar os chars da string passada um à um.
    strcpy(fantasyBook.title, "Blood Blockade Battlefront");
    strcpy(fantasyBook.year, "2010");

    printf("Nome do livro %s Ano: %s\n\n", fantasyBook.title, fantasyBook.year);

    /* exemplo 2: typedef */

    ulli giganticNumber = 18446744073709551615ULL;

    printf("Unsigned long long gigante: %llu\n\n", giganticNumber);

    
    return 0;
}