#include<bits/stdc++.h>
#define ull unsigned long long
const ull mod=1e9+7;
const ull base1=233;
const ull base2=131;
using namespace std;
set<pair<ull,ull>> st;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        ull h1=0,h2=0;
        for(int i=s.size()-1;i>=0;i--){
            h1=h1*base1+s[i];
            h2=(h2*base2+s[i])%mod;
            st.insert(make_pair(h1,h2));
        }
    }
    cout<<st.size();
    return 0;
}