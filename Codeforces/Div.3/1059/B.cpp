#include<bits/stdc++.h>
using namespace std;
string s;
bool vis[300];
int T,n;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        cin>>s;
        for(int i=0;i<n;i++) vis[i+1]=s[i]-'0';
        vector<int> ans;
        for(int i=1;i<=n;i++) if(!vis[i]) ans.push_back(i);
        cout<<ans.size()<<'\n';
        for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
        cout<<'\n';
    }
    return 0;
}