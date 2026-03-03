#include<bits/stdc++.h>
#define ll long long
using namespace std;
void __(){
    int n;
    cin>>n;
    int maxx=-1,minn=1e9;
    ll cnt=0,ans=0;
    map<int,int> pos;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        pos[x]=i;
        if(x>maxx||x<minn){
            cnt+=i;
            maxx=x+1;
            minn=x+1;
        }else{
            cnt+=i-pos[x-1];
            maxx=x+1;
        }
        ans+=cnt;
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