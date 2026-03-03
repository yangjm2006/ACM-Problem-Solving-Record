#include<bits/stdc++.h>
#define ll long long
const int N=2e5+100;
const int M=3e7+100;
bool ntp[M+1];
int prime[M/5],cnt;
void solve(){
    int n;
    std::cin>>n;
    bool vis[41]={0};
    for(int i=1;i<=n;i++){
        ll x;
        std::cin>>x;
        for(int j=1;j<=cnt;j++) if(x%prime[j]) vis[j]=1;
    }
    for(int i=1;i<=cnt;i++) if(vis[i]){
        std::cout<<prime[i]<<'\n';
        break;
    }
}
int main(){
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
    for(int i=2;i<=M;i++){
        if(!ntp[i]) prime[++cnt]=i;
        if(cnt==int(40)) break;
        for(int j=1;j<=cnt&&prime[j]<=M/i;j++){
            ntp[i*prime[j]]=1;
            if(i%prime[j]==0) break;
        }
    }
    int T;
    std::cin>>T;
    while(T--){
        solve();
    }
    return 0;
}