#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF=1e18;
const int N=2e6+100;
struct node{
    ll tim;
    int op,id;
    bool operator < (const node &_) const{
        return tim>_.tim;
    }
};
struct edge{
    int v,w;
};
vector<edge> e[N];
int a[N];
ll ans[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    priority_queue<node> q;
    for(int i=1;i<=k;i++){
        ll t;int num;
        cin>>t>>num;
        for(int j=1;j<=num;j++){
            int id;
            cin>>id;
            q.push((node){t,2,id});
        }
    }
    for(int i=1;i<=m;i++){
        int u,v;ll w;
        cin>>u>>v>>w;
        e[u].push_back((edge){v,w});
    }
    for(int i=1;i<=n;i++) ans[i]=INF;
    for(int i=1;i<=n;i++){
        if(a[i]==0){
            ans[i]=0;
            for(auto x:e[i]){
                int v=x.v;ll w=x.w;
                if(ans[v]==INF) q.push((node){w,1,v});
            }
        }
    }
    while(!q.empty()){
        int u=q.top().id,op=q.top().op;ll t=q.top().tim;q.pop();
        if(ans[u]!=INF) continue;
        if(op==1){
            a[u]--;
            if(a[u]<=0){
                ans[u]=t;
                for(auto x:e[u]){
                    int v=x.v;ll w=x.w;
                    if(ans[v]==INF) q.push((node){t+w,1,v});
                }
            }
        }else{
            ans[u]=t;
            for(auto x:e[u]){
                int v=x.v;ll w=x.w;
                if(ans[v]==INF) q.push((node){t+w,1,v});
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(ans[i]==INF) cout<<"-1 ";
        else cout<<ans[i]<<" ";
    }
    return 0;
}