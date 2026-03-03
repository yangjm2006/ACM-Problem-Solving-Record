#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+100;
ll T,h,n,a[N],c[N];
bool check(ll x){
    ll res=0;
    for(int i=1;i<=n;i++){
        res+=((x-1)/c[i]+1)*a[i];
        if(res>=h) return 1;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>h>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>c[i];
        ll l=1,r=1e12;
        while(l<r){
            ll mid=l+r>>1;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        cout<<l<<'\n';
    }
    return 0;
}