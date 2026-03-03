#include<bits/stdc++.h>
using namespace std;
const int N=3e3+100;
bool mp[N][N],vis[N],ans[N][N];
void __(){
    int n,C;
    cin>>n>>C;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
        char c;
        cin>>c;
        mp[n-i+1][j]=(bool)(c=='.');
        ans[i][j]=0;
    }
    for(int i=1;i<=n;i++){
        vis[i]=mp[1][i];
        ans[0][i]=0;
    }
    ans[1][C]=1;
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=n;j++) if(ans[i][j]){
            if(mp[i+1][j]||vis[j]) ans[i+1][j]=1;
            if(mp[i+1][j+1]||vis[j+1]) ans[i+1][j+1]=1;
            if(mp[i+1][j-1]||vis[j-1]) ans[i+1][j-1]=1;
        }
        for(int j=1;j<=n;j++) if(ans[i+1][j]==0&&mp[i+1][j]==0) vis[j]=0;
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++) cout<<ans[n-i+1][j];
    //     cout<<"-----------\n";
    // }
    for(int i=1;i<=n;i++) cout<<ans[n][i];
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}