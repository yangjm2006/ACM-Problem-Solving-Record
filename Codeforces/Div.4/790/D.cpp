#include<bits/stdc++.h>
using namespace std;
int T,n,m,ans,a[300][300],dx[4]={1,-1,1,-1},dy[4]={1,1,-1,-1};
int main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        ans=0;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
            int sum=a[i][j];
            for(int k=1;k<=max(n,m);k++){
                for(int t=0;t<=3;t++){
                    int x=i+dx[t]*k,y=j+dy[t]*k;
                    if(x>=1&&x<=n&&y>=1&&y<=m) sum+=a[x][y];
                }
            }
            ans=max(ans,sum);
        }
        cout<<ans<<'\n';
    }
    return 0;
}