#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+100;
const ll mod=998244353;
ll tr[N],T,q,n,ans,vis[N],s0[N],pw[N],a[N],t[N];
void build(int u,int l,int r){
    if(l==r) return tr[u]=a[l],void();
    int mid=l+r>>1;
    build(u<<1,l,mid);build(u<<1|1,mid+1,r);
}
ll query(int u,int l,int r,int L,int R){
    if(l>=L&&r<=R) return tr[u];
    int mid=l+r>>1;ll res=0;
    if(mid>=L) res+=query(u<<1,l,mid,L,R);
    if(mid<R) res+=query(u<<1|1,mid+1,r,L,R);
    return res;
}
void update(int u,int l,int r,int x,bool k){
    if(l==r) return tr[u]=k*pw[x-1],void();
    int mid=l+r>>1;
    if(mid>=x) update(u<<1,l,mid,x,k);
    else update(u<<1|1,mid+1,r,x,k);
    return;
}
void bd(int u,int l,int r){
    // if(l==r) return t[u]=vis[l];
    int mid=l+r>>1;
    build(u<<1,l,mid);build(u<<1|1,mid+1,r);
}
void qry(int u,int l,int r,int L,int R){
    if(l>=L&&r<=R) return t[u],void();
    // int 
}
void upt(){

}
string str;
int main(){
    // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    pw[0]=1;
    for(int i=1;i<N;i++) pw[i]=pw[i-1]*2%mod;
    while(T--){
        ans=0;
        cin>>str;
        n=str.size();
        for(int i=0;i<n;i++) if(str[i]=='1') vis[i+1]=1;
        for(int i=1;i<=n;i++){
            s0[i]=s0[i-1];
            if(!vis[i]) s0[i]=(s0[i]+pw[i-1]);
        }
        for(int i=1;i<=n;i++){
            ans*=2;
            if(vis[i]) ans+=s0[i-1];
            else ans+=(pw[i-1]-1-s0[i-1]);
            ans++;
            ans%=mod;
            cout<<ans<<'\n';
        }
        cout<<ans<<"-----------------\n";
        build(1,1,n);
        // while(q--){
        //     int x;
        //     cin>>x;
        //     cout<<ans<<'\n';
        // }
    }
    return 0;
}
/*
3
001
00110
101110001
*/