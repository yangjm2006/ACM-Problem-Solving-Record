#include<bits/stdc++.h>
using namespace std;
void solve(){
    vector<int> v(3);
    cin>>v[0]>>v[1]>>v[2];
    sort(v.begin(),v.end());
    if(v[0]+v[1]==v[2]) cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}