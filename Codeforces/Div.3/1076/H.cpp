#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int n,val[N],num[N],sz[N],fuc[N];
vector<int> g[N],ans,mp[N];
queue<int> que;
void dfs(int u,int fa){
    sz[u]++;
    for(auto v:g[u]){
        if(v==fa) continue;
        dfs(v,u);
        sz[u]+=sz[v];
        if(sz[v]%2==0) fuc[u]++;
    }
    if(sz[u]%2==1&&fa!=0) fuc[u]++;
    if(fuc[u]==0) que.push(u);
}
void solve(){
    cin>>n;
    ans.clear();
    while(!que.empty()) que.pop();
    for(int i=1;i<=n;i++){
        cin>>val[i];
        val[i]%=2;
        g[i].clear();
        mp[i].clear();
        num[i]=sz[i]=fuc[i]=0;
    }
    vector<pair<int,int>> e;
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        e.push_back(make_pair(u,v));
        if(val[u]!=0) num[v]++;
        if(val[v]!=0) num[u]++;
        if(val[u]==0&&val[v]!=0) mp[v].push_back(u);
        if(val[v]==0&&val[u]!=0) mp[u].push_back(v);
    }
    vector<bool> vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(val[i]==0){
            if(num[i]==0){
                cout<<"NO\n";
                return;
            }else if(num[i]%2==1){
                ans.push_back(i);
                vis[i]=1;
            }
        }
    }
    for(auto x:e){
        int u=x.first,v=x.second;
        if(val[u]!=0&&val[v]!=0){
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    for(int i=1;i<=n;i++) if(sz[i]==0&&val[i]!=0){
        dfs(i,0);
        if(sz[i]%2==0){
            cout<<"NO\n";
            return;
        }
        while(!que.empty()){
            int u=que.front();que.pop();
            ans.push_back(u);
            for(auto v:mp[u]){
                if(vis[v]==0){
                    ans.push_back(v);
                    vis[v]=1;
                }
            }
            for(auto v:g[u]){
                fuc[v]--;
                if(fuc[v]==0) que.push(v);
            }
        }
    }
    // for(int i=1;i<=n;i++) cout<<fuc[i]<<" ";cout<<"!!!!!!!!\n";
    cout<<"YES\n";
    for(auto x:ans) cout<<x<<" ";
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}