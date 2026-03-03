#include"bits/stdc++.h"
#define ll long long
using namespace std;
const ll INF=1e18;
ll n,c[20],a[20];
ll dfs(ll x){
    if(x<0) return INF;
    if(x%10) return c[x%10]+dfs(x/10);
    if(x==0) return 0;
    ll minn=INF;
    minn=min(minn,dfs(x/10)+c[0]);
    minn=min(minn,dfs(x/10-1)+a[3]);
    minn=min(minn,dfs(x/10-5)+a[4]);
    minn=min(minn,dfs(x/10-10)+a[5]);
    minn=min(minn,dfs(x/10-50)+a[6]);
    minn=min(minn,dfs(x/10-100)+a[7]);
    return minn;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<=9;i++) cin>>c[i];
        for(int i=1;i<=7;i++) cin>>a[i];
        c[1]=min(c[1],a[1]);c[5]=min(c[5],a[2]);
        if(n==0) cout<<c[0]<<'\n';
        else cout<<dfs(n)<<'\n';
    }
    return 0;
}