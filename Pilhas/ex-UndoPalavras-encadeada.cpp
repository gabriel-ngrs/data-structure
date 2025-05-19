#include <iostream>
using namespace std;

struct No{
    string palavra;
    No* proximo;
};

class Pilha {
    private:
        No* topo;
    public:
        Pilha(){
            topo = nullptr;  // Ponteiro aponta para o nullptr, ja que a pilha esta vazia
        }
        ~Pilha(){
            while (topo != nullptr){
                desempilhar();
            }
        }
        void empilhar(string PALAVRA){
            No* novo = new No;  // Aloca memoria
            novo->palavra = PALAVRA;  // Atribui o parametro a variavel
            novo->proximo = topo;  // ponteiro proximo do novo no aponta para o antigo topo (a pilha é lida de cima para baixp)
            topo = novo;  // topo aponta para o novo no
        }

        void desempilhar(){
            if (topo == nullptr){  // Verifica se a pilha esta vazia
                cout << "Pilha vazia" << endl;
                return;
            }
            No* temp = topo;  //  No temporario começando do topo da pilha
            topo = topo->proximo;  // avançando para o proximo no (descendo na pilha)
            delete temp;  // liberando memoria
        }

        void exibir(){
            if (topo == nullptr){
                cout << "Pilha vazia" << endl;
                return;
            }
            cout << "Palavras:" << endl;
            No* atual = topo;
            while (atual != nullptr) {
                cout << atual->palavra << endl;
                atual = atual->proximo;
            }
        }
};


int main() {
    Pilha p;
    int opcao;
    string palavra;

    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Empilhar" << endl;
        cout << "2. Desempilhar" << endl;
        cout << "3. Exibir pilha" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch(opcao) {
            case 1:
                cout << "Digite a palavra para empilhar: ";
                cin >> palavra;
                p.empilhar(palavra);
                break;
            case 2:
                p.desempilhar();
                break;
            case 3:
                p.exibir();
                break;
            case 0:
                cout << "Encerrando programa." << endl;
                break;
            default:
                cout << "Opcao invalida." << endl;
        }

    } while(opcao != 0);

    return 0;
}