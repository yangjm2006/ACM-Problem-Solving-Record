#include<bits/stdc++.h>
using namespace std;
const int N=3e6+100;
const int INF=1e9;
struct edge{
    int v,c,nxt;
}e[N];
int _=1,head[N];
void adde(int u,int v,int c){
    e[++_].v=v;e[_].c=c;e[_].nxt=head[u];head[u]=_;
    e[++_].v=u;e[_].c=0;e[_].nxt=head[v];head[v]=_;
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
int sum;
void dinic(){
    int res=0,tmp;
    while(bfs()&&(tmp=dfs(s,INF))) res+=tmp;
    cout<<sum-res<<'\n';
}
int n,m,a[N],b[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    cin>>m;
    s=n+2*m+1;t=s+1;
    for(int i=1;i<=n;i++){
        sum+=a[i]+b[i];
        adde(s,i,b[i]);adde(i,t,a[i]);
    }
    for(int i=1,k,c1,c2;i<=m;i++){
        cin>>k>>c1>>c2;
        sum+=c1+c2;
        adde(s,n+i,c2);adde(n+m+i,t,c1);
        for(int j=1,x;j<=k;j++){
            cin>>x;
            adde(n+i,x,INF);
            adde(x,n+m+i,INF);
        }
    }
    dinic();
    return 0;
}