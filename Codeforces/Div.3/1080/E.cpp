#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+100;
const ll mod=1e9+7;
struct edge{
    int v,nxt;
}e[N];
int _,head[N];
void adde(int u,int v){
    e[++_].v=v;e[_].nxt=head[u];head[u]=_;
}
ll f[N],ans[N];
void dfs1(int u){
    bool flg=0;
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].v;
        dfs1(v);
        f[u]+=f[v];
        flg=1;
    }
    if(flg) f[u]+=4;
    f[u]%=mod;
}
void dfs2(int u){
    ans[u]+=f[u]+1;
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].v;
        ans[v]+=ans[u];
        dfs2(v);
    }
    ans[u]%=mod;
}
void __(){
    int n;
    cin>>n;
    _=0;
    for(int i=1;i<=n;i++) head[i]=f[i]=ans[i]=0;
    for(int i=1;i<=n;i++){
        int u,v;
        cin>>u>>v;
        if(u){
            adde(i,u);
            adde(i,v);
        }
    }
    dfs1(1);
    dfs2(1);
    // for(int i=1;i<=n;i++) cout<<f[i]<<" ";cout<<'\n';
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}