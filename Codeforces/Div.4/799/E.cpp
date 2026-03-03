#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int T,n,m;
bool vis[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>m;
        int cnt=0;
        for(int i=1;i<=n;i++){
            cin>>vis[i];
            if(vis[i]) cnt++;
        }
        if(cnt<m){
            cout<<"-1\n";
            continue;
        }
        vector<int> v1,v2;
        v1.push_back(0);v2.push_back(0);
        for(int i=1;i<=n;i++){
            if(vis[i]) v1.push_back(i);
        }
        for(int i=n;i>=1;i--){
            if(vis[i]) v2.push_back(n-i+1);
        }
        int ans=1e9;
        for(int i=0;i<=cnt-m;i++){
            ans=min(ans,v1[i]+v2[cnt-m-i]);
        }
        cout<<ans<<'\n';
    }
    return 0;
}