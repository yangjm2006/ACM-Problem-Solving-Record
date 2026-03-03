#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll pw(int x){
    ll res=1;
    for(int i=1;i<=x;i++) res*=10;
    return res;
} 
void solve(){
    ll l,r,ans=0;
    cin>>l>>r;
    for(int i=10;i>=0;i--){
        cout<<l<<" "<<r<<"++\n";
        if(l/pw(i)==r/pw(i)){
            if(l/pw(i)){
                ans+=2;
                l%=pw(i);
                r%=pw(i);
            }
        }
    }
    while(r){
        if(l==r-1) ans++;
        l/=10;r/=10;
    }
    cout<<ans<<'\n';
}
int main(){
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
    int T;
    std::cin>>T;
    while(T--) solve();
    return 0;
}