#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
const int INF=1e9;
struct edge{
    int v,c,w,nxt;
}e[N];
int _=1,head[N];
void adde(int u,int v,int c,int w){
    e[++_].v=v;e[_].c=c;e[_].w=w;e[_].nxt=head[u];head[u]=_;
    e[++_].v=u;e[_].c=0;e[_].w=-w;e[_].nxt=head[v];head[v]=_;
}
int dis[N],cur[N],s,t,n,m;
bool vis[N];
bool spfa(){
    for(int i=1;i<=t;i++){
        dis[i]=INF;
        cur[i]=head[i];
        vis[i]=0;
    }
    queue<int> q;q.push(s);vis[s]=1;dis[s]=0;
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
    return dis[t]!=INF;
}
int dfs(int u,int flow){
    if(u==t) return flow;
    int res=0;vis[u]=1;
    for(int i=cur[u];i&&flow;i=e[i].nxt){
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
void dinic(){
    int res1=0,res2=0,tmp;
    while(spfa()&&(tmp=dfs(s,INF))){
        res1+=tmp;
        res2+=tmp*dis[t];
    }
    cout<<res1<<" "<<res2;
}
int main(){
    cin>>n>>m;
    for(int i=2;i<=n-1;i++) adde(i,n+i,1,0);
    adde(1,n+1,INF,0);adde(n,n+n,INF,0);
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        adde(n+u,v,1,w);
    }
    s=1;t=2*n;
    dinic();
    return 0;
}