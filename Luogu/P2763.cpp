#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
const int INF=1e9;
struct edge{
    int v,c,nxt;
}e[N];
int _=1,head[N];
void adde(int u,int v,int c){
    e[++_].v=v;e[_].c=c;e[_].nxt=head[u];head[u]=_;
    e[++_].v=u;e[_].c=0;e[_].nxt=head[v];head[v]=_;
}
int s,t,k,n,dis[N],cur[N],cnt;
bool bfs(){
    for(int i=1;i<=t;i++) dis[i]=INF;
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
    for(int i=1;i<=t;i++) cur[i]=head[i];
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
vector<int> ans[N];
void dinic(){
    int res=0,tmp;
    while(bfs()&&(tmp=dfs(s,INF))) res+=tmp;
    // cout<<res<<"!!!\n";
    if(tmp==cnt){
        for(int u=n+1;u<=n+k;u++){
            for(int i=head[u];i;i=e[i].nxt){
                if(e[i].c>0) ans[u-n].push_back(e[i].v);
            }
        }
        for(int i=1;i<=k;i++){
            cout<<i<<": ";
            for(int j=0;j<ans[i].size();j++) cout<<ans[i][j]<<" ";
            cout<<'\n';
        }
    }else cout<<"No Solution!";
}
int main(){
    cin>>k>>n;
    s=n+k+1;t=n+k+2;
    for(int i=1;i<=n;i++) adde(s,i,1);
    for(int i=1,x;i<=k;i++){
        cin>>x;
        cnt+=x;
        adde(i+n,t,x);
    }
    for(int i=1,p;i<=n;i++){
        cin>>p;
        for(int j=1,x;j<=p;j++){
            cin>>x;
            adde(i,n+x,1);
        }
    }
    dinic();
    return 0;
}