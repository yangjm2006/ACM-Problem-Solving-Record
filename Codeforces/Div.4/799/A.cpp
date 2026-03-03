#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int a[4],ans=0;
        for(int i=0;i<4;i++) cin>>a[i];
        for(int i=1;i<4;i++) ans+=(a[0]<a[i]);
        cout<<ans<<'\n';
    }
    return 0;
}