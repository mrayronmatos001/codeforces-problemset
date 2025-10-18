#include <iostream>

int main() {
    // Otimizações de I/O (já estavam corretas no seu código)
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    for (int i = 1; i <= n; ++i) {

        if (i % 2 != 0) { // Se i for ímpar (1, 3, ...)
            std::cout << "I hate";
        } else { // Se i for par (2, 4, ...)
            std::cout << "I love";
        }

        if (i < n) {
            std::cout << " that ";
        }
    }

    std::cout << " it\n"; // Usar '\n' é mais rápido que endl

    return 0;
}