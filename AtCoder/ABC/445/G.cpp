#include<bits/stdc++.h>
using namespace std;
const int N=2e6+100;
const int INF=1e9;
struct edge{
    int v,c,nxt;
}e[N];
int _=1,head[N];
void adde(int u,int v,int c){
    // cout<<u<<" "<<v<<" "<<c<<"++\n";
    e[++_].v=v;e[_].c=c;e[_].nxt=head[u];head[u]=_;
    e[++_].v=u;e[_].c=0;e[_].nxt=head[v];head[v]=_;
}
int s,t,dis[N],cur[N];
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
void dinic(){
    int tmp,res=0;
    while(bfs()&&(tmp=dfs(s,INF))) res+=tmp;
    // cout<<res<<"+++\n";
}
int mp[400][400],n,a,b;
vector<int> g[N];
int cal(int x,int y){
    return (x-1)*n+y;
}
int col[N];
void color(int u,int dep){
    if(dep%2==0) col[u]=2;
    else col[u]=1;
    for(auto v:g[u]){
        if(col[v]==0) color(v,dep+1);
    }
}
int main(){
    cin>>n>>a>>b;
    s=n*n+1;t=s+1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char c;
            cin>>c;
            if(c=='#') mp[i][j]=-1;
        }
    }
    int dx[8]={a,a,-a,-a,b,b,-b,-b},dy[8]={b,-b,b,-b,a,-a,a,-a};
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(mp[i][j]!=-1){
        for(int k=0;k<8;k++){
            int x=i+dx[k],y=j+dy[k];
            if(x>=1&&x<=n&&y>=1&&y<=n&&mp[x][y]!=-1){
                g[cal(i,j)].push_back(cal(x,y));
                g[cal(x,y)].push_back(cal(i,j));
            }
        }
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(mp[i][j]!=-1&&col[cal(i,j)]==0){
        color(cal(i,j),1);
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++) cout<<col[cal(i,j)]<<" ";cout<<'\n';
    // }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
        if(col[cal(i,j)]==1){
            adde(s,cal(i,j),1);
            for(int k=0;k<8;k++){
                int x=i+dx[k],y=j+dy[k];
                if(x>=1&&x<=n&&y>=1&&y<=n&&col[cal(x,y)]==2){
                    adde(cal(i,j),cal(x,y),1);
                }
            }
        }else if(col[cal(i,j)]==2){
            adde(cal(i,j),t,1);
        }
    }
    dinic();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(col[cal(i,j)]==0) cout<<'#';
            else if(col[cal(i,j)]==1){
                if(dis[cal(i,j)]==INF) cout<<'.';
                else cout<<'o';
            }else{
                if(dis[cal(i,j)]==INF) cout<<'o';
                else cout<<'.';
            }
        }
        cout<<'\n';
    }
    return 0;
}