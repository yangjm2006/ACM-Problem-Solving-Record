#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> v1,v2;
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        if(c=='a') v1.push_back(i);
        else v2.push_back(i);
    }
    int p=v1.size()/2;ll ans1=0,ans2=0;
    for(int i=0;i<v1.size();i++){
        ans1+=abs(v1[i]-v1[p])-abs(i-p);
    }
    p=v2.size()/2;
    for(int i=0;i<v2.size();i++){
        ans2+=abs(v2[i]-v2[p])-abs(i-p);
    }
    cout<<min(ans1,ans2)<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}