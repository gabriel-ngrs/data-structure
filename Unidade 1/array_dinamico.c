#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho;

    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    int *arr = (int *)malloc(tamanho * sizeof(int));

    if (arr == NULL) {
        printf("Erro de alocação de memoria.");
        return 1;
    }
    
    for(int i=0;i<tamanho;i++) {
        printf("Digite o valor da posicao %d: ", i+1);
        scanf("%d", &arr[i]);
    
    }

    for(int i=0;i<tamanho;i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}