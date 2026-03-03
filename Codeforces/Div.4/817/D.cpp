#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> v;ll ans=0;
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        if(c=='L'){
            ans+=i-1;
            v.push_back((n-i)-(i-1));
        }
        else{
            ans+=n-i;
            v.push_back((i-1)-(n-i));
        }
    }
    sort(v.begin(),v.end(),greater<int>());
    for(int i=0;i<n;i++){
        ans=max(ans,ans+v[i]);
        cout<<ans<<" ";
    }
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}