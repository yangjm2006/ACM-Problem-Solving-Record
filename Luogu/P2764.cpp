#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
const int INF=1e9;
struct edge{
    int v,c,nxt;
}e[N];
int _=1,head[N];
void adde(int u,int v,int c){
    e[++_].v=v;e[_].c=c;e[_].nxt=head[u];head[u]=_;
    e[++_].v=u;e[_].c=0;e[_].nxt=head[v];head[v]=_;
}
int s,t,dis[N],cur[N],n,m;
bool bfs(){
    for(int i=1;i<=t;i++) dis[i]=INF;
    queue<int> q;dis[s]=0;q.push(s);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].v,c=e[i].c;
            if(c>0&&dis[v]>dis[u]+1){
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
    for(int i=1;i<=t;i++) cur[i]=head[i];
    return dis[t]!=INF;
}
int dfs(int u,int flow){
    if(u==t) return flow;
    int res=0;
    for(int i=head[u];i&&flow;i=e[i].nxt){
        cur[u]=i;
        int v=e[i].v,c=e[i].c;
        if(c>0&&dis[v]==dis[u]+1){
            int fw=dfs(v,min(c,flow));
            flow-=fw;res+=fw;
            e[i].c-=fw;e[i^1].c+=fw;
        }
    }
    return res;
}
vector<int> ans;
int res;
void dinic(){
    int tmp;
    while(bfs()&&(tmp=dfs(s,INF))) res+=tmp;
}
int in[N],to[N];
int main(){
    cin>>n>>m;
    s=n*2+1;t=n*2+2;
    for(int i=1;i<=n;i++) adde(s,i,1);
    for(int i=1;i<=n;i++) adde(i+n,t,1);
    for(int i=1,u,v;i<=m;i++){
        cin>>u>>v;
        adde(u,v+n,1);
    }
    dinic();
    for(int u=n+1;u<=n*2;u++) for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].v,c=e[i].c;
        if(c>0&&v!=t){
            in[u-n]++;
            to[v]=u-n;
        }
    }
    for(int i=1;i<=n;i++) if(!in[i]){
        cout<<i<<" ";
        for(int u=to[i];u;u=to[u]) cout<<u<<" ";
        cout<<'\n';
    }
    cout<<n-res;
    return 0;
}