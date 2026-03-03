#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
struct node{
    ll cntu,cntr,sumi,sums,sqts,prd;
    node(){
        cntu=cntr=sumi=sums=sqts=prd=0;
    }
    node operator * (node _){
        node ans;
        (ans.cntu=cntu+_.cntu)%=mod;
        (ans.cntr=cntr+_.cntr)%=mod;
        (ans.sumi=sumi+_.sumi+cntr*_.cntr%mod)%=mod;
        (ans.sums=sums+_.sums+cntu*_.cntr%mod)%=mod;
        (ans.sqts=sqts+_.sqts+cntu*cntu%mod*_.cntr%mod+2*cntu*_.sums%mod)%=mod;
        (ans.prd=prd+_.prd+cntu*_.sumi%mod+cntr*_.sums%mod+cntu*cntr%mod*_.cntr%mod)%=mod;
        return ans;
    }
    friend node operator ^ (node a,ll b){
        node ans;
        for(;b;b>>=1,a=a*a) if(b&1) ans=ans*a;
        return ans;
    }
}U,R,ans;
ll cal(ll a,ll b,ll c,ll d){
    return (a*b+c)/d;
}
node solve(ll a,ll b,ll c,ll n,node A,node B){
    if(n==0) return node();
    if(a>=b) return solve(a%b,b,c,n,A,(A^(a/b))*B);
    ll m=cal(n,a,c,b);
    if(m==0) return B^n;
    ll cnt=n-cal(b,m,-c-1,a);
    return (B^((b-c-1)/a))*A*solve(b,a,(b-c-1)%a,m-1,B,A)*(B^cnt);
}
void __(){
    ll n,a,b,c;
    cin>>n>>a>>c>>b;
    ans=(U^(c/b))*solve(a,b,c%b,n,U,R);
    cout<<(ans.sums+c/b)%mod<<" "<<(ans.sqts+(c/b)*(c/b)%mod)%mod<<" "<<ans.prd<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    U.cntu=1;
    R.cntr=1;R.sumi=1;
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}