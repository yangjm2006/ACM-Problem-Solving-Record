#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
const int INF=1e9;
struct edge{
    int u,v,c,w,nxt;
}e[N];
int _,head[N];
void adde(int u,int v,int c,int w){
    e[++_]=(edge){u,v,c,w,head[u]};head[u]=_;
    e[++_]=(edge){v,u,0,-w,head[v]};head[v]=_;
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
                    vis[v]=1;
                    q.push(v);
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
        if(c>0&&dis[v]==dis[u]+w&&vis[v]==0){
            int fw=dfs(v,min(c,flow));
            flow-=fw;res+=fw;
            e[i].c-=fw;e[i^1].c+=fw;
        }
    }
    return res;
}
int dinic(){
    int res=0,tmp;
    while(spfa()&&(tmp=dfs(s,INF))) res+=tmp;
    return res;
}
int n;
struct node{
    int x,y;
}a[N],b[N];
int mp[5050][5050],dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};
int drt[5050][5050];
bool is_gull(int x){
    return (x>=1)&&(x<=n);
}
bool is_food(int x){
    return (x>=n+1)&&(x<=n+n);
}
vector<int> ans;
char id_to_direct[10050];
vector<int> g[10050];
int in[10050];
void topo_sort(){
    queue<int> que;
    for(int i=1;i<=n;i++){
        if(!in[i]){
            que.push(i);
            ans.push_back(i);
        }
    }
    while(!que.empty()){
        int u=que.front();que.pop();
        for(auto v:g[u]){
            in[v]--;
            if(!in[v]){
                que.push(v);
                ans.push_back(v);
            }
        }
    }
}
bool in_table(int x){
    return x>=1&&x<=5000;
}
void __(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
        mp[a[i].x][a[i].y]=i;
    }
    for(int i=1;i<=n;i++){
        cin>>b[i].x>>b[i].y;
        mp[b[i].x][b[i].y]=n+i;
    }
    _=1;
    s=n+n+1;t=s+1;
    for(int i=1;i<=t;i++){
        head[i]=in[i]=0;
        g[i].clear();
    }
    for(int i=1;i<=n;i++) adde(s,n+i,1,0);
    for(int i=1;i<=n;i++) adde(i,t,1,0);
    vector<int> vec[5050][4];
    for(int i=1;i<=n;i++){
        int x=b[i].x,y=b[i].y;
        for(int k=0;k<4;k++){
            int len=1;
            while(in_table(x+dx[k]*len)&&in_table(y+dy[k]*len)&&is_gull(mp[x+dx[k]*len][y+dy[k]*len])){
                vec[i][k].push_back(mp[x+dx[k]*len][y+dy[k]*len]);
                len++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        int maxx=-1;
        for(int k=0;k<4;k++) maxx=max(maxx,(int)vec[i][k].size());
        for(int j=maxx-1;j>=0;j--){
            for(int k=0;k<4;k++){
                if(j<vec[i][k].size()){
                    int id=vec[i][k][j];
                    adde(i+n,id,1,j);
                    drt[i][id]=k;
                }
            }
        }
    }
    if(dinic()!=n){
        cout<<"No\n";
        return;
    }
    cout<<"Yes\n";
    for(int i=2;i<=_;i+=2){
        int u=e[i].u,v=e[i].v;
        if(e[i].c==0&&is_food(u)&&is_gull(v)){
            u-=n;
            int k=drt[u][v];
            if(k==0) id_to_direct[v]='R';
            else if(k==1) id_to_direct[v]='L';
            else if(k==2) id_to_direct[v]='D';
            else id_to_direct[v]='U';
            for(int j=0;j<vec[u][k].size();j++){
                if(vec[u][k][j]==v) break;
                g[v].push_back(vec[u][k][j]);
                in[vec[u][k][j]]++;
            }
        }
    }
    topo_sort();
    for(auto x:ans) cout<<x<<" "<<id_to_direct[x]<<"\n";
    ans.clear();
    for(int i=1;i<=n;i++){
        mp[a[i].x][a[i].y]=mp[b[i].x][b[i].y]=0;
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        __();
    }
    return 0;
}