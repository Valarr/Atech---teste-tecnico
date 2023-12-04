#include <stdio.h>
#include <stdlib.h>

// Função para calcular o máximo entre dois números
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Função para encontrar a área máxima de retângulo
int maximalRectangle(int* heights, int size) {
    // Aloca dinamicamente uma pilha para armazenar índices
    int* stack = (int*)malloc((size + 1) * sizeof(int));
    int top = -1; // Inicializa o topo da pilha
    int maxArea = 0; // Inicializa a área máxima

    // Itera sobre os elementos, incluindo um elemento fictício ao final
    for (int i = 0; i <= size; ++i) {
        // Enquanto a pilha não está vazia e o elemento atual é menor que o elemento no topo da pilha
        while (top != -1 && (i == size || heights[i] < heights[stack[top]])) {
            // Calcula a área do retângulo com base na altura do elemento no topo da pilha
            int height = heights[stack[top--]];
            // Calcula a largura do retângulo
            int width = (top == -1) ? i : i - stack[top] - 1;
            // Atualiza a área máxima
            maxArea = max(maxArea, height * width);
        }
        // Adiciona o índice atual à pilha
        stack[++top] = i;
    }

    // Libera a memória alocada para a pilha
    free(stack);
    // Retorna a área máxima encontrada
    return maxArea;
}

// Função principal para encontrar o retângulo de maior área contendo apenas '1' na matriz
int maximalRectangle(char matrix[][5], int rows, int cols) {
    // Verifica se a matriz está vazia
    if (rows == 0 || cols == 0) {
        return 0;
    }

    // Aloca dinamicamente um array para armazenar as alturas das barras
    int* heights = (int*)malloc(cols * sizeof(int));
    int maxArea = 0; // Inicializa a área máxima

    // Itera sobre cada linha da matriz
    for (int i = 0; i < rows; ++i) {
        // Atualiza as alturas das barras com base nos valores na matriz
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == '1') {
                // Se o valor na matriz for '1', incrementa a altura da barra
                heights[j] = (i == 0) ? 1 : heights[j] + 1;
            } else {
                // Se o valor na matriz for '0', zera a altura da barra
                heights[j] = 0;
            }
        }

        // Calcula a área máxima de retângulo para a linha atual
        maxArea = max(maxArea, maximalRectangle(heights, cols));
    }

    // Libera a memória alocada para as alturas
    free(heights);
    // Retorna a área máxima encontrada
    return maxArea;
}

// Função principal
int main() {
    // Exemplo de entrada
    char matrix[][5] = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    int rows = 4;
    int cols = 5;

    // Chamada da função para encontrar a área do retângulo de maior área contendo apenas '1'
    int result = maximalRectangle(matrix, rows, cols);

    // Exibição do resultado
    printf("Saída: %d\n", result);
}

