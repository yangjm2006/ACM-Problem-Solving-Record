#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T,x,y,z,v;
int main(){
    cin>>T;
    while(T--){
        ll ans=0;
        cin>>x>>y>>z>>v;
        for(ll i=1;i<=x;i++) for(ll j=1;j<=y;j++) if(v%(i*j)==0){
            ans=max(ans,(x-i+1)*(y-j+1)*max(0ll,z-v/(i*j)+1));
        }
        cout<<ans<<'\n';
    }
    return 0;
}