#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
const int INF=1e9;
struct edge{
    int v,c,nxt;
}e[N];
int _=1,head[N];
void adde(int u,int v,int c){
    e[++_].v=v;e[_].c=c;e[_].nxt=head[u];head[u]=_;
    e[++_].v=u;e[_].c=0;e[_].nxt=head[v];head[v]=_;
}
int dis[N],s,t,cur[N];
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
    cout<<sum-res;
}
int n,m,k;
bool vis[200][200];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    s=n+m+1;t=s+1;
    vector<int> s1(n+1),s2(m+1);
    for(int i=1,x;i<=n;i++){
        cin>>x;
        adde(s,i,x);
        sum+=x;
        s1[i]=x;
    }
    for(int i=1,x;i<=m;i++){
        cin>>x;
        adde(n+i,t,x);
        sum+=x;
        s2[i]=x;
    }
    for(int i=1,x,y;i<=k;i++){
        cin>>x>>y;
        vis[x][y]=1;
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(!vis[i][j]){
        adde(i,n+j,1);
        s1[i]--;s2[j]--;
    }
    for(int i=1;i<=n;i++) if(s1[i]>0){
        cout<<"JIONG!";
        return 0;
    }
    for(int i=1;i<=m;i++) if(s2[i]>0){
        cout<<"JIONG!";
        return 0;
    }
    dinic();
    return 0;
}