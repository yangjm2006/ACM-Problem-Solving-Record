#include<bits/stdc++.h>
using namespace std;
int T,n,k;
int main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        cout<<k/(n-1)*n+k%(n-1)-(k%(n-1)==0)<<'\n';
    }
    return 0;
}