#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    std::cin>>n;
    std::string s;
    std::vector<int> v(30,0);
    std::cin>>s;
    for(auto x:s) v[x-'a']++;
    bool f=0;
    for(int i=1;i<n-1;i++) if(v[s[i]-'a']>=2) f=1;
    if(f) std::cout<<"YES\n";
    else std::cout<<"NO\n";
}
int main(){
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
    int T;
    std::cin>>T;
    while(T--) solve();
    return 0;
}