#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
const int N=1e3+10;
ll dp[N][N][2],sum[N][N][2];
void __(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
        if(i<=j) dp[i][j][1]=1;
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
        sum[i][j][1]=sum[i-1][j][1]+sum[i][j-1][1]-sum[i-1][j-1][1]+dp[i][j][1];
    }
    for(int o=2;o<=m;o++){
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
            if(i<=j){
                dp[i][j][o&1]=sum[i][n][(o-1)&1]-sum[i][j-1][(o-1)&1]-sum[0][n][(o-1)&1]+sum[0][j-1][(o-1)&1];
                (dp[i][j][o&1]+=mod)%=mod;
            }
        }
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
            sum[i][j][o&1]=sum[i-1][j][o&1]+sum[i][j-1][o&1]-sum[i-1][j-1][o&1]+dp[i][j][o&1];
            (sum[i][j][o&1]+=mod)%=mod;
        }
    }
    cout<<sum[n][n][m&1];
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    __();
    return 0;
}