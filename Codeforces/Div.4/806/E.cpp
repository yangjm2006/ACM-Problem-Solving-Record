#include<bits/stdc++.h>
int n;
bool mp[200][200];
void solve(){
    std::cin>>n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
        char c;
        std::cin>>c;
        mp[i][j]=c-'0';
    }
    int ans=0;
    for(int i=1;i<=(n+1)/2;i++) for(int j=1;j<=n/2;j++){
        int tot=0;
        tot+=mp[i][j];
        tot+=mp[j][n+1-i];
        tot+=mp[n+1-j][i];
        tot+=mp[n+1-i][n+1-j];
        ans+=std::min(tot,4-tot);
    }
    std::cout<<ans<<'\n';
}
int main(){
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
    int T;
    std::cin>>T;
    while(T--) solve();
    return 0;
}