#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int S,A,B,X,M=0,c=1;
  cin >> S >> A >> B >> X;
  bool toRun=true, toStop=false;
  for (int i=0; i<X; i++) {
    if (toRun) {
      M+=S;
    }
    if (toRun && c==A) {
      toRun=false;
      toStop=true;
      c=0;
    } 
    if (toStop && c==B) {
      toStop=false;
      toRun=true;
      c=0;
    }
    c++;
  }
  cout << M << endl;
}