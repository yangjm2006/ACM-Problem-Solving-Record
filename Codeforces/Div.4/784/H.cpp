#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int T,n,k,a[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>a[i];
        int vis=0;
        for(int i=30;i>=0;i--){
            int cnt=n;
            for(int j=1;j<=n;j++) cnt-=bool(a[j]&(1<<i));
            if(cnt<=k){
                k-=cnt;
                cnt=0;
            }
            if(cnt==0) vis|=(1<<i);
        }
        cout<<vis<<'\n';
    }
    return 0;
}