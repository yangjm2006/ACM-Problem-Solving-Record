#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct edge{
    int v,nxt;
}e[N];
int _,head[N];
void adde(int u,int v){
    // cout<<u<<" "<<v<<"++\n";
    e[++_].v=v;e[_].nxt=head[u];head[u]=_;
}
int dfn[N],low[N],dn,col[N],cn,stc[N],tp;
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
int n,m;
void tarjan(){
    for(int i=2;i<=2*n+1;i++) if(!dfn[i]) dfs(i);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        if(!c){
            adde(u<<1,v<<1|1);
            adde(v<<1|1,u<<1);
            adde(u<<1|1,v<<1);
            adde(v<<1,u<<1|1);
        }else{
            adde(u<<1,v<<1);
            adde(v<<1,u<<1);
            adde(u<<1|1,v<<1|1);
            adde(v<<1|1,u<<1|1);
        }
    }
    tarjan();
    // for(int i=1;i<=n;i++){
    //     cout<<col[i<<1]<<" "<<col[i<<1|1]<<"!!!!\n";
    // }
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(col[i<<1]==col[i<<1|1]){
            cout<<"Impossible";
            return 0;
        }
        if(col[i<<1]<col[i<<1|1]) ans.push_back(i);
    }
    cout<<ans.size()<<'\n';
    for(auto x:ans) cout<<x<<' ';
    return 0;
}