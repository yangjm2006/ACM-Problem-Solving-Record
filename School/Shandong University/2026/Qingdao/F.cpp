#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1010;
ll dp[N][N],a[N][N],w1[N][N],w2[N][N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
    for(int i=1;i<=n;i++){
        ll res=0;
        for(int j=1;j<=m;j++){
            res+=a[i][j];
            w1[i][j+2]=res*res;
        }
    }
    for(int j=1;j<=m;j++){
        ll res=0;
        for(int i=1;i<=n;i++){
            res+=a[i][j];
            w2[i+2][j]=res*res;
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
            if(i==n&&j==m) dp[i][j]=0;
            else if(i==n) dp[i][j]=dp[i][j+1]+w1[i][j+1];
            else if(j==m) dp[i][j]=dp[i+1][j]+w2[i+1][j];
            else dp[i][j]=min(dp[i][j+1]+w1[i][j+1],dp[i+1][j]+w2[i+1][j]);
        }
    }
    cout<<dp[1][1];
    return 0;
}