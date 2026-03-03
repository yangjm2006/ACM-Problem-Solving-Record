#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,ans=0,cnt=0;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<0) cnt++;
        else if(a[i]==0) ans++;
    }
    if(cnt&1) ans+=2;
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}