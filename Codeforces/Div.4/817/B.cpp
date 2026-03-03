#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<bool> vis1(n,0),vis2(n,0);
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        if(c=='R') vis1[i]=1;
    }
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        if(c=='R') vis2[i]=1;
    }
    for(int i=0;i<n;i++){
        if(vis1[i]^vis2[i]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}
int main(){
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}