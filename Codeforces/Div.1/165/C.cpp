#include<bits/stdc++.h>
using namespace std;
const int INF=2e9;
const int N=1e6+100;
struct edge{
    int v,c,nxt;
}e[N];
int _,head[N];
void adde(int u,int v,int c){
    e[++_].v=v;e[_].c=c;e[_].nxt=head[u];head[u]=_;
    e[++_].v=u;e[_].c=c;e[_].nxt=head[v];head[v]=_;
}
bool vis[N],ans[N];
int val[N],res[N],n,m;
void topo(){
    queue<int> q;q.push(1);vis[1]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].v,c=e[i].c;
            if(vis[v]==0){
                res[v]+=c;
                ans[i]=1;
                if(v!=n&&res[v]*2==val[v]){
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1,u,v,c;i<=m;i++){
        cin>>u>>v>>c;
        adde(u,v,c);
        val[u]+=c;val[v]+=c;
    }
    topo();
    for(int i=1;i<=m;i++) cout<<ans[i*2]<<'\n';
    return 0;
}