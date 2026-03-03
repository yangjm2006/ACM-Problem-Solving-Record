#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF=1e18;
void solve(){
    int n,q;
    cin>>n>>q;
    vector<ll> a(n+1),b(n+2,0),s(n+2,0);
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    ll mexx=n;b[0]=INF;
    for(int i=1;i<=n;i++)
        if(a[i]==i-1) b[i]=min(b[i-1],b[i]);
        else{
            mexx=i-1;
            b[i]=0;
            break;
        }
    for(int i=mexx;i>=1;i--){
        s[i]=s[i+1]+i*(b[i]-b[i+1]);
    }
    while(q--){
        ll m;
        cin>>m;
        if(m==mexx){
        	cout<<"1\n";
        	continue;
		}
        if(m==0){
            cout<<"-1\n";
            continue;
        }
        if(m>s[1]){
            cout<<"-1\n";
            continue;
        }
        int l=1,r=mexx;
        while(l<r){
            int mid=(l+r>>1)+1;
            if(s[mid]>=m) l=mid;
            else r=mid-1;
        }
        cout<<max(2ll,b[l]-(s[l]-m)/l)<<"\n";
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}