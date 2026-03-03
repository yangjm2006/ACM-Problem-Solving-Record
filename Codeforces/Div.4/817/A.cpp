#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    string s,s0="Timur";
    cin>>s;
    sort(s0.begin(),s0.end());
    sort(s.begin(),s.end());
    if(s==s0) cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}