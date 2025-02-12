#include <iostream>
using namespace std;

int main() {
    int tamanho;
    cout << "Qual o tamanho do array? ";
    cin >> tamanho;

    int *arr = new int[tamanho];

    for (int i=0;i<tamanho;i++) {
        cout << "Digite o valor da posicao " << i+1 <<" : ";
        cin >> arr[i];
    }

    for (int i=0;i<tamanho;i++) {
        cout << arr[i];
    }

    delete[] arr;
    return 0;
}