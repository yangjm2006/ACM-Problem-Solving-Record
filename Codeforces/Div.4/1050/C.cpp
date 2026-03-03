#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int T,ans,n,m,a[N];
bool b[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        ans=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i];
            ans+=a[i]-a[i-1];
            ans-=(a[i]-a[i-1]&1)^(b[i]^b[i-1]);
        }
        ans+=m-a[n];
        cout<<ans<<'\n';
    }
    return 0;
}