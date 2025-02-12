#include <stdio.h>

int main() {
    int array[5];
    int i;

    for (i=0;i<5;i++) {
        printf("Digite o valor da posicao %d: ", i+1);
        scanf("%d", &array[i]);        
    }

    for (i=0;i<5;i++) {
        printf("%d ", array[i]);
    }
    return 0;
}