#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int T,n,m,k;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        vector<int> a[n+1];
        for(int i=1;i<=n;i++) for(int j=1;j<=m+1;j++) a[i].push_back(0);
        if(m%k){
            int cnt=0;
            for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=(cnt++)%k+1;
        }else{
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++) a[i][j]=(i+j)%k+1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) cout<<a[i][j]<<" ";
            cout<<'\n';
        }
    }
    return 0;
}