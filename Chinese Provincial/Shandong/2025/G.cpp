#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    cin>>k>>n;
    vector<int> t(k);
    for(int i=0;i<k;i++){
        int a,b;
        cin>>a>>b;
        t[i]=n-a+b;
    }
    sort(t.begin(),t.end());
    int ans=0;
    for(int i=0;i<k;i++){
        ans=max(ans+1,t[i]);
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}