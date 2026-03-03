#include<bits/stdc++.h>
using namespace std;
bool vis[60][60];
int n,m,fa[4000],num[4000],cnt[4000];
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
int cal(int x,int y){
    return (x-1)*m+y;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
        vis[i][j]=0;
        fa[cal(i,j)]=cal(i,j);
        num[cal(i,j)]=1;
        cnt[cal(i,j)]=0;
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
        char c;
        cin>>c;
        if(c=='*') vis[i][j]=1;
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(vis[i][j]){
        if(i<n&&vis[i+1][j]){
            num[find(cal(i,j))]+=num[find(cal(i+1,j))];
            fa[find(cal(i+1,j))]=find(cal(i,j));
        }
        if(j<m&&vis[i][j+1]){
            num[find(cal(i,j))]+=num[find(cal(i,j+1))];
            fa[find(cal(i,j+1))]=find(cal(i,j));
        }
    }
    bool f=1;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(vis[i][j]){
        if(i<n&&j<m&&vis[i+1][j+1]&&find(cal(i,j))!=find(cal(i+1,j+1))) f=0;
        if(i<n&&j>1&&vis[i+1][j-1]&&find(cal(i,j))!=find(cal(i+1,j-1))) f=0;
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(vis[i][j]&&num[find(cal(i,j))]==1) f=0;
    for(int i=1;i<=n*m;i++) if(num[find(i)]!=1&&num[find(i)]!=3) f=0;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(vis[i][j]){
        if(i<n&&vis[i+1][j]){
            cnt[find(cal(i,j))]+=100;
        }
        if(j<m&&vis[i][j+1]){
            cnt[find(cal(i,j))]++;
        }
    }
    for(int i=1;i<=n*m;i++) if(cnt[find(i)]!=0&&cnt[find(i)]!=101) f=0;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<num[find(cal(i,j))]<<" ";
    //     }
    //     cout<<'\n';
    // }
    if(f) cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){
    int T;
    cin>>T;
    while(T--) solve();
}