#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    string s;
    getline(cin, s);
    set<char> letters;

    for (char letter : s) {
        if (letter=='{' || letter==' ' || letter==',' || letter=='}') {
        } else {
            letters.insert(letter);
        }
    }

    cout << letters.size() << endl;
}