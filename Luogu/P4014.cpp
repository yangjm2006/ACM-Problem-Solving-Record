#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
const int N=1e6+100;
struct edge{
    int v,c,w,nxt;
}e[N];
int _=1,head[N];
void adde(int u,int v,int c,int w){
    e[++_].v=v;e[_].c=c;e[_].w=w;e[_].nxt=head[u];head[u]=_;
    e[++_].v=u;e[_].c=0;e[_].w=-w;e[_].nxt=head[v];head[v]=_;
}
int dis[N],s,t,cur[N];
bool vis[N];
bool spfa(){
    for(int i=1;i<=t;i++){
        dis[i]=INF;vis[i]=0;cur[i]=head[i];
    }
    queue<int> q;q.push(s);dis[s]=0;vis[s]=1;
    while(!q.empty()){
        int u=q.front();q.pop();vis[u]=0;
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].v,c=e[i].c,w=e[i].w;
            if(c>0&&dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(!vis[v]){
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
    }
    // for(int i=1;i<=t;i++) cout<<dis[i]<<" ";cout<<'\n';
    return dis[t]!=INF;
}
int dfs(int u,int flow){
    if(u==t) return flow;
    int res=0;vis[u]=1;
    for(int i=cur[u];i;i=e[i].nxt){
        cur[u]=i;
        int v=e[i].v,c=e[i].c,w=e[i].w;
        if(c>0&&vis[v]==0&&dis[v]==dis[u]+w){
            int fw=dfs(v,min(c,flow));
            flow-=fw;res+=fw;
            e[i].c-=fw;e[i^1].c+=fw;
        }
    }  
    return res;
}
int res=0;
void dinic(){
    int tmp;
    while(spfa()&&(tmp=dfs(s,INF))) res+=tmp*dis[t];
}
int n,a[100][100];
int main(){
    cin>>n;
    s=2*n+1;t=2*n+2;
    for(int i=1;i<=n;i++) adde(s,i,1,0);
    for(int i=1;i<=n;i++) adde(n+i,t,1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            adde(i,j+n,1,a[i][j]);
        }
    }
    dinic();
    cout<<res<<'\n';
    res=0;
    _=1;
    for(int i=1;i<=t;i++) head[i]=0;
    for(int i=1;i<=n;i++) adde(s,i,1,0);
    for(int i=1;i<=n;i++) adde(n+i,t,1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            adde(i,j+n,1,-a[i][j]);
        }
    }
    dinic();
    cout<<-res;
    return 0;
}