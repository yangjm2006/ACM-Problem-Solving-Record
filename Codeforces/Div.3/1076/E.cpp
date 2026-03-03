#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int dp[n+1];
    for(int i=1;i<=n;i++) dp[i]=INT_MAX/2;
    for(int i=1,x;i<=n;i++){
        cin>>x;
        dp[x]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=2;j*j<=n;j++) if(i%j==0){
            dp[i]=min(dp[i],dp[j]+dp[i/j]);
        }
    }
    for(int i=1;i<=n;i++)
        if(dp[i]==INT_MAX/2) cout<<"-1 ";
        else cout<<dp[i]<<" ";
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}