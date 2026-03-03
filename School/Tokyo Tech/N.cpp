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
bool vis[N],fl=1;
void dfs(int u,int fa){
    if(!fl) return;
    int cnt=0;
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(v==fa) continue;
        dfs(v,u);
        if(vis[v]) cnt++;
    }
    if(cnt==0) vis[u]=1;
    else if(cnt==1) vis[u]=0;
    else fl=0;
}
int n;
int main(){
    cin>>n;
    for(int i=1,u,v;i<=n-1;i++){
        cin>>u>>v;
        adde(u,v);adde(v,u);
    }
    dfs(1,0);
    // for(int i=1;i<=n;i++) cout<<vis[i]<<" ";cout<<'\n';
    if(vis[1]==0&&fl) cout<<"Bob";
    else cout<<"Alice";
    return 0;
}