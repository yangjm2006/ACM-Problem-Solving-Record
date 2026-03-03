#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T,x,y;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>x>>y;
        // vector<ll> ans;
        ll vis1=0,vis2=0;
        for(int i=32;i>=0;i--){
            // if((1ll<<i)>x) continue;
            if((y&(1ll<<i))^(x&(1ll<<i))){
                // ans.push_back(1ll<<i);
                // x^=(1ll<<i);
                if(!vis1) vis1^=(1ll<<i);
                else vis2^=(1ll<<i);
            }
        }
        if(vis1>x) cout<<"-1\n";
        else{
            // cout<<ans.size()<<'\n';
            // for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
            // if(ans.size()) cout<<'\n';
            cout<<2<<'\n'<<vis2<<" "<<vis1<<" "<<'\n';
        }
    }
    return 0;
}