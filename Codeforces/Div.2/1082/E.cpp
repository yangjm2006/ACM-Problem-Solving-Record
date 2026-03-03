#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
const int N=1e6+100;
ll pw[N],dp[N][2];
void __(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    dp[0][0]=1;
    int sum=0;ll ans=0;
    for(int i=1;i<=n;i++){
        if(s[i-1]=='('){
            (ans+=pw[i-1])%=mod;
            sum++;
            dp[i][0]=dp[i-1][0];
            (dp[i][1]=dp[i-1][1]*2+dp[i-1][0])%=mod;
        }else{
            (ans+=dp[i-1][0]+dp[i-1][1])%=mod;
            sum--;
            dp[i][1]=dp[i-1][1];
            (dp[i][0]=dp[i-1][0]*2+dp[i-1][1])%=mod;
        }
        if(sum<2) dp[i][1]=0;
    }
    // for(int i=1;i<=n;i++) cout<<dp[i][0]<<" ";cout<<'\n';
    // for(int i=1;i<=n;i++) cout<<dp[i][1]<<" ";cout<<'\n';
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    pw[0]=1;
    for(int i=1;i<N;i++) pw[i]=pw[i-1]*2%mod;
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}