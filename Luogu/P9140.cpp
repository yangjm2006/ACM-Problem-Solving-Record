#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e6+100;
const ll INF=1e18;
struct edge{
    int v,nxt;
    ll w;
}e[N];
int _,head[N];
void adde(int u,int v,ll w){
    // cout<<u<<" "<<v<<" "<<w<<"++\n";
    e[++_].v=v;e[_].w=w;e[_].nxt=head[u];head[u]=_;
}
bool vis[N];
ll dis[N];
struct node{
    ll v,w;
    bool operator < (const node &_){
        return w*_.v>_.w*v;
    }
}a[60];
void spfa(){
    for(int i=0;i<a[1].v;i++) dis[i]=-INF;
    queue<int> q;
    q.push(0);dis[0]=0;
    while(!q.empty()){
        int u=q.front();q.pop();vis[u]=0;
        // cout<<u<<"++\n";
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].v;ll w=e[i].w;
            if(dis[v]<dis[u]+w){
                dis[v]=dis[u]+w;
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
    // for(int i=0;i<a[1].v;i++) cout<<dis[i]<<" ";cout<<'\n';
}
int main(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i].v>>a[i].w;
    sort(a+1,a+1+n);
    for(int i=0;i<a[1].v;i++){
        for(int j=2;j<=n;j++){
            adde(i,(i+a[j].v)%a[1].v,a[j].w-(i+a[j].v)/a[1].v*a[1].w);
        }
    }
    spfa();
    while(q--){
        ll v;
        cin>>v;
        if(dis[v%a[1].v]==-INF) cout<<"-1\n";
        else cout<<dis[v%a[1].v]+v/a[1].v*a[1].w<<'\n';
    }
    return 0;
}