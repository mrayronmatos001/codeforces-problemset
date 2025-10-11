#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,e;
	cin >> n;

	int friends[n];

	for (int i=0; i<n; i++) {
		cin >> e;
		friends[e-1]=i+1;
	}
	for (int i=0; i<n; i++) {
		cout << friends[i] << endl;
	}
	return 0;
}