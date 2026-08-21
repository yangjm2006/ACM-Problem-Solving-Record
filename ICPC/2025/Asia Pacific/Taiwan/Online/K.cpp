#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
const int INF=1e9;
struct edge{
    int v,c,nxt;
}e[N*N*80];
int _=1,head[N*N*2];
void adde(int u,int v,int c){
    // cout<<u<<" "<<v<<" "<<c<<"++\n";
    e[++_].v=v;e[_].c=c;e[_].nxt=head[u];head[u]=_;
    e[++_].v=u;e[_].c=0;e[_].nxt=head[v];head[v]=_;
}
int n,a[N][N];
int cal(int x,int y){
    return (x-1)*n+y;
}
int s,t,dis[N*N*2],cur[N*N*2];
bool bfs(){
    for(int i=1;i<=t;i++){
        dis[i]=INF;
        cur[i]=head[i];
    }
    queue<int> q;q.push(s);dis[s]=0;
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
    // for(int i=1;i<=t;i++) cout<<dis[i]<<" ";cout<<'\n';
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
            res+=fw;flow-=fw;
            e[i^1].c+=fw;e[i].c-=fw;
        }
    }
    return res;
}
void dinic(){
    int res=0,tmp,tot=0;
    while(bfs()&&(tmp=dfs(s,INF))){
        res+=tmp;
        // cout<<tmp<<" "<<dis[t]<<"!!!!!\n";
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
        if(a[i][j]) tot++;
    }
    // cout<<res<<" "<<tot<<"!!!!!!!!!!\n";
    cout<<2*(n*n-res-tot)+res;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
    s=n*n*2+2*n+1;t=s+1;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
        if(a[i][j]) adde(s,cal(i,j),a[i][j]-1);
        else adde(n*n+cal(i,j),t,1);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]>=2){
                adde(cal(i,j),2*n*n+i,INF);
                adde(cal(i,j),2*n*n+n+j,INF);
            }
            if(a[i][j]==0){
                adde(2*n*n+i,n*n+cal(i,j),1);
                adde(2*n*n+n+j,n*n+cal(i,j),1);
            }
        }
    }
    dinic();
    return 0;
}