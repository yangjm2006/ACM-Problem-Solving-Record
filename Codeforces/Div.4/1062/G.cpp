#include<bits/stdc++.h>
#define ll long long
void solve(){
    int n;
    std::cin>>n;
    std::vector<ll> a(n+1),c(n+1),dp(n+1);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    ll sum=0;
    for(int i=1;i<=n;i++){
        std::cin>>c[i];
        sum+=c[i];
    }
    dp[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i-1;j++){
            if(a[i]>=a[j]) dp[i]=std::max(dp[i],dp[j]);
        }
        dp[i]+=c[i];
    }
    ll ans=1e18;
    for(int i=1;i<=n;i++) ans=std::min(ans,sum-dp[i]);
    std::cout<<ans<<'\n';
}
int main(){
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
    int T;
    std::cin>>T;
    while(T--) solve();
    return 0;
}