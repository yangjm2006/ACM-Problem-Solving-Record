#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(){
    ll ans=0;
    int n,m;
    cin>>n>>m;
    vector<vector<ll>> a(n+1,vector<ll>(m+1));
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
    for(int i=1;i<=n;i++){
        ll tmp=0;
        vector<ll> v(m+1,0);
        for(int j=1;j<=m;j++){
            if(a[i][j]>=0) tmp+=a[i][j];
            else{
                v[j]=min(abs(a[i][j]),tmp);
                tmp-=v[j];
            }
        }
        tmp=0;
        for(int j=m;j>=1;j--){
            if(a[i][j]<0) tmp-=a[i][j];
            else{
                v[j]=-min(tmp,a[i][j]);
                tmp+=v[j];
            }
        }
        for(int j=1;j<=m;j++) a[i][j]+=v[j];
        if(i<n) for(int j=1;j<=m;j++) if(a[i][j]>0){
            a[i+1][j]+=a[i][j];
            a[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) ans+=abs(a[i][j]);
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
}
/*
1
3 3
-1 100 -2
1 -1 -1
-1 -1 -1
*/