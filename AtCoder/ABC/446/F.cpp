#include<bits/stdc++.h>
using namespace std;
const int N=3e5+100;
vector<int> e[N];
int n,m,ans,cnt;
bool vis[N];
void dfs(int u,int x){
    if(vis[u]==0&&u<=x) cnt++;
    vis[u]=1;
    if(u>x){
        ans++;
    }else{
        for(int v:e[u]){
            if(vis[v]==0) dfs(v,x);
        }
    }
}
void __(){
    cin>>n>>m;
    for(int i=1,u,v;i<=m;i++){
        cin>>u>>v;
        e[u].push_back(v);
    }
    vis[1]=1;ans=1;
    for(int i=1;i<=n;i++){
        if(vis[i]){
            cnt++;
            dfs(i,i);
            ans--;
        }
        // cout<<cnt<<"++\n";
        if(cnt==i) cout<<ans<<'\n';
        else cout<<"-1\n";
        // for(int j=1;j<=n;j++) cout<<vis[j]<<" ";cout<<"----\n";
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    __();
    return 0;
}