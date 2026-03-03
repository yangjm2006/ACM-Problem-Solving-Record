#include<bits/stdc++.h>
using namespace std;
const int N=2e6+100;
struct edge{
    int v,nxt;
}e[N];
int _,head[N];
void adde(int u,int v){
    e[++_].v=v;e[_].nxt=head[u];head[u]=_;
}
int n,m,dn,dfn[N],low[N],cn,col[N],stc[N],tp;
bool vis[N];
void dfs(int u){
    dfn[u]=low[u]=++dn;
    stc[++tp]=u;vis[u]=1;
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(!dfn[v]) dfs(v);
        if(vis[v]) low[u]=min(low[u],low[v]);
    }
    if(dfn[u]==low[u]){
        cn++;
        do{
            col[stc[tp]]=cn;
            vis[stc[tp]]=0;
        }while(stc[tp--]!=u);
    }
}
void tarjan(){
    for(int i=2;i<=2*n+1;i++) if(!dfn[i]) dfs(i);
}
bool ans[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1,u,v,a,b;i<=m;i++){
        cin>>u>>a>>v>>b;
        adde((u<<1|a)^1,v<<1|b);
        adde((v<<1|b)^1,u<<1|a);
    }
    tarjan();
    for(int i=1;i<=n;i++){
        if(col[i<<1]==col[i<<1|1]){
            cout<<"IMPOSSIBLE";
            return 0;
        }
        if(col[i<<1|1]<col[i<<1]) ans[i]=1;
    }
    cout<<"POSSIBLE\n";
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    return 0;
}