#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+100;
const ll mod=998244353;
ll ans,n,a[N],cnt[N*N];
ll amax = -1;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        amax = max(amax, a[i]);
    }
    sort(a+1,a+1+n);
    cnt[0]=1;
    ll res = 1;
    for(int j=1;j<=n;j++){

        ll sum = 0;
        for(int i = 0; i <= a[j]; i++){
            sum += cnt[i];
            sum %= mod;
        }
        ans+=(res-sum);
		 
        for(int i=amax;i>=0;i--){
            if(i>=a[j]) cnt[i]+=cnt[i-a[j]];
            cnt[i]%=mod;
        }
                
        res *= 2;
        res %= mod;
        ans += mod;
        ans %= mod;

    }
    cout << ans;
    return 0;
}