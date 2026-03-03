#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
const ll INF=1e9+100;
ll T,l1,r1,l2,r2,k;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>k>>l1>>r1>>l2>>r2;
        ll ans=0,t=1;
        for(int i=0;i<=60;i++){
            ll minn=max(l1*t,l2),maxx=min(r1*t,r2);
            ll ansl,ansr;
            ll l=1,r=1e9+10;
            while(l<r){
                ll mid=l+r>>1;
                if(mid*t>=minn) r=mid;
                else l=mid+1;
            }
            ansl=l;
            l=1;r=1e9+10;
            while(l<r){
                ll mid=(l+r>>1)+1;
                if(mid*t<=maxx) l=mid;
                else r=mid-1;
            }
            ansr=l;
            if(ansl*t<minn||ansr*t>maxx) continue;
            // cout<<ansl<<" "<<ansr<<"------\n";
            if(ansr>=ansl) ans+=ansr-ansl+1;
            t*=k;
            if(t>=INF) break;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
/*
7
2 2 6 2 12
2 1 1000000000 1 1000000000
3 5 7 15 63
1000000000 1 5 6 1000000000
15 17 78 2596 20914861
2 3 3 6 6
2 3 3 7 7
*/