#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+100;
ll a,b,c,n,m,x[N];
void __(){
    cin>>n>>m>>a>>b>>c;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    ll f=0,cnt=0;
    for(int i=2;i<=n;i++){
        if(x[i]!=(x[i-1]+1)%m) f=1;
        if(x[i]<=x[i-1]) cnt++;
    }
    // cout<<cnt*m+x[n]+1<<"!!\n";
    cout<<a*(cnt*m+x[n]+1)+f*c+b*(cnt*m+x[n]+1-n);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    __();
	return 0;
}