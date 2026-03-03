#include<bits/stdc++.h>
void solve(){
    std::vector<int> v(4);
    for(int i=0;i<4;i++) std::cin>>v[i];
    bool f=1;
    for(int i=1;i<4;i++) if(v[i]!=v[0]) f=0;
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