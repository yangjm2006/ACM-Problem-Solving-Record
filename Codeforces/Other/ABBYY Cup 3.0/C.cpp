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
int s,t,dis[N],cur[N];
bool vis[N];
bool spfa(){
    for(int i=1;i<=t;i++){
        dis[i]=INF;
        cur[i]=head[i];
        vis[i]=0;
    }
    queue<int> q;dis[s]=0;q.push(s);vis[s]=1;
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
int n,m,a[100][100],dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
void dinic(){
    int res=0,tmp;
    while(spfa()&&(tmp=dfs(s,INF))) res+=tmp*dis[t];
    cout<<n*m/2+res;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
    s=n*m+1;t=s+1;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
        if(i+j&1){
            adde(s,(i-1)*m+j,1,0);
            for(int k=0;k<=3;k++){
                int x=i+dx[k],y=j+dy[k];
                if(x>=1&&x<=n&&y>=1&&y<=m) adde((i-1)*m+j,(x-1)*m+y,1,-(a[i][j]==a[x][y]));
            }
        }
        else adde((i-1)*m+j,t,1,0);
    }
    dinic();
    return 0;
}