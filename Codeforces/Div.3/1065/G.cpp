#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e6+3;
const int N=1e6+3;
ll ksm(ll a,ll b){
    ll ans=1;
    for(;b;b>>=1,a=a*a%mod) if(b&1) ans=ans*a%mod;
    return ans;
}
ll fac[N],inv[N];
ll n,a[N],b[N],c[N];
bool check(){
    for(int i=1;i<=n;i++) if(c[i]<a[i]) return 0;
    return 1;
}
ll res,ans;
void cal1(){
    ll tmp=0;
    for(int i=1;i<=n;i++) tmp+=b[i]-c[i]*2;
    ans=ans*fac[tmp]%mod;
    tmp++;
    res+=tmp;
    return;
}
void cal2(){
    ll tmp=0;
    for(int i=1;i<=n;i++){
        tmp+=b[i]-a[i];
        ans*=inv[b[i]-a[i]];
        ans%=mod;
    }
    res+=tmp;
    if(tmp>=mod) ans=0;
    else ans*=fac[tmp];
    ans%=mod;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) c[i]=b[i]/2;
    res=0,ans=1;
    while(check()){
        cal1();
        for(int i=1;i<=n;i++){
            c[i]/=2;
            b[i]/=2;
        }
        // for(int i=1;i<=n;i++) cout<<b[i]<<" ";cout<<"!!!!!!\n";
    }
    cal2();
    cout<<res<<" "<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    fac[0]=1;
    for(int i=1;i<N;i++) fac[i]=fac[i-1]*i%mod;
    inv[N-1]=ksm(fac[N-1],mod-2);
    for(int i=N-2;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
    // for(int i=1;i<=10;i++) cout<<fac[i]<<" ";cout<<'\n';
    // for(int i=1;i<=10;i++) cout<<inv[i]<<" ";cout<<'\n';
    // for(int i=1;i<=10;i++) cout<<fac[i]*inv[i]%mod<<" ";cout<<'\n';
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}