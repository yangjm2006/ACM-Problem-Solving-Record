#include<bits/stdc++.h>
#define ll long long
using namespace std;
void __(){
    ll p,q;
    cin>>p>>q;
    if(p<q&&3*p>=2*q) cout<<"Bob\n";
    else cout<<"Alice\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}