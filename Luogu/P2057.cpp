#include<bits/stdc++.h>
using namespace std;
const int N=4e5+100;
const int INF=1e9;
struct edge{
    int v,c,nxt;
}e[N];
int _=1,head[N];
void adde(int u,int v,int c){
    e[++_].v=v;e[_].c=c;e[_].nxt=head[u];head[u]=_;
    e[++_].v=u;e[_].c=c;e[_].nxt=head[v];head[v]=_;
}
int n,m,s=403,t=404,dis[N];
bool bfs(){
    for(int i=1;i<=t;i++) dis[i]=INF;
    queue<int> q;q.push(s);dis[s]=0;
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
    // cout<<dis[s]<<" ";for(int i=1;i<=n;i++) cout<<dis[i]<<" ";cout<<dis[t]<<"\n";
    return dis[t]!=INF;
}
int dfs(int u,int flow){
    if(u==t) return flow;
    int res=0;
    for(int i=head[u];i&&flow;i=e[i].nxt){
        int v=e[i].v,c=e[i].c;
        if(c>0&&dis[v]==dis[u]+1){
            int fw=dfs(v,min(flow,c));
            flow-=fw;res+=fw;
            e[i].c-=fw;e[i^1].c+=fw;
        }
    }
    return res;
}
void dinic(){
    int tmp,res=0;
    while(bfs()&&(tmp=dfs(s,INF))) res+=tmp;
    cout<<res;
}
int main(){
    cin>>n>>m;
    for(int i=1,x;i<=n;i++){
        cin>>x;
        if(x) adde(s,i,1);
        else adde(i,t,1);
    }
    for(int i=1,u,v;i<=m;i++){
        cin>>u>>v;
        adde(u,v,1);
    }
    dinic();
    return 0;
}
/*
3 3
1 0 0
1 2
1 3
3 2
*/