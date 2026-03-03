#include<bits/stdc++.h>
using namespace std;
#define ll long long
void __(){
    ll n,len[3],val[3];
    cin>>n>>val[1]>>val[2];
    val[0]=val[1]+val[2];
    len[0]=8;
    len[1]=7;
    len[2]=2;
    ll ans=-1;
    for(int i=0;i<=10;i++){
        if(i*len[0]<=n){
            ans=max(ans,i*val[0]+(n-i*len[0])/len[1]*val[1]);
            ans=max(ans,i*val[0]+(n-i*len[0])/len[2]*val[2]);
        }
        if(i*len[1]<=n){
            ans=max(ans,i*val[1]+(n-i*len[1])/len[0]*val[0]);
        }
        if(i*len[2]<=n){
            ans=max(ans,i*val[2]+(n-i*len[2])/len[0]*val[0]);
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}