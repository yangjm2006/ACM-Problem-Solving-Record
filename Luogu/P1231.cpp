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
int dis[N],cur[N],s,t;
bool bfs(){
    for(int i=1;i<=t;i++){
        dis[i]=INF;
        cur[i]=head[i];
    }
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
    return dis[t]!=INF;
}
int dfs(int u,int flow){
    if(u==t) return flow;
    int res=0;
    for(int i=cur[u];i&&flow;i=e[i].nxt){
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
void dinic(){
    int res=0,tmp;
    while(bfs()&&(tmp=dfs(s,INF))) res+=tmp;
    cout<<res;
}
int n1,n2,n3,m1,m2;
int main(){
    cin>>n1>>n2>>n3;
    s=n1*2+n2+n3+1;t=s+1;
    for(int i=1;i<=n2;i++) adde(s,i,1);
    for(int i=1;i<=n3;i++) adde(i+n2,t,1);
    for(int i=1;i<=n1;i++) adde(n2+n3+i,n2+n3+n1+i,1);
    cin>>m1;
    for(int i=1,u,v;i<=m1;i++){
        cin>>u>>v;
        adde(v,n2+n3+u,1);
    }
    cin>>m2;
    for(int i=1,u,v;i<=m2;i++){
        cin>>u>>v;
        adde(n2+n3+n1+u,n2+v,1);
    }
    dinic();
    return 0;
}