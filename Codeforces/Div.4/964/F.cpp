#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e5+100;
const ll mod=1e9+7;
ll ksm(ll a,ll b){
    ll ans=1;
    for(;b;b>>=1,a=a*a%mod) if(b&1) ans=ans*a%mod;
    return ans;
}
ll jie[N],inj[N];
ll C(int n,int m){
    if(m>n||n<0||m<0) return 0;
    return jie[n]*inj[m]%mod*inj[n-m]%mod;
}
ll T,n,m,k;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    jie[0]=1;
    for(ll i=1;i<N;i++) jie[i]=jie[i-1]*i%mod;
    inj[N-1]=ksm(jie[N-1],mod-2);
    for(ll i=N-2;i>=0;i--) inj[i]=inj[i+1]*(i+1)%mod;
    cin>>T;
    while(T--){
        cin>>n>>k;
        ll ans=0;m=0;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            if(x==1) m++;
        }
        for(int i=0;i<=m;i++){
            if(i>k-i){
                ans+=C(m,i)*C(n-m,k-i)%mod;
                ans%=mod;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}