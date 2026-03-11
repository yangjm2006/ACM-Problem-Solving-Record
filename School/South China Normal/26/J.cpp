#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    double ans=0;
    for(int i=1;i<=n;i++){
        long long x,y,a,b;
        cin>>x>>y>>a>>b;
        ans+=sqrt((x-a)*(x-a)+(y-b)*(y-b));
    }
    int sx,sy;
    cin>>sx>>sy;
    cout<<fixed<<setprecision(10)<<ans*2;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}