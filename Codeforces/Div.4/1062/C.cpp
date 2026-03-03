#include<bits/stdc++.h>
const int N=2e5+100;
int a[N];
void solve(){
    int n;
    std::cin>>n;
    bool f1=0,f2=0;
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
        if(a[i]&1) f1=1;
        else f2=1;
    }
    if(f1&&f2) std::sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) std::cout<<a[i]<<" ";
    std::cout<<'\n';
}
int main(){
    int T;
    std::cin>>T;
    while(T--){
        solve();
    }
    return 0;
}