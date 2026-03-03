#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+100;
const ll mod=998244353;
struct edge{
    int v,nxt;
}e[N];
int _,head[N];
void adde(int u,int v){
    e[++_].v=v;e[_].nxt=head[u];head[u]=_;
}
int n;
ll ans,cnt=1,zs[N],jie[N];
void dfs(int u,int fa){
    zs[u]++;
    map<ll,ll> mp;vector<ll> vec;
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(v==fa) continue;
        dfs(v,u);
        zs[u]+=zs[v];
        mp[zs[v]]++;
        vec.push_back(zs[v]);
    }
    for(auto &x:mp){
        cnt=cnt*jie[x.second]%mod;
    }
    sort(vec.begin(),vec.end(),greater<ll>());
    for(int i=0;i<vec.size();i++){
        ans+=vec[i]*(i+1);
    }
    ans++;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    jie[0]=1;
    for(ll i=1;i<=n;i++) jie[i]=jie[i-1]*i%mod;
    for(int u=2,v;u<=n;u++){
        cin>>v;
        adde(u,v);adde(v,u);
    }
    dfs(1,-1);
    cout<<ans<<'\n'<<cnt;
    return 0;
}