#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+100;
ll T,n,a[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        ll ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+1+n,greater<ll>());
        int cnt=0;
        vector<ll> v;
        for(int i=1;i<=n;i++){
            if(a[i]&1){
                cnt++;
                v.push_back(a[i]);
            }
            else ans+=a[i];
        }
        for(int i=0;i<(cnt+1)/2;i++) ans+=v[i];
        cout<<(cnt?ans:0)<<'\n';
    }
    return 0;
}