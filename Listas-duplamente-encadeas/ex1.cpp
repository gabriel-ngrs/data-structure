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


};