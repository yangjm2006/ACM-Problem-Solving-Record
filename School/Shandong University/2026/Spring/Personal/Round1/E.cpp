#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
const int INF=1e9+1000;
int a[N],b[N],n;
void __(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    int ans=-1;
    for(int k=0;k<=n;k++){
        int minn=INF;
        for(int i=1;i<=k;i++){
            minn=min(minn,abs(a[i]-b[n-k+i]));
        }
        for(int i=k+1;i<=n;i++){
            minn=min(minn,abs(a[i]-b[i-k]));
        }
        ans=max(ans,minn);
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}