#include<bits/stdc++.h>
#define ll long long
void solve(){
    int n;
    std::cin>>n;
    std::vector<ll> a(n+1),c(n+1);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    ll sum=0;
    for(int i=1;i<=n;i++){
        std::cin>>c[i];
        sum+=c[i];
    }
    std::set<std::pair<ll,ll>> st;
    st.insert(std::make_pair(0,0));st.insert(std::make_pair(1e18,1e18));
    for(int i=1;i<=n;i++){
        std::pair<ll,ll> nw=std::make_pair(a[i],c[i]+std::prev(st.lower_bound(std::make_pair(a[i]+1,0ll)))->second);
        while(st.lower_bound(std::make_pair(a[i],0ll))->second<=nw.second){
            st.erase(st.lower_bound(std::make_pair(a[i],0ll)));
        }
        st.insert(nw);
    }
    st.erase(std::prev(st.end()));
    ll ans=1e18;
    for(auto &x:st) ans=std::min(ans,sum-x.second);
    std::cout<<ans<<'\n';
}
int main(){
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
    int T;
    std::cin>>T;
    while(T--) solve();
    return 0;
}