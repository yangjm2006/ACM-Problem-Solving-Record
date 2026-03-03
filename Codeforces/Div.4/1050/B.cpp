#include<bits/stdc++.h>
using namespace std;
int T,n,m;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        int x;
        cin>>n>>m>>x>>x;
        for(int i=1;i<=n+m;i++) cin>>x;
        cout<<n+m<<'\n';
    }
    return 0;
}