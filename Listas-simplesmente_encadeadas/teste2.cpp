#include <iostream>
using namespace std;

struct No {  // Estrutura No, a qual possui uma variavel e um ponteiro do tipo No
    int dado;  
    No* proximo;  
};

class ListaEncadeada {
    private:
        No* inicio;
    public:
        ListaEncadeada(){
            inicio = nullptr;
            cout << "Lista criada com sucesso" << endl;
        } 
        ~ListaEncadeada(){
            while (inicio != nullptr) {
                No* temp = inicio;
                inicio = inicio->proximo;
                delete temp;
            }
            cout << "Memoria liberada da lista" << endl;
        }
        void inserir_inicio(int valor) {
            No* novo = new No; // Criando um novo ponteiro do tipo No e alocando memoria dinamicamente
            novo->dado = valor;  // Colocando o valor na variavel
            novo->proximo = inicio;  // O ponteiro proximo do No agora é o antigo inicio
            inicio = novo;  // Inicio agora é o novo No
        }

        void exibir() {
        
        }
};

int main(){
    ListaEncadeada l1;

    
    return 0;
}