#include <iostream>
using namespace std;

struct No {
    int dado;
    No* anterior;
    No* proximo;
};

class ListaDuplamenteEncadeada {
    private:
        No* inicio;
        No* fim;
    public:
        ListaDuplamenteEncadeada() {
            inicio = nullptr; // Como a lista esta vazia, o inicio aponta direto para o nullptr
            fim = nullptr;
            cout << "Lista criada com sucesso!" << endl;
        }

        ~ListaDuplamenteEncadeada(){
            No* temp; // Criando um no temporario
            while (temp->proximo != nullptr) {  // Iterando por cada no e deletando o mesmo
                temp = inicio;
                inicio = inicio->proximo;
                delete temp;
            }
            cout << "Memoria liberada com sucesso!" << endl;
        }

        void inserir_inicio(int valor) {
            No* novo = new No;  // Alocando memoria
            novo->dado = valor;

            if (inicio == nullptr) {  // Verificando se a lista esta vazia 
                inicio = novo;  // Inicio agora aponta para o novo no
                novo->proximo = nullptr;  // Ponteiro proximo do novo no aponta agora para nullptr pois ele é o primeiro e unico elemento
                novo->anterior = nullptr;  // Ponteiro anterior do novo no aponta agora para nullptr pois ele é o primeiro e unico elemento
                fim = novo;  // Fim agora aponta para o novo no, pois a lista estava vazia, logo esse no é o inicio e fim da lista
                cout << "Elemento inserido com sucesso." << endl;
                return;
            }

            novo->proximo = inicio;  // Ponteiro proximo do novo no aponta agora para o proximo elemente, que era antes o inicio
            inicio->anterior = novo;  // Ponteiro anterior do 2 no, que no caso era o inicio agora aponta para o novo
            novo->anterior = nullptr;  // Anterior do novo aponta pra null pois agora é o primeiro no
            inicio = novo;  // Inicio agora aponta para o novo no
            cout << "Elemento inserido com sucesso." << endl;
        }   

        void inserir_final(int valor) {
            No* novo = new No;
            novo->dado = valor;

            if(inicio == nullptr) {  // Verificando se a lista esta vazia
                inicio = novo;  // Usando mesma logica do metodo inserir_inicio
                novo->proximo = nullptr;
                novo->anterior = nullptr;
                fim = novo;
                cout << "Elemento inserido com sucesso." << endl;
                return;
            }

            novo->proximo = nullptr;  // O novo no agora aponta para o nullptr pois é agora o ultimo no
            novo->anterior = fim;  // O seu ponteiro anterior aponta para o antigo ultimo no
            fim->proximo = novo;  // O ponteiro proximo do antigo ultimo no agora aponta para o novo no
            fim = novo;  // O fim agora e o novo no
            cout << "Elemento inserido com sucesso." << endl;
        }
};