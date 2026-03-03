#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,x;
    cin>>n>>x;
    int a[n+1],b[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+n,greater<int>());
    for(int i=1;i<=n;i++) if(a[i]+b[i]>x){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
}
int main(){
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}