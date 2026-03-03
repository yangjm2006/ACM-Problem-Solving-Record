#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+100;
ll tr[N<<2];
void push_up(int u){
    tr[u]=tr[u<<1]+tr[u<<1|1];
}
void add(int u,int l,int r,int x){
    if(l==r) return tr[u]++,void();
    int mid=l+r>>1;
    if(x<=mid) add(u<<1,l,mid,x);
    else add(u<<1|1,mid+1,r,x);
    push_up(u);
}
ll query(int u,int l,int r,int L,int R){
    if(l>=L&&r<=R) return tr[u];
    ll res=0,mid=l+r>>1;
    if(L<=mid) res+=query(u<<1,l,mid,L,R);
    if(R>mid) res+=query(u<<1|1,mid+1,r,L,R);
    return res;
}
int T,n;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n*4;i++) tr[i]=0;
        ll ans=0;
        for(int i=1,x;i<=n;i++){
            cin>>x;
            ans+=query(1,1,n,x,n);
            add(1,1,n,x);
        }
        cout<<ans<<'\n';
    }
    return 0;
}