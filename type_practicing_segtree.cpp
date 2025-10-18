#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct segtree
{
    vector<ll> seg;
    int neutro;
    int size;
    segtree(vector<ll>&v,int en=0) {
        int n=1;
        while(n<v.size()) n*=2;
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
    void set(int index, int value, int x, int lx, int rx) {
        if (rx-lx==1) {
            seg[x]=value;
            return;
        }

        int mid = lx + (rx-lx)/2;
        if (index < mid) {
            set(index,value,2*x+1,lx,mid);
        } else {
            set(index,value,2*x+2,mid,rx);
        }
        seg[x]=seg[2*x+1]+seg[2*x+2];
    }
    void set(int index, int value) {
        set(index,value,0,0,size);
    }
    ll query(int l, int r, int x, int lx, int rx) {
        if (rx<=l || lx>=r) return neutro;
        if (lx>=l && rx<=r) return seg[x];
        int mid = lx + (rx-lx)/2;
        return query(l,r,2*x+1,lx,mid) + query(l,r,2*x+2,mid,rx);

    }
    ll query(int l, int r) {
        query(l,r,0,0,size);
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
}