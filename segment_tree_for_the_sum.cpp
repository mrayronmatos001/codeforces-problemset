#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct segtree
{
    vector<ll> seg;
    int neutro;
    int size;
    segtree(vector<ll>& v, int en=0) {
        int n=1;
        while(n<v.size()) n=2*n;
        seg.assign(2*n,en);
        neutro=en;
        size=n;
        build(v,0,0,size);
    }
    void build(vector<ll>&v,int x,int lx,int rx) {
        if (rx-lx==1) {
            if (lx<v.size()) seg[x]=v[lx];
            return;
        }
        int mid = lx + (rx-lx)/2;
        build(v,2*x+1,lx,mid);
        build(v,2*x+2,mid,rx);
        seg[x]=seg[2*x+1]+seg[2*x+2];
    }
    void set(int index, int valor, int x, int lx, int rx) {
        if (rx-lx==1) {
            seg[x]=valor;
            return;
        }
        int mid=lx+(rx-lx)/2;
        if (index<mid) {
            set(index,valor,2*x+1,lx,mid);
        } else {
            set(index,valor,2*x+2,mid,rx);
        }
        seg[x]=seg[2*x+1]+seg[2*x+2];
    }
    void set(int index,int valor) {
        set(index,valor,0,0,size);
    }
    ll query(int l,int r, int x, int lx, int rx) {
        if (rx<=l || lx>=r) return neutro;
        if (lx>=l && rx<=r) return seg[x];
        int mid = lx+(rx-lx)/2;
        return query(l,r,2*x+1,lx,mid)+query(l,r,2*x+2,mid,rx);
    }
    ll query(int l, int r) {
        return query(l,r,0,0,size);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,q;
    cin>>n>>q;
    vector<ll> v(n);
    for(ll i=0;i<n;i++) {
        cin>>v[i];
    }
    segtree s = segtree(v);
    ll a,b,c;
    while(q--) {
        cin>>a>>b>>c;
    }
} 