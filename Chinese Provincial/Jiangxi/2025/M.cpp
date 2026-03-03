#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n, k;
    cin >> n >> k;
    for(int i=1;i<=n-k;i++) cout<<2;
    for(int i=n-k+1;i<=n;i++) cout<<3;
    return 0;
}