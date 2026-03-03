#include<bits/stdc++.h>
using namespace std;
int n,s,t;
int main(){
    cin>>n>>s>>t;
    if((t-s+n)%n<=n/2) cout<<1;
    else cout<<2;
    return 0;
}