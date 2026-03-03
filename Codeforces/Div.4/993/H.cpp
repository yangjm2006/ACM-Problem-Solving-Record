#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e3+100;
ll T,n,q,a[N][N],s[4][N][N],x1,yy,x2,y2;
ll qry(int id){
    return s[id][x2][y2]-s[id][x1-1][y2]-s[id][x2][yy-1]+s[id][x1-1][yy-1];
}
void init(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            s[1][i][j]=s[1][i][j-1]+s[1][i-1][j]-s[1][i-1][j-1]+a[i][j];
            s[2][i][j]=s[2][i][j-1]+s[2][i-1][j]-s[2][i-1][j-1]+j*a[i][j];
            s[3][i][j]=s[3][i][j-1]+s[3][i-1][j]-s[3][i-1][j-1]+i*a[i][j];
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>q;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
        init();
        while(q--){
            cin>>x1>>yy>>x2>>y2;
            ll ans=0;
            ans+=qry(2)-qry(1)*(yy-1);
            ans+=(qry(3)-qry(1)*x1)*(y2-yy+1);
            cout<<ans<<" ";
        }
        cout<<"\n";
    }
    return 0;
}