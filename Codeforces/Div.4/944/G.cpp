#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int a[N];
multiset<int> st[N];
map<int,int> mp;
set<int> stt;
void solve(){
    mp.clear();stt.clear();
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        stt.insert(a[i]>>2);
        st[i].clear();
    }
    int cn=0;
    for(auto x:stt){
        mp[x]=++cn;
    }
    for(int i=1;i<=n;i++) st[mp[a[i]>>2]].insert(a[i]);
    // for(int i=1;i<=n;i++) cout<<mp[a[i]>>2]<<" ";cout<<"!!!!!\n";
    for(int i=1;i<=n;i++){
        cout<<*st[mp[a[i]>>2]].begin()<<" ";
        st[mp[a[i]>>2]].erase(st[mp[a[i]>>2]].begin());
    }
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}