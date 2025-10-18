#include <bits/stdc++.h>
using namespace std;

int main() {
    // Otimização de I/O (essencial e já presente no seu código)
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s1, s2;
    std::cin >> s1 >> s2;

    for (size_t i = 0; i < s1.length(); ++i) {
        if (s1[i] == s2[i]) {
            std::cout << '0';
        } else {
            std::cout << '1';
        }
    }
    std::cout << '\n'; // Usar '\n' é geralmente mais rápido que std::endl, pois não força o "flush" do buffer.

    return 0;
}