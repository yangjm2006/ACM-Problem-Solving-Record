#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
const int INF=1e9;
struct edge{
    int u,v,c,nxt;
}e[N];
int _,head[N];
void adde(int u,int v,int c){
    e[++_]=(edge){u,v,c,head[u]};head[u]=_;
    e[++_]=(edge){v,u,0,head[v]};head[v]=_;
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
int dinic(){
    int res=0,tmp;
    while(bfs()&&(tmp=dfs(s,INF))) res+=tmp;
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
char id_to_direct[5050];
vector<int> g[5050];
int in[5050];
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
        head[i]=0;
        g[i].clear();
    }
    for(int i=1;i<=n;i++) adde(s,n+i,1);
    for(int i=1;i<=n;i++) adde(i,t,1);
    vector<int> vec[5050][4];
    for(int i=1;i<=n;i++){
        int x=b[i].x,y=b[i].y;
        for(int k=0;k<4;k++){
            int len=1;
            while(is_gull(mp[x+dx[k]*len][y+dy[k]*len])){
                vec[i][k].push_back(mp[x+dx[k]*len][y+dy[k]*len]);
                len++;
            }
            for(int j=vec[i][k].size()-1;j>=0;j--){
                int id=vec[i][k][j];
                adde(i+n,id,1);
                drt[i][id]=k;
            }
        }
    }
    if(dinic()!=n){
        cout<<"No";
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
    for(int i=0;i<ans.size()-1;i++) cout<<ans[i]<<" "<<id_to_direct[ans[i]]<<'\n';
    cout<<ans[n-1]<<" "<<id_to_direct[ans[n-1]];
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
        if(T!=0) cout<<'\n';
    }
    return 0;
}