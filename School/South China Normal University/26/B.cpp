#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+100;
int a[N];
void solve(){
    int n;
    cin>>n;
    ll ans=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int k=0;k<=30;k++){
        ll cnt=0;
        for(int i=1;i<=n;i++) if((a[i]>>k)&1) cnt++;
        ans+=(1<<k)*cnt*(cnt-1)/2;
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}