#include <bits/stdc++.h>
using namespace std;

inline int sum_digits(int num)
{
    int sum=0;
    
    while(num>0) {
        int digit = num%10;
        sum+=digit;
        num/=10;
    };
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int sum=1;
    for (int i=1; i<N; i++) {
        sum += sum_digits(sum);
    }

    cout << sum << endl;
}