#include <iostream>
using std::cin;
using std::cout;
using std::min;
using std::max;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <map>
using std::map;
int main (void) {
	// input
	int n, k;
	string s;
	cin >> n >> k;
	cin >> s;
	// make a dictionary: memo[t] := #appearance of t
	map<string, int> memo;
	for (int i = 0; i < n-k+1; i++) {
		string t = s.substr(i, k);
		memo[t] += 1;
	}
	// find max appearance
	int vmax = 0;
	for (auto &[key, val] : memo) {
		vmax = max(vmax, val);
	}
	// list all t with max appearance (for-map lists all keys in lexicographical order)
	vector<string> vs;
	for (auto &[key, val] : memo) {
		if (val == vmax) vs.push_back(key);
	}
	// output
	cout << vmax << "\n";
	for (int i = 0; i < vs.size(); i++) {
		if (i > 0) cout << " ";
		cout << vs[i];
	}
	cout << "\n";
	return 0;
}