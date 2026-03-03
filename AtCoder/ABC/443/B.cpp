#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n,k;
    cin>>n>>k;
    ll l=1,r=1e9;
    while(l<r){
        ll mid=l+r>>1;
        if((2*n+mid-1)*mid/2/k) r=mid;
        else l=mid+1;
    }
    cout<<l-1;
    return 0;
}