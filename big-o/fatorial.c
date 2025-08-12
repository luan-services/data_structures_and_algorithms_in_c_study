#include <stdio.h> // isso é uma diretiva de pré-processador. A palavra #include instrui o compilador a incluir o conteúdo de 
// um arquivo de cabeçalho (header file) em nosso programa. Neste caso, estamos incluindo o arquivo stdio.h (Standard Input/Output), 
// que contém as funções para operações de entrada e saída de dados, como a função printf().
#include <stdbool.h> // Necessário para usar 'bool', 'true' e 'false'

// Complexidade fatorial considera todas as permutações possíveis para cada elemento, tornando um algoritmo MUITO pesado para qualquer n grande
// velocidade: impraticável para n > 10.

// um exemplo de permutação de string, char *str recebe um ponteiro para o primeiro elemento de uma string de characteres
void permuteString(char *str, int left, int right) {
    if (left == right) {
        printf("%s\n", str);
        return;
    }
    for (int i = left; i <= right; i++) {
        char tmp = str[left]; str[left] = str[i]; str[i] = tmp;
        permuteString(str, left+1, right);
        tmp = str[left]; str[left] = str[i]; str[i] = tmp;
    }
}

        
    

// int -> o tipo do retorno da função
// int argc -> int que representa a qtd de argumentos passados ao rodar o código, ex no terminal roda: test.exe "OI" "eu", resultado será 2
// char *argv[] -> array contendo os argumentos, argv[0] sempre será o nome do programa, ex: argv[0] = test, argv[1] = OI, argv[2] = eu
int main(int argc, char *argv[]) {
    
    char palavra[] = "Helks";
    int length = sizeof(palavra) / sizeof(char) - 1;

    printf(" Permutation of string of size %i:", length);
    permuteString(palavra, 0, length - 1);


    return 0;
}