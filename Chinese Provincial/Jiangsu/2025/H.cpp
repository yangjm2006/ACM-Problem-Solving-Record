#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
const int N=2e6+100;
map<char,int> mp;
ll dp[N];
void __(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    s="0"+s;
    mp.clear();
    for(int i=1;i<=n;i++) dp[i]=0;
    for(int i=1;i<=k+1;i++){
        if(mp[s[i]]==0) dp[i]=1;
        dp[i]+=dp[i-1];
        mp[s[i]]=1;
    }
    for(int i=k+2;i<=n;i++){
        if(mp[s[i]]==0) dp[i]=dp[i-k-1]+1;
        else dp[i]=dp[i-k-1]-dp[mp[s[i]]-1];
        mp[s[i]]=i-k;
        dp[i]+=dp[i-1];
        (dp[i]+=mod)%=mod;
    }
    // for(int i=1;i<=n;i++) cout<<dp[i]-dp[i-1]<<" ";cout<<'\n';
    cout<<dp[n]<<'\n';
}
int main(){
    ios::sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}
