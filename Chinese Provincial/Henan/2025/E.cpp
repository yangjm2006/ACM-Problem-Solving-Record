#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+100;
int _,tr[N][27],a[N];
int n;
void insert(string s){
    int p=0;
    for(int i=0;i<s.size();i++){
        if(!tr[p][int(s[i]-'a')]) tr[p][int(s[i]-'a')]=++_;
        p=tr[p][int(s[i]-'a')];
        a[p]++;
    }
}
ll query(string s){
    ll ans=0;
    int p=0;
    for(int i=0;i<s.size();i++){
        if(!tr[p][int(s[i]-'a')]) return ans;
        p=tr[p][int(s[i]-'a')];
        ans+=a[p];
    }
    return ans;
}
string s[N];
void solve(){
    ll ans=0;
    cin>>n;
    for(int i=1;i<=2*n;i++) cin>>s[i];
    sort(s+1,s+1+2*n);
    for(int i=1;i<=n;i++) insert(s[2*i-1]);
    for(int i=1;i<=n;i++) ans+=query(s[2*i]);
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    // cin>>T;
    T=1;
    while(T--) solve();
    return 0;
}