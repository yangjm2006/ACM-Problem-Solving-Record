#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1,0);
    a[1]=n;a[2]=n+1;
    for(int i=3;i<=n;i++) a[i]=a[1]+a[i-1]+1;
    cout<<n<<"\n";
    for(int i=1;i<=n;i++) cout<<i<<" ";cout<<'\n';
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}