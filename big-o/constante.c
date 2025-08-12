#include <stdio.h> // isso é uma diretiva de pré-processador. A palavra #include instrui o compilador a incluir o conteúdo de 
// um arquivo de cabeçalho (header file) em nosso programa. Neste caso, estamos incluindo o arquivo stdio.h (Standard Input/Output), 
// que contém as funções para operações de entrada e saída de dados, como a função printf().
#include <stdbool.h> // Necessário para usar 'bool', 'true' e 'false'

// Complexidade linear é aquela que não muda independente do tamanho da entrada. Ela é sempre 1.
// velocidade: instantânea, para qualquer tipo de entrada

// char* define que o return type da função é um ponteiro para char (precisa ser feito assim para retornar o endereço de um valor dentro da string)
char* getFirstStudent(char arr[][20]) { // O (1) - complexidade constante, pois não importa o tamanho do array, sempre acessa o primeiro elemento
    
    // retorna o endereço de arr[0] (pq é o array recebido é bidimensional), ou seja um ponteiro apontando pro primeiro elemento do array (joao)    
    return arr[0]; // O (1)
}

// int -> o tipo do retorno da função
// int argc -> int que representa a qtd de argumentos passados ao rodar o código, ex no terminal roda: test.exe "OI" "eu", resultado será 2
// char *argv[] -> array contendo os argumentos, argv[0] sempre será o nome do programa, ex: argv[0] = test, argv[1] = OI, argv[2] = eu
int main(int argc, char *argv[]) {
    // cria um array de 5 elementos char, definindo que cada um deles têm no máximo 19 char + '\0' (20)
    char students[5][20] = {"Joao", "Maria", "Jose", "Ana", "Pedro"}; 

    // imprime todos os chars do firstStudent (formando a string ) e para quando chegar em '\0'
    printf("%s", getFirstStudent(students));

    return 0;
}