#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+100;
ll T,n,m,a[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+1+n,greater<ll>());
        for(int i=1;i<=n;i++) a[i]+=a[i-1];
        while(m--){
            int x;
            cin>>x;
            if(a[n]<x) cout<<"-1\n";
            else{
                int l=1,r=n;
                while(l<r){
                    int mid=l+r>>1;
                    if(a[mid]>=x) r=mid;
                    else l=mid+1;
                }
                cout<<l<<'\n';
            }
        }
    }
    return 0;
}