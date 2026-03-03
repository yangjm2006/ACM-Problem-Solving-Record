#include<bits/stdc++.h>
using namespace std;
const int V=1000;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<vector<bool>> vis(V+1,vector<bool>(V+1));
    vector<vector<int>> v(V+1),cnt(V+1,vector<int>(V+1,0));
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<=V;i++) for(int j=0;j<V;j++){
            int x=i,y=j;
            vis[i][j]=1;
            while(x&&y){
                if(x%10+y%10>9) vis[i][j]=0;
                x/=10;y/=10;
            }
            if(vis[i][j]) v[i].push_back(j);
        }
    long long ans=0;
    for(int i=1;i<=n;i++){
        int vis1=a[i]/V,vis2=a[i]%V;
        for(auto x:v[vis1]) ans+=cnt[x][vis2];
        for(auto x:v[vis2]) cnt[vis1][x]++;
    }
    cout<<ans;
    return 0;
}