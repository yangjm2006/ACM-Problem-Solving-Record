#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,T,ans;
int main(){
    cin>>n>>T;
    for(int i=1;i<=n;i++){
        ll k,t;
        cin>>t>>k;
        if(t+ans<=T) ans+=t;
        else{
            if(ans<=T){
                t-=T-ans;
                ans=T;
            }
            ans=max(ans+1,min(k+T+1,ans+t));
        }
    }
    cout<<ans<<'\n';
    return 0;
}
/*
 3 5
 1 2
 2 3
 3 4

 3 1
 1 1
 2 2
 3 3
*/