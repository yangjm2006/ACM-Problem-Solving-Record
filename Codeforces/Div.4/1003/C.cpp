#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+100;
const ll INF=1e18;
ll T,n,m,a[N],b[N],tmp;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        tmp=-INF;
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=m;i++) cin>>b[i];
        sort(b+1,b+1+m);
        bool f=1;
        for(int i=1;i<=n;i++){
            int l=1,r=m;
            while(l<r){
                int mid=l+r>>1;
                if(b[mid]-a[i]>=tmp) r=mid;
                else  l=mid+1;
            }
            ll minn=INF;
            if(a[i]>=tmp) minn=min(a[i],minn);
            if(b[l]-a[i]>=tmp) minn=min(b[l]-a[i],minn);
            if(minn<tmp||minn==INF){
                f=0;
                break;
            }
            else tmp=minn;
        }
        if(f) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}