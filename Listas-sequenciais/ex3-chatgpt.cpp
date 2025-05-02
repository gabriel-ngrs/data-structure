/*Exercício 3 — Buscar valor
Adicione um método buscar(int valor) que:

Retorna o índice do valor caso ele exista.

Retorna -1 caso o valor não esteja presente*/

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

                for(int i=0;i<tamanho_atual;i++){ // Copia os valores de um para o outro
                    novo_array[i] = array[i];
                }

                delete[] array; // Libera a memoria antes alocada
                array = novo_array; // Atualiza o ponteiro e o novo tamanho maximo
                tamanho_max *= 2;
                
                array[tamanho_atual] = valor; // Adicionando o valor após realocar memoria
                tamanho_atual++;
                cout << "Valor adicionado" << endl;
                
            } else {
                array[tamanho_atual] = valor;
                tamanho_atual++;
                cout << "Valor adicionado" << endl;
            }
        }
        void removerIndice(int indice){

            if (indice > tamanho_atual) { // Verifico se o indice é menor do que a lista
                cout << "Indice invalido!" << endl;

            } else if (indice == tamanho_atual) { // Verificando se o indice é o ultimo termo
                tamanho_atual--;
                cout << "Indice removido" << endl;

            } else { 
                for(int i=indice; i<tamanho_atual; i++){ // Itero sobre o array, começando pelo indice passado por parametro
                    array[i] = array[i+1];
                }
                tamanho_atual--;
                cout << "Indice removido" << endl;
            }
        }

        int buscar(int valor) {
            for(int i = 0;i<tamanho_atual;i++){
                if(array[i] == valor) {
                    return i;
                    
                }
            }
            return -1;
        }

        void exibir(){
            for(int i=0; i<tamanho_atual;i++){
                cout << array[i] << " "; 
            }
            cout << endl;
        }
};

int main() {
    ListaSeq l1;
    l1.inserirFinal(1);
    l1.inserirFinal(2);
    l1.inserirFinal(3);
    l1.inserirFinal(4);
    l1.inserirFinal(5);

    l1.exibir();

    cout << l1.buscar(4) << endl;

    return 0;
}