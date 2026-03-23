#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+100;
ll sum[N],a[N];
void __(){
    ll n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        ll res=0;
        for(int j=i;j>=1;j--){
            res+=a[j];
            if(res>=2*a[i]) break;
            int l=i,r=n;
            while(l<r){
                int mid=(l+r>>1)+1;
                if(sum[mid]-sum[i]+res<2*a[i]) l=mid;
                else r=mid-1;
            }
            ans+=l-i+1;
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}