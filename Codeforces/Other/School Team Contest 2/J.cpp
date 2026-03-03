#include<bits/stdc++.h>
using namespace std;
const int N=1050;
char c[N][N];
int n,m,id[N][N],ans[N][N],cnt;
bool vis[N][N];
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
void make(){
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
        if(ans[i][j]||id[i][j]==-1) continue;
        if(id[i][j]==id[i][j+1]){
            bool vs[5]={0};
            for(int o=0;o<3;o++){
                for(int k=0;k<4;k++){
                    vs[ans[i+dx[k]][j+o+dy[k]]]=1;
                }
            }
            int col;
            for(int k=1;k<=4;k++) if(!vs[k]){
                col=k;
                break;
            }
            for(int o=0;o<3;o++) ans[i][j+o]=col;
        }
        if(id[i+1][j]==id[i][j]){
            bool vs[5]={0};
            for(int o=0;o<3;o++){
                for(int k=0;k<4;k++){
                    vs[ans[i+o+dx[k]][j+dy[k]]]=1;
                }
            }
            int col;
            for(int k=1;k<=4;k++) if(!vs[k]){
                col=k;
                break;
            }
            for(int o=0;o<3;o++) ans[i+o][j]=col;
        }
    }
}
struct node{
    int x,y;
};
int in[N][N];
queue<node> q;
void spfa(){
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(in[i][j]==1) q.push((node){i,j});
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++) cout<<in[i][j]<<" ";
    //     cout<<'\n';
    // }
    while(!q.empty()){
        int x=q.front().x,y=q.front().y,u=(x-1)*m+y;q.pop();
        // cout<<x<<" "<<y<<"----\n";
        for(int k=0;k<4;k++){
            if(id[x+dx[k]][y+dy[k]]==0&&x+dx[k]>=1&&x+dx[k]<=n&&y+dy[k]>=1&&y+dy[k]<=m){
                in[x+dx[k]][y+dy[k]]--;
                if(in[x+dx[k]][y+dy[k]]==1) q.push((node){x+dx[k],y+dy[k]});
            }
        }
        if(vis[x][y]&&id[x][y]==0){
            cnt++;
            if(x+2<=n&&id[x+1][y]==0&&id[x+2][y]==0){
                id[x][y]=id[x+1][y]=id[x+2][y]=cnt;
                q.push((node){x+1,y});q.push((node){x+2,y});
            }else if(x-2>=1&&id[x-1][y]==0&&id[x-2][y]==0){
                id[x][y]=id[x-1][y]=id[x-2][y]=cnt;
                q.push((node){x-1,y});q.push((node){x-2,y});
            }else if(y+2<=m&&id[x][y+1]==0&&id[x][y+2]==0){
                id[x][y]=id[x][y+1]=id[x][y+2]=cnt;
                q.push((node){x,y+1});q.push((node){x,y+2});
            }else if(y-2>=1&&id[x][y-1]==0&&id[x][y-2]==0){
                id[x][y]=id[x][y-1]=id[x][y-2]=cnt;
                q.push((node){x,y-1});q.push((node){x,y-2});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
        char ch;
        cin>>ch;
        if(ch=='.') id[i][j]=-1;
        else if(ch=='w') vis[i][j]=1;
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(id[i][j]==0){
        for(int k=0;k<4;k++){
            if(id[i+dx[k]][j+dy[k]]==0&&i+dx[k]>=1&&i+dx[k]<=n&&j+dy[k]>=1&&j+dy[k]<=m){
                in[i+dx[k]][j+dy[k]]++;
            }
        }
    }
    spfa();
    bool f=1;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(id[i][j]==0) f=0;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++) cout<<id[i][j]<<" ";
    //     cout<<'\n';
    // }
    if(!f){
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    make();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cout<<(ans[i][j]==0?'.':char('a'+ans[i][j]-1));
        cout<<'\n';
    }
    return 0;
}