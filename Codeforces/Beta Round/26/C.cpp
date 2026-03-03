#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,z,cnt,id[200][200];
void work(){
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
        if(id[i][j]) continue;
        if(z){
            z--;
            cnt++;
            id[i][j]=id[i+1][j]=id[i][j+1]=id[i+1][j+1]=cnt;
        }else if(x>=2){
            x-=2;
            cnt++;
            id[i][j]=id[i][j+1]=cnt;
            cnt++;
            id[i+1][j]=id[i+1][j+1]=cnt;
        }else if(y>=2){
            y-=2;
            cnt++;
            id[i][j]=id[i+1][j]=cnt;
            cnt++;
            id[i][j+1]=id[i+1][j+1]=cnt;
        }
    }
}
int ans[200][200],dx[9]={-1,-1,-1,0,0,0,1,1,1},dy[9]={-1,0,1,-1,0,1,-1,0,1};
void make(){
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
        if(ans[i][j]) continue;
        bool vis[5]={0};
        int col,nw=id[i][j];
        for(int k=0;k<9;k++){
            if(id[i+dx[k]][j+dy[k]]!=nw) continue;
            for(int o=0;o<9;o++) if(abs(dx[o])+abs(dy[o])<=1&&i+dx[k]+dx[o]>=1&&j+dy[k]+dy[o]>=1)
                vis[ans[i+dx[k]+dx[o]][j+dy[k]+dy[o]]]=1;
        }
        for(int k=1;k<=4;k++) if(!vis[k]){
            col=k;
            break;
        }
        for(int k=0;k<9;k++){
            if(id[i+dx[k]][j+dy[k]]==nw) ans[i+dx[k]][j+dy[k]]=col;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>x>>y>>z;
    if(n%2!=0&&m%2!=0){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    if(n%2==0&&m%2==0){
        work();
    }
    if(n%2==1&&m%2==0){
        n--;x-=m/2;
        if(x<0){
            cout<<"IMPOSSIBLE";
            return 0;
        }
        work();
        n++;
        for(int i=1;i<=m;i+=2){
            cnt++;
            id[n][i]=id[n][i+1]=cnt;
        }
    }
    if(n%2==0&&m%2==1){
        m--;y-=n/2;
        if(y<0){
            cout<<"IMPOSSIBLE";
            return 0;
        }
        work();
        m++;
        for(int i=1;i<=n;i+=2){
            cnt++;
            id[i][m]=id[i+1][m]=cnt;
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++) cout<<id[i][j]<<" ";
    //     cout<<'\n';
    // }
    bool f=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) if(!id[i][j]) f=0;
    }
    if(!f){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    make();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cout<<char('a'+ans[i][j]-1);
        cout<<'\n';
    }
    return 0;
}