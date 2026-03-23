#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+100;
const int INF=1e9+100;
int a[N];
struct edge{
    int v,w;
};
vector<edge> e[N];
int n,m,val[N];
bool check(int x){
    for(int i=1;i<=n;i++) val[i]=-1;
    val[1]=0;
    for(int u=1;u<=n;u++) if(val[u]!=-1){
        val[u]=min(x,val[u]+a[u]);
        for(auto x:e[u]){
            int v=x.v,w=x.w;
            if(val[u]>=w) val[v]=max(val[v],val[u]);
        }
    }
    return val[n]!=-1;
}
void __(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        e[i].clear();
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back((edge){v,w});
    }
    int l=0,r=INF;
    while(l<r){
        int mid=l+r>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    if(l==INF) cout<<"-1\n";
    else cout<<l<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}