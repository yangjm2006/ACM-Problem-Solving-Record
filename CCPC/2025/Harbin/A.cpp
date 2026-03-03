#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a,ll b){
    if(b==0) return a;
    return a%b==0?b:gcd(b,a%b);
}
void solve(){
    ll g=0;
    int n;
    cin>>n;
    vector<ll> a(n+1),b(n);
    for(int i=1;i<=n;i++) cin>>a[i];
    bool f=1;
    for(int i=1;i<=n;i++) if(a[i]!=a[1]) f=0;
    if(f){
        cout<<"infinite\n";
        return;
    }
    for(int i=1;i<=n-1;i++){
        g=gcd(g,abs(a[i]-a[i+1]));
    }
    if(g==0) cout<<"infinite\n";
    else{
        ll yu = a[1]%g;
        if(yu==0){
            cout<<g<<" "<<1<<'\n';
            return;
        }
        cout<<g<<" "<<g/gcd(yu,g)<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
}