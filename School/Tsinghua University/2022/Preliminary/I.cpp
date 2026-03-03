#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+100;
const ll INF=1e18;
struct edge{
    int v,nxt;ll c;
}e[N];
int _=1,head[N];
void adde(int u,int v,ll c){
    e[++_].v=v;e[_].c=c;e[_].nxt=head[u];head[u]=_;
    e[++_].v=u;e[_].c=0;e[_].nxt=head[v];head[v]=_;
}
int s,t,cur[N];
ll dis[N];
bool bfs(){
    for(int i=1;i<=t;i++){
        dis[i]=INF;
        cur[i]=head[i];
    }
    queue<int> q;q.push(s);dis[s]=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].v;ll c=e[i].c;
            if(c>0&&dis[v]>dis[u]+1){
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
    return dis[t]!=INF;
}
ll dfs(int u,ll flow){
    if(u==t) return flow;
    ll res=0;
    for(int i=cur[u];i&&flow;i=e[i].nxt){
        cur[u]=i;
        int v=e[i].v;ll c=e[i].c;
        if(c>0&&dis[v]==dis[u]+1){
            ll fw=dfs(v,min(c,flow));
            flow-=fw;res+=fw;
            e[i].c-=fw;e[i^1].c+=fw;
        }
    }
    return res;
}
void dinic(){
    ll res=0,tmp;
    while(bfs()&&(tmp=dfs(s,INF))) res+=tmp;
    cout<<res;
}
int n,m;
int main(){
    cin>>n>>m;
    s=3*n+1;t=s+1;
    for(int i=1;i<=2*n;i++){
        ll c,d,e;
        cin>>c>>d>>e;
        adde(s,i,d);adde(i,t,c);
        if(i&1) adde(i,i+1,e);
        else adde(i,i-1,e);
    }
    for(int i=1;i<=n;i++){
        adde(2*n+i,2*i-1,INF);
        adde(2*n+i,2*i,INF);
    }
    for(int i=1;i<=m;i++){
        int u,v;ll w1,w2;
        cin>>u>>v>>w1>>w2;
        adde(v,2*n+(u+1)/2,w1);
        adde(2*n+(v+1)/2,u,w2);
    }
    dinic();
    return 0;
}