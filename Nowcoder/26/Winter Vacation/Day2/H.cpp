#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+100;
ll tr[N<<2],tag[N<<2];
void pushup(int u){
    tr[u]=tr[u<<1]+tr[u<<1|1];
}
void build(int u,int l,int r){
    tag[u]=tr[u]=0;
    if(l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid);build(u<<1|1,mid+1,r);
}
void pushdown(int u,int l,int r){
    int mid=l+r>>1;
    tag[u<<1]+=tag[u];tag[u<<1|1]+=tag[u];
    tr[u<<1]+=tag[u]*(mid-l+1);
    tr[u<<1|1]+=tag[u]*(r-mid);
    tag[u]=0;
}
void add(int u,int l,int r,int L,int R,ll x){
    if(l>=L&&r<=R){
        tag[u]+=x;
        tr[u]+=x*(r-l+1);
        return;
    }
    pushdown(u,l,r);
    int mid=l+r>>1;
    if(mid>=L) add(u<<1,l,mid,L,R,x);
    if(mid<R) add(u<<1|1,mid+1,r,L,R,x);
    pushup(u);
}
ll query(int u,int l,int r,int L,int R){
    if(l>=L&&r<=R) return tr[u];
    pushdown(u,l,r);
    int mid=l+r>>1;
    ll res=0;
    if(mid>=L) res+=query(u<<1,l,mid,L,R);
    if(mid<R) res+=query(u<<1|1,mid+1,r,L,R);
    pushup(u);
    return res;
}
void __(){
    int n;
    cin>>n;
    ll sum=0;
    build(1,1,n);
    map<int,int> mp;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        add(1,1,n,mp[x]+1,i,1);
        mp[x]=i;
        sum+=query(1,1,n,1,i)*(n-i+1);
        // for(int j=1;j<=n;j++){
        //     cout<<query(1,1,n,j,j)<<" ";
        // }
        // cout<<'\n';
    }
    cout<<sum<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}