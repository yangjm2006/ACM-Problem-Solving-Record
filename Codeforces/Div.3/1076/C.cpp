#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,q;
    cin>>n>>q;
    int a[n+1],b[n+1],s[n+2]={0};
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    a[n]=max(a[n],b[n]);
    s[n]=a[n];
    for(int i=n-1;i>=1;i--){
        a[i]=max(a[i],max(a[i+1],b[i]));
        s[i]+=s[i+1]+a[i];
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<s[l]-s[r+1]<<' ';
    }
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}