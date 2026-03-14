#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
struct edge{
    int v,nxt;
}e[N];
int _,head[N];
void adde(int u,int v){
    e[++_].v=v;e[_].nxt=head[u];head[u]=_;
}
bool vis[N],vs[N];
int sz[N],n;
void dfs(int u,int fa){
    vector<int> vec;
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(v==fa) continue;
        dfs(v,u);
        sz[u]+=sz[v];
        // vis[sz[v]]=1;
        // vis[n-sz[v]-1]=1;
        vec.push_back(sz[v]);
    }
    sz[u]++;
    // vis[n-sz[u]]=1;
    // vis[sz[u]-1]=1;
    vec.push_back(n-sz[u]);
    for(int i=1;i<=n;i++) vs[i]=0;
    vs[0]=1;
    for(auto x:vec){
        for(int i=n;i>=0;i--) if(i-x>=0&&vs[i-x]){
            vs[i]=1;
        }
    }
    // for(auto x:vec) cout<<x<<" ";cout<<"!!!\n";
    for(int i=1;i<=n;i++) vis[i]|=vs[i];
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        adde(u,v);adde(v,u);
    }
    dfs(1,0);
    int cnt=0;
    for(int i=1;i<=n-2;i++) if(vis[i]) cnt++;
    cout<<cnt<<'\n';
    for(int i=1;i<=n-2;i++) if(vis[i]) cout<<i<<" "<<n-i-1<<'\n';
    return 0;
}