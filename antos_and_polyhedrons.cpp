#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    map<string,int> polyedrons;
    polyedrons["Tetrahedron"]=4;
    polyedrons["Cube"]=6;
    polyedrons["Octahedron"]=8;
    polyedrons["Dodecahedron"]=12;
    polyedrons["Icosahedron"]=20;

    int n, faces=0;
    cin >> n;

    for (int i=0;i<n;i++) {
        string s;
        cin >> s;
        faces+=polyedrons[s];
    }

    cout << faces << endl;
}