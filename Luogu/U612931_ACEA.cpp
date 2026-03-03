#include<bits/stdc++.h>
#define ll long long
using namespace std;
// ll gsc(ll a,ll b,const ll mod){
//     ll ans=0;
//     for(;b;b>>=1,(a<<=1)%=mod) if(b&1) (ans+=a)%=mod;
//     return ans;
// }
ll gsc(ll a,ll b,const ll mod){
    return (ll)((__int128)a*b%mod);
}
ll ksm(ll a,ll b,const ll mod){
    ll ans=1;
    for(;b;b>>=1,a=gsc(a,a,mod)) if(b&1) ans=gsc(ans,a,mod);
    return ans;
}
ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}
void __(){
    ll a,b;
    cin>>a>>b;
    cout<<gcd(ksm(a,b,b),b)<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}