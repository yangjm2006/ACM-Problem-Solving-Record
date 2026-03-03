#include"bits/stdc++.h"
#define ll long long
const ll INF=1e18;
using namespace std;
void solve(){
    ll n,c,ans=-INF;
    cin>>n>>c;
    vector<ll> a(n+1),dp(40,0);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) for(int k=33;k>=0;k--){
        if(k==0) dp[0]=dp[0]+a[i]-c;
        else if(k==33) dp[k]=max(dp[k],dp[k-1]+(a[i]>>k));
        else dp[k]=max(dp[k]+(a[i]>>k)-c,dp[k-1]+(a[i]>>k));
    }
    for(int k=0;k<=33;k++) ans=max(ans,dp[k]);
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}