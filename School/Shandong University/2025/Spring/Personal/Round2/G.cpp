#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
struct edge{
    int v,nxt;
}e[N];
int _,head[N];
void adde(int u,int v){
    e[++_].v=v;e[_].nxt=head[u];head[u]=_;
}
int n;
bool vis[N];
int sz[N],ans[N];
void dfs1(int u,int fa){
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(v==fa) continue;
        dfs1(v,u);
        if(sz[v]>0) sz[u]+=sz[v];
    }
    if(vis[u]==0) sz[u]--;
}
void dfs2(int u,int fa){
    
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>vis[i];
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        adde(u,v);adde(v,u);
    }
    dfs1(1,0);
    ans[1]=sz[1];
    dfs2(1,0);
    for(int i=1;i<=n;i++) cout<<ans[i];
    return 0;
}