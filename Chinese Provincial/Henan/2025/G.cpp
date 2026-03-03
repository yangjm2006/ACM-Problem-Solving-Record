#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,x;
    cin>>n;
    if(n%3==0){
        x=2*n/3;
        for(int i=1;i<=x-1;i++) cout<<i<<" "<<i+1<<'\n';
        for(int i=x+1;i<=n;i++) cout<<1<<" "<<i<<'\n';
    }else if(n%3==2){
        x=(2*n-1)/3;
        for(int i=1;i<=x-1;i++) cout<<i<<" "<<i+1<<'\n';
        for(int i=x+1;i<=n;i++) cout<<1<<" "<<i<<'\n';
    }else{
        if(n==4) cout<<"-1\n";
        else{
            n--;
            x=2*n/3;
            for(int i=1;i<=x-1;i++) cout<<i<<" "<<i+1<<'\n';
            for(int i=x+1;i<=n;i++) cout<<1<<" "<<i<<'\n';
            cout<<2<<" "<<n+1<<'\n';
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}