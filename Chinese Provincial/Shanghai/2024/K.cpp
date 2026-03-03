#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF=1e18;
struct node{
    ll a,b;
    bool operator < (const node &x) const{
        return b>x.b;
    }
}x[40];
ll maxx,n,m;
void dfs(int u,ll res,ll sum,ll ans){
    maxx=max(ans,maxx);
    if(u>n) return;
    // cout<<u<<" "<<res<<" "<<sum<<" "<<ans<<"==\n";
    for(int i=u;i<=n;i++){
        if(x[i].a<=res){
            dfs(i+1,res-x[i].a,sum+x[i].b,ans+sum);
        }
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>x[i].a;
    for(int i=1;i<=n;i++) cin>>x[i].b;
    sort(x+1,x+1+n);
    dfs(1,m,0,0);
    cout<<maxx;
}
int main(){
    solve();
    return 0;
}
/*
 5 20
 4 5 6 7 8
 5 8 7 4 9
*/