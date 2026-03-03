#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
    ll cntu,cntr,sums;
    node(){
        cntu=cntr=sums=0;
    }
    node operator * (node _){
        node ans;
        ans.cntu=cntu+_.cntu;
        ans.cntr=cntr+_.cntr;
        ans.sums=sums+_.sums+cntu*_.cntr;
        return ans;
    }
    friend node operator ^ (node a,ll b){
        node ans;
        for(;b;b>>=1,a=a*a) if(b&1) ans=ans*a;
        return ans;
    }
}U,R;
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
ll S(ll n,ll a,ll b,ll c){
    node ans=(U^(c/b))*solve(a,b,c%b,n,U,R);
    return ans.sums;
}
void __(){
    ll n,m,a,b;
    cin>>n>>m>>a>>b;
    if(a==0) cout<<min(b,n)<<'\n';
    else cout<<(b!=0)-S(n-1,a,m,b)+S(n-1,a-1,m,b-1+m)<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    U.cntu=1;
    R.cntr=1;
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}