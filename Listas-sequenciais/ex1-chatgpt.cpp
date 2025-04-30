/*Exercício 1 — Inserção no final da lista
Crie uma classe ListaSeq que:

Aloca dinamicamente um array de int com capacidade inicial de 5 elementos.

Possui um método inserirFinal(int valor) que:

Insere o valor no final da lista.

Redimensiona a lista para o dobro do tamanho caso ela fique cheia.

Possui um método exibir() que imprime todos os elementos.*/

#include <iostream>
using namespace std;

class ListaSeq {
    private:
        int* array;
        int tamanho_atual;
        int tamanho_max;

    public:
        ListaSeq(){  // Construtor
            array = new int[5]; // Alocando 5 espaços na memoria para o array
            tamanho_max = 5;
            tamanho_atual = 0;
        }

        ~ListaSeq(){  // Destrutor
            delete[] array; // Liberando memoria
        }

        void inserirFinal(int valor){
            if (tamanho_atual == tamanho_max) { // Se estiver cheio, realoca memoria criando outro array com o dobro de tamanho
                cout << "Lista cheia, realocando memoria..." << endl;
                int* novo_array = new int[tamanho_max * 2];
                cout << "Espaco dobrado" << endl;

                for(int i=0;i<tamanho_atual;i++){ // Copia os valores de um para o outro
                    novo_array[i] = array[i];
                }
                cout << "Lista copiada e passada para a nova" << endl;

                delete[] array; // Libera a memoria antes alocada
                array = novo_array; // Atualiza o ponteiro e o novo tamanho maximo
                tamanho_max *= 2;
                cout << "Memoria antiga liberada e ponteiro atualizado" << endl;
                
                array[tamanho_atual] = valor; // Adicionando o valor após realocar memoria
                tamanho_atual++;
                cout << "Valor adicionado" << endl;
                
            } else {
                array[tamanho_atual] = valor;
                tamanho_atual++;
                cout << "Valor adicionado" << endl;
            }
        }
        void exibir(){
            for(int i=0; i<tamanho_atual;i++){
                cout << array[i] << " "; 
            }
            cout << endl;
        }
};

int main() {
    ListaSeq lista; // Criando a lista
    lista.inserirFinal(1); // Colocando o valor 10 no final dela
    lista.inserirFinal(2); // Colocando o valor 10 no final dela
    lista.inserirFinal(3); // Colocando o valor 10 no final dela
    lista.inserirFinal(4); // Colocando o valor 10 no final dela
    lista.inserirFinal(5); // Colocando o valor 10 no final dela

    lista.inserirFinal(6); // Colocando o valor 10 no final dela
    lista.inserirFinal(7); // Colocando o valor 10 no final dela
    lista.inserirFinal(8); // Colocando o valor 10 no final dela
    lista.exibir();

}