#include<bits/stdc++.h>
using namespace std;
void solve(){
    set<int> st;
    int n;
    cin>>n;
    bool f=0;
    for(int i=1,x;i<=n;i++){
        cin>>x;
        if(st.find(x)!=st.end()){
            f=1;
        }
        st.insert(x);
    }
    if(f) cout<<"NO\n";
    else cout<<"YES\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}