#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int T,n,a[N][N];
bool vis[N*2];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=2*n;i++) vis[i]=0;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
        vector<int> ans;
        for(int i=1;i<=n;i++){
            ans.push_back(a[1][i]);
            vis[a[1][i]]=1;
        }
        for(int i=2;i<=n;i++){
            ans.push_back(a[i][n]);
            vis[a[i][n]]=1;
        }
        for(int i=1;i<=2*n;i++) if(!vis[i]) cout<<i<<" ";
        for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
        cout<<'\n';
    }
    return 0;
}