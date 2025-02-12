#include <iostream>
using namespace std;

int main() {
    int i;
    int array[5];

    for (i=0;i<5;i++) {
        cout << "Digite o valor da posicao " << i+1 << ": ";
        cin >> array[i];       
    }

    for (i=0;i<5;i++) {
        cout << array[i] << " ";
    }
    return 0;
}