#include <iostream>
using namespace std;

int main() {
    int qtdNumerosSeq, numeroAserSomado, valorTotal = 0, A[100];
    bool possivel = false;

    cin >> qtdNumerosSeq >> numeroAserSomado;

    for (int i = 0; i < qtdNumerosSeq; i++) {
        cin >> A[i];
        valorTotal += A[i];
    }

    for (int i = 0; i < qtdNumerosSeq; i++) {
        if (valorTotal - A[i] == numeroAserSomado) {
            possivel = true;
            break;
        }
    }

    if (possivel) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}