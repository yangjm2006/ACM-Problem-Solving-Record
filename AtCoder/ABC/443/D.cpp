#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e5+100;
int n;
ll a[N];
void __(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]=-a[i];
    }
    ll ans=0;
    for(int i=2;i<=n;i++){
        ans+=max(0ll,a[i-1]-1-a[i]);
        a[i]=max(a[i-1]-1,a[i]);
    }
    for(int i=n-1;i>=1;i--){
        ans+=max(0ll,a[i+1]-1-a[i]);
        a[i]=max(a[i+1]-1,a[i]);
    }
    // for(int i=1;i<=n;i++) cout<<a[i]<<" ";cout<<"!!!!!!!\n";
    cout<<ans<<'\n';
}
int main(){
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}