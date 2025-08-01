#include <stdio.h> // isso é uma diretiva de pré-processador. A palavra #include instrui o compilador a incluir o conteúdo de 
// um arquivo de cabeçalho (header file) em nosso programa. Neste caso, estamos incluindo o arquivo stdio.h (Standard Input/Output), 
// que contém as funções para operações de entrada e saída de dados, como a função printf().
#include <stdbool.h> // Necessário para usar 'bool', 'true' e 'false'

// int -> o tipo do retorno da função
// int argc -> int que representa a qtd de argumentos passados ao rodar o código, ex no terminal roda: test.exe "OI" "eu", resultado será 2
// char *argv[] -> array contendo os argumentos, argv[0] sempre será o nome do programa, ex: argv[0] = test, argv[1] = OI, argv[2] = eu
int main(int argc, char *argv[]) {
    int notas[5] = {10, 8, 7, 9, 10};
    char nome_completo[] = "Joao da Silva"; // uma string é um array de chars
    char cidade[20] = "Brasilia"; // Define um tamanho máximo de 20 caracteres no array
    bool tem_carteira_de_motorista = true;

    printf("Nome: %s\n", nome_completo);
    printf("Tem carteira de motorista? %s\n", tem_carteira_de_motorista ? "Sim" : "Não");
    printf("A primeira nota foi: %d\n", notas[0]);
    printf("Olá, Mundo!\n");
    return 0; 
}