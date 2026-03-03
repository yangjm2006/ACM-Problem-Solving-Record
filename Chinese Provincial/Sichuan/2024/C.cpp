#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+100;
const ll INF=1e18;
struct edeg{
    int v,nxt;ll c;
}e[N];
int _=1,head[N];
void adde(int u,int v,ll c){
    e[++_].v=v;e[_].c=c;e[_].nxt=head[u];head[u]=_;
    e[++_].v=u;e[_].c=0;e[_].nxt=head[v];head[v]=_;
}
ll dis[N];
int s,t,cur[N];
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
bool vis[N];
int n,m,l;
int cal(int z,int x,int y){
    return (z-1)*(n*m)+(x-1)*m+y;
}
int main(){
    cin>>n>>m>>l;
    s=n*m*l+1;t=s+1;
    for(int k=1;k<=l;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char c;
                cin>>c;
                if(c=='B') vis[cal(k,i,j)]=1;
            }
        }
    }
    for(int k=1;k<=l;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                ll c;
                cin>>c;
                int u=cal(k,i,j);
                if(vis[u]) adde(s,u,c);
                else adde(u,t,c);
            }
        }
    }
    for(int k=1;k<=l;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i>1) adde(cal(k,i,j),cal(k,i-1,j),INF);
                if(j>1) adde(cal(k,i,j),cal(k,i,j-1),INF);
                if(k>1) adde(cal(k,i,j),cal(k-1,i,j),INF);
            }
        }
    }
    adde(s,1,INF);
    adde(n*m*l,t,INF);
    dinic();
    return 0;
}