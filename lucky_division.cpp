#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> lucky_numbers;

    lucky_numbers.push_back(4);
    lucky_numbers.push_back(7);
    
    lucky_numbers.push_back(44);
    lucky_numbers.push_back(47);
    lucky_numbers.push_back(74);
    lucky_numbers.push_back(77);
    
    lucky_numbers.push_back(444);
    lucky_numbers.push_back(447);
    lucky_numbers.push_back(474);
    lucky_numbers.push_back(477);
    lucky_numbers.push_back(744);
    lucky_numbers.push_back(747);
    lucky_numbers.push_back(774);
    lucky_numbers.push_back(777);
    
    bool is_almost_lucky = false;
    
    for (int lucky : lucky_numbers) {
        if (n % lucky == 0) {
            is_almost_lucky = true;
            break;
        }
    }
    
    if (is_almost_lucky) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    
    return 0;
}