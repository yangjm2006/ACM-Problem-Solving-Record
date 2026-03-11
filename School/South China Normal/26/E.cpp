#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+100;
const int INF=1e9+100;
int n,k,a[N],cnt;
bool vis[N];
bool check(int x){
    for(int i=1;i<=n;i++) vis[i]=0;
    int lst=-INF;
    cnt=0;
    for(int i=1;i<=n;i++){
        if(a[i]-lst<x){
            cnt++;
            vis[i]=1;
        }else{
            lst=a[i];
        }
    }
    return cnt<=k;
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    int l=1,r=INF;
    while(l<r){
        int mid=(l+r>>1)+1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    check(l);
    cout<<cnt<<'\n';
    for(int i=1;i<=n;i++) if(vis[i]) cout<<i<<" ";
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}