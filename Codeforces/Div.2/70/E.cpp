#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
const int INF=1e9;
struct edge{
    int v,c,nxt;
}e[N];
int _=1,head[N];
void adde(int u,int v,int c){
    e[++_].v=v;e[_].c=c;e[_].nxt=head[u];head[u]=_;
    e[++_].v=u;e[_].c=0;e[_].nxt=head[v];head[v]=_;
}
int n,T;
int mp1[20][20],mp2[20][20],dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
struct node{
    int x,y;
};
int posx,posy,ds[20][20],nw[20][20];
void bfs1(){
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) ds[i][j]=INF;
    queue<node> q;q.push((node){posx,posy});ds[posx][posy]=0;
    while(!q.empty()){
        int x=q.front().x,y=q.front().y;q.pop();
        for(int i=0;i<=3;i++){
            int xx=x+dx[i],yy=y+dy[i];
            if(mp1[xx][yy]<=9&&xx>=1&&xx<=n&&yy>=1&&yy<=n&&ds[xx][yy]>ds[x][y]+1){
                ds[xx][yy]=ds[x][y]+1;
                q.push((node){xx,yy});
            }
        }
    }
    ds[posx][posy]=INF;
}
vector<node> v;
void bfs2(int px,int py){
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) nw[i][j]=INF;
    queue<node> q;q.push((node){px,py});nw[px][py]=0;
    while(!q.empty()){
        int x=q.front().x,y=q.front().y;q.pop();
        if(nw[x][y]>=ds[x][y]||nw[x][y]==T) continue;
        for(int i=0;i<=3;i++){
            int xx=x+dx[i],yy=y+dy[i];
            if(mp1[xx][yy]<=9&&xx>=1&&xx<=n&&yy>=1&&yy<=n&&nw[xx][yy]>nw[x][y]+1){
                nw[xx][yy]=nw[x][y]+1;
                q.push((node){xx,yy});
            }
        }
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(mp2[i][j]<=9&&mp2[i][j]>0){
        if(nw[i][j]<=ds[i][j]&&nw[i][j]<=T) v.push_back((node){i,j});
    }
}
int s=300,t=301,cur[N],dis[N];
void init(){
    bfs1();
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(mp1[i][j]<=9&&mp1[i][j]>0){
        v.clear();
        bfs2(i,j);
        adde(s,(i-1)*10+j,mp1[i][j]);
        for(auto p:v){
            adde((i-1)*10+j,100+(p.x-1)*10+p.y,INF);
        }
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(mp2[i][j]<=9&&mp2[i][j]>0){
        adde(100+(i-1)*10+j,t,mp2[i][j]);
    }
}
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
    for(int i=cur[u];i;i=e[i].nxt){
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
    int res=0,tmp;
    while(bfs()&&(tmp=dfs(s,INF))) res+=tmp;
    cout<<res;
}
int main(){
    cin>>n>>T;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char c;
            cin>>c;
            if(c=='Z'){
                mp1[i][j]=11;
                posx=i;posy=j;
            }
            else if(c=='Y') mp1[i][j]=10;
            else mp1[i][j]=c-'0';
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char c;
            cin>>c;
            if(c!='Z'&&c!='Y') mp2[i][j]=c-'0';
        }
    }
    init();
    dinic();
    return 0;
}