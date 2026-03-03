#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,s,x,sum=0;
    cin>>n>>s>>x;
    for(int i=1,y;i<=n;i++){
        cin>>y;
        sum+=y;
    }
    if(sum<=s&&(sum-s)%x==0) cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}