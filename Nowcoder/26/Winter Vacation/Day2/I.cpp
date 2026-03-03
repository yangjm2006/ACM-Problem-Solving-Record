#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
string s[N];
void __(){
    int n,m;
    cin>>n>>m;
    int vis0=0,vis1=0;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        for(auto c:s[i]){
            if(c=='1') vis1++;
            else vis0++;
        }
    }
    for(int i=1;i<=n;i++){
        for(auto c:s[i]){
            if(c=='1'){
                if(vis1>=2) cout<<'Y';
                else cout<<'N';
            }
            if(c=='0'){
                if(vis0>=2) cout<<'Y';
                else cout<<'N';
            }
        }
        cout<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}