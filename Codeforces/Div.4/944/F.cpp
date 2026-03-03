#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long R;
    cin>>R;
    long long ans=0;
    for(long long i=0;i<=R;i++){
        long long l=0,r=1e9,ll;
        while(l<r){
            long long mid=l+r>>1;
            if(mid*mid>=R*R-i*i) r=mid;
            else l=mid+1;
        }
        ll=l;
        l=0;r=1e9;
        while(l<r){
            long long mid=(l+r>>1)+1;
            if(mid*mid<(R+1)*(R+1)-i*i) l=mid;
            else r=mid-1;
        }
        // cout<<i<<" "<<l<<" "<<ll<<"!!!\n";
        ans+=l-ll+1;
    }
    ans--;
    cout<<ans*4<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
/*
6
1
2
3
4
5
1984

5
1
2
3
4
5
*/