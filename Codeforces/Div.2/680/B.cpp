#include<bits/stdc++.h>
using namespace std;
void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<max(a+b,c+d)<<'\n';
}
int main(){
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}