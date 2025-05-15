/*Exercício: Lista de Números Inteiros - Inserção, Impressão e Remoção
Implemente uma lista simplesmente encadeada em C ou C++ que permita as seguintes operações:

Inserir um número no final da lista. ok

Inserir um número no inicio da lista. ok

Imprimir todos os elementos da lista. ok 

Remover um número específico da lista (informado pelo usuário). ok

Liberar toda a memória alocada pela lista ao final do programa. ok

Regras:
Use structs com ponteiros para criar os nós da lista.

Crie um menu com as opções para o usuário interagir com a lista.*/

#include <iostream>
using namespace  std;

struct No {
    int numero;
    No* proximo;
};

class ListaEncadeada {
    private:
        No* inicio; 
        int quantidade_atual_elementos = 0;  // Criando um contador para o futuro
    public:
            ListaEncadeada(){
                inicio = nullptr; // Como a lista esta vazia, o inicio aponta direto para o nullptr
                cout << "Lista criada com sucesso!" << endl;
            }

            ~ListaEncadeada(){
                No* temp; // Criando um no temporario
                while (temp->proximo != nullptr) {  // Iterando por cada no e deletando o mesmo
                    temp = inicio;
                    inicio = inicio->proximo;
                    delete temp;
                }
                cout << "Memoria liberada com sucesso!" << endl;
            }

            void inserir_final(int valor) {
                No* novo = new No;  // Alocando memoria 
                novo->numero = valor;  

                if (inicio == nullptr) {  // Verificando se a lista esta vazia
                    novo->proximo = nullptr;  // Utlimo elemento aponta para o nullptr
                    inicio = novo;  // Inicio agora aponta para esse novo elemento
                } else {
                    No* aux = inicio;
                    while (aux->proximo != nullptr) {
                        aux = aux->proximo;  // Iterando ate parar no ultimo nó, o qual aponta para nullptr
                    }
                    novo->proximo = nullptr;  // Ultimo elemento aponta para o nullpt
                    aux->proximo = novo;  // O antigo ultimo no agora é o penultimo e aponta para o ultimo, que agora é o novo
                }
            }

            void inserir_inicio(int valor) {
                No* novo = new No;  // Alocando memoria
                novo->numero = valor;

                if (inicio == nullptr) {  // Verificando se a lista esta vazia
                    novo->proximo = nullptr;  // Utlimo elemento aponta para o nullptr
                    inicio = novo;  // Inicio agora aponta para esse novo elemento
                } else {
                    novo->proximo = inicio;  // Novo aponta para o antigo inicio
                    inicio = novo;  // inicio agora aponta para o novo
                }
            }

            void imprimir_lista() {
                No* aux = inicio;  // Variavel auxiliar
                int contador = 1;
                while (aux != nullptr) {
                    cout << "Elemento " << contador << " = " << aux->numero << endl;
                    aux = aux->proximo;  // Avança para o proximo no
                    contador++;
                }
            }

            void remover_especifico(int valor) {
                No* aux = inicio;
                No* anterior = nullptr;
                int encontrado = 0;

                while (aux != nullptr) {  // Iterando sobre a lista
                    if (aux->numero == valor) {
                        if (aux == inicio) { // Verificando se o numero que o usuario digitou é o inicio da lista
                            inicio = aux->proximo; // Apontando para o proximo, que agora será o novo incio
                            encontrado = 1; // atualiza a variavel encontrado
                            delete aux;

                        } else {  // Caso seja o numero que o usario digitou esteja no meio ou no final
                            anterior->proximo = aux->proximo;   // Pula o no atual, o qual sera removido
                            encontrado = 1;
                            delete aux;
                        }
                        break;
                    } else {
                        anterior = aux; // Guarda o anterior, que no caso é o atual
                        aux = aux->proximo;  // Avança para o proximo no
                    }
                }
                if (encontrado == 1) {
                    cout << "Numero " << valor << " removido com sucesso!" << endl;
                } else {
                    cout << "Numero " << valor << " nao encontrado!" << endl;
                }
            }
};

int main() {
    ListaEncadeada lista;
    int opcao;
    int valor;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Inserir no inicio\n";
        cout << "2. Inserir no final\n";
        cout << "3. Imprimir lista\n";
        cout << "4. Remover numero\n";
        cout << "5. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite o valor a ser inserido no início: ";
                cin >> valor;
                lista.inserir_inicio(valor);
                break;
            case 2:
                cout << "Digite o valor a ser inserido no final: ";
                cin >> valor;
                lista.inserir_final(valor);
                break;
            case 3:
                lista.imprimir_lista();
                break;
            case 4:
                cout << "Digite o valor a ser removido: ";
                cin >> valor;
                lista.remover_especifico(valor);
                break;
            case 5:
                cout << "Encerrando o programa...\n";
                break;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
                break;
        }

    } while (opcao != 5);
    return 0;
}