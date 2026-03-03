#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+100;
ll T,n,s[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>s[i];
        for(int i=n-1;i>=1;i--) s[i]+=s[i+1];
        sort(s+2,s+n+1,greater<ll>());
        for(int i=1;i<=n;i++){
            s[i]+=s[i-1];
            cout<<s[i]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}