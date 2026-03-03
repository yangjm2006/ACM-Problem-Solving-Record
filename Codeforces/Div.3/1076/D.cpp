#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e5+100;
ll a[N],b[N];
void solve(){
    int n;
    cin>>n;
    ll maxx=-1;
    set<ll> st;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        st.insert(a[i]);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) b[i]+=b[i-1];
    for(ll x:st){
        ll l=0,r=n;
        while(l<r){
            ll mid=l+r>>1;
            if(a[mid]>=x) r=mid;
            else l=mid+1;
        }
        ll num=n-l+1;
        l=0;r=n;
        while(l<r){
            ll mid=(l+r>>1)+1;
            if(b[mid]<=num) l=mid;
            else r=mid-1;
        }
        maxx=max(maxx,l*x);
    }
    cout<<maxx<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}