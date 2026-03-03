#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=4e5+100;
const ll INF=1e18;
ll a[N],n,D;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>D;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll R=0,ans=0;
    set<ll> st;
    st.insert(INF);
    for(int i=1;i<=n;i++){
        while(R<n&&*st.upper_bound(a[R+1]-D)>=a[R+1]+D){
            st.insert(a[R+1]);
            R++;
        }
        ans+=R-i+1;
        st.erase(a[i]);
    }
    cout<<ans;
    return 0;
}