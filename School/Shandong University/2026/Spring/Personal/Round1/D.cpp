#include<bits/stdc++.h>
using namespace std;
void __(){
    int n;
    cin>>n;
    map<int,int> mp;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        int cnt=0;
        while(x%2==0){
            x/=2;
            cnt++;
        }
        mp[x]=max(mp[x],cnt);
    }
    int ans=0;
    for(auto &x:mp){
        ans+=x.second;
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}