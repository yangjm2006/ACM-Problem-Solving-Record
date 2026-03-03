#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+10;
const int M=1e5+100;
const ll INF=1e18;
struct edge{
    int v,nxt;ll w;
}e[M];
int _,head[N];
void adde(int u,int v,ll w){
    e[++_].v=v;e[_].w=w;e[_].nxt=head[u];head[u]=_;
}
ll n,m,H,h[N],dis[110][N];
struct node{
    int u,h;ll d;
    bool operator < (const node &x) const{
        return d>x.d;
    }
};
priority_queue<node> q;
bool vis[110][N];
void dij(){
    for(int i=0;i<=H;i++) for(int j=1;j<=n;j++) dis[i][j]=INF;
    dis[0][1]=0;q.push((node){1,0,0});
    while(!q.empty()){
        int u=q.top().u,uh=q.top().h;ll d=q.top().d;q.pop();
        if(vis[uh][u]) continue;vis[uh][u]=1;
        for(int i=head[u];i;i=e[i].nxt){
            ll w=e[i].w;int vh,v=e[i].v;
            if(h[v]<h[u]) vh=0;
            else if(h[v]-h[u]+uh<=H) vh=h[v]-h[u]+uh;
            else continue;
            if(dis[vh][v]>d+w){
                dis[vh][v]=d+w;
                q.push((node){v,vh,d+w});
            }
        }
    }
}
int main(){
    cin>>n>>m>>H;
    for(int i=1;i<=n;i++) cin>>h[i];
    for(int i=1,u,v;i<=m;i++){
        ll w;
        cin>>u>>v>>w;
        adde(u,v,w);adde(v,u,w);
    }
    dij();
    for(int i=2;i<=n;i++){
        ll ans=INF;
        for(int j=0;j<=H;j++){
            ans=min(ans,dis[j][i]);
        }
        if(ans==INF) cout<<"-1 ";
        else cout<<ans<<" ";
    }
    return 0;
}
/*
6 7 3
 1 2 3 4 5 6
 1 2 1
 2 4 10
 1 3 8
 2 3 2
 3 5 9
 4 3 100
 2 6 2
*/