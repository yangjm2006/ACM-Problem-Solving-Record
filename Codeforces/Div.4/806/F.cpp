#include<bits/stdc++.h>
void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n+1),s(n+1,0);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    for(int i=1;i<=n;i++) if(a[i]<i) s[i]=1;
    for(int i=1;i<=n;i++) s[i]+=s[i-1];
    long long ans=0;
    for(int i=1;i<=n;i++) if(a[i]<i) ans+=s[std::min(std::max(0,a[i]-1),n)];
    std::cout<<ans<<'\n';
}
int main(){
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
    int T;
    std::cin>>T;
    while(T--) solve();
    return 0;
}