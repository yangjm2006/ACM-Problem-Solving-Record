#include<bits/stdc++.h>
using namespace std;
int mp[40][40],n,cnt,f[24];
main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    f[1]=1;f[2]=2;
    for(int i=3;i<=23;i++) f[i]=f[i-1]+f[i-2];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                cout<<"0 ";
            }else cout<<f[i]+f[j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}