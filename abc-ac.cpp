#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int length = s.length();
    int middle_index = length/2;

    string result = s.substr(0, middle_index) + s.substr(middle_index+1);
    
    cout << result << endl;

    return 0;
}