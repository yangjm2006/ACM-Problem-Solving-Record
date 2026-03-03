#include<bits/stdc++.h>
void solve(){
    int n;
    std::cin>>n;
    std::string s1,s2;
    std::cin>>s1>>s2;
    std::vector<int> v(30,0);
    for(auto c:s1) v[int(c-'a')]++;
    for(auto c:s2) v[int(c-'a')]--;
    bool f=1;
    for(auto x:v) if(x) f=0;
    std::cout<<(f?"YES\n":"NO\n");
}
int main(){
    int T;
    std::cin>>T;
    while(T--){
        solve();
    }
    return 0;
}