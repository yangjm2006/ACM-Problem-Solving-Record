#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T,a,b,c,d;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>a>>b>>c>>d;
        int ans=0;
        if(a>=c&&b>=d){
            if(a>c||b>d) ans++;
        }
        if(a>=d&&b>=c){
            if(a>d||b>c) ans++;
        }
        cout<<ans*2<<'\n';
    }
    return 0;
}