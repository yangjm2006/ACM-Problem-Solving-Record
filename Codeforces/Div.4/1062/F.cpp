#include<bits/stdc++.h>
#define ll long long
const int N=2e5+100;
struct edge{
    int v,nxt;
}e[N<<1];
int _,head[N];
void adde(int u,int v){
    e[++_].v=v;e[_].nxt=head[u];head[u]=_;
}
int zs[N],n,k;
ll ans;
void dfs(int u,int fa){
    zs[u]++;
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(v==fa) continue;
        dfs(v,u);
        zs[u]+=zs[v];
        if(n-zs[v]>=k) ans+=zs[v];
    }
    if(zs[u]>=k) ans+=n-zs[u];
}
void solve(){
    ans=_=0;
    std::cin>>n>>k;
    for(int i=1;i<=n;i++) zs[i]=head[i]=0;
    for(int i=1,u,v;i<=n-1;i++){
        std::cin>>u>>v;
        adde(u,v);adde(v,u);
    }
    dfs(1,-1);
    std::cout<<ans+n<<'\n';
}
int main(){
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
    int T;
    std::cin>>T;
    while(T--) solve();
    return 0;
}