#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll ans=0;
    int n,m;
    cin>>n>>m;
    vector<vector<ll>> a(n+2,vector<ll>(m+2,0));
    vector<vector<ll>> v1(n+2,vector<ll>(m+2,0));
    vector<vector<ll>> v2(n+2,vector<ll>(m+2,0));
    vector<vector<ll>> f(n+2,vector<ll>(m+2,0));
    
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
    
    for(int i = 1; i <= n; i++){
        v1[i][m] = min(a[i][m], 0ll);
        for(int j = m-1; j >= 1; j--){
            v1[i][j] = min(v1[i][j+1] + a[i][j], 0ll);
        }  
    }

    for(int j = 1; j <= m; j++){
        v2[n][j] = min(a[n][j], 0ll);
        for(int i = n-1; i >= 1; i--){
            v2[i][j] = min(v2[i+1][j] + a[i][j], 0ll);
        }
    }

    for(int i = n; i >= 1; i--){
        for(int j = m; j >= 1; j--){
            f[i][j] = a[i][j] + min(f[i+1][j+1], 0ll) + min(v1[i][j+1], 0ll) + min(v2[i+1][j], 0ll);
            
        }
    }


}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
}