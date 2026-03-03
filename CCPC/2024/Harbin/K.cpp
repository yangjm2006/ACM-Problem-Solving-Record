#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
ll T,n;
ll m;

struct node{
    ll w,l,r;
}a[N];

bool cmp(node a,node b){
    return a.w<b.w;
}
ll sumr[N],suml[N];
ll lenr[N],lenl[N];


void solve(){
    cin>>n>>m;
    ll num = 0;
    ll tmp = 0;
    for(int i=1;i<=n;i++){
        cin>>a[i].w>>a[i].l>>a[i].r;
    }

    ll ans = num;
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        sumr[i]=sumr[i-1]+a[i].r*a[i].w;
        suml[i]=suml[i-1]+a[i].l*a[i].w;
        lenl[i]=lenl[i-1]+a[i].l;
        lenr[i]=lenr[i-1]+a[i].r;
        num+=a[i].l*a[i].w;
        tmp+=a[i].l;
    }

    for(int i=1;i<=n;i++){
        ll l=i,r=n;
        ll tmpx = tmp-a[i].l;
        while(l<=r){
            ll mid = (l+r)>>1;
            if(lenr[n]-lenr[mid]-(lenl[n]-lenl[mid])+tmpx<=m){
                r=mid-1;
            }
            else l=mid+1;
        }
        r++;
        ll cha = m-tmpx-(lenr[n]-lenr[r]-lenl[n]+lenl[r]);
        // cout<<lenr[n]<<" "<<lenr[r]<<" "<<lenl[n]<<" "<<lenl[r]<<endl;
        // cout<<r<<" ! "<<tmpx<<" "<<cha<<endl;
        ll tpnum = num - a[i].w*a[i].l + (sumr[n]-sumr[r]-suml[n]+suml[r]) + cha*a[r].w;
        // cout<<num-a[i].w*a[i].l<<endl;
        ans=max(ans,tpnum);
        // cout<<i<<" "<<ans<<" "<<tpnum<<endl;
    }
    cout<<ans<<endl;
}

int main(){
    T=1;
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(T--){
        solve();
    }
    return 0;
}