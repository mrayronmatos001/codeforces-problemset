#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<long long> candies(t);
    for (int i=0;i<t; i++) {
        cin >> candies[i]; 
    }
    for (int i=0;i<t;i++) {
        long long half = candies[i]/2;
        long long result = candies[i]-(half+1);
        cout << result << endl;
    }
}