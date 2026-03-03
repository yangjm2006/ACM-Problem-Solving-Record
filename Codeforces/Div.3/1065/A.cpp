#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    if(n%2) cout<<"0\n";
    else cout<<n/4+1<<'\n';
}
int main(){
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}