#include<bits/stdc++.h>
using namespace std;
int T,n;
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        cout<<max(0,n-2)<<'\n';
    }
    return 0;
}