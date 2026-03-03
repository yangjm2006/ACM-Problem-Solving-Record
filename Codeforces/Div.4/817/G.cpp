#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> ans1(n),ans2(n);
    for(int i=1;i<=(n+1)/2;i++) ans1[i]=i|(1<<30);
    for(int i=1;i<=n/2;i++) ans2[i]=i;
    if(n&1){
        ans1[(n+1)/2]=(1<<29);
        ans1[1]|=(1<<29);
    }
    if((n/2)&1){
        ans1[1]^=(1<<30);
        ans1[2]|=(1<<28);
        ans2[1]|=(1<<28);
    }
    for(int i=1;i<=n;i++)
        if(i&1) cout<<ans1[(i+1)/2]<<" ";
        else cout<<ans2[i/2]<<" ";
    cout<<'\n';
}
int main(){
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}