#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T,n;
int cnt[50000];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        memset(cnt,0,sizeof(cnt));
        cin>>n;
        ll ans=0;
        for(int i=1;i<=n;i++){
            char c;int c1,c2;
            cin>>c;
            c1=c-'a'+1;
            cin>>c;
            c2=c-'a'+1;
            ans+=cnt[c1]+cnt[c2*233]-cnt[c1+c2*233]*2;
            cnt[c1]++;
            cnt[233*c2]++;
            cnt[c1+c2*233]++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}