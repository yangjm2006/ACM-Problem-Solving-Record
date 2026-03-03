#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
struct edge{
    int v,nxt;
}e[N];
int _,head[N];
void adde(int u,int v){
    // cout<<u<<" "<<v<<"++\n";
    e[++_].v=v;e[_].nxt=head[u];head[u]=_;
}
int n,m,l[N],r[N];
bool check(int x,int y){
    if(l[x]==l[y]||r[x]==r[y]||l[x]==r[y]||l[y]==r[x]) return 0;
    return (l[x]>l[y]&&l[x]<r[y])^(r[x]>l[y]&&r[x]<r[y]);
}
int dfn[N],dn,low[N],col[N],cn,stc[N],tp;
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
    for(int i=2;i<=2*m+1;i++) if(!dfn[i]) dfs(i);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>l[i]>>r[i];
        if(l[i]>r[i]) swap(l[i],r[i]);
    }
    for(int i=1;i<=m;i++) for(int j=i+1;j<=m;j++){
        if(check(i,j)){
            adde(i<<1,j<<1|1);
            adde(i<<1|1,j<<1);
            adde(j<<1,i<<1|1);
            adde(j<<1|1,i<<1);
        }
    }
    tarjan();
    vector<char> ans;
    // for(int i=1;i<=m;i++){
    //     cout<<col[i<<1]<<" "<<col[i<<1|1]<<"!!!'\n";
    // }
    for(int i=1;i<=m;i++){
        if(col[i<<1]==col[i<<1|1]){
            cout<<"Impossible";
            return 0;
        }
        if(col[i<<1]<col[i<<1|1]) ans.push_back('o');
        else ans.push_back('i');
    }
    for(auto x:ans) cout<<x;
    return 0;
}