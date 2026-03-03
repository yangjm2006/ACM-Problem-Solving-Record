#include<bits/stdc++.h>
#define ll long long
#define MAXN 500010
#define MAXV 2000010

using namespace std;

ll a[MAXN];
ll dp[MAXN];

int last[MAXV];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,k;
    cin >> n >> k;
    for(ll i = 1; i <= n; i++){
    	cin >> a[i];
	}
	last[0] = 0;
	for(ll i = 1; i <= (1<<20); i++){
		last[i]=-1;
	}
	
    ll sum = 0;
	for(ll i=1;i<=n;i++){
        dp[i] = dp[i-1];
        sum^=a[i];
        ll lst = sum^k;
        if(last[lst]!=-1)dp[i] = max(dp[i],dp[last[lst]]+1);
        // cout<<i<<" "<<sum<<" "<<lst<<" "<<last[lst]<<" "<<dp[i]<<endl;
        last[sum]=i;
    }
    cout<<dp[n]<<endl;

    return 0;
}