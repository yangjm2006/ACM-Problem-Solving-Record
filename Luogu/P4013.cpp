#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10;
const ll INF=1e18;
struct edge{
    int v,nxt;ll c,w;
}e[N];
int _=1,head[N];
void adde(int u,int v,ll c,ll w){
    e[++_].v=v;e[_].c=c;e[_].w=w;e[_].nxt=head[u];head[u]=_;
    e[++_].v=u;e[_].c=0;e[_].w=-w;e[_].nxt=head[v];head[v]=_;
}
int tot=3020,s=3001,t=3002,cur[N],id[50][50],idcnt,m,n;;
ll dis[N],a[50][50];
bool vis[N];
bool spfa(){
    for(int i=1;i<=tot;i++) dis[i]=INF,vis[i]=0;
    queue<int> q;dis[s]=0;vis[s]=1;q.push(s);
    while(!q.empty()){
        int u=q.front();q.pop();vis[u]=0;
        if(u==t) continue;
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].v;ll c=e[i].c,w=e[i].w;
            if(c>0&&dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
    for(int i=1;i<=tot;i++) cur[i]=head[i];
    return dis[t]!=INF;
}
ll dfs(int u,ll flow){
    if(u==t) return flow;
    vis[u]=1;ll res=0;
    for(int i=cur[u];i&&flow;i=e[i].nxt){
        cur[u]=i;
        int v=e[i].v;ll c=e[i].c,w=e[i].w;
        if(c>0&&vis[v]==0&&dis[v]==dis[u]+w){
            ll fw=dfs(v,min(c,flow));
            flow-=fw;res+=fw;
            e[i].c-=fw;e[i^1].c+=fw;
        }
    }
    return res;
}
void solve1(){
    for(int i=1;i<=m;i++) adde(s,id[1][i]<<1,1,0);
    for(int i=1;i<=m+n-1;i++) adde(id[n][i]<<1|1,t,1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m+i-1;j++){
            adde(id[i][j]<<1,id[i][j]<<1|1,1,-a[i][j]);
            if(i<n){
                adde(id[i][j]<<1|1,id[i+1][j]<<1,1,0);
                adde(id[i][j]<<1|1,id[i+1][j+1]<<1,1,0);
            }
        }
    }
    ll res=0,tmp;
    while(spfa()&&(tmp=dfs(s,INF))) res+=tmp*dis[t];
    cout<<-res<<'\n';
}
void solve2(){
    _=1;
    for(int i=1;i<=tot;i++) head[i]=0;
    for(int i=1;i<=m;i++) adde(s,id[1][i]<<1,1,0);
    for(int i=1;i<=m+n-1;i++) adde(id[n][i]<<1|1,t,INF,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m+i-1;j++){
            adde(id[i][j]<<1,id[i][j]<<1|1,INF,-a[i][j]);
            if(i<n){
                adde(id[i][j]<<1|1,id[i+1][j]<<1,1,0);
                adde(id[i][j]<<1|1,id[i+1][j+1]<<1,1,0);
            }
        }
    }
    ll res=0,tmp;
    while(spfa()&&(tmp=dfs(s,INF))) res+=tmp*dis[t];
    cout<<-res<<'\n';
}
 void solve3(){
     _=1;
     for(int i=1;i<=tot;i++) head[i]=0;
     for(int i=1;i<=m;i++) adde(id[1][i]<<1,t,INF,0);
     for(int i=1;i<=m+n-1;i++) adde(s,id[n][i]<<1|1,1,0);
     for(int i=1;i<=n;i++){
         for(int j=1;j<=m+i-1;j++){
             adde(id[i][j]<<1|1,id[i][j]<<1,INF,-a[i][j]);
             if(i<n){
                 adde(id[i+1][j]<<1,id[i][j]<<1|1,1,0);
                 adde(id[i+1][j+1]<<1,id[i][j]<<1|1,1,0);
             }
         }
     }
     ll res=0;
     spfa();
     for(int i=1;i<=m;i++) res+=dis[id[1][i]<<1];
     cout<<-res<<'\n';
 }
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>m>>n;
    for(int i=1;i<=n;i++) for(int j=1;j<=m+i-1;j++){
        cin>>a[i][j];
        id[i][j]=++idcnt;
    }
    solve1();
    solve2();
    solve3();
    return 0;
}