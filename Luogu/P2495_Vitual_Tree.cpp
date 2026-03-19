#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e5+100;
const ll INF=1e18;
vector<pair<int,ll>> e1[N];
vector<int> e2[N];
int dfn[N],dn,st[30][N];
ll w[N];
void dfs1(int u,int fa){
    st[0][dfn[u]=++dn]=fa;
    for(auto x:e1[u]){
        int v=x.first;ll val=x.second;
        if(v==fa) continue;
        w[v]=min(w[u],val);
        dfs1(v,u);
    }
}
int lg[N];
int get(int x,int y){
    return dfn[x]<dfn[y]?x:y;
}
int lca(int u,int v){
    if(u==v) return u;
    u=dfn[u];v=dfn[v];
    if(u>v) swap(u,v);
    u++;
    int k=lg[v-u+1];
    return get(st[k][u],st[k][v-(1<<k)+1]);
}
bool cmp(int x,int y){
    return dfn[x]<dfn[y];
}
ll dp[N];
void dfs2(int u,int fa){
    for(auto v:e2[u]){
        if(v==fa) continue;
        dfs2(v,u);
        dp[u]+=min(dp[v],w[v]);
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    for(int i=2;i<=n;i++) lg[i]=lg[i/2]+1;
    for(int i=1;i<n;i++){
        int u,v;ll w;
        cin>>u>>v>>w;
        e1[u].push_back(make_pair(v,w));
        e1[v].push_back(make_pair(u,w));
    }
    w[1]=INF;
    dfs1(1,0);
    for(int k=1;k<=lg[n];k++){
        for(int i=1;i<=n-(1<<k-1);i++){
            st[k][i]=get(st[k-1][i],st[k-1][i+(1<<k-1)]);
        }
    }
    int m;
    cin>>m;
    while(m--){
        int k;
        cin>>k;
        vector<int> vec1,vec2;
        for(int i=1;i<=k;i++){
            int x;
            cin>>x;
            vec1.push_back(x);
            vec2.push_back(x);
            dp[x]=INF;
        }
        sort(vec1.begin(),vec1.end(),cmp);
        vec2.push_back(1);
        for(int i=1;i<vec1.size();i++){
            vec2.push_back(lca(vec1[i],vec1[i-1]));
        }
        sort(vec2.begin(),vec2.end(),cmp);
        vec2.erase(unique(vec2.begin(),vec2.end()),vec2.end());
        for(int i=1;i<vec2.size();i++){
            int u=lca(vec2[i],vec2[i-1]),v=vec2[i];
            e2[u].push_back(v);
            e2[v].push_back(u);
        }
        dfs2(1,0);
        cout<<dp[1]<<'\n';
        for(auto x:vec2){
            e2[x].clear();
            dp[x]=0;
        }
    }
    return 0;
}