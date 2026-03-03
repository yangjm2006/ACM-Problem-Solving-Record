#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<bool> vis(1000,0);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        vis[x]=1;
    }
    for(int i=0;;i++) if(!vis[i]){
        cout<<i<<'\n';
        return;
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}