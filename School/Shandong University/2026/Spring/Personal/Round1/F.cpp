#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int a[N],f[N][2];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    // f[n][1]=a[n];f[n-1][1]=a[n-1];f[n-1][0]=a[n];
    for(int i=n;i>=1;i--){
        f[i][0]=max(f[i+1][1],f[i+1][0]);
        f[i][1]=min(f[i+1][1],f[i+1][0])+a[i];
    }
    // for(int i=1;i<=n;i++) cout<<f[i][0]<<" ";cout<<"\n";
    // for(int i=1;i<=n;i++) cout<<f[i][1]<<" ";cout<<"\n";
    cout<<min(f[1][0],f[1][1])<<" "<<max(f[1][0],f[1][1]);
    return 0;
}