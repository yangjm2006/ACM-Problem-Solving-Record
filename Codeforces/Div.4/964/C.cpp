#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e5+100;
const ll mod=1e9+7;
ll T,n,m,s;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>s>>m;
        bool f=0;
        ll lst=0;
        for(int i=1,l;i<=n;i++){
            cin>>l;
            if(l-lst>=s) f=1;
            cin>>lst;
        }
        if(m-lst>=s) f=1;
        if(f) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}