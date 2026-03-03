#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=200;
ull T,n,k,t[N],l[N],w[N];
bool check(ull x){
    ull res=0;
    for(int i=1;i<=n;i++){
        res+=x/(t[i]*l[i]+w[i])*l[i];
        res+=min((x%(t[i]*l[i]+w[i]))/t[i],l[i]);
        if(res>=k) return 1;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>t[i]>>l[i]>>w[i];
        ull l=1,r=2e18;
        while(l<r){
            ull mid=l+r>>1;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        cout<<l<<'\n';
    }
    return 0;
}