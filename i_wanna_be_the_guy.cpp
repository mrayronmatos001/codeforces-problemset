#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n;
    set<int> nums;
    cin >> n;
    int p,q;
    cin >> p;
    vector<int> stack_p, stack_q;
    for (int i=0; i<p; i++) {
        int value;
        cin >> value;
        stack_p.push_back(value);
        nums.insert(value);
    }
    cin >> q;
    for (int i=0; i<q; i++) {
        int value;
        cin >> value;
        stack_q.push_back(value);
        nums.insert(value);
    }
    if (nums.size()==n) {
        cout << "I become the guy.";
    } else {
        cout << "Oh, my keyboard!";
    }
    cout << endl;
}