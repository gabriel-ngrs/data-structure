#include <stdio.h>
#include <stdlib.h>

int* lista; // Lista dinâmica
int tamanho_atual = 0; // Quantidade de elementos
int capacidade = 0; // Capacidade total

void criarlista(int capacidade_inicial) {
    capacidade = capacidade_inicial;
    lista = (int*) malloc(capacidade * sizeof(int));

    if (lista == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
}

void adicionar_elemento(int novo_valor) {
    if (tamanho_atual == capacidade) {
        printf("A lista esta cheia, aumentando de tamanho...\n");

        if (capacidade == 0) capacidade = 1; // Garante capacidade mínima
        capacidade *= 2;

        lista = (int*) realloc(lista, capacidade * sizeof(int));
        if (lista == NULL) {
            printf("Erro ao realocar memoria!\n");
            exit(1);
        }
    }

    lista[tamanho_atual] = novo_valor;
    tamanho_atual++;
}

void exibir_lista() {
    printf("Lista: ");
    for (int i = 0; i < tamanho_atual; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

void destruir_lista() {
    free(lista);
}

int main() {
    int capacidade_inicial;
    printf("Digite o tamanho inicial da lista: ");
    scanf("%d", &capacidade_inicial);

    criarlista(capacidade_inicial);

    for (int i = 0; i < 5; i++) {
        int entrada=0;
        printf("Digite o valor da posicao %d: ", i+1);
        scanf("%d", &entrada);
        adicionar_elemento(entrada);
    }

    exibir_lista();
    destruir_lista();

    return 0;
}
