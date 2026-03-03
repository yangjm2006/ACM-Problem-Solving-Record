#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF=1e18;
void solve(){
    int n;
    cin>>n;
    ll maxx[n+2],minn[n+2],x[n+1],y[n+1];
    for(int i=0;i<=n;i++){
        maxx[i]=0;
        minn[i]=2e9;
    }
    ll ax,ay,bx,by;
    cin>>ax>>ay>>bx>>by;
    set<ll> st;
    map<ll,ll> mp;
    for(int i=1;i<=n;i++){ 
        cin>>x[i];
        st.insert(x[i]);
    }
    ll cnt=0;
    for(auto x:st){
        mp[x]=++cnt;
    }
    for(int i=1;i<=n;i++) cin>>y[i];
    for(int i=1;i<=n;i++){
        ll id=mp[x[i]];
        maxx[id]=max(maxx[id],y[i]);
        minn[id]=min(minn[id],y[i]);
    }
    maxx[0]=minn[0]=ay;
    cnt++;
    maxx[cnt]=minn[cnt]=by;
    // cout<<cnt<<"!!!!!!!!!!!!!\n";
    // for(int i=0;i<=cnt;i++){
    //     cout<<maxx[i]<<" "<<minn[i]<<"------\n";
    // }
    ll dp[cnt+1][2];
    for(int i=1;i<=cnt;i++){
        dp[i][0]=dp[i][1]=INF;
    }
    dp[0][0]=dp[0][1]=0;
    for(int i=1;i<=cnt;i++){
        dp[i][0]=min(dp[i-1][0]+abs(maxx[i]-minn[i-1]),dp[i-1][1]+abs(maxx[i]-maxx[i-1]))+maxx[i]-minn[i];
        dp[i][1]=min(dp[i-1][0]+abs(minn[i]-minn[i-1]),dp[i-1][1]+abs(minn[i]-maxx[i-1]))+maxx[i]-minn[i];
    }
    cout<<min(dp[cnt][1],dp[cnt][0])+bx-ax<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
/*
1
6 1 1 10 10
2 2 3 3 7 7
4 6 3 7 5 8
*/