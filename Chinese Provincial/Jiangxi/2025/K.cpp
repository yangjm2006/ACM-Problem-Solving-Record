#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF=1e17;
const int N=1e6+100;
ll n,s,ans=INF,a[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<=3;i++){
        int to=i;ll vis=0;
        for(int j=1;j<=n;j++) vis+=(a[j]-to+4)%4;
        // cout<<to<<" "<<vis<<"--\n";
        ans=min(ans,(4-(to+vis)%4)%4+vis);
    }
    cout<<ans;
    return 0;
}