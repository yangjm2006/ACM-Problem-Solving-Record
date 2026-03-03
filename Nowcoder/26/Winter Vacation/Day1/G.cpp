#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
bool check(ll x){
    ll res=1;
    for(int i=1;i<=17;i++){
        if(res==x) return 1;
        res*=10;
    }
    return 0;
}
ll dne(ll x){
    ll res=1;
    while(res*10<=x) res*=10;
    return res;
}
void prt(ll x){
    bool f=0;
    while(x){
        if(x%10) f=1;
        if(f) cout<<x%10;
        x/=10;
    }
    cout<<'\n';
}
void solve(){
    ll l,r;
    cin>>l>>r;
    if(l==r){
        prt(l);
        return;
    }
    if(check(r)){
        prt(r-1);
        return;
    }
    l=max(l,dne(r)+1);
    // cout<<l<<"!!!!!!!\n";
    if(l==r){
        prt(l);
        return;
    }
    ll res=10000000000000000ll;
    while(res!=0&&r/res==l/res){
        res/=10;
    }
    ll ans;
    // cout<<r%res<<"!!!"<<res<<"!!!\n";
    if(r%res==res-1) ans=r/res;
    else ans=r/res-1;
    // cout<<ans<<"-------\n";
    while(res!=1){
        res/=10;
        ans=ans*10+9;
    }
    prt(ans);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}