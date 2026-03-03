#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
struct edge{
    int v,nxt;
}e[N<<1];
int _,head[N];
void adde(int u,int v){
    e[++_].v=v;e[_].nxt=head[u];head[u]=_;
}
int dfn[N],dn,st[22][N];
void dfs(int u,int fa){
    st[0][dfn[u]=++dn]=fa;
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(v==fa) continue;
        dfs(v,u);
    }
}
int get(int x,int y){
    return dfn[x]<dfn[y]?x:y;
}
int lca(int u,int v){
    if(u==v) return u;
    u=dfn[u];v=dfn[v];
    if(u>v) swap(u,v);
    u++;
    int k=__lg(v-u+1);
    return get(st[k][u],st[k][v-(1<<k)+1]);
}
int n,m,root;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>root;
    for(int i=1,u,v;i<=n-1;i++){
        cin>>u>>v;
        adde(u,v);adde(v,u);
    }
    dfs(root,-1);
    for(int k=1;k<=__lg(n);k++){
        for(int i=1;i+(1<<k-1)<=n;i++){
            st[k][i]=get(st[k-1][i],st[k-1][i+(1<<k-1)]);
        }
    }
    while(m--){
        int a,b;
        cin>>a>>b;
        cout<<lca(a,b)<<'\n';
    }
    return 0;
}