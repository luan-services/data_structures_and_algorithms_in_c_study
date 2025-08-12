#include <stdio.h> // isso é uma diretiva de pré-processador. A palavra #include instrui o compilador a incluir o conteúdo de 
// um arquivo de cabeçalho (header file) em nosso programa. Neste caso, estamos incluindo o arquivo stdio.h (Standard Input/Output), 
// que contém as funções para operações de entrada e saída de dados, como a função printf().
#include <stdbool.h> // Necessário para usar 'bool', 'true' e 'false'

// Complexidade linearítmica geralmente é encontrada em algoritmos que dividem as entradas em partes menores (logn), processam as partes e
// em seguida mesclam os resutados (n), gerando um desempenho melhor que n².
// velocidade: muito rápida, usada como padrão nas bibliotecas de sort.

void merge(int arr[], int left, int middle, int right) { // O (n), função que serve para juntar dois arrays
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // arrays criados dentro de função alocam memória e automáticamente liberam após o fim da função, a não ser que sejam criados com malloc,
    // aí ficam para sempre  
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    i = 0; // Initial index of first sub-array
    j = 0; // Initial index of second sub-array
    k = left; // Initial index of merged sub-array

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int left, int right) { // O (n logn), divide os arrays em metades menores e depois junta.

    if (left < right) {  // se o indíce primeiro elemento é diferente do último
        int middle = left + (right - left) / 2; // encontra o elemento do meio

        // divide o array em dois e chama o mergeSort pra cada lado
        mergeSort(arr, left, middle); // O (log n)
        mergeSort(arr, middle + 1, right); // O (log n)

        // chama a função de juntar arrays ordenadamente
        merge(arr, left, middle, right); // O (n)
    }
}

// int -> o tipo do retorno da função
// int argc -> int que representa a qtd de argumentos passados ao rodar o código, ex no terminal roda: test.exe "OI" "eu", resultado será 2
// char *argv[] -> array contendo os argumentos, argv[0] sempre será o nome do programa, ex: argv[0] = test, argv[1] = OI, argv[2] = eu
int main(int argc, char *argv[]) {
    
    // array em ordem crescente.
    int numbers[] = {1,6,5,0,12,15,20,322,47,19,102};
    int length = sizeof(numbers) / sizeof(numbers[0]);
    int search = 15;

    mergeSort(numbers, 0, length - 1);

    for (int i = 0; i < length; i++) {
        printf("%i ", numbers[i]);
    };

    return 0;
}