#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
const int INF=1e9;
struct edge{
    int v,w,nxt;
}e[N];
int _,head[N];
void adde(int u,int v,int w){
    e[++_].v=v;e[_].w=w;e[_].nxt=head[u];head[u]=_;
}
bool vis[N];
int dis[N],n,h;
void spfa(){
    for(int i=0;i<=n;i++){
        dis[i]=-INF;
    }
    queue<int> q;q.push(0);vis[0]=1;dis[0]=0;
    while(!q.empty()){
        int u=q.front();q.pop();vis[u]=0;
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].v,w=e[i].w;
            if(dis[v]<dis[u]+w){
                dis[v]=dis[u]+w;
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
}
int main(){
    cin>>n>>h;
    for(int i=1;i<=h;i++){
        int b,e,t;
        cin>>b>>e>>t;
        adde(b-1,e,t);
    }
    for(int i=1;i<=n;i++){
        adde(0,i,0);
        adde(i,i-1,-1);
        adde(i-1,i,0);
    }
    spfa();
    // for(int i=1;i<=n;i++) cout<<dis[i]<<" ";cout<<"\n";
    cout<<dis[n];
    return 0;
}