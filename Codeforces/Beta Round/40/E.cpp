#include<bits/stdc++.h>
using namespace std;
int n,k;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    if(n==1){
        cout<<"0";
        return 0;
    }
    k=n/2;
    cout<<k*(n-k)<<'\n';;
    for(int i=1;i<=k;i++){
        for(int j=k+1;j<=n;j++){
            cout<<i<<" "<<j<<'\n';
        }
    }
    return 0;
}