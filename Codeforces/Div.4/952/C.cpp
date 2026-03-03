#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T,n;
set<ll> st;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        st.clear();
        cin>>n;
        int ans=0;ll s=0;
        for(int i=1;i<=n;i++){
            ll x;
            cin>>x;
            s+=x;
            st.insert(x);
            if(s%2==0&&st.find(s/2)!=st.end()) ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}