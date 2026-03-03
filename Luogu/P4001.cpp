#include<bits/stdc++.h>
using namespace std;
const int M=6e6+100;
const int N=1e6+100;
const int INF=1e9;
struct edge{
    int v,c,nxt;
}e[M];
int _=1,head[N];
void adde(int u,int v,int c){
    e[++_].v=v;e[_].c=c;e[_].nxt=head[u];head[u]=_;
    e[++_].v=u;e[_].c=c;e[_].nxt=head[v];head[v]=_;
}
int s,t,dis[N],cur[N];
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
    while(bfs()&&(tmp=dfs(s,INF))){
        res+=tmp;
    }
    cout<<res;
}
int n,m;
int cal(int x,int y){
    return m*(x-1)+y;
}
int main(){
    cin>>n>>m;
    s=n*m+1;t=s+1;
    for(int i=1;i<=n;i++) for(int j=1,c;j<=m-1;j++){
        cin>>c;
        adde(cal(i,j),cal(i,j+1),c);
    }
    for(int i=1;i<=n-1;i++) for(int j=1,c;j<=m;j++){
        cin>>c;
        adde(cal(i,j),cal(i+1,j),c);
    }
    for(int i=1;i<=n-1;i++) for(int j=1,c;j<=m-1;j++){
        cin>>c;
        adde(cal(i,j),cal(i+1,j+1),c);
    }
    adde(s,cal(1,1),INF);adde(cal(n,m),t,INF);
    dinic();
    return 0;
}