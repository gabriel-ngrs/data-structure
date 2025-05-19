#include <iostream>
using namespace std;

class Pilha {
    private:
        string vetor_palavras[100];
        int topo;
    public:
        Pilha(){
            topo = 0;
        }

        void empilhar(string palavra) {
            if (topo >= 100) {
                cout << "Nao e possivel empilhar a palavra " << palavra << " pois a pilha ja esta cheia" << endl;
                return;
            }
            vetor_palavras[topo] = palavra;
            topo++;
        }

        void desempilhar() {
            if (topo == 0) {
                cout << "Lista vazia, nao tem o que desempilhar" << endl;
                return;
            }
            topo--;
        }

        void exibir() {
            cout << "Palavras:" << endl;
            for(int i = topo-1; i>=0; i--) {
                cout << vetor_palavras[i] << endl;
            }
        }
};

int main(){
    Pilha p1;
    int escolha;
    string palavra;
    
    do {
        cout << "1 para empilhar uma nova palavra." << endl;
        cout << "2 para desempilhar a ultima palavra." << endl;
        cout << "3 para exibir a pilha de cima para baixo." << endl;
        cout << "0 para sair." << endl;
        cout << "Escolha: " << endl;
        cout << endl;
        cin >> escolha;

        switch (escolha){
            case 1:
                cout << "Digite a palavra: " << endl;
                cin >> palavra;
                p1.empilhar(palavra);
                break;
            case 2:
                p1.desempilhar();
                break;
            case 3:
                p1.exibir();
                break;
            case 0:
                cout << "Finalizando..." << endl;
                break;
            default:
                cout << "Opcao invalida." << endl;
        }

    } while (escolha != 0);

    return 0;
}