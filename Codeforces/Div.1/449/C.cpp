#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
const int N=1e5+100;
ll n,m,sed,vmax,a[N];
ll rnd(){
    ll ret=sed;
    return ret;
}
struct node{
    ll l,r;
    mutable ll v;
    node(ll l,ll r=0,ll v=0):l(l),r(r),v(v){}
    bool operator < (const node &x) const{
        return l<x.l;
    }
};
set<node> st;
auto split(ll pos){
    auto it=st.lower_bound((node)(pos));
    if(it!=st.end()&&it->l==pos) return it;
    it--;
    ll l=it->l,r=it->r,v=it->v;
    st.erase(it);
    st.insert((node){l,pos-1,v});
    return st.insert((node){pos,r,v}).first;
}
void assign(ll l,ll r,ll v){
    auto ed=split(r+1),be=split(l);
    st.erase(be,ed);
    st.insert((node){l,r,v});
}
int main(){
    cin>>n>>m>>sed>>vmax;
    for(int i=1;i<=n;i++) a[i]=rnd()%vmax+1;
    while(m--){
        ll op=rnd()%4+1,l=rnd()%n+1,r=rnd()%n+1;
        if(l>r) swap(l,r);

    }
    return 0;
}