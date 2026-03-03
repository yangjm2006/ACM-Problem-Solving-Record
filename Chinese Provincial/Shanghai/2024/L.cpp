#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
const int INF=1e9;
int n,m,k,num[N],ans1[N],ans0[N];
vector<int> vec[N];
bool vis[N];
void dfs(int u,int fa){
    bool f=1;
    for(auto v:vec[u]){
        dfs(v,u);
        if(vis[v]) ans1[u]=min(ans1[u],ans1[v]+1);
        if(ans1[v]==INF) f=0;
    }
    if(f&&num[u]){
        int sum=0;
        for(auto v:vec[u]){
            sum+=ans1[v];
        }
        ans1[u]=min(ans1[u],sum);
    }
}
void solve(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        ans1[i]=ans0[i]=INF;
        num[i]=0;
        vis[i]=0;
    }
    for(int i=1;i<=n;i++){
        vec[i].clear();
        cin>>num[i];
        for(int j=1,x;j<=num[i];j++){
            cin>>x;
            vec[i].push_back(x);
        }
    }
    for(int i=1,u,v;i<=m;i++){
        cin>>u>>v;
        vis[v]=1;
    }
    for(int i=1,x;i<=k;i++){
        cin>>x;
        ans1[x]=ans0[x]=0;
    }
    dfs(1,0);
    // for(int i=1;i<=n;i++) cout<<ans1[i]<<" ";cout<<"!!!!!\n";
    if(ans1[1]==INF) cout<<"-1\n";
    else cout<<ans1[1]<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}