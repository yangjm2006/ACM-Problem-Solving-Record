#include<bits/stdc++.h>
void solve(){
    int n,s;
    std::cin>>n>>s;
    std::vector<int> v(n+1);
    for(int i=1;i<=n;i++) std::cin>>v[i];
    std::cout<<std::min(std::abs(s-v[1]),std::abs(s-v[n]))+std::abs(v[1]-v[n])<<'\n';
}
int main(){
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
    int T;
    std::cin>>T;
    while(T--) solve();
    return 0;
}