#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n;map<int,int> mp;
        cin>>n;
        for(int i=1,x;i<=n;i++){
            cin>>x;
            mp[x]++;
        }
        int ans=0,cnt=0;
        for(auto &x:mp){
            ans++;
            if(x.second%2==0){
                cnt+=x.second-1;
            }
        }
        cout<<ans-(cnt&1)<<'\n';
    }
    return 0;
}