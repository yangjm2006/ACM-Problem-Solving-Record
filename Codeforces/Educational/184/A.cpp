#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,v1=0,v2=0,a;
    cin>>n>>a;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x>a) v2++;
        else if(x<a) v1++;
    }
    if(v1>v2) cout<<a-1<<'\n';
    else cout<<a+1<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}