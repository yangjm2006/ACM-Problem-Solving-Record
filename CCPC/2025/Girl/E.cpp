#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+100;
const ll INF=1e9;
ll gcd(ll x,ll y){
    return x%y?gcd(y,x%y):y;
}
ll n,m,del[N],ans[N],tr[N<<2];
void pushup(int u){
    tr[u]=min(tr[u<<1],tr[u<<1|1]);
}
void build(int u,int l,int r){
    if(l==r) return tr[u]=ans[l],void();
    int mid=l+r>>1;
    build(u<<1,l,mid);build(u<<1|1,mid+1,r);
    pushup(u);
}
ll query(int u,int l,int r,int L,int R){
    if(l>=L&&r<=R) return tr[u];
    int mid=l+r>>1;ll ans=INF;
    if(L<=mid) ans=min(ans,query(u<<1,l,mid,L,R));
    if(mid<R) ans=min(ans,query(u<<1|1,mid+1,r,L,R));
    return ans;
}
map<ll,ll> mp;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll x,y;
        cin>>x>>y;
        mp[x]=max(mp[x],y);
    }
    for(auto &x:mp){
        ll a=x.first,b=x.second,tmp=0;
        for(ll i=a;i<N;i+=a){
            tmp+=b;
            del[i]=max(del[i],tmp);
        }
    }
    for(int i=1;i<N;i++) del[i]=max(del[i],del[i-1]);
    for(int i=1;i<N;i++) ans[i]=i-del[i];
    build(1,1,N-1);
    // for(int i=0;i<=100;i++) cout<<ans[i]<<" ";cout<<'\n';
    for(int i=1;i<=n;i++){
        ll w,x,y,g,ans1,ansx;
        cin>>w>>x>>y;
        x*=w;
        g=gcd(x,y);
        x/=g;y/=g;
        ans1=query(1,1,N-1,int(x/y)+1,int(w));
        ansx=x-del[x/y]*y;
        // cout<<ans1<<" "<<ansx<<" "<<y<<"!!!\n";
        if(ansx<y*ans1) cout<<ansx<<" "<<y<<'\n';
        else cout<<ans1<<" "<<1<<'\n';
    }
}
/*
 3 2
 10 5
 15 8
 9 7 10
 26 8 10
 35 7 10
*/