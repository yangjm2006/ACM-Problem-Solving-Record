#include<bits/stdc++.h>
using namespace std;
int n,cnt,a[200][200];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n-2;i++){
        a[1][i]=++cnt;
    }
    for(int i=2;i<=n-2;i++){
        a[i][1]=++cnt;
        for(int j=2;j<=n-2;j++) a[i][j]=a[i][j-1];
    }
    a[n-1][n-1]=++cnt;a[n-1][n]=++cnt;
    a[n][n-1]=++cnt;a[n][n]=++cnt;
    ++cnt;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(!a[i][j]) a[i][j]=cnt;
    cout<<"Yes\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cout<<a[i][j]<<" ";
        cout<<'\n';
    }
    return 0;
}