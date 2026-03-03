#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    string s;
    cin>>n>>s;
    vector<int> num(26,0);
    for(auto c:s) num[int(c-'a')]++;
    cout<<n-num[int(s[n-1]-'a')]<<'\n';
}
int main(){
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}