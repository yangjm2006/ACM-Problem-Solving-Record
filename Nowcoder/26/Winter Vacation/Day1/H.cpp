#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+100;
const ll mod=998244353;
int a[N],pre[N];
ll dp[N],s[N];
void solve(){
    ll n;
    cin>>n;
    for(int i=2;i<=n+1;i++) cin>>a[i];
    int lst=1;
    dp[1]=s[1]=1;
    for(int i=2;i<=n+1;i++){
        pre[i]=lst;
        if(a[i]) lst=i;
    }
    for(int i=2;i<=n+1;i++){
        int j=i,vis=0;
        while((vis&a[j])==0&&j>=1){
            vis|=a[j];
            j=pre[j];
        }
        // cout<<i<<" "<<j<<"!!!!\n";
        dp[i]=(s[i-1]-s[j-1]+mod)%mod;
        s[i]=(s[i-1]+dp[i])%mod;
    }
    // for(int i=1;i<=n+1;i++) cout<<dp[i]<<" ";cout<<"==========\n";
    cout<<dp[n+1]%mod<<'\n';
}
int main(){
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}