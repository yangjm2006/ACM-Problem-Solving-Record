#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,k,s=0;
    cin>>n>>k;
    vector<int> cnt(n+1,0);
    for(int i=1,x;i<=n;i++){
        cin>>x;
        cnt[x]++;
    }
    for(int i=0;i<=k-1;i++) if(!cnt[i]) s++;
    cout<<max(s,cnt[k])<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}