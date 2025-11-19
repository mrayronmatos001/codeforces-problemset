#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,q;
  cin >> n >> q;
  vector<int> pc(n+1,1);
  pc[0]=0;
  int o=1;
  while(q--){
    int x,y;
    cin >> x >> y;
    int res=0;
    while(o<=x){
      res+=pc[o];
      pc[y]+=pc[o];
      o++;
    }
    cout << res << "\n";
  }
  return 0;
}