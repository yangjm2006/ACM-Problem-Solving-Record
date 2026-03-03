#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(){
    ll x,y,ans=1;
    cin>>x>>y;
    if(x%y){
        cout<<x<<'\n';
        return;
    }
    for(ll i=2;i*i<=y;i++){
        ll res=1,tmp=x;
        while(y%i==0){
            y/=i;
            res*=i;
        }
        res/=i;
        while(tmp%i==0){
            tmp/=i;
        }
        ans=max(ans,tmp*res);
    }
    if(y!=1){
        ll tmp=x;
        while(tmp%y==0){
            tmp/=y;
        }
        ans=max(ans,tmp);
    }
    cout<<ans<<'\n';
}
int main(){
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}