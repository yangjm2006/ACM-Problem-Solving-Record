#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF=1e18+10000;
const int N=70;
bool vis[N];
ll a[N],b[N];
bool check(ll x){
    for(int i=0;i<=62;i++) b[i]=a[i];
    for(int i=62;i>=1;i--){
        if(b[i]>=INF) return 0;
        if(vis[i]==0){
            b[i-1]+=b[i]*2;
            b[i]=0;
        }else{
            if(b[i]>x){
                b[i-1]+=(b[i]-x)*2;
                b[i]=x;
            }
        }
    }
    // for(int i=10;i>=0;i--) cout<<b[i]<<" ";cout<<'\n';
    if(b[0]){
        if(vis[0]==0||b[0]>x) return 0;
    }
    return 1;
}
void __(){
    ll s,m;
    cin>>s>>m;
    for(int i=0;i<=62;i++){
        if((1ll<<i)&m) vis[i]=1;
        else vis[i]=0;
        if((1ll<<i)&s) a[i]=1;
        else a[i]=0;
    }
    ll l=1,r=INF;
    while(l<r){
        ll mid=l+r>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    if(l==INF) cout<<"-1\n";
    else cout<<l<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}