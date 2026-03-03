#include"bits/stdc++.h"
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int> v(27);
        for(auto x:s) v[x-'A']=1;
        int ans=s.size();
        for(auto x:v) ans+=x;
        cout<<ans<<'\n';
    }
    return 0;
}