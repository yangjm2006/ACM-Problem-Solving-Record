#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
bool tr[N];
int a[N],n;
bool c[N];
bool check(int x){
    for(int i=1;i<=n;i++){

    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>c[i];
    int l=0,r=1e9;
    while(l<r){
        int mid=l+r>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    return 0;
}