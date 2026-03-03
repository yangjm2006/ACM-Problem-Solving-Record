#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
long long a[N],b[N];
void solve(){
    long long n,k,q;
    cin>>n>>k>>q;
    for(int i=1;i<=k;i++) cin>>a[i];
    for(int i=1;i<=k;i++) cin>>b[i];
    while(q--){
        long long d;
        cin>>d;
        int l=0,r=k;
        while(l<r){
            int mid=(l+r>>1)+1;
            if(a[mid]<d) l=mid;
            else r=mid-1;
        }
        // cout<<l<<"!! ";
        cout<<(d-a[l])*(b[l+1]-b[l])/(a[l+1]-a[l])+b[l]<<' ';
    }
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}