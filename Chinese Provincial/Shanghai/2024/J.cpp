#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int prime[N],cnt,a[N];
bool ntp[N+1];
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) a[i]+=a[i-1];
    for(int j=1;j<=n;j++) for(int i=1;i+j-1<=n;i++){
        if(ntp[a[i+j-1]-a[i-1]]){
            cout<<j-1<<'\n';
            return;
        }
    }
    cout<<-1<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i=2;i<=N;i++){
        if(!ntp[i]) prime[++cnt]=i;
        for(int j=1;j<=cnt&&prime[j]<=N/i;j++){
            ntp[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
    // for(int i=cnt;i>=cnt-10;i--) cout<<prime[i]<<" ";cout<<'\n';
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}