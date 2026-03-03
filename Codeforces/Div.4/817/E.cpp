#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(){
    int n,q;
    cin>>n>>q;
    vector<vector<ll>> v(1001,vector<ll>(1001,0ll));
    for(int i=1;i<=n;i++){
        ll h,w;
        cin>>h>>w;
        v[h][w]+=h*w;
    }
    for(int i=1;i<=1000;i++) for(int j=1;j<=1000;j++) v[i][j]+=v[i][j-1];
    while(q--){
        int h1,w1,h2,w2;
        cin>>h1>>w1>>h2>>w2;
        ll ans=0;
        for(int i=h1+1;i<=h2-1;i++){
            ans+=v[i][w2-1]-v[i][w1];
        }
        cout<<ans<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}