#include <iostream>
using namespace std;

struct No {
    int dado;  // Valor armazenado no nó
    No* proximo;  // Ponteiro que aponta para uma outra estrutura do tipo No
};

class ListaEncadeada {
    private:
        No* inicio;  // Ponteiro que aponta para uma outra estrutura do tipo No, essa em especifico vai ser o inicio da lista encadeada
    public:
        ListaEncadeada() {  // Contrutor padrao apontando para nullptr, pois a lista ainda esta vazia
            inicio = nullptr;
        }

        ~ListaEncadeada() {  // Destrutor, liberando memoria alocada para cada no da lista
            while (inicio != nullptr) {  // Enquanto a lista nao estiver vazia
                No* temp = inicio;  // Guarda o ponteiro atual
                inicio = inicio->proximo;  // Avança para o proximoo
                delete temp;  // Libera a memoria
            }
        }

        void inserirInicio(int valor) {  
            No* novo = new No;  // Criando um novo no, alocando memoria dinamicamente
            novo->dado = valor;  // Acessando a variavel dado atraves do ponteiro e preenchendo seu valor
            novo->proximo = inicio;  // Aponta o novo no para para o antigo inicio
            inicio = novo;  // Atualiza o inicio da lista para o novo no
        }

        void exibir() {
            No* atual = inicio; 
            while (atual != nullptr) {
                cout << atual->dado << " ";
                atual = atual->proximo;
            }
            cout << endl;
        }
};

int main() {
    ListaEncadeada lista;
    lista.inserirInicio(10);
    lista.inserirInicio(20);
    lista.inserirInicio(30);
    lista.exibir(); // Deve exibir: 30 20 10
    return 0;
}