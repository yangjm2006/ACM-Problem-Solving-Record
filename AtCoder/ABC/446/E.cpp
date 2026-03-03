#include<bits/stdc++.h>
using namespace std;
const int N=1e3+100;
int m,a,b;
int vis[N][N];
int dfs(int x,int y){
    if(vis[x][y]) return vis[x][y];
    int z=(b*x+a*y)%m;
    if(z==0) return vis[x][y]=1;
    vis[x][y]=-1;
    if(dfs(y,z)==1) return vis[x][y]=1;
    return -1;
}
void __(){
    cin>>m>>a>>b;
    int ans=0;
    for(int i=1;i<=m-1;i++) for(int j=1;j<=m-1;j++) if(dfs(i,j)==-1) ans++;
    // for(int i=0;i<=m-1;i++) for(int j=0;j<=m-1;j++){
    //     cout<<i<<" "<<j<<" "<<dfs(i,j)<<"++\n";
    // }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    __();
    return 0;
}