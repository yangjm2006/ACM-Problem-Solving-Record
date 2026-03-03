#include<bits/stdc++.h>
using namespace std;
const int N=1e3+100;
int a[N][N],n;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n-1;i++) for(int j=0;j<n-1;j++) a[i][j]=(i+j)%(n-1)+1;
    for(int i=0;i<n;i++) a[i][n-1]=a[n-1][i]=a[i][i];
    for(int i=0;i<n;i++) a[i][i]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout<<a[i][j]<<" ";
        cout<<'\n';
    }
    return 0;
}