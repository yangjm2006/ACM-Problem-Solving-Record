#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
const int INF=1e9;
int n,m,dis[N][N],dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
bool vis[N][N],vs[N][N];
vector<pair<int,int>> v1,v2;
void bfs1(int x,int y){
    if(x<1||x>n||y<1||y>m) return;
    if(vis[x][y]) return;
    if(vs[x][y]) return;
    vs[x][y]=1;
    v1.push_back(make_pair(x,y));
    for(int k=0;k<4;k++){
        bfs1(x+dx[k],y+dy[k]);
    }
}
void bfs2(int x,int y){
    if(x<1||x>n||y<1||y>m) return;
    if(vis[x][y]) return;
    if(vs[x][y]) return;
    vs[x][y]=1;
    v2.push_back(make_pair(x,y));
    for(int k=0;k<4;k++){
        bfs2(x+dx[k],y+dy[k]);
    }
}
void solve(){
	v1.clear();v2.clear();
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
        char c;
        cin>>c;
        if(c=='#') vis[i][j]=1;
        else vis[i][j]=0;
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) vs[i][j]=0;
    bfs1(1,1);
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) vs[i][j]=0;
    bfs2(n,m);
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) dis[i][j]=INF;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) vs[i][j]=0;
    queue<pair<int,int>> q;
    for(auto &x:v1){
        dis[x.first][x.second]=0;
        q.push(make_pair(x.first,x.second));
    }
    while(!q.empty()){
        int x=q.front().first,y=q.front().second;q.pop();
        if(x<1||x>n||y<1||y>m) continue;
        if(vs[x][y]) continue;
        vs[x][y]=1;
        for(int k=0;k<4;k++){
            int xx=x+dx[k],yy=y+dy[k];
            if(dis[xx][yy]>dis[x][y]+1){
                dis[xx][yy]=dis[x][y]+1;
                q.push(make_pair(xx,yy));
            }
        }
    }
    int minn=INF;
    for(auto &x:v2){
        minn=min(minn,dis[x.first][x.second]);
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++) cout<<dis[i][j]<<" ";cout<<'\n';
    // }
    cout<<max(0,minn-1)<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}