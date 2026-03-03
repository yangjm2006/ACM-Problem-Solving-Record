#include"bits/stdc++.h"
using namespace std;
using ll = long long;

void solve(){
    ll n;
    cin>>n;
    // ll ans = 0;
    if(n%3==1){
        cout<<"0 ";
        cout<<n/3+1<<'\n';
    }
    else if(n%3==2){
        cout<<"0 ";
        cout<<n/3+2<<'\n';
    }
    else{
        cout<<"1 ";
        cout<<n/3<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}