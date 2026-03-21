#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+100;
const ll INF=-1e18;
struct node{
    ll m,s;
    bool operator < (const node &_) const{
        return m<_.m;
    }
}a[N];
ll sum[N],ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;ll d;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i].m>>a[i].s;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i].s;
    }
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        while(l<r){
            int mid=l+r>>1;
            if(a[mid].m>a[i].m-d) r=mid;
            else l=mid+1; 
        }
        // cout<<i<<" "<<l<<"!!\n";
        ans=max(ans,sum[i]-sum[l-1]);
    }
    cout<<ans;
    return 0;
}